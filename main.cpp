#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <regex>
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

void Schrage(vector<Task> tasks)
{
    int t = 0; int Cmax= 0;int k=0; Task e;
    Task pi[10000];
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

    cout<< "kolejność:" << endl;
    for(unsigned int i=0;i<tasks.size();i++)
        cout << pi[i]._s()+1 << " ";
    cout << endl;
    cout << "cmax szragowy:"<< Cmax << endl;


}

void prmtS(vector<Task> tasks)
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
    cout <<"Cmax szragowy z przerwaniami: "<< Cmax << endl;


}

int main()
{

    fstream file("/home/dominik/RPQ_spd1/dane.txt");
    string header;
    regex ptt("data.*");
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
        Schrage(tasks);
        prmtS(tasks);
    }
    file.close();
    return 0;
}

