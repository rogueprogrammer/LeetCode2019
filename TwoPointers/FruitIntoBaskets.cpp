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

//https://leetcode.com/problems/fruit-into-baskets/
int totalFruit(vector<int>& tree) {
	
	if (tree.size() == 0) return 0;
	int numFruit = 1;
	int i = 0;
	int j = 0; 
	unordered_map<int, int> m; //maps from tree[i] -> latest seen i
	while (j < tree.size()) {

		if (m.size() <= 2) {
			m[tree[j]] = j++;
		}
		if (m.size() > 2) {
			
			//Discard first fruit
			int min = tree.size();
			for (auto it = m.begin(); it != m.end(); ++it) {
				min = std::min(min, it->second);
			}
			i = min + 1;
			m.erase(tree[min]);
		}
		numFruit = std::max(numFruit, j - i);
	}
	return numFruit;
}


void main() {
	
	//vector<int> tree = { 1,2,1 };
	//vector<int> tree = {3, 3, 3, 1, 1, 2, 1, 1, 2, 3, 3, 4};
	vector<int> tree = { 1, 2, 3, 2, 2 };
	cout << totalFruit(tree) << endl;
	
	system("PAUSE");
}
