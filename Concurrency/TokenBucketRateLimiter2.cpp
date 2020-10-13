#include "Header.h"
#include <time.h>
#include <mutex>


// aspects of concurrency to consider? 
// can critical section be smaller?
// aspects of scalable systems to consider?
class TokenBucket {
public:
    double lastRefilledTimestamp;
    int numTokensCurrentlyInBucket;
    int refreshRate; // number of tokens added to bucket per second
    int maxCapacity; // max number of tokens that can be in bucket
    time_t t;
    mutex m;
    condition_variable cv;

    // tokens = # of tokens currently in bucket
    // refreshRate = new tokens added at this rate (tokens/sec)
    // capacity = max capacity of tokens a bucket can hold
    TokenBucket(int tokens, int refreshRate, int capacity) {

        this->lastRefilledTimestamp = time(&t);
        this->maxCapacity = capacity;
        this->numTokensCurrentlyInBucket = tokens;
        this->refreshRate = refreshRate;
        // second implementation - create a background thread which constantly calls refill each second 
        // and get would only wait while there's not enough

    }

    void get(int amount) {
        double amountTokensToAdd = refill(); //this line can be removed in second implementation

        unique_lock<mutex> lk(m);
        while (amountTokensToAdd < amount) {
            cv.wait(lk);
        }
        
        this->numTokensCurrentlyInBucket += amountTokensToAdd;
        lastRefilledTimestamp = time(&t);

        if (numTokensCurrentlyInBucket > amount) {
            numTokensCurrentlyInBucket -= amount;
        }
        lk.unlock();
    }

    // returns the amount of tokens to refill
    double refill() {
        unique_lock<mutex> lk(m);
        double currentTime = time(&t);
        double tokensToAdd = (currentTime - lastRefilledTimestamp) * refreshRate;
        tokensToAdd = (tokensToAdd < maxCapacity) ? tokensToAdd : maxCapacity;
        return tokensToAdd;
        lk.unlock();
    }

};

/*
1. if you refill, and not enough tokens are there, you don't refill
2. if tokens are available, no need to wait for them
3. when one thread takes
*/




void main() {

    map<int, TokenBucket> m;

	system("PAUSE");
}


