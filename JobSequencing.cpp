#include<bits/stdc++.h>
using namespace std;
struct Job
{
    char id;
    int dead;
    int profit; 
};
bool Cmp(Job A,Job B)
{
    return(A.profit>B.profit);
}
void JobScheduling(Job A[],int n)
{
    sort(A,A+n,Cmp);
    int maxdead=0;
    for(int i=0;i<n;i++)
    {
        if(A[i].dead>maxdead)
        {
            maxdead=A[i].dead;
        }
    }
    int Slots=min(maxdead,n)+1;
    int Sequence[Slots];
    for(int i=0;i<Slots;i++)
    {
    Sequence[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=min(n,A[i].dead);j>0;j--)
        {
            if(Sequence[j]==-1)
            {
            Sequence[j]=i;
            break;
            }
        }
    }
    int P=0;
    cout<<"Sequence of Jobs:\t";
    for(int i=0;i<Slots;i++)
    {
        if(Sequence[i]!=-1)
        {
        cout<<A[Sequence[i]].id<<" ";
        P+=A[Sequence[i]].profit;
        }
    }
    cout<<"\nMaximum Profit:\t\t"<<P<<endl;
}
int main()
{
    Job arr[] = { { 'a', 2, 100 },
                { 'b', 1, 19 },
                { 'c', 2, 27 },
                { 'd', 1, 25 },
                { 'e', 3, 15 } };
    int n=sizeof(arr)/sizeof(arr[0]);
    JobScheduling(arr,n);
    return 0;
}