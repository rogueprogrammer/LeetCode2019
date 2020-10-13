#include "Header.h"
#include <time.h>
#include <mutex>
#include <thread>


// aspects of concurrency to consider? 
// can critical section be smaller?
// aspects of scalable systems to consider?
class TokenBucket {
public:
    double lastRefilledTimestamp;
    int numTokensCurrentlyInBucket;
    int refreshRate; // number of tokens added to bucket per second
    int maxCapacity; // max number of tokens that can be in bucket
    mutex m;
    condition_variable notEnoughTokens;
    condition_variable tooManyTokens;

    // tokens = # of tokens currently in bucket
    // refreshRate = new tokens added at this rate (tokens/sec)
    // capacity = max capacity of tokens a bucket can hold
    TokenBucket(int tokens, int refreshRate, int capacity) {

        this->maxCapacity = capacity;
        this->numTokensCurrentlyInBucket = tokens;
        this->refreshRate = refreshRate;

        // create a background thread to constantly refill at refresh rate
        std::thread t(&TokenBucket::refill, this);
        t.detach(); // make it a background thread
        
    }

    void get(int amount) {

        unique_lock<mutex> lk(m);
        while (amount > this->numTokensCurrentlyInBucket) {
            cout << "Cannot get " << amount << " tokens. Waiting ... " << endl;
            notEnoughTokens.wait(lk);
        }
        this->numTokensCurrentlyInBucket -= amount;
        cout << "withdrawing " << amount << " tokens" << " new amount is: " << this->numTokensCurrentlyInBucket << endl;
        tooManyTokens.notify_one();

        lk.unlock();
    }
   
    // refill every second
    void refill() {
        int num_seconds = 1;
        while (1) {
            clock_t currentTime = clock();
            this->lastRefilledTimestamp = currentTime;
            unique_lock<mutex> lk(m);
            while (currentTime - this->lastRefilledTimestamp < (num_seconds * CLOCKS_PER_SEC)) {
                currentTime = clock();
            }
            while (this->numTokensCurrentlyInBucket >= this->maxCapacity) {
                cout << "Token bucket has reached maximum capacity of " << this->maxCapacity << " tokens." << endl;
                tooManyTokens.wait(lk);
            }

            double tokensToAdd = ((currentTime - this->lastRefilledTimestamp) * this->refreshRate) / 1000;
            this->numTokensCurrentlyInBucket = 
                (tokensToAdd + this->numTokensCurrentlyInBucket < maxCapacity) ? 
                tokensToAdd + this->numTokensCurrentlyInBucket : maxCapacity;
            this->lastRefilledTimestamp = clock();
            cout << "Added " << tokensToAdd << " tokens. Total num of tokens in bucket = " << this->numTokensCurrentlyInBucket << endl;
            notEnoughTokens.notify_all();
            lk.unlock();
        }
    }

};




void main() {


    TokenBucket* tb = new TokenBucket(0, 1, 10);
    tb->get(2);
    tb->get(9);

	system("PAUSE");
}


