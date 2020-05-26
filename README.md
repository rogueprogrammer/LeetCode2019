# LeetCode2019

******HEAPS:

struct maxHeapComparator {

	bool operator()(const int& a, const int &b) {
		return a < b;
	}
	
};

void heaptest() {

	vector<int> v = { 10, 11, 8, 7, 6 };
	priority_queue<int, vector<int>, maxHeapComparator> pq;
	for (int x : v) {
		pq.push(x);
	}
	//pq: 11, 10, 8, 7, 6
}
