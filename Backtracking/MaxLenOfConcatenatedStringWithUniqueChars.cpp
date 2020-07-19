   // https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
   
   bool isUnique(string s) {
    sort(s.begin(), s.end());
    if (s.size() == 1) return true;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) return false;
    }
    return true;
}

int _max(int x, int y) {
    return x > y ? x : y;
}

void dfs(vector<string>& arr, int& posn, string& acc, int& maxLen) {
    if (posn >= arr.size()) return;
    if (!isUnique(acc)) {
        posn++;
        if (posn < arr.size()) {
            acc = arr[posn];
        }
    }

    for (int i = posn + 1; i < arr.size(); ++i) {
        string temp = acc;
        acc += arr[i];
        if (isUnique(acc)) {
            maxLen = _max(maxLen, acc.size());
            dfs(arr, i, acc, maxLen);
        }
        acc = temp;
    }
}

int maxLength(vector<string>& arr) {
    int maxLen = 0;
    // run dfs on every unique string. if one doesn't exist, then return 0
    for (int i = 0; i < arr.size(); ++i) {
        string s = arr[i];
        if (isUnique(s)) {
            int posn = i;
            string acc = s;
            int curMax = acc.size();
            if (arr.size() == 1) return arr[0].size();
            dfs(arr, posn, acc, curMax);
            maxLen = max(maxLen, curMax);
        }
    }
    return maxLen;
}
