#include <iostream>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
  public:
      Graph(int V);
      void addEdge(int from, int to);
      void bfs(int source); // BFS using queue
      void dfs_stack(int source); // DFS using stack
      void dfs_recursive(int source); // DFS using recursion
      void dfs_recursive_aux(bool * visited, int node); // helper function for dfs_recursive
  private:
      int V;
      list<int> * adjList;
};

Graph::Graph (int v)
{
    V = v;
    adjList = new list<int>[V];
}

void Graph::addEdge (int from, int to)
{
    adjList[from].push_back(to);
}

// BREADTH FIRST SEARCH - using queue
void Graph::bfs(int source)
{
    bool * visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[V] = false;

    // list structure being used as queue here
    list<int> q;

    visited[source] = true;
    q.push_back(source);

    while (!q.empty()) {
        int f = q.front();
        cout << f << " ";
        q.pop_front();

        for (list<int>::iterator it = adjList[f].begin(); it != adjList[f].end(); it++)
        {
            if (! visited[*it])
            {
                visited[*it] = true;
                q.push_back(*it);
            }
        }
    }
}

//DEPTH FIRST SEARCH - using stack
void Graph::dfs_stack(int source)
{
    bool * visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    stack<int> _stack;

    _stack.push(source);

    while (! _stack.empty())
    {
        int f = _stack.top();
        cout << f << " ";
        _stack.pop();

        visited[f] = true;

        for (list<int>::iterator it = adjList[f].begin(); it != adjList[f].end(); it++)
        {
            if (! visited[*it])
                _stack.push(*it);
        }
    }
}

void Graph::dfs_recursive(int source)
{
    bool * visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    dfs_recursive_aux(visited, source);
}

void Graph::dfs_recursive_aux(bool * visited, int node)
{
    cout << node << " ";

    visited[node] = true;

    for (list<int>::iterator it = adjList[node].begin(); it != adjList[node].end(); it++)
    {
        if (! visited[*it])
            dfs_recursive_aux(visited, *it);
    }
}

int main()
{

    Graph graph(4);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,2);
    graph.addEdge(2,0);
    graph.addEdge(2,3);
    graph.addEdge(3,3);

    graph.bfs(2);

    cout << endl;

    graph.dfs_stack(2);

    cout << endl;

    graph.dfs_recursive(2);

    return 0;
}
