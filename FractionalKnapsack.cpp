#include<bits/stdc++.h>
using namespace std;
struct Bag
{
    int id;
    double cost;
    double weight;
    double ratio;
};
bool Cmp(Bag A,Bag B)
{
    return (A.ratio>B.ratio);
}
int main()
{
    int n;
    cout<<"Enter the number of items:\t";
    cin>>n;
    Bag B[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Cost and Weight of Item"<<i+1<<"\nCost\t";
        cin>>B[i].cost;
        cout<<"Weight\t";
        cin>>B[i].weight;
        B[i].id=i+1;
        B[i].ratio=B[i].cost/B[i].weight;
    }
    sort(B,B+n,Cmp);
    int x=0;
    double W;
    double cost=0;
    cout<<"Enter the capacity of bag\t";
    cin>>W;
    cout<<"Items that should be carried are:\n";
    while(W>0&&x<n)
    {
        if(B[x].weight>W)
        {
        cout<<"Item "<<B[x].id<<"\tWeight\t"<<W<<" Kg\n";
        cost=cost+W*B[x].ratio;
        W=0;
        }
        else
        {
            cout<<"Item "<<B[x].id<<"\tWeight\t"<<B[x].weight<<" Kg\n";
            W=W-B[x].weight;
            cost+=B[x].cost;
            x++;
        }
    }
    cout<<"\nTotal profit earned\t"<<cost<<endl;
    return 0;
}