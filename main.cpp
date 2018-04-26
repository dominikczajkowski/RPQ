#include <iostream>
#include <fstream>
//#include <algorithm>
#include <vector>
#include <queue>
#include <regex>
using namespace std;



class Task
{
int r,p,q,s;

public:
//Task(int R,int P,int Q,int S):r(R),p(P),q(Q),s(S) {}
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

int seq_time(vector<Task> v)
{
    int x=0;
    int c=0;
    for(int i=0;i<static_cast<int>(v.size());i++)
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
//        if(t1._r() == t2._r())
//        {
//            if(t1._s() < t2._s())
//                return true;
//            if(t1._s() > t2._s())
//                return false;
//        }


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
//        if(t1._q() == t2._q())
//        {
//            if(t1._s() < t2._s())
//                return true;
//            if(t1._s() > t2._s())
//                return false;
//        }
        return false;
    }
};

void Schrage(vector<Task> tasks, int n)
{
    int t = 0; int Cmax= 0; Task e;
    vector<Task> pi;
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
        G.pop();
        t=t+e._p();
        pi.push_back(e);
//        t+=e._p();
//        Cmax=max(Cmax,t+e._q());
        t=max(e._r(),t)+e._p();
        Cmax=max(Cmax,(t+e._q()));





    }
    int x=0;
    int c=0;
    for(int i=0;i<n;i++)
    {
        x=max(pi[i]._r(),x)+pi[i]._p();
        c=max(c,(x+pi[i]._q()));
    }
////    cout<< "kolejność:" << endl;
////    for(unsigned int i=0;i<tasks.size();i++)
////        cout << pi[i]._s()+1 << " ";
////    cout << endl;
    cout << "cmax szragowy:"<< c << endl;


}

int prmtS(vector<Task> tasks)
{
    int t = 0; int Cmax= 0; Task e; int l=0;
    priority_queue<Task, vector<Task>, TaskCompareClassG> G;
    priority_queue<Task, vector<Task>, TaskCompareClassN> N;
    for(unsigned int i=0;i<tasks.size();i++)
        N.push(tasks[i]);
    while(!G.empty() || !N.empty())
    {
        while(!N.empty() && N.top()._r() <= t)
        {
            e=N.top();
            G.push(e);
            N.pop();
            if(e._q()>tasks[l]._q())
                tasks[l]._p()=t-e._r();
            if(tasks[l]._p()>0)
                G.push(tasks[l]);
        }
        if(G.empty())
        {
            t=N.top()._r();
            continue;
        }
        e=G.top();
        G.pop();
        l=e._s();
        t+=e._p();
        Cmax=max(Cmax,t+e._q());
    }
    return Cmax;

}

int main()
{

    fstream file("/home/dominik/RPQ_spd1/dane.txt");
    string header;
    regex ptt("data.*");
    //file >> header;
    int n;

    vector <Task> tasks;
    Task tmp;
    vector <Task> ts;


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
        cout << n << endl;
        for(int i=0;i<n;i++)
        {
            file >> tmp._r() >> tmp._p() >> tmp._q();
            tmp._s()=i;
            tasks.push_back(tmp);
        }
        cout << endl << "kolejność pre:" << endl;
//        for(int i=0;i<n;i++)
//            cout << tasks[i]._s()+1 << " ";
        cout << endl;
        Schrage(tasks, n);
       // cout << "Schrage cmax:" << seq_time(ts) << endl;
//        cout << "prmtS:" << prmtS(tasks) << endl;
//            for(int i=0;i<n;i++)
//                cout << tasks[i]._r() << " " << tasks[i]._p() << " " << tasks[i]._q() << endl;
            cout << endl << "kolejność:" << endl;
//            for(int i=0;i<n;i++)
//                cout << ts[i]._s()+1 << " ";

        cout << endl;


    }






////    for(int i=0;i<n;i++)
////        cout << tasks[i]._r() << " " << tasks[i]._p() << " " << tasks[i]._q() << endl;

////    sort(tasks.begin(),tasks.end(),compare);
//    int t1 = seq_time(tasks);
////    sort(tasks.begin(),tasks.end(),compare_maxq);
//    int t2 = seq_time(tasks);
////    if(t2>t1)
////        sort(tasks.begin(),tasks.end(),compare);
////    Call+=seq_time(tasks);
////    cout << endl;

////    cout << "after sort:"<< endl;
////    for(int i=0;i<n;i++)
////        cout << tasks[i]._r() << " " << tasks[i]._p() << " " << tasks[i]._q() << endl;

////    cout << endl << "kolejność:" << endl;
////    for(int i=0;i<n;i++)
////        cout << tasks[i]._s()+1 << " ";

