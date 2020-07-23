#include "Header.h"

//https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        if (maxHeap.empty() || num > maxHeap.top()) {
            minHeap.push(num);
        }
        else {
            maxHeap.push(num);
        }
        
        //resize if difference in sizes is 2 or more
        if (!maxHeap.empty() && abs((int)maxHeap.size() - (int)minHeap.size()) >= 2) {
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
        else if (!minHeap.empty() && abs((int)minHeap.size() - (int)maxHeap.size()) >= 2) {
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return minHeap.top();
    }

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};


void main() {
    /*MedianFinder* mf = new MedianFinder();
    mf->addNum(1);
    mf->addNum(2);
    double median = mf->findMedian();
    mf->addNum(3);
    median = mf->findMedian();*/

    MedianFinder* mf = new MedianFinder();
    mf->addNum(-1);
    double median = mf->findMedian();
    mf->addNum(-2);
    median = mf->findMedian();
    mf->addNum(-3);
    median = mf->findMedian();
    mf->addNum(-4);
    median = mf->findMedian();
    mf->addNum(-5);
    median = mf->findMedian();


	system("PAUSE");
}
