class HitCounter {
public:
    /** Initialize your data structure here. */
    /* https://leetcode.com/problems/design-hit-counter/submissions/
    O(1) hit()  O(s) getHits()    
    let times[i] equal the timestamp:

    1, 2, 302
 
    
    let hits[i] equal the number of hits at the timestamp:
    1, 2, 1 + num elements between (302, 2)
    O(s) s is total seconds in given time interval, in this case 300.
basic ideal is using buckets. 1 bucket for every second because we only need to keep the recent hits info for 300 seconds. hit[] array is wrapped around by mod operation. Each hit bucket is associated with times[] bucket which record current time. If it is not current time, it means it is 300s or 600s... ago and need to reset to 1.
    */
    
    vector<int> hits;
    vector<int> times;
    
    HitCounter() {
        hits.resize(300);
        times.resize(300);
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int index = timestamp % 300;
        if (times[index] != timestamp) {
            times[index] = timestamp;
            hits[index] = 1;
        } else {
            hits[index]++;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int total = 0;
        for (int i = 0; i < 300; i++) {
            if (timestamp - times[i] < 300) {
                total += hits[i];
            }
        }
        return total;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
