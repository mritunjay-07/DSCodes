#include <iostream>
using namespace std;
int graph[6][6] =
    {{0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0},
     {0, 0, 0, 1, 0, 0},
     {0, 1, 0, 0, 0, 0},
     {1, 1, 0, 0, 0, 0},
     {1, 0, 1, 0, 0, 0}};
int visited[6];
void dfs(int n)
{
    int u = n;
    if (visited[u] != 1)
    {
        cout << u;
        visited[u] = 1;
        for (int v = 0; v < 6; v++)
        {
            if (graph[u][v] == 1 && visited[v] != 1)
            {
                dfs(v);
            }
        }
    }
}
int main()
{
    dfs(0);
    return 0;
}
