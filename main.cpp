#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;



class Task
{
int r,p,q,s;

public:
Task(int R,int P,int Q,int S):r(R),p(P),q(Q),s(S) {}
int & _r() {return r;}
int & _p() {return p;}
int & _q() {return q;}
int & _s() {return s;}
<<<<<<< Updated upstream
bool operator < (Task t)
{
    if(this->_p()<t._p())
        return true;
    return false;
}
=======

const int & _r() const {return r;}
const int & _p() const {return p;}
const int & _q() const {return q;}
const int & _s() const {return s;}

>>>>>>> Stashed changes
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
int main()
{
    const Task tsk(343,444,434,4);
    cout << tsk._p();
    fstream file("/home/dominik/RPQ_spd1/dane.txt");
    string header;
    file >> header;
    int n;
    file >> n;
    cout << header << endl;
    cout << n << endl;
    vector <Task> tasks;
    Task tmp(0,0,0,0);
    int Call=0;

    for(int i=0;i<n;i++)
    {
        file >> tmp._r() >> tmp._p() >> tmp._q();
        tmp._s()=i;
        tasks.push_back(tmp);
    }

    for(int i=0;i<n;i++)
        cout << tasks[i]._r() << " " << tasks[i]._p() << " " << tasks[i]._q() << endl;

    sort(tasks.begin(),tasks.end(),compare);
    int t1 = seq_time(tasks);
    sort(tasks.begin(),tasks.end(),compare_maxq);
    int t2 = seq_time(tasks);
    if(t2>t1)
        sort(tasks.begin(),tasks.end(),compare);
    Call+=seq_time(tasks);
    cout << endl;
    cout << "after sort:"<< endl;
    for(int i=0;i<n;i++)
        cout << tasks[i]._r() << " " << tasks[i]._p() << " " << tasks[i]._q() << endl;

    cout << endl << "kolejność:" << endl;
    for(int i=0;i<n;i++)
        cout << tasks[i]._s()+1 << " ";

    cout << endl;
    cout << "Cmax:"<<seq_time(tasks) << endl;
    file >> header;
    file >> n;
    cout << header << endl;
    cout << n << endl;
    tasks.clear();
    for(int i=0;i<n;i++)
    {
        file >> tmp._r() >> tmp._p() >> tmp._q();
        tmp._s()=i;
        tasks.push_back(tmp);
    }
    for(int i=0;i<n;i++)
        cout << tasks[i]._r() << " " << tasks[i]._p() << " " << tasks[i]._q() << endl;

    sort(tasks.begin(),tasks.end(),compare);
    t1 = seq_time(tasks);
    sort(tasks.begin(),tasks.end(),compare_maxq);
    t2 = seq_time(tasks);
    if(t2>t1)
        sort(tasks.begin(),tasks.end(),compare);
    Call+=seq_time(tasks);
    cout << endl;
    cout << "after sort:"<< endl;
    for(int i=0;i<n;i++)
        cout << tasks[i]._r() << " " << tasks[i]._p() << " " << tasks[i]._q() << endl;

    cout << endl << "kolejność:" << endl;
    for(int i=0;i<n;i++)
        cout << tasks[i]._s()+1 << " ";
    cout << endl;
    cout << "Cmax:"<<seq_time(tasks) << endl;
    file >> header;
    file >> n;
    cout << header << endl;
    cout << n << endl;
    tasks.clear();
    for(int i=0;i<n;i++)
    {
        file >> tmp._r() >> tmp._p() >> tmp._q();
        tmp._s()=i;
        tasks.push_back(tmp);
    }
    for(int i=0;i<n;i++)
        cout << tasks[i]._r() << " " << tasks[i]._p() << " " << tasks[i]._q() << endl;

    sort(tasks.begin(),tasks.end(),compare);
    t1 = seq_time(tasks);
    sort(tasks.begin(),tasks.end(),compare_maxq);
    t2 = seq_time(tasks);
    if(t2>t1)
        sort(tasks.begin(),tasks.end(),compare);
    Call+=seq_time(tasks);
    cout << endl;
    cout << "after sort:"<< endl;
    for(int i=0;i<n;i++)
        cout << tasks[i]._r() << " " << tasks[i]._p() << " " << tasks[i]._q() << endl;

    cout << endl << "kolejność:" << endl;
    for(int i=0;i<n;i++)
        cout << tasks[i]._s()+1 << " ";
    cout << endl;
    cout << "Cmax:"<<seq_time(tasks) << endl;
    file >> header;
    file >> n;
    cout << header << endl;
    cout << n << endl;
    tasks.clear();
    for(int i=0;i<n;i++)
    {
        file >> tmp._r() >> tmp._p() >> tmp._q();
        tmp._s()=i;
        tasks.push_back(tmp);
    }
    for(int i=0;i<n;i++)
        cout << tasks[i]._r() << " " << tasks[i]._p() << " " << tasks[i]._q() << endl;

    sort(tasks.begin(),tasks.end(),compare);
    t1 = seq_time(tasks);
    sort(tasks.begin(),tasks.end(),compare_maxq);
    t2 = seq_time(tasks);
    if(t2>t1)
        sort(tasks.begin(),tasks.end(),compare);
    Call+=seq_time(tasks);
    cout << endl;
    cout << "after sort:"<< endl;
    for(int i=0;i<n;i++)
        cout << tasks[i]._r() << " " << tasks[i]._p() << " " << tasks[i]._q() << endl;

    cout << endl << "kolejność:" << endl;
    for(int i=0;i<n;i++)
        cout << tasks[i]._s()+1 << " ";
    cout << endl;
    cout << "Cmax:"<<seq_time(tasks) << endl;
    cout << "Summary Cmax:" << Call << endl;
    file.close();
    return 0;
}

