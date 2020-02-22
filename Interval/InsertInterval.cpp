//https://leetcode.com/problems/insert-interval/submissions/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
   vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> left, right;
    for (int i = 0; i < intervals.size(); i++) {
        if (intervals[i].end < newInterval.start) {
            left.push_back(intervals[i]);
        }
        if (intervals[i].start > newInterval.end) {
            right.push_back(intervals[i]);
        }
    }
    int s = newInterval.start, e = newInterval.end;
    if ((left.size()+right.size()) != intervals.size()) {
        s = min(s, intervals[left.size()].start);
        e = max(e, intervals[intervals.size()-right.size()-1].end);
    }
    Interval middle(s,e);
    left.push_back(middle);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}
};
