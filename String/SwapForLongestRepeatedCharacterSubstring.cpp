#include "Header.h"

/*
https://leetcode.com/problems/swap-for-longest-repeated-character-substring/submissions/
47/47
Strategy -
    a b a b a a
    (a,1), (b,1), (a,1), (b,1), (a,2)
    find a character, pivot, where on both sides, characters are same, but different from pivot.
    the same character, must have another pivot elsewhere
    find all instances of this in the string, and choose the one with maximum total sum aronud the pivot.


    a b c c c a c
    (a,1),(b,1),(c,3),(a,1), (c,1)
    the same character in this case cannot be traded, because another c doesn't exist somewhere

    */
//2:55
map<char, vector<pair<int, int>>> populateMap(string text) {
    /*a b a b a a
    a -> (0, 1), (2, 1), (4, 2)
    b - (1, 1), (3, 1)
    */
    map<char, vector<pair<int, int>>> res;
    int i = 0;
    int j = 0;
    while (i < text.size()) {
        while (text[i] == text[j] && j < text.size()) {
            ++j;
        }
        char cur = text[i];
        int index = i;
        int len = j - i;
        res[cur].push_back(make_pair(index, len));
        i = j;
    }
    return res;
}

int maxConsecutiveChars(string text) {
    
    int maxLen = 1;
    int i = 0; int j = 0; 
    while (j < text.size()) {
        while (text[i] == text[j] && j < text.size()) {
            j++;
        }
        maxLen = max(maxLen, j - i);
        i = j;
    }
    return maxLen;
}

int maxRepOpt1(string text) {
    
    map<char, vector<pair<int, int>>> ht = populateMap(text); // <char, <index, len>>
    // find the sameChar, which is same on both sides
    /*a b a b a a
    a -> (0, 1), (2, 1), (4, 2)
    b - (1, 1), (3, 1)
    */
    char sameChar = NULL;
    int maxContiguous = 0;
    for (auto it = ht.begin(); it != ht.end(); ++it) {
        vector<pair<int, int>> pairs = it->second;
        sort(pairs.begin(), pairs.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first < b.first;
            }
        );
        if (pairs.size() >= 3) {
            /*
            aabaaabaaaba
            a -> (0, 2), (3, 3), (7,3), (11, 1)
            "babbaaabbbbbaa"
            b -> (0, 1), (2,2), (7,5)
            a -> (1,1), (4,3), (12,2)
            */
            for (int i = 0; i < pairs.size()-1; ++i) {
                int j = i + 1;
                if(pairs[i].first == pairs[j].first - pairs[i].second - 1){
                    sameChar = it->first;
                    maxContiguous = max(maxContiguous, pairs[i].second + pairs[j].second + 1);
                }
            }
            int maxConsec = 0;
            for (int i = 0; i < pairs.size(); ++i) {
                maxConsec = max(maxConsec, pairs[i].second);
            }
            maxContiguous = max(maxConsec + 1, maxContiguous);
        }
        else if (pairs.size() == 2) {
            /*
            aabaaa 
            a -> (0,2), (3, 3)
            b -> (2, 1)

            aaabbaaa
            a -> (0, 3), (5, 3)
            b -> (3, 2)
            */
            sameChar = it->first;
            if (abs(pairs[1].first - pairs[0].first) - 1 == pairs[0].second) { //pivot point found
                maxContiguous = max(maxContiguous, pairs[0].second + pairs[1].second);
            }
            else {
                int maxLen = max(pairs[0].second, pairs[1].second) + 1;
                maxContiguous = max(maxContiguous, maxLen);
            }
        }
    }
    return (sameChar != NULL) ? maxContiguous : maxConsecutiveChars(text); //only if samechar != null

}



void main() {
    cout << maxRepOpt1("babbaaabbbbbaa") << endl; //6
    cout << maxRepOpt1("aabaaabaaaba") << endl; //7
    cout << maxRepOpt1("bbbccaaaaad") << endl; //5
    cout << maxRepOpt1("abcdef") << endl; //1
    cout << maxRepOpt1("ababaa") << endl; //4 
    cout << maxRepOpt1("aabaaa") << endl; //5
    cout << maxRepOpt1("aaabaaa") << endl;  //6
    cout << maxRepOpt1("aaabbaaa") << endl; //4
    system("PAUSE");
}
