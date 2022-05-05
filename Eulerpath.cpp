#include<bits/stdc++.h>
using namespace std;
class Graph
{
    map< int,list<int> > G;
    int Vertices;
    public:
    Graph(int V)
    {
        Vertices=V;
    }
    void AddEdge(int u,int v)
    {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    void RemoveEdge(int u,int v)
    {
        list<int>::iterator iu=find(G[u].begin(),G[u].end(),v);
        *iu=-1;
        list<int>::iterator iv=find(G[v].begin(),G[v].end(),u);
        *iv=-1;        
    }
    int DFSCount(int u,map<int,bool> &Visited)
    {
        int Count=1;
        Visited[u]=true;
        list<int>::iterator i;
        for(i=G[u].begin();i!=G[u].end();++i)
        {
            if(*i!=-1&&Visited[*i]!=true)
            Count+=DFSCount(*i,Visited);
        }
        return Count;
    }
    bool IsSafe(int u,int v)
    {
        int Count=0;
        list<int>::iterator i;
        for(i=G[u].begin();i!=G[u].end();++i)
        {
            if(*i!=-1)
            Count++;
        }        
        if(Count==1)
        return true;
        map<int ,bool> Visited1;
        int Count1=DFSCount(u,Visited1);
        RemoveEdge(u,v);
        map<int ,bool> Visited2;
        int Count2=DFSCount(u,Visited2);
        AddEdge(u,v);
        if(Count1>Count2)
        return false;
        return true;
    }
    void EulerPath()
    {
        int u;
        for(int i=0;i<Vertices;i++)
        {
            if(G[i].size()!=0)
            {
            u=i;
            break;
            }
        }
        for(int i=0;i<Vertices;i++)
        {
            if(G[i].size()%2==1)
            {
                u=i;
                break;
            }
        }
        EulerPathU(u);
        cout<<endl;
    }
    void EulerPathU(int u)
    {
        list<int>::iterator i;
        for(i=G[u].begin();i!=G[u].end();++i)
        {
            int v=*i;
            if(v!=-1&&IsSafe(u,v))
            {
                cout<<u<<"->"<<v<<" ";
                RemoveEdge(u,v);
                EulerPathU(v);
            }
        }
    }
    bool IsEulerian()
    {
        map<int,bool> V;
        int OddCount=0;
        for(int i=0;i<Vertices;i++)
        {
            if(G[i].size()%2==1)
            OddCount++;
        }
        if(OddCount>2)
        {
        cout<<"Euler Path or Circuit Does Not Exist";
        return false;
        }
        int NonZeroDeg=0,x,y;
        for(int i=0;i<Vertices;i++)
        {
            if(G[i].size()!=0)
            {
            NonZeroDeg++;
            x=i;
            }
        }
        if(NonZeroDeg==DFSCount(x,V))
        {
            if(OddCount==0)
            cout<<"Euler Circuit:\t";
            else
            cout<<"Euler Path:\t";
            return true;
        }   
        cout<<"Euler Path or Circuit Does Not Exist";
        return false;
    }
};
int main()
{
    Graph G(5);
    G.AddEdge(1, 0);
    G.AddEdge(0, 2);
    G.AddEdge(2, 1);
    G.AddEdge(0, 3);
    G.AddEdge(3, 4);
    G.AddEdge(3, 2);
    G.AddEdge(3, 1);
    G.AddEdge(2, 4);
    if(G.IsEulerian())
    G.EulerPath();
    return 0;
}