#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <regex>
#include <algorithm>
using namespace std;



class Task
{
int r,p,q,s;

public:
int & _r() {return r;}
int & _p() {return p;}
int & _q() {return q;}
int & _s() {return s;}


const int & _r() const {return r;}
const int & _p() const {return p;}
const int & _q() const {return q;}
const int & _s() const {return s;}


};
bool compare(Task a,Task b)
{
    if(a._r()<b._r())
        return true;
    return false;
}
bool compare_maxq(Task a,Task b)
{
    if(a._q()>b._q())
        return true;
    return false;
}

int seq_time(Task *v, int n)
{
    int x=0;
    int c=0;
    for(int i=0;i<n;i++)
    {
        x=max(v[i]._r(),x)+v[i]._p();
        c=max(c,(x+v[i]._q()));
    }
    return c;

}



class TaskCompareClassN
{
public:
    bool operator()(const Task &t1, const Task &t2)
    {
        if(t1._r() > t2._r())
            return true;
        else
            return false;
        if(t1._r() == t2._r())
        {
            if(t1._s() < t2._s())
                return true;
            if(t1._s() > t2._s())
                return false;
        }


        return false;
    }
};
class TaskCompareClassG
{
public:
    bool operator()(const Task &t1, const Task &t2)
    {
        if(t1._q() < t2._q())
            return true;
        else
            return false;
        if(t1._q() == t2._q())
        {
            if(t1._s() < t2._s())
                return true;
            if(t1._s() > t2._s())
                return false;
        }
        return false;
    }
};

int Schrage(vector<Task> tasks, Task *pi)
{
    int t = 0; int Cmax= 0;int k=0; Task e;
    //Task pi[10000];
    priority_queue<Task, vector<Task>, TaskCompareClassG> G;
    priority_queue<Task, vector<Task>, TaskCompareClassN> N;
    for(unsigned int i=0;i<tasks.size();i++)
        N.push(tasks[i]);
    while(!G.empty() || !N.empty())
    {
        while(!N.empty() && N.top()._r() <= t)
        {
            e=N.top();
            G.push(N.top());
            N.pop();
        }
        if(G.empty())
        {
            t=N.top()._r();
            continue;
        }

        e=G.top();
        pi[k]=e;
        k++;
        G.pop();
        t=t+e._p();        
        Cmax=max(Cmax,(t+e._q()));
    }

//    cout<< "kolejność:" << endl;
//    for(unsigned int i=0;i<tasks.size();i++)
//        cout << pi[i]._s()+1 << " ";
//    cout << endl;
//    cout << "cmax szragowy:"<< Cmax << endl;
    return Cmax;

}

int prmtS(vector<Task> tasks)
{
    int t = 0; int Cmax= 0; Task e,l;
    priority_queue<Task, vector<Task>, TaskCompareClassG> G;
    priority_queue<Task, vector<Task>, TaskCompareClassN> N;
    for(unsigned int i=0;i<tasks.size();i++)
        N.push(tasks[i]);

    l._q()=999999;
    while((!N.empty())||(!G.empty()))
    {
        while((!N.empty())&&(N.top()._r()<=t))
        {
            e=N.top();
            G.push(e);
            N.pop();
            if(e._q()>l._q())
            {
                l._p()=t-e._r();
                t=e._r();
                if(l._p()>0) G.push(l);
            }
        }

        if(G.empty())
        {
            t=N.top()._r();
            continue;
        }
        e=G.top();
        G.pop();
        l=e;
        t+=e._p();
        Cmax=max(Cmax,t+e._q());

    }

    return Cmax;

}

int BlokB(Task *PI, int n)
{
    int i = 0;
    int b = 0;
    int a =0;
//    for (i = n; i > 0; i--)
//    {
//        if (seq_time(PI,n) == seq_time(PI,i) + PI[i]._q())
//        {
//            //cout << "seqtime:" << seq_time(PI,i) << endl;
//            b = i;
//            break;
//        }
//    }

//    return b;
    int aktualnyMax=0;
    for (int i=0; i < n; i++) {														//przejrzyj listeZadan. jezeli moment rozpoczecia realizacji+r+q = Cmax,
        if (seq_time(PI,i)+PI[i]._p()+PI[i]._q() > aktualnyMax) {		//to mamy zadanie, ktore konczy caly proces
            b=i;
            aktualnyMax=seq_time(PI,i)+PI[i]._p()+PI[i]._q();
        }
    }
//    a=b;
//    while ((a>=1) && (listaZadan[a-1].t_on+listaZadan[a-1].p >= listaZadan[a].r) ){
//        a--;
//    }
    return b;
}

