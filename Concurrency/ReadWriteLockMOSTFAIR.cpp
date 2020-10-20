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
using namespace std;


// for fairness, we use a doubly linked list of distinct condition variables
// to incorporate parallelism among readers, we allow multiple readers at the same time, but only within a certain timeframe
// idea is to have two queues, one for read cvs and one for write cvs,
// and check front of read and write queues to see which one is less and that one goes first: either burst of reads, or exactly one write thread
class ReaderWriterLockFair {

	mutex m;
	list<pair<condition_variable, long>> readCVs;
	list<pair<condition_variable, long>> writeCVs;

	bool isWriterActive;
	bool isReaderActive;

	long getCurrentTimestamp() {
		clock_t res;
		return (long)res;
	}

	// wake up all the condition_variable tied threads if theyre within a certain timeframe
	void wakeReadThreads( long timespan) {
		long lastReadTime = getCurrentTimestamp();
		while(!readCVs.empty()) {
			pair<condition_variable, long> cur = readCVs.front();
			if (cur.second > lastReadTime && cur.second < lastReadTime + timespan) { // if the element is between the last read time 
				cur.first.notify_one();
				readCVs.pop_front();
			}
			else {
				firstReader = true;
				break;
			}
		}
	}

	void wakeNextWriteThread() {
		if(!writeCVs.empty()) {
			condition_variable writeCV = writeCVs.front().first;
			writeCV.notify_one();
			writeCVs.pop_front();
		}
	}

	// check front of read and write queues to see which one is less and that one goes first: either burst of reads, or exactly one write thread
	void wakeNextCV() {
		unique_lock<mutex> lk(m);
		if (writeCVs.empty() && readCVs.empty()) {
			return;
		}
		else if (writeCVs.empty()) {
			wakeReadThreads(10);
		}
		else if (readCVs.empty()) {
			wakeNextWriteThread();
		}
		else { // both queues have read/write threads' condition variables waiting so take the one with the earlier timestamp
			if (writeCVs.front().second <= readCVs.front().second) {
				wakeNextWriteThread();
			}
			else {
				wakeReadThreads(10);
			}
		}
		lk.unlock();
	}

	void readLock() {
		unique_lock<mutex> lk(m);
		// if any writing thread is active or if any of the queues have a line up, then need to wait
		while (isWriterActive || !readCVs.empty() || !writeCVs.empty()) {
			condition_variable cv;
			long t = getCurrentTimestamp();
			readCVs.push_back(make_pair(cv, t));
			cv.wait(lk);
		}
		isReaderActive = true;
		cout << "ReadLock()" << endl;
		lk.unlock();
	}

	void readUnlock() {
		unique_lock<mutex> lk(m);
		cout << "ReadUnlock()" << endl;
		isReaderActive = false;
		wakeNextCV();
		lk.unlock();
	}

	void writeLock() {
		unique_lock<mutex> lk(m);
		while (isReaderActive || isWriterActive || !writeCVs.empty() || !readCVs.empty()) {
			condition_variable cv;
			long t = getCurrentTimestamp();
			writeCVs.push_back(make_pair(cv, t));
			cv.wait(lk);
		}
		isWriterActive = true;
		cout << "WriteLock()" << endl;
		lk.unlock();
	}

	void writeUnlock() {
		unique_lock<mutex> lk(m);
		cout << "WriteUnlock()" << endl;
		isWriterActive = false;
		wakeNextCV();
		lk.unlock();
	}

};
