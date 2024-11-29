#include <iostream>
#include <forward_list>
#include <vector>
#include <array>

class Graph {
  public:
    int nodes;
    int vertices;
    std::vector<int> *graph = nullptr;

    Graph(int size) {
      nodes = size;
      vertices = 0;
      graph = new std::vector<int>[size];   
    }

    void addEdge(int a, int b) {
      graph[a].push_back(b);
      graph[b].push_back(a);
      vertices++;
    }

    int dfs() {
      bool visited[nodes] = {};
      int paths[nodes] = {};
      int count = 0;

      for (int i = 0; i < nodes; i++) {
        if (!visited[i]) {
          dfs(i, count, visited, paths);
          count++;
        }
      }
   
      for (int i = 0; i < nodes; i++) {
        std::cout << "Node [" << i << "]: path " << paths[i] << std::endl;
      }
   
      return count;
    }

    void dfs(int node, int count, bool visited[], int paths[]) {
      visited[node] = true;
      paths[node] = count;

      for (int num : graph[node]) {
        if (!visited[num]) {
          dfs(num, count, visited, paths);
        }
      }
    }
};

int main() {
  Graph graph(6);
  graph.addEdge(0, 1);
  graph.addEdge(0, 3);
  graph.addEdge(2, 4);
  int count = graph.dfs();
  
  std::cout << "Number of paths: " << count << std::endl;

  return 0;
}