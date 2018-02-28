#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int seq_time(int *s, int *r, int *p, int *q, int n)
{
    int time=0;
    for(int i=0; i<n;i++)
    {
        if(i==0)
        {
            time+=r[s[i]];
            time+=p[s[i]];
        }
        if(i==(n-1)){
            if(q[s[i-1]]<(q[s[i]]+p[s[i]]))
                time+=q[s[i]];
            else
                time+=(q[s[i-1]]-(p[s[i]]+q[s[i]]));
            time+=p[s[i]];
        }
        else
        {
            time+=p[s[i]];


        }
     }
    return time;
}




int main()
{
    fstream file("/home/dominik/RPQ_spd1/dane.txt");
    string header;
    file >> header;
    int n;
    file >> n;
    cout << header << endl;
    cout << n << endl;
    int *R = new int[n];
    int *P = new int[n];
    int *Q = new int[n];
    int *seq = new int[n];
  //  int *nseq;
    for(int i=0;i<n;i++)
        seq[i]=i;
    for(int i=0;i<n;i++)
    {
        file >> R[i] >> P[i] >> Q[i];
    }

    file.close();
    for(int i=0;i<n;i++)
        cout << R[i] << " " << P[i] << " " << Q[i] << endl;


    cout << endl;
   // cout << "production time:" << seq_time(nseq,R,P,Q,n) <<endl;
    cout << endl;
    delete R;
    delete P;
    delete Q;
    delete seq;
   // delete nseq;
    return 0;
}

