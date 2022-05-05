#include<iostream>
using namespace std;

int main()
{
    int start[]  =  {1, 3, 0, 5, 8, 5};
    int finish[] =  {2, 4, 6, 7, 9, 9};
    int n=(sizeof(start))/sizeof(int) ,count=1;
    cout<<"\nSequence of Activities:\t";
    cout<<"0 ";
    int j=0;
    for(int i=1;i<n;i++)
    {
        if(start[i]>=finish[j])
        {
            cout<<i<<" ";
            j=i;
            count++;
        }
    }
    cout<<"\nMaximum "<<count<<" Activities can be performed\n";
    return 0;
}