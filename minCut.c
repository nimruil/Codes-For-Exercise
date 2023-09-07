// C implementation

#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;
  
// number of vertices
#define V 6
  
// if there is a path from source to destination true, else false
// keep path in array
int bfs(int rGraph[V][V], int s, int t, int parent[])
{
    //make an array of visited nodes, mark them as not visited in the beginning
    bool visited[V];
    memset(visited, 0, sizeof(visited));
  
    //make a queue, add source and mark it as visited
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
  
    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
  
        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
  
    // if we reached destination with BFS true, else false
    return (visited[t] == true);
}
  
// DFS which finds nodes that can be reached from source, alternative to BFS
void dfs(int rGraph[V][V], int s, bool visited[])
{
    visited[s] = true;
    for (int i = 0; i < V; i++)
       if (rGraph[s][i] && !visited[i])
           dfs(rGraph, i, visited);
}
  
// minimum cut ciktisi
void minCut(int graph[V][V], int s, int t)
{
    int u, v;
  
    int rGraph[V][V]; 
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];
  
    int parent[V];
    int max_flow = 0;
    while (bfs(rGraph, s, t, parent))
    {
	// maximum flow in the current path
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
            max_flow += path_flow;
        // capacity revisions
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
    }
  
    bool visited[V];
    memset(visited, false, sizeof(visited));
    dfs(rGraph, s, visited);
    cout << "Max flow = " << max_flow <<endl;
    int cut_counter = 1;
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++)
         if (visited[i] && !visited[j] && graph[i][j])
         {
             cout << cut_counter << ". cut = ";
             cout << i+1 << " - " << j+1 << endl;
             cut_counter++;
         }
    return;
}
  
int main()
{
    int graph[V][V] = { {0, 7, 6, 0, 0, 0},
                        {0, 0, 1, 4, 0, 0},
                        {0, 5, 0, 2, 9, 0},
                        {0, 0, 0, 0, 6, 10},
                        {0, 0, 0, 0, 0, 17},
                        {0, 0, 0, 0, 0, 0}
                      };
  
    minCut(graph, 0, 5);
  
    return 0;
}
