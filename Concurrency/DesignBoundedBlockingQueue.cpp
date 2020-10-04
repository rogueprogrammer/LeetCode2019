// https://leetcode.com/problems/design-bounded-blocking-queue/submissions/

class BoundedBlockingQueue {
public:
    mutex m;
    int limit;
    queue<int> q;
    condition_variable q_Changed;


    BoundedBlockingQueue(int capacity) {
        limit = capacity;
    }

    void enqueue(int element) {
        unique_lock<mutex> lck(m); // condition variables require unique_lock and don't accept mutexes, which is why we need to use unique_lock encapsulating the mutex

        // {grab the lock and push the element} on condition variable predicate that the size of the queue is less than limit
        q_Changed.wait(lck, [this] {return q.size() < limit; });
        q.push(element);

        // wake up waiting threads who are waiting to dequeue, but waiting on the q.size <= 0
        q_Changed.notify_one(); 
    }

    int dequeue() {
        unique_lock<mutex> lck(m);
        
        q_Changed.wait(lck, [this] { return q.size() > 0; });
        int top = q.front();
        q.pop();
        q_Changed.notify_one(); 
        return top;
    }

    int size() {
        return q.size();
    }
};
