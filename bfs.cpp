#include <iostream>
#include <queue>
using namespace std;
int graph[4][4] = 
{   {0, 1, 1, 0},
    {0, 0, 1, 0},
    {1, 0, 0, 1},
    {0, 0, 0, 1}
}; 
void bfs(int n)
{
    int u;
    queue<int> explore;
    int visited[4];
    cout<<n;
    explore.push(n);
    visited[n]=1;
    while(!explore.empty()){
        u=explore.front();
        explore.pop();
        for(int v=0;v<4;v++){
            if(graph[u][v]==1 && visited[v]!=1)
            {
                cout<<" "<<v;
                explore.push(v);
                visited[v]=1;
            }
        }
    }
}
int main()
{
    bfs(1);
    return 0;
}
