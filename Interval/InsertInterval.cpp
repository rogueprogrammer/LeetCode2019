//https://leetcode.com/problems/insert-interval/submissions/

class Solution {
public:
     
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int> newInterval) {
    /*
            intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
            left = [1, 2]
            right = [12, 16]
            mergedInterval = [min(interval[0], newInterval[0]),
                              max(interval[1], newInterval[1])]
    */
    vector<vector<int>> res;
    if (intervals.size() == 0) {
        res.push_back(newInterval); return res;
    }
    vector<vector<int>> left; vector<vector<int>> right;
    for (int i = 0; i < intervals.size(); ++i) {
        vector<int> cur = intervals[i];
        if (cur[1] < newInterval[0]) {
            left.push_back(cur);
            res.push_back(cur);
        }
        else if (cur[0] > newInterval[1]) {
            right.push_back(cur);
        }
    }
    int s; int e;
    if (left.size() + right.size() == intervals.size()) {
        res.push_back(newInterval);
        for (int i = 0; i < right.size(); ++i) {
            res.push_back(right[i]);
        }
        return res;
    }
    vector<int> afterLeft = intervals[left.size()];
    vector<int> beforeRight = intervals[intervals.size() - right.size()-1];
    s = min(afterLeft[0], newInterval[0]);
    e = max(beforeRight[1], newInterval[1]);
    vector<int> mergedInterval = { s, e };
    res.push_back(mergedInterval);
    for (int i = 0; i < right.size(); ++i) {
        res.push_back(right[i]);
    }
    
    return res;
}
    
    
};
