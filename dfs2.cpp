#include <iostream>
#include <stack>
using namespace std;

int all_visited(int arr[], int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] == 0)
            return i;
    }
    return -1;
}

static int visited[6] = {0};

void DFS(int arr[][6], int start)
{ 
    cout << start << " ";
    visited[start] = 1;
    for (int j = 0; j < 6; j++)
    {
        if (arr[start][j] == 1 && visited[j] == 0)
        {
            DFS(arr, j);
        }
    }
    return;
}

int main()
{
    int A[6][6] = {{0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 0, 0},
                   {1, 1, 0, 0, 0, 0},
                   {1, 0, 1, 0, 0, 0}};
    DFS(A, 0);
    while(all_visited(visited, 6) != -1)
        DFS(A, all_visited(visited, 6));
    return 0;
}