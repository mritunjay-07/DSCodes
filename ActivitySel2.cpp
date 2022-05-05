#include<bits/stdc++.h>
using namespace std;
struct ActivitySel
{
    int id;
    int start;
    int finish;
};
bool Cmp(ActivitySel A,ActivitySel B)
{
    return(A.finish<B.finish);
}
int main()
{
    ActivitySel S[]={{3,5,7},{1,1,2},{2,3,4},{4,0,6},{5,5,9},{6,8,9}};
    int n=(sizeof(S)/sizeof(S[0]));
    sort(S,S+n,Cmp);
    int count=1;
    cout<<"\nSequence of Activities:\t";
    cout<<S[0].id<<" ";
    int j=0;
    for(int i=1;i<n;i++)
    {
        if(S[i].start>=S[j].finish)
        {
            cout<<S[i].id<<" ";
            j=i;
            count++;
        }
    }
    cout<<"\nMaximum "<<count<<" Activities can be performed\n";
    return 0;
}