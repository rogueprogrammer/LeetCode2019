//https://leetcode.com/problems/moving-average-from-data-stream/submissions/
class MovingAverage {
public:
    int sizeMA;
    queue<int> q;
    double sum;
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sizeMA = size;
        sum = 0;
    }
    
    double next(int val) {
        
        q.push(val);
        //cout << "Q SIZE: " << q.size() << endl;
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
