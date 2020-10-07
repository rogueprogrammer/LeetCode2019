// Compiled with: g++ -Wall -std=c++14 -pthread

/*
Implement a concurrent hash-based map using lock striping.
Note: Apply a locking strategy that offers better concurrency and scalability; instead of synchronizing every method on a common lock, restricting access to a single thread at a time, utilize a finer-grained locking mechanism called lock striping to allow a greater degree of shared access.

bool Find(const K key, int& value);
bool Insert(const K key, const int value);
void Resize(int size);
    

insert(1, 10); t1 at time t
resize(2);
insert(3, 30); t2 at time t
find(1, 11) ; t4 at time t+1
size = 2, maxNumElems = 2
resize by doubling

*/


#include <iostream>
using namespace std;

class Hashmap{
  private:
    vector<list<pair<int, int>>> hm; //hm[hash] = {<key, value>}
    int count;
    int size;
    mutex m;
    
    Hashmap(int s = 0){
     count = 0;   
     size = s;
    }
    
    int getIndex(int key){
        return key % hm.size();
    }
    
  public:
    /*
    insert(1, 10)  t
    insert(2, 20)  t
    find(2, 20)    t -> false
    
    find(3, 30)   t+1 -> f
    find(2, 15)   t+1 -> f
    find(2, 20)   t+1 -> true
    
    int return_value
    Find(2, return_value)  // return_value is from the map
    
    */
    int numFindThreads;
    int numInsertThreads;
    
    condition_variable cvFind; //guarding threads waiting on Find()
    condition_variable cvInsert;  //guarding threads waiting on Insert()
    
    //Find works great for multiple read threads
    // but if another thread is inserting then, read threads need to wait
    bool Find(const int key, int& value/*output*/){
        unique_lock<mutex> lk(m);
        while(numInsertThreads > 0 ){
            cvFind.wait(lk); 
        }
        ++numFindThreads;
        
        list<pair<int, int>> l = hm[getIndex(key)]; // t1 and t2 will have differeent versions of the same list if its at same key
        --numFindThreads;
        //cvInsert.notify_one
        lk.unlock();
        
        
        for(pair<int, int> p : l){
            if(p.first == key){
                value = p.second;
                return true;   
            }
        }
        
        
        return false;
        
    }
    void InsertUnlock(){
        if(numFindThreads > 0){
            cvFind.notify_all();
        }
        if(numInsertThreads > 0){
            cvInsert.notify_one();
        }
        lk.unlock();
    }
    //only allow insert thread to happen if no other therad is finding/inserting
    //single threaded insert
    
    // 1: t1 read k1: 1
    // 2: t2 write k1=2
    // 3: t1 read k1: 2
    
    // t1...t10000 read()
    // t500 write() /// write thread needs to wait 500 units of time
    
    bool Insert(int  key, int value){
        unique_lock<mutex> lk(m);
        while(numInsertThreads > 0 && numFindThreads > 0   ){
            cvFind.wait(lk);   
        }
        ++numInsertThreads;
        
        list<pair<int, int>> l = hm[getIndex(key)];
        
        
        for(pair<int, int> p : l){
            if(p.first == key){
                InsertUnlock();
                return false;  
            }
        }
        l.push_back(make_pair(key, value));
        ++count;
        if(count == size){
            Resize(size * 2);   
        }
        
        InsertUnlock();

        
        return true;
    }
    
    void Resize(int size){
        this.size = size;
        hm.resize(size);
    }
};  



/*
* Problem: Efficient Read-Write Concurrent Map
*
* Solution:
* ReaderWriterConcurrentHashMap is made of HashBuckets.
* Map is resizable.
* Buckets Read lock is required to access HashBuckets.
* Buckets Write lock is required to rezie hash map.
* Bucket Level read lock is required to find an element in the bucket.
* Bucket Level write lock is required to insert/delete an element in the bucket.
*
*/
template <class K, class V>
class HashBucket {
  public:
  bool Find(const K key, V& value/*OUT*/) {
    // Read lock
    std::shared_lock<std::shared_mutex> lock(rwLock_);
    auto it = map_.find(key);
    if (it == map_.end()) {
      return false;
    }
    value = it->second;
    return true;
  }

bool Insert(const K key, const V value) {
  // Write lock
  std::unique_lock<std::shared_mutex> lock(rwLock_);
  auto ret = map_.insert(make_pair(key, value));
  return ret.second;
}

private:
  std::map<K,V> map_;
  std::shared_mutex rwLock_;
};

template <class K, class V>
class ReaderWriterConcurrentHashMap {
public:
  ReaderWriterConcurrentHashMap() : numBuckets_(DEFAULT_NUM_BUCKETS),
    buckets_(DEFAULT_NUM_BUCKETS) {}
  ReaderWriterConcurrentHashMap(int numBuckets) :
    numBuckets_(numBuckets),
    buckets_(numBuckets) { }

bool Find(const K key, V& value/*OUT*/) {
  size_t hash = hasher_(key);
  int bucketIdx = hash % numBuckets_;
  std::shared_lock<std::shared_mutex> lock(rwBucketLock_);
  return buckets_[bucketIdx].Find(key, value);
}

/*
* @brief Insert a key in the map
* @return true if inserted,
* else, false.
*/
bool Insert(const K key, const V value) {
  size_t hash = hasher_(key);
  int bucketIdx = hash % numBuckets_;
  // Read lock
  std::shared_lock<std::shared_mutex> lock(rwBucketLock_);
  bool ret = buckets_[bucketIdx].Insert(key, value);
  if (ret == true) {
    size_++;
  }
}
    
private:
bool ReSize() {
  size_t hash = hasher_(key);
  int bucketIdx = hash % numBuckets_;
  // Write lock
  std::unique_lock<std::shared_mutex> lock(rwBucketLock_);
  // Code for resize
  lock.unlock();
}

  const static int DEFAULT_NUM_BUCKETS{127};
  int numBuckets_{DEFAULT_NUM_BUCKETS};
  // Fixed size buckets.
  std::vector<HashBucket<K,V>> buckets_;
  std::hash<K> hasher_;
  int size_;
  std::shared_mutex rwBucketLock_;
};
    




int main(){
    cout << "Hello, World!" << endl;
    return 0;
}
