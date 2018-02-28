#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;


// klasa implementująca model zadania maszynowego , s - nr w kolejce
class Task
{
int r,p,q,s;

public:
Task(int R,int P,int Q,int S):r(R),p(P),q(Q),s(S) {}

int & _r() {return r;}
int & _p() {return p;}
int & _q() {return q;}
int & _s() {return s;}

};
/*  funkcja pomocnicza dla sort, sortowanie rosnąco po r*/
bool compare(Task a,Task b)
{
    if(a._r()<b._r())
        return true;
    return false;
}
/*  funkcja pomocnicza dla sort, sortowanie malejąco po q*/
bool compare_maxq(Task a,Task b)
{
    if(a._q()>b._q())
        return true;
    return false;
}
/*  Liczenie Cmax  */
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
    fstream file("dane.txt");
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
    cout << endl << "kolejność:" << endl;
    for(int i=0;i<n;i++)
        cout << tasks[i]._s()+1 << " ";

    cout << endl;
    cout << "Cmax:"<<seq_time(tasks) << endl;

    //druga sekwencja danych
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
    cout << endl << "kolejność:" << endl;
    for(int i=0;i<n;i++)
        cout << tasks[i]._s()+1 << " ";
    cout << endl;
    cout << "Cmax:"<<seq_time(tasks) << endl;
    //3 sekwencja danych
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

    cout << endl << "kolejność:" << endl;
    for(int i=0;i<n;i++)
        cout << tasks[i]._s()+1 << " ";
    cout << endl;
    cout << "Cmax:"<<seq_time(tasks) << endl;
    //4 seria danych
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

    cout << endl << "kolejność:" << endl;
    for(int i=0;i<n;i++)
        cout << tasks[i]._s()+1 << " ";
    cout << endl;
    cout << "Cmax:"<<seq_time(tasks) << endl;
    cout << "Summary Cmax:" << Call << endl;
    file.close();
    return 0;
}

