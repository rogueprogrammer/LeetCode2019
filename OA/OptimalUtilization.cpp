// https://leetcode.com/discuss/interview-question/373202
/*
a = [[1, 2], [2, 4], [3, 6]]
b = [[1, 2]]
target = 7

Output: [[2, 1]]
*/
vector<vector<int>> findPairs(vector<vector<int>> a, vector<vector<int>> b, int target) {
	sort(a.begin(), a.end(), [](vector<int> x, vector<int> y) {return x[1] < y[1]; });
	sort(b.begin(), b.end(), [](vector<int> x, vector<int> y) { return x[1] < y[1]; });

	vector<vector<int>> res;
	int i = 0, j = a.size() - 1;
	int max = 0;
	while (i < b.size() && j >= 0) {
		if (a[j][1] + b[i][1] > target) {
			j--;
		}
		else {
			if (a[j][1] + b[i][1] > max) {
				max = a[j][1] + b[i][1];
				res.clear();
				res.push_back(vector<int>{a[j][0], b[i][0]});
			}
			else if (a[j][1] + b[i][1] == max) {
				res.push_back(vector<int>{a[j][0], b[i][0]});
			}
			i++;
		}
	}
	return res;
}



void main() {

	vector<vector<int>> a = { {1, 2},{2, 4},{3, 6} };
	vector<vector<int>> b = { {1, 2} };
	int target = 7;
	a = { {1, 3},{2, 5},{3, 7},{4, 10} };
	b = { {1, 2},{2, 3},{3, 4},{4, 5} };
	target = 10;
	vector<vector<int>> res = findPairs(a, b, target);

	system("PAUSE");
}
