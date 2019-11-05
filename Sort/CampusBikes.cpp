
//https://leetcode.com/problems/campus-bikes/submissions/
//passed all cases
//Idea: use bucket sort to sort the manhattan distances. 
    //Bucket sort is a good idea since we know any x or y is between 0 and 1000 inclusive,
    // meaning that we have an upper bound of 2000 as the manhattan distance. 
//O(mn) bucket sort (m == number of workers, n == number of bikes)
class Solution {
public:
    int manhattanDistance(int p1x, int p1y, int p2x, int p2y){
        return abs(p1x-p2x) + abs(p1y - p2y);
    }
    
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int numWorkers = workers.size();
        int numBikes = bikes.size();

        //Get distance for cartesian product of each worker to bike.
        //given that any x or y is between 0 and 1000 inclusive, manhattan distance can be 
        //max of 2000
        vector< vector <pair<int, int> > > distances(2001); //bucket of distances, each distance can 
        //have multiple worker/bike combination that share that distance
        for(int i =0 ; i < numWorkers; ++i){
            for(int j = 0; j < numBikes; ++j){
                int wx = workers[i][0];
                int wy = workers[i][1];
                int bx = bikes[j][0];
                int by = bikes[j][1];
                int distance = manhattanDistance(wx, wy, bx, by);
                distances[distance].push_back(make_pair(i, j));
            }
        }
        
        vector<int> ans(numWorkers, -1);
        vector<bool> takenBikes(bikes.size(), false);
        for(int i = 0; i < 2000; ++i){
            vector<pair<int, int>> wbpairs = distances[i];
            for(pair<int, int> p : wbpairs){
                int w = p.first;
                int b = p.second;
                if((ans[w] == -1) &&(takenBikes[b] == false)){
                    ans[w] = b;
                    takenBikes[b] = true;
                }
            }
        }
        return ans;
        
    }
};
