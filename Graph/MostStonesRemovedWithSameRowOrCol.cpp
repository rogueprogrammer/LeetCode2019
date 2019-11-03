//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column
//passed 62/68 test cases, gets a TLE on test case with extremely large number of input values.
// no need for union find, just a standard BFS or DFS to find the number of connected components in the graph
//Compute: number of moves = number of stones - number of connected components
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
              
        //Step 1 - Build graph
        //map< pair<int, int>, vector< <pair<int, int>>>> adj;
        map<int, vector<vector<int>> > rows;
        map<int, vector<vector<int> >> cols;
        for(int i = 0; i < stones.size(); ++i){
            vector<int> stone = stones[i];
            int row = stone[0];
            int col = stone[1];
            rows[row].push_back(stone);
            cols[col].push_back(stone);
        }
        
        //Step 2 - Compute number of components using BFS
        int numComponents = 0;
        queue<vector<int>> q;
        set<vector<int>> visited;
        while(visited.size() != stones.size() ){
            ++numComponents;
            //find first stone that is not already visited and add it to the queue
            for(int i = 0; i < stones.size(); ++i){
                vector<int> stone = stones[i];
                auto it = visited.find(stone);
                if(it == visited.end()){
                    q.push(stone);
                    break;
                }
            }
            
            while(!q.empty()){
                vector<int> curStone = q.front();
                visited.insert(curStone);
                //vector<vector<int>> neighbors = adj[curStone];
                vector<vector<int>> neighbors;
                int row = curStone[0];
                int col = curStone[1];
                vector<vector<int>> allStonesInSameRow = rows[row];
                vector<vector<int>> allStonesInSameCol = cols[col];
                for(vector<int> r : allStonesInSameRow){
                    neighbors.push_back(r);
                }
                for(vector<int> c : allStonesInSameCol){
                    neighbors.push_back(c);
                }
                
                for(vector<int> n : neighbors){
                    auto it = visited.find(n);
                    if(it == visited.end()){
                        q.push(n);
                    }
                }
                q.pop();
            }
        }
        return stones.size() - numComponents;
    }
};
