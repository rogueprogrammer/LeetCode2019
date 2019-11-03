
//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column
//passed 54/68 test cases, gets a TLE on test case with extremely large number of input values.
// no need for union find, just a standard BFS or DFS to find the number of connected components in the graph
int removeStones(vector<vector<int>>& stones) {
        //number of moves = number of stones - number of connected components
              
        //Step 1 - Build graph
        //map< pair<int, int>, vector< <pair<int, int>>>> adj;
        map<vector<int>, vector<vector<int>>> adj;
        for(int i = 0; i < stones.size(); ++i){
            vector<int> curStone = stones[i];
            //find all other stones that share same row or col
            for(int j = 0; j < stones.size(); ++j){
                if(i == j) continue;
                vector<int> otherStone = stones[j];
                if(otherStone[0] == curStone[0] || otherStone[1] == curStone[1]){
                    adj[curStone].push_back(otherStone);
                }
            }
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
                vector<vector<int>> neighbors = adj[curStone];
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
