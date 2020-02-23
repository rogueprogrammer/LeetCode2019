class Solution {
public:
     // https://leetcode.com/problems/merge-intervals/submissions/
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // [ [1, 3], [2, 6], [3, 9], [8, 10], [15, 18] ]
        //   [1, 6], [8, 10], [15, 18]
        vector<vector<int>> res;
        if(intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end(),[](vector<int> a, vector<int> b){return a[0] < b[0];});
        res.push_back(intervals[0]);
        int prev = 0;
        for(int i = 0; i < intervals.size(); ++i){
            vector<int> interval = intervals[i];
            if(interval[0] <= res[prev][1]){
                res[prev][1] = max(res[prev][1], interval[1]);
            }else{
                res.push_back(interval);
                ++prev;
            }
        }
        return res;
    }
};
