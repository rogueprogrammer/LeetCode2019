//https://leetcode.com/problems/time-based-key-value-store
class TimeMap {
public:
	/** Initialize your data structure here. */
	TimeMap() {

	}
	map<pair<string, int>, string> m;

	void set(string key, string value, int timestamp) {
		m[pair<string, int>(key, timestamp)] = value;
	}

	string get(string key, int timestamp) {
		auto start = m.lower_bound(pair<string, int>(key, 0));
		auto end = m.upper_bound(pair<string, int>(key, timestamp));
		string res = "";
		int ts = 0;
		for (auto it = start; it != end; ++it) {
			if (it->first.second >= ts) {
				ts = it->first.second;
				res = it->second;
			}
		}
		return res;
	}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
