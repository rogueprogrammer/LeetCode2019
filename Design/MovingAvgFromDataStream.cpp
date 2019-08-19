//https://leetcode.com/problems/moving-average-from-data-stream/

/*
Runtime: 28 ms, faster than 94.73% of C++ online submissions for Moving Average from Data Stream.
Memory Usage: 15.3 MB, less than 100.00% of C++ online submissions for Moving Average from Data Stream.
*/
class MovingAverage {
public:
    int sizeMA;
    queue<int> q;
    double sum;
    
    MovingAverage(int size) {
        sizeMA = size;
        sum = 0;
    }
    
    double next(int val) {
        q.push(val);
        if(q.size() > sizeMA){
            int f = q.front();
            q.pop();
            sum += val;
            sum -= f;
            return (sum/q.size());
        } else{
            sum += val;
            return (sum/q.size());
        }
    }
};
