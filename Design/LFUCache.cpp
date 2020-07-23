#include "Header.h"

//https://leetcode.com/problems/lfu-cache/submissions/
//passing 9/23, get back to this later
//idea is to use 3 hashmaps, one for frequencies, one for operation id and one for key,val pairs


/*
    capacity = 4
    insert(1,1), insert(2,2), insert(3,3), insert(4, 4), get(1), get(2), insert (5,5)

    (1,1) Frequency= 2
    (2,2) Frequency = 2
    (3,3) Frequency = 1
    (4,4) Frequency = 1
    leastFrequent = 1

    Frequency -> Key mapping
    1 -> {3, 4}
    2 -> {1, 2}
    */


class LFUCache {
public:
    LFUCache(int capacity) {
        leastFrequent = INT_MAX;
        size = capacity;
        opId = -1;
    }

    void updateOpId(int key) {
        opId++;
        lastAccessed[key] = opId;
    }

    void updateFrequencies(int key) {
        int curFrequency = data[key].second;
        int newFrequency = curFrequency + 1;

        //remove curFrequency
        vector<int> curFrequencies = frequencies[curFrequency];
        for (int i = 0; i < curFrequencies.size(); ++i) {
            if (curFrequencies[i] == key) {
                frequencies[curFrequency].erase(frequencies[curFrequency].begin()+i);
            }
        }

        //update with new frequency
        frequencies[newFrequency].push_back(key);

        //update in data as well
        data[key].second = newFrequency;

        //iterate through frequencies to find one with size > 0. that is the least frequent
        if (frequencies[leastFrequent].size() == 0) {
            leastFrequent = INT_MAX;
            for (auto it = frequencies.begin(); it != frequencies.end(); ++it) {
                vector<int> f = it->second;
                if (f.size() != 0) {
                    leastFrequent = min(leastFrequent, it->first);
                }
            }
        }

        
    }
    
    int get(int key) {
        if (size == 0) return -1;
        auto it = data.find(key);
        if (it == data.end()) {
            return -1;
        }
        updateOpId(key);
        updateFrequencies(key);
        return data[key].first;
    }

    void put(int key, int value) {
        if (size == 0) return;
        if (data.size() + 1 > size) {
            vector<int> leastFrequents = frequencies[leastFrequent];
            if (leastFrequents.size() == 1) {
                int keyToRemove = leastFrequents[0];
                data.erase(keyToRemove);
                frequencies.erase(leastFrequent);
            }
            else {
                //find the key with the least accessed operationId
                int lowestAccessedKey = -1;
                int lowestOperation = INT_MAX;
                int indexToErase = -1;
                for (int i = 0; i < leastFrequents.size(); ++i) {
                    int curKey = leastFrequents[i];
                    int lastOpId = lastAccessed[curKey];
                    if (lastOpId < lowestOperation) {
                        lowestOperation = lastOpId;
                        lowestAccessedKey = curKey;
                        indexToErase = i;
                    }
                }
                data.erase(lowestAccessedKey);
                frequencies[leastFrequent].erase(frequencies[leastFrequent].begin() + indexToErase);

            }

        }
        data[key] = make_pair(value, 1);


        updateOpId(key);

        //update frequencies with 1 as the frequency
        leastFrequent = min(leastFrequent, 1);
        frequencies[1].push_back(key);
    }

    int size;
    int opId;
    int leastFrequent;
    unordered_map<int, int> lastAccessed; //key -> opId
    unordered_map<int, pair<int, int>> data; //key -> val, frequency
    unordered_map<int, vector<int>> frequencies; //frequency -> keys

};


void main() {
  
    LFUCache* cache = new LFUCache(1);
    cache->put(2, 1);
    int res = cache->get(2);
    cache->put(3, 2);
    res = cache->get(2);
    res = cache->get(3);

    /*
    LFUCache* cache = new LFUCache(2);
    int res;
    cache->put(1, 1);
    cache->put(2, 2);
    cache->get(1);
    cache->put(3, 3);
    res = cache->get(2);
    res = cache->get(3);
    cache->put(4, 4);
    res = cache->get(1);
    res = cache->get(3);
    res = cache->get(4);*/

    system("PAUSE");
}
