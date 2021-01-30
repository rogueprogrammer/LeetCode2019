// https://leetcode.com/problems/minimum-window-substring/
// close to working solution, need to debug (maybe 1-2 lines need changing). algo is correct
string minWindow(string s, string t) {
    /*

                i         j
    Input: s = "D A O B E C O D E B A  N  C", t = "ABC"
                0 1 2 3 4 5 6 7 8 9 10 11 12
    Output: "BANC"


   A - 1
   B - 1
   C - 1

    */
    map<char, int> hm;
    for (char c : t) {
        hm[c]++;
    }
    string res = "";
    if (s == "" || t == "" || t.size() > s.size()) {
        return res;
    }

    int start = 0; int end = 0;
    int count = t.size();
    int minLength = INT_MAX;
    int minStart = -1; int minEnd = -1;

    while (end < s.size()) {
        char cur = s[end];
        auto it = hm.find(cur);
        if (it != hm.end()) {
            hm[cur]--;
            count--;
        }
        end++;
        while (count == 0) {
            if (end - start < minLength) {
                minLength = end - start;
                minStart = start;
                minEnd = end;
            }
            cur = s[start];
            auto it = hm.find(cur);
            if (it != hm.end()) {
                count++;
                hm[cur]++;
            }
            start++;
        }

    }
    res.substr(minStart, minEnd - minStart);
    return res;
}
