#include "Header.h"
#include <time.h>
#include <mutex>
#include <thread>


/*

OnDemand Refill vs Background thread Daemon performing Refill():

The biggest differences between the two:
1. Ondemand, we don't waste cycles constantly providing the tokens. CPU usage is saved here.

2. Having refill() as a background thread has advantage of not having any waits for constant get operations. If there is 1000s of get() requests being made by a user simultaneously,
then the wait would be longer, to get the tokens. 

So in the end, it depends on what we care about.  

*/


#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <queue>
#include <math.h>
#include <map>
#include <cstdlib>
#include <cmath>
#include <bitset>
#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std;


/*
OnDemand Refill vs Background thread Daemon performing Refill():
The biggest differences between the two:
1. Ondemand, we don't waste cycles constantly providing the tokens. CPU usage is saved here.
2. Having refill() as a background thread has advantage of not having any waits for constant get operations. If there is 1000s of get() requests being made by a user simultaneously,
then the wait would be longer, to get the tokens.
So in the end, it depends on what we care about.
*/


class TokenBucket {
public:
    double lastRefilledTimestamp;
    int numTokensCurrentlyInBucket;
    int refreshRate; // number of tokens added to bucket per second
    int maxCapacity; // max number of tokens that can be in bucket
    mutex m;

    // tokens = # of tokens currently in bucket
    // refreshRate = new tokens added at this rate (tokens/sec)
    // capacity = max capacity of tokens a bucket can hold
    TokenBucket(int tokens, int refreshRate, int capacity) {
        this->maxCapacity = capacity;
        this->numTokensCurrentlyInBucket = tokens;
        this->refreshRate = refreshRate;
        this->lastRefilledTimestamp = clock();
    }

    void get(int amount) {
        unique_lock<mutex> lk(m);
        while (amount > this->numTokensCurrentlyInBucket) {
            refill_lock_held();
        }
        this->numTokensCurrentlyInBucket -= amount;
        cout << "Accessed " << amount << " tokens. " << this->numTokensCurrentlyInBucket << " tokens remaining." << endl;
        lk.unlock();
    }

    // refill - happens on demand
    void refill_lock_held() {
        clock_t currentTime = clock();
        int num_seconds = 1;
        while (currentTime - this->lastRefilledTimestamp < num_seconds * CLOCKS_PER_SEC) {
            currentTime = clock();
        }

        int tokensToAdd = ((currentTime - this->lastRefilledTimestamp) * refreshRate) / 1000;
        if (tokensToAdd + this->numTokensCurrentlyInBucket > maxCapacity) {
            tokensToAdd = maxCapacity - this->numTokensCurrentlyInBucket;
            this->numTokensCurrentlyInBucket += tokensToAdd;
        }
        else {
            this->numTokensCurrentlyInBucket += tokensToAdd;
        }
        cout << tokensToAdd << " tokens were added." << this->numTokensCurrentlyInBucket << " currently in bucket" << endl;
        this->lastRefilledTimestamp = clock();
    }

};

void main() {
    TokenBucket* tb = new TokenBucket(0, 1, 10);
    tb->get(8);
    tb->get(9);

    system("PAUSE");
}
void main() {
    TokenBucket* tb = new TokenBucket(0, 1, 10);
    tb->get(8);
    tb->get(9);

	system("PAUSE");
}
