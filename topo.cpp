#include <bits/stdc++.h>
using namespace std;
int graph[6][6] =
    {{0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0},
     {0, 0, 0, 1, 0, 0},
     {0, 1, 0, 0, 0, 0},
     {1, 1, 0, 0, 0, 0},
     {1, 0, 1, 0, 0, 0}};
void topological()
{
    int s;
    int visited[6] = {0};
    int indegree[6] = {0};
    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            indegree[j] = indegree[j] + graph[i][j];
        }
    }
    for (int j = 0; j < 6; j++)
    {
        cout << indegree[j] << " ";
    }
    cout << "\n";
    int count = 0;
    while (count != 6)
    {
        for (int j = 0; j < 6; j++)
        {
            if (indegree[j] == 0 && visited[j] == 0)
            {
                s = j;
                cout << s << " ";
                indegree[j]--;
                visited[j]++;
                count++;
                for (int i = 0; i < 6; i++)
                {
                    if (graph[j][i] == 1)
                    {
                        indegree[i]--;
                    }
                }
            }
        }
    }
}
int main()
{
    topological();
    return 0;
}
