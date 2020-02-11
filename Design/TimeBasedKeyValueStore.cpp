//https://leetcode.com/problems/time-based-key-value-store
class TimeMap {
public:
	/** Initialize your data structure here. */
	TimeMap() {

	}
	map<string, map<int, string>> m;
	void set(string key, string value, int timestamp) {
		m[key][timestamp] = value;
	}

	string get(string key, int timestamp) {
		auto end = m[key].upper_bound(timestamp);
		string res = "";
		if (end == m[key].begin()) {
			return "";
		}
		return prev(end)->second;
	}
};

// another possible solution:


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
		auto end = m.upper_bound(pair<string, int>(key, timestamp));
		string res = "";
		if (end == m.begin()) {
			return res;
		}
		return prev(end)->second;
	}
};
