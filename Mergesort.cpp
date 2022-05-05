#include<bits/stdc++.h>
using namespace std;
void Merging(int A[],int low,int mid,int high)
{
    int B[10];
    int i=low;
    int j=mid+1;
    int k=low;
    while(i<=mid&&j<=high)
    {
        if(A[i]<A[j])
        {
            B[k++]=A[i++];
        }
        else 
        {
            B[k++]=A[j++];
        }
    }
    while(i<=mid)
    {
        B[k++]=A[i];
    }
    while(j<=mid)
    {
        B[k++]=A[j];
    }
    for(i=low;i<=high;i++)
    {
        A[i]=B[i];
    }
}
void mergesort(int A[],int n)
{
    int i,low,mid,high,p;
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p)
        {
            low=i;
            high=i+p-1;
            mid=(low+high)/2;
            Merging(A,low,mid,high);
        }
    }
    if(p/2<n)
    {
        Merging(A,0,p/2,n-1);
    }
}
int main()
{
    int A[]={2,5,4,3,7,8,10,9};
    int n=8;
    mergesort(A,n);
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}
