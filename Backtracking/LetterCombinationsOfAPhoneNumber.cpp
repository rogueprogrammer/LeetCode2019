vector<string> mapping = {
		"abc", //2
		"def", //3
		"ghi", //4
		"jkl", //5
		"mno", //6
		"pqrs", //7
		"tuv", //8
		"wxyz" //9
	};
void dfs(string& digits, int& posn, string& soFar, vector<string>& allCombinations) {
	
	if (posn >= digits.size()) {
		allCombinations.push_back(soFar);
		return;
	}

	int digit = digits[posn] - '0';
	string curString = mapping[digit - 2];
	for (int i = 0; i < curString.size(); ++i) {
		soFar += curString[i];
		posn++;
		dfs(digits, posn, soFar, allCombinations);
		soFar.pop_back();
		posn--;
	}
}

vector<string> letterCombinations(string digits) {
	vector<string> res;
	if (digits == "") {
		return res;
	}
    
    
	int posn = 0;
	string soFar = "";
	dfs(digits, posn, soFar, res);
	return res;
}
