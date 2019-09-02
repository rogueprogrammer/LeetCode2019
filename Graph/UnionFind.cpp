#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
Minimum Spanning Tree - Given a connected undirected graph, the
spanning tree is a subgraph that connects all the
vertices together. Thus the MST is the subgraph that connects all the
vertices with the minimum edge weight.
Kruskal's Algorithm (Greedy):
1. Sort all the edges in increasing order of their weight
2. Pick the smallest edge. Check if it forms a cycle with the spanning
tree formed so far.
   If cycle is not formed, include this edge. Else, discard it.
3. Repeat step 2 until there are (v-1) edges in the spanning tree.

CYCLE DETECTION - Union Find Algorithm
for each unvisited edge (u,v) in edge set E
{
  if(Find(u) == Find(v)){
        //cycle detected
  }
  else{
    Union(x,y); // x and y are the sets that u and v belong to
  }
}
*/

vector<int> parent;

//recursively find the parent of x
int _find(int x){
        if (parent[x] == x){
                return x;
        }
        return _find(parent[x]);
}

//Combine x and y into one set making the parent of (parent of x)
equal to the parent of y
void _union(int x, int y){
        int px = _find(x);
        int py = _find(y);
        if (px == py){ //both belonging to same set => cycle found
                cout << "cycle found with " << x << " and " <<  y << endl;
        }
        else{
                parent[px] = py;
        }
}

int main() {

        /*
        0
        |     \
        1     2
  /  |
3 -- 4
        */
        //initialize parents
        int N = 5;
        parent = vector<int>(5);
        for (int i = 0; i < parent.size(); ++i){
                parent[i] = i;
        }
        vector<pair<int, int>> edges = {
                        {0, 1},
                        {0, 2},
                        {1, 3},
                        {1, 4},
                        {3, 4}
        };
        for (pair<int, int> edge : edges){
                _union(edge.first, edge.second); //cycle at 3,4
        }
        system("PAUSE");

}
