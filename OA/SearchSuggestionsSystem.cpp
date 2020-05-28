// https://leetcode.com/problems/search-suggestions-system/submissions/
/*
products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"

products_sorted = ["mobile","moneypot", "monitor", "mouse", "mousepad"]

m - [mobile, moneypot, monitor]
mo - [mobile, moneypot, monitor]
mou - [mouse, mousepad]
mous - [mouse, mousepad]
mouse - [mouse, mousepad]

1. sort the products list lexicographically.
2. for each letter, get prefix up to that letter
3. loop through all words (up to max of 3), and if the prefix of word matches the prefix, then add to list
O(nlogn) + O(mn), n is size of products list, m is searchWord size
*/

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
	
	vector<vector<string>> res;

	sort(products.begin(), products.end(), [](string a, string b) {
		return a < b;
		});

	for (int i = 1; i <= searchWord.size(); ++i) {
		vector<string> curList;
		string prefix = searchWord.substr(0, i);
		for (int j = 0; j < products.size(); ++j) {
			if (curList.size() >= 3) {
				break;
			}
			string curWordPrefix = products[j].substr(0, i);
			if (prefix == curWordPrefix) {
				curList.push_back(products[j]);
			}
		}
		res.push_back(curList);
	}

	return res;

}
