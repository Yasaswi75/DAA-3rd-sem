#include <iostream>
#include <vector>
using namespace std;

bool DFS(int node, int parent, vector<vector<int> > &graph,
         vector<bool> &visited)
{
    visited[node] = true;

    for (int i = 0; i < graph[node].size(); i++)
    {
        int next = graph[node][i];

        if (!visited[next])
        {
            if (DFS(next, node, graph, visited))
                return true;
        }
        else if (next != parent)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int vertices = 4;

    vector<vector<int> > graph(vertices);

    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    graph[3].push_back(0);
    graph[0].push_back(3);

    vector<bool> visited(vertices, false);

    if (DFS(0, -1, graph, visited))
        cout << "Cycle exists in the graph";
    else
        cout << "No cycle exists in the graph";

    return 0;
}
