#include<bits/stdc++.h>
using namespace std;
class Graph
{
    map< int,list<int> > G;
    map<int,bool> Visited;
    map<int,bool> Finish;
    vector<int> Sequence;
    int V;
    public:
    Graph(int V)
    {
        this->V=V;
        for (int i = 0; i < V; i++)
        {
            Finish[i]=false;
            Visited[i]=false;
        }
    }   
    void AddEdge(int u,int v)
    {
        G[u].push_back(v);
    }
    void DFS(int u)
    {
        Visited[u]=true;
        list<int>::iterator i;
        for(i=G[u].begin();i!=G[u].end();++i)
        {
            if(!Visited[*i])
            {
                DFS(*i);
            }
            else if(Visited[*i]&&!Finish[*i])
            {
                cout<<"Topological Sort not Possible..";
                exit(0);
            }
        }
        Sequence.push_back(u);
        Finish[u]=true;
    }
    void TopologicalSort()
    {
        for(int i=0;i<V;i++)
        {
            if(!Visited[i])
            DFS(i);
        }
        cout<<"Topological Sort of Graph is:\t";
        for(int i=V-1;i>=0;i--)
        {
            cout<<Sequence[i]<<" ";
        }
    }
        
};
int main()
{
    Graph g(6);
    g.AddEdge(5, 2);
    g.AddEdge(5, 0);
    g.AddEdge(4, 0);
    g.AddEdge(4, 1);
    g.AddEdge(2, 3);
    g.AddEdge(3, 1);
    g.TopologicalSort();
}