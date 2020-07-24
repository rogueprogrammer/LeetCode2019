//https://leetcode.com/problems/longest-palindromic-substring/submissions/

class Solution {
public:
    
string longestPalindrome(string s) {
    /*

    let dp[i][j] be whether s[i...j] is a palindrome

Do bigger example after:
        0 1 2 3 4 5 6
        r a c e c a r
    r   1 0 0 0 0 0 1
    a     1 0 0 0 1 0
    c       1 0 1 0 0
    e         1 0 0 0
    c           1 0 0
    a             1 0
    r               1


Do smaller example first:
       0 1 2 3
       j i i j
   0 j 1 0 0
   1 i   1 1 0
   2 i     1 0
   3 j       1
        */
    int n = s.size();
    if (n <= 1) return s;

    vector<vector<bool>> dp(n, vector<bool>(n));
    int maxLen = 1;
    string res = ""; res += s[0];
    for (int len = 0; len < n; ++len) {

        for (int row = 0; row < n; ++row) {
            if (row + len >= n) {
                break;
            }
            if (len == 0) { //base case
                dp[row][row + len] = 1;
            }
            else if (len == 1) { //base case
                dp[row][row + len] = s[row] == s[row + 1];
            }
            else {
                dp[row][row + len] = (s[row] == s[row + len]) && (dp[row + 1][row + len - 1]);
            }
            if (dp[row][row + len] == 1) {
                if (len+1 > maxLen) {
                    maxLen = len+1;
                    res = s.substr(row, len+1);
                }
            }
        }
    }
    return res;

}
};
