//https://leetcode.com/problems/reorder-log-files/

bool customCompare(string a, string b) {

	//check first char after space
	int i = 0;
	string a_identifier;
	string b_identifier;
	while (a[i] != ' ') {
		++i;
		a_identifier += a[i];
	}
	int j = 0;
	while (b[j] != ' ') {
		++j;
		b_identifier += b[j];
	}

	if (isalpha(a[i + 1])) {
		if (!isalpha(b[j + 1])) return true;
		else {
			string a_comb;
			string b_comb;
			for (int ii = i; ii < a.size(); ++ii) {
				if (a[ii] != ' ') {
					a_comb += a[ii];
				}
			}
			for (int jj = j; jj < b.size(); ++jj) {
				if (b[jj] != ' ') {
					b_comb += b[jj];
				}
			}

			if (a_comb > b_comb) {
				return false;
			}
			else if (a_comb < b_comb) {
				return true;
			}
			else {
				return a_identifier > b_identifier;
			}
		}
	}
	else {
		if (isalpha(b[j + 1])) return false;
		else { //both are numbers, a should come first
			return false;
		}
	}
}

class Solution {
public:
	//["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
	//["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"] 
	vector<string> reorderLogFiles(vector<string>& logs) {
		sort(logs.begin(), logs.end(), customCompare);
		return logs;
	}
};
