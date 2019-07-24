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

//https://leetcode.com/problems/partition-labels/
//Submitted, passed 116/116

vector<int> partitionLabels(string S) {
	vector<int> res;
	vector<int> A(26, -1);

	// initialize A with latest most index in S
	for (int i = 0; i < S.size(); ++i) {
		A[S[i] - 'a'] = i;
	}

	int min = 0; int max = A[S[0] - 'a'];
  
	// Check if the current char is greater than the latest most index seen so far (max), updating min/max along the way
	for (int i = 0; i < S.size(); ++i) {
		if (i == max) {
			res.push_back(max - min + 1);
			if (i < S.size()-1) {
				min = i + 1;
				max = A[S[i + 1] - 'a'];
			}
		}
		if (A[S[i] - 'a'] > max) {
			max = A[S[i] - 'a'];
		}
	}

	return res;
}

void main() {
	partitionLabels("ababcbacadefegdehijhklij");
	partitionLabels("eccbbbbdec");
	partitionLabels("gdcadbdhzijh");
	
	system("PAUSE");
}

