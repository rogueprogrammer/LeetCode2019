#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
using namespace std;


 //https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
 int lengthOfLongestSubstringKDistinct(string s, int k) {

	if (s.size() == 0) return 0;

	unordered_map<char, int> m; //character to latest position

	int i = 0;
	int j = 0;
	int res = 1; string str;
	while (j < s.size()) {

		if (m.size() <= k) {
			m[s[j]] = j++;
		}

		if (m.size() > k) {
			//find smallest index in m, discard that and make i point to one higher
			int smallest = s.size();
			char ch;
			for (auto it : m) {
				if (it.second < smallest) {
					smallest = it.second;
					ch = it.first;
				}
			}
			i = smallest + 1;
			auto it = m.find(ch);
			m.erase(it);
		}
		if (j - i + 1 > res) {
			res = j - i;
			str = s.substr(i, j - i);
		}
		
	}
	return res;

}

void main() {

	cout << lengthOfLongestSubstringKDistinct("abcabdeabcbbbbbad", 3) << endl;
	cout << lengthOfLongestSubstringKDistinct("eceba", 2) << endl;
	system("PAUSE");
}
