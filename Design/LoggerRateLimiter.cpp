//https://leetcode.com/problems/logger-rate-limiter/
/*
Runtime: 100 ms, faster than 38.23% of C++ online submissions for Logger Rate Limiter.
Memory Usage: 32.7 MB, less than 100.00% of C++ online submissions for Logger Rate Limiter.
*/

class Logger {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> ht;
    Logger() {}
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        auto it = ht.find(message);
        if(it == ht.end()){ //not in ht
            ht[message] = timestamp;
            return true;
        } else{
            int oldTimeStamp = ht[message];
            if(abs(timestamp - oldTimeStamp) >= 10){
                ht[message] = timestamp;
                return true;
            }
            return false;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
