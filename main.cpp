#include <iostream>
#include <fstream>
//#include <algorithm>
#include <vector>
#include <queue>
#include <regex>
using namespace std;



struct Task
{
    int r, p, q, s;
};

bool compare(Task a,Task b)
{
    if(a.r<b.r)
        return true;
    return false;
}
bool compare_maxq(Task a,Task b)
{
    if(a.q>b.q)
        return true;
    return false;
}

int seq_time(vector<Task> v)
{
    int x=0;
    int c=0;
    for(int i=0;i<static_cast<int>(v.size());i++)
    {
        x=max(v[i].r,x)+v[i].p;
        c=max(c,(x+v[i].q));
    }
    return c;

}



class TaskCompareClassN
{
public:
    bool operator()(const Task &t1, const Task &t2)
    {
        if(t1.r > t2.r)
            return true;
        else
            if(t1.r == t2.r)
                if(t1.s > t2.s)
                    return true;
            else
                    return false;
            return false;
    }
};

class TaskCompareClassG
{
public:
    bool operator()(const Task &t1, const Task &t2)
    {
        if(t1.q < t2.q)
            return true;
        else
            if(t1.q == t2.q)
                if(t1.s > t2.s)
                    return true;
            else
                    return false;
            return false;
    }
};

void Schrage(vector<Task> tasks, int n)
{
    int t = 0; int Cmax= 0;int k=0; Task e;
    Task pi[10000];
    priority_queue<Task, vector<Task>, TaskCompareClassG> G;
    priority_queue<Task, vector<Task>, TaskCompareClassN> N;
    for(unsigned int i=0;i<tasks.size();i++)
        N.push(tasks[i]);
    while(!G.empty() || !N.empty())
    {
        while(!N.empty() && N.top().r <= t)
        {
            e=N.top();
            G.push(N.top());
            N.pop();
            if(G.empty())
            {
                t=N.top().r;
                continue;
            }
        }


        e=G.top();
        G.pop();
        t=t+e.p;
        pi[k]=e;
        k++;

        t=max(e.r,t)+e.p;
        Cmax=max(Cmax,(t+e.q));






    }
    int x=0;
    int c=0;
    for(int i=0;i<n;i++)
    {
        x=max(pi[i].r,x)+pi[i].p;
        c=max(c,(x+pi[i].q));
    }

    cout << "cmax szragowy:"<< c << endl;
    cout << endl << "kolejność:" << endl;
    cout << n << endl;
    for(int i=0;i<n;i++)
        cout << pi[i].s+1 << " ";

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
        while(!N.empty() && N.top().r <= t)
        {
            e=N.top();
            G.push(e);
            N.pop();
            if(e.q>tasks[l].q)
                tasks[l].p=t-e.r;
            if(tasks[l].p>0)
                G.push(tasks[l]);
        }
        if(G.empty())
        {
            t=N.top().r;
            continue;
        }
        e=G.top();
        G.pop();
        l=e.p;
        t+=e.p;
        Cmax=max(Cmax,t+e.q);
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
            file >> tmp.r >> tmp.p >> tmp.q;
            tmp.s=i;
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
            cout << n << endl;
            for(int i=0;i<n;i++)
                cout << ts[i].s+1 << " ";

        cout << endl;


    }







    file.close();
    return 0;
}

