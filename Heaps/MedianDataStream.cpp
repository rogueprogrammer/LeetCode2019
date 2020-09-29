// https://leetcode.com/problems/find-median-from-data-stream/submissions/
// runtime: O(logn) for rebalancing step in addnum(), and O(1) for get median
// space complexity: O(n)

class MedianFinder {
public:
    /** 
    The trick in this program is to visualize a sorted array organized like this:
    [ low elements ]  [Median] [ high elements ]
    
    We need access to the high end of the low elements and the low end of the high elements
    high end of low elements -> make a max heap of the low elements
    low end of the high elements -> make a min heap of the high elements.
    Now draw out the min/max heaps on an example to come up with the algo:
    
    [2, 7, 5, 4, 1]

    maxHeap:
    4
    2
    1


    minHeap:

    5
    7
    Anything greater than maxHeap's root belongs in minHeap, since minHeap contains elements that are in upper half.
    Anything less than maxHeap's root belongs in maxHeap.
    After insert operation, do rebalancing based on the Invariant: Size of the two heaps must not differ more than 1. 
    For median, if both heaps have same amount of elments, return the average of the roots. else retrun the root of the heap that has more elements.


    */
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {

    }

    void addNum(int num) {
        if (maxHeap.empty()) {
            maxHeap.push(num);
        }
        else if (num > maxHeap.top()) {
            minHeap.push(num);
        }
        else {
            maxHeap.push(num);
        }
        int minHeapSize = minHeap.size();
        int maxHeapSize = maxHeap.size();
        // rebalancing
        if (maxHeapSize-minHeapSize > 1) {
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
        else if (minHeapSize-maxHeapSize > 1) {
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        }
    }

    double findMedian() {
        if (minHeap.size() + maxHeap.size() == 0) {
            return 0;
        }
        else if (minHeap.size() == maxHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else if (minHeap.size() > maxHeap.size()) {
            return minHeap.top();
        }
        else {
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
