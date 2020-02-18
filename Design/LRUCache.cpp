//leetcode.com/problems/lru-cache/
//100% test cases pass
class LRUCache {
public:
	unordered_map<int, list<pair<int, int>>::iterator> m;
	list<pair<int, int>> l;
	int size;

	LRUCache(int capacity) {
		size = capacity;
	}

	int get(int key) {
		auto it = m.find(key);
		if (it == m.end()) {
			return -1;
		}
		list<pair<int, int>>::iterator it2 = m[key]; //get iterator
		pair<int, int> p = pair<int, int>(key, it2->second); //create a new key val pair
		l.erase(it2); //erase old key val pair from list
		l.push_front(p); //put the pair in front of the list
		m.erase(key); //erase mapping from m and replace with new mapping
		m[key] = l.begin(); //reset the mapping in m
		return m[key]->second;
	}

	void put(int key, int val) {
		auto it = m.find(key);
		if (it != m.end()) { //already in the cache, move it to front of list and delete existing mappings
			l.erase(it->second);
			m.erase(key);
			pair<int, int> p = pair<int, int>(key, val);
			l.push_front(p);
			m[key] = l.begin();
			return;
		}
		pair<int, int> p = pair<int, int>(key, val);
		l.push_front(p);
		m[key] = l.begin();
		if (m.size() > size) {
			auto it = l.back();
			int keyToDelete = it.first;
			m.erase(keyToDelete);
			l.pop_back();
		}
	}

};



void main() {

	int capacity = 2;
	LRUCache* obj = new LRUCache(capacity);
	obj->put(2, 1); 
	obj->put(1,1);
	obj->put(2, 3);
	obj->put(4, 1);
	obj->get(1);
	obj->get(2);	
	system("PAUSE");
}
