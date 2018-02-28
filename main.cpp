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

void sort(int *s, int *r, int *p, int *q, int n)
{
    int nseq[n];
    for(int i=0;i<n;i++)
        nseq[i]=i;
    int it=0;

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n-1;j++)
        {
       // if(s[j]!=n)
            if(r[s[j+1]]<=p[s[j]] && q[s[j]]<=p[s[j+1]])
            {
                int v=s[j+1];
                s[j+1]=s[j];
                s[j]=v;
               // nseq[s[i]]=it;
                it++;
            }
//        if(s[i]==0)
//            nseq
        }

    }
    int *mrx=min_element(r,r+n);
    int mr=0;
    int *mqx=min_element(q,q+n);
    int mq=0;
    for(int i=0;i<n;i++)
    {
        if(r[s[i]] == *mrx )
            mr=s[i];
        cout<<r[s[i]] << " ";
    }
    cout << endl;
//    int v=s[0];
//    s[0]=s[mr];
//    s[mr]=v;

cout << *mrx << "nr of r:"<< mr << " " << *mqx << endl;


    for(int i=0;i<n;i++)
        cout << s[i]+1 << " ";
    cout << endl;
    cout << "production time:" << seq_time(s,r,p,q,n) <<endl;
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
    sort(seq,R,P,Q,n);

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