int BlokA(int B, Task *PI)
{
//    int Cmax=0;int A;

//    for(A = 0; A < B; A++)
//    {

//        Cmax = 0;
//        for (int i = A; i <= B; i++)
//        {
//            Cmax += PI[i]._p();
//        }

//        if (U == (PI[A]._r() + Cmax + PI[B]._q()))
//        {
//            return A;
//        }
//    }
        int A=B;
        while ((A>=1) && (seq_time(PI,A-1)+PI[A-1]._p() >= PI[A]._r()) ){
            A--;
        }
    return A;

}

int RefTask(int A, int B, Task *PI)
{
    int C = -1;
    for (int i = B; i >= A; i--)
    {
        if (PI[i]._q() < PI[B]._q())
        {
            C = i;
            break;
        }
    }
    return C;
}
int Carlier(int UB, int LB, int n, Task *pi, Task *piOpt,int U,vector<Task> tasks,Task tmp, int rm, int qm, int sm)
{
    U = Schrage(tasks,pi);
    if(U<UB){
        for(int i=0; i<n;i++)
            piOpt[i]=pi[i];
        UB=U;
    }
    int B = BlokB(pi,n);
    int A = BlokA(B,pi);
    int C = RefTask(A,B,pi);
    cout << "A:" << A << " B:"<<B<<" C:"<<C<<endl;
    if(C == -1)  cout << U;
    for(int i = C+1;i<=B;i++)
    {
        tmp._r()=min(tmp._r(),pi[i]._r());
        tmp._p() += pi[i]._p();
        tmp._q()=min(tmp._q(),pi[i]._q());
    }
    if(rm == -69)
    {
        sm = pi[C]._s();
        rm = pi[C]._r();
    }
    pi[C]._r() = max(pi[C]._r(),tmp._r()+tmp._p());

    LB = prmtS(tasks);

    if(LB < UB)
        cout << "UB" << UB << endl;
        Carlier(UB,LB, n,pi,piOpt,U,tasks,tmp,rm,qm,sm);
    for(int i = 0;i<n;i++)
    {
        if(sm == pi[i]._s())
            pi[i]._r()=rm;
    }
    rm=-69;
    if(qm == -69)
    {
        sm = pi[C]._s();
        qm = pi[C]._q();
    }
    pi[C]._q() = max(pi[C]._q(),tmp._q()+tmp._p());
    LB = prmtS(tasks);
    if(LB<UB)
         cout << "LB" << LB << endl;
        Carlier(UB,LB, n,pi,piOpt,U,tasks,tmp,rm,qm,sm);
    for(int i = 0;i<n;i++)
    {
        if(sm == pi[i]._s())
            pi[i]._q()=qm;
    }
    qm=-69;
    cout << U;


}
void CarlierEXEC(vector<Task> tasks)
{
    Task pi[10000];
    Task piOpt[10000];
    int U=0; int UB=999999; int LB=0;
    for(int i;i<tasks.size();i++)
        pi[i]=tasks[i];
    Task tmp;
    tmp._r()=999999;
    tmp._p()=0;
    tmp._q()=999999;
    int n=tasks.size();
    Carlier(UB,LB,n,pi,piOpt,U,tasks,tmp,-69,-69,-69);
    cout << "break";
    cout << "Cmax:"<< seq_time(piOpt,tasks.size()) << endl;
    for(int i=0;i<tasks.size();i++)
        cout << piOpt[i]._s() << " ";

    cout << endl;
}

int main()
{

    fstream file("/home/dominik/RPQ_spd1/dane.txt");
    string header;
    regex ptt("data.*");
    int n;

    vector <Task> tasks;
    Task tmp;


    while(1)
    {
        while(1)
        {
            file >> header;
            if (regex_match(header,ptt))
                break;
        }
        if(file.eof()) break;
        tasks.clear();
        file >> n;
        cout << header << endl;
       // cout << n << endl;
        for(int i=0;i<n;i++)
        {
            file >> tmp._r() >> tmp._p() >> tmp._q();
            tmp._s()=i;
            tasks.push_back(tmp);
        }
//        Schrage(tasks);
//        prmtS(tasks);
        CarlierEXEC(tasks);

    }
    file.close();
    return 0;
}