//    cout << endl;
//    vector <Task> t = Schrage(tasks);
//   // cout << "Cmax:"<<seq_time(tasks) << endl;
//    cout << "Schrage cmax:" << seq_time(Schrage(tasks)) << endl;
////        for(int i=0;i<n;i++)
////            cout << t[i]._r() << " " << t[i]._p() << " " << t[i]._q() << endl;
//        cout << endl << "kolejność:" << endl;
//        for(int i=0;i<n;i++)
//            cout << t[i]._s()+1 << " ";
//   // file >> header;
//    while(1)
//    {
//        file >> header;
//        if (regex_match(header,ptt))
//            break;
//    }
//    file >> n;
//    cout << header << endl;
//    cout << n << endl;
//    tasks.clear();
//    for(int i=0;i<n;i++)
//    {
//        file >> tmp._r() >> tmp._p() >> tmp._q();
//        tmp._s()=i;
//        tasks.push_back(tmp);
//    }
////    for(int i=0;i<n;i++)
////        cout << tasks[i]._r() << " " << tasks[i]._p() << " " << tasks[i]._q() << endl;

////    sort(tasks.begin(),tasks.end(),compare);
////    t1 = seq_time(tasks);
////    sort(tasks.begin(),tasks.end(),compare_maxq);
////    t2 = seq_time(tasks);
////    if(t2>t1)
////        sort(tasks.begin(),tasks.end(),compare);
////    Call+=seq_time(tasks);
////    cout << endl;
////    cout << "after sort:"<< endl;
////    for(int i=0;i<n;i++)
////        cout << tasks[i]._r() << " " << tasks[i]._p() << " " << tasks[i]._q() << endl;

////    cout << endl << "kolejność:" << endl;
////    for(int i=0;i<n;i++)
////        cout << tasks[i]._s()+1 << " ";
////    cout << endl;
////    cout << "Cmax:"<<seq_time(tasks) << endl;
//    cout << "Schrage cmax:" << seq_time(Schrage(tasks)) << endl;
//    file >> header;
//    file >> n;
//    cout << header << endl;
//    cout << n << endl;
//    tasks.clear();
//    for(int i=0;i<n;i++)
//    {
//        file >> tmp._r() >> tmp._p() >> tmp._q();
//        tmp._s()=i;
//        tasks.push_back(tmp);
//    }
//    for(int i=0;i<n;i++)
//        cout << tasks[i]._r() << " " << tasks[i]._p() << " " << tasks[i]._q() << endl;

//    sort(tasks.begin(),tasks.end(),compare);
//    t1 = seq_time(tasks);
//    sort(tasks.begin(),tasks.end(),compare_maxq);
//    t2 = seq_time(tasks);
//    if(t2>t1)
//        sort(tasks.begin(),tasks.end(),compare);
//    Call+=seq_time(tasks);
//    cout << endl;
//    cout << "after sort:"<< endl;
//    for(int i=0;i<n;i++)
//        cout << tasks[i]._r() << " " << tasks[i]._p() << " " << tasks[i]._q() << endl;

//    cout << endl << "kolejność:" << endl;
//    for(int i=0;i<n;i++)
//        cout << tasks[i]._s()+1 << " ";
//    cout << endl;
//    cout << "Cmax:"<<seq_time(tasks) << endl;
//    file >> header;
//    file >> n;
//    cout << header << endl;
//    cout << n << endl;
//    tasks.clear();
//    for(int i=0;i<n;i++)
//    {
//        file >> tmp._r() >> tmp._p() >> tmp._q();
//        tmp._s()=i;
//        tasks.push_back(tmp);
//    }
//    for(int i=0;i<n;i++)
//        cout << tasks[i]._r() << " " << tasks[i]._p() << " " << tasks[i]._q() << endl;

//    sort(tasks.begin(),tasks.end(),compare);
//    t1 = seq_time(tasks);
//    sort(tasks.begin(),tasks.end(),compare_maxq);
//    t2 = seq_time(tasks);
//    if(t2>t1)
//        sort(tasks.begin(),tasks.end(),compare);
//    Call+=seq_time(tasks);
//    cout << endl;
//    cout << "after sort:"<< endl;
//    for(int i=0;i<n;i++)
//        cout << tasks[i]._r() << " " << tasks[i]._p() << " " << tasks[i]._q() << endl;

//    cout << endl << "kolejność:" << endl;
//    for(int i=0;i<n;i++)
//        cout << tasks[i]._s()+1 << " ";
//    cout << endl;
//    cout << "Cmax:"<<seq_time(tasks) << endl;
//    cout << "Summary Cmax:" << Call << endl;
    file.close();
    return 0;
}

