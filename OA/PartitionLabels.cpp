//https://leetcode.com/problems/partition-labels/

class Solution {
public:
  vector<int> partitionLabels(string S) {
	vector<int> res;
	vector<int> A(26, -1);

	//initialize A with latest most index in S
	for (int i = 0; i < S.size(); ++i) {
		A[S[i] - 'a'] = i;
	}

	int min = 0; int max = A[S[0] - 'a'];
	//int max = -1;
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


};
