#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <sstream>
#include <List>
#include <assert.h>
using namespace std;

// https://leetcode.com/discuss/interview-question/762546/

int isWinner(vector<vector<string>> codelist, vector<string> cart) {
    int cartIdx = 0;
    int totalNum = 0;
    int count = 0;
    int i = 0; //index of codelist

    for (auto codeList : codelist) {
        totalNum += codeList.size();
    }
    while (i < codelist.size()) {
        vector<string> list = codelist[i];
        int j = 0; //used to iterate through list
        while (j < list.size() && cartIdx < cart.size()) {
            if (list[j] == cart[cartIdx]) {
                cartIdx++;
                j++;
                count++;
            }
            else if (list[j] == "anything") {
                cartIdx++;
                j++;
                count++;
            }
            else {
                if (j == 0) cartIdx++;
                else return 0;
            }
        }
        i++;
    }
    return count == totalNum;
}



void main() {

    vector<vector<string>> codelist1 = { {"apple", "apple"},{"banana", "anything", "banana"} };
    

    vector<string> cart1 = { "orange", "apple", "apple", "banana", "orange", "banana" };

    cart1 = { "apple", "apple", "orange", "orange", "banana", "apple", "banana", "banana" };

    cout << isWinner(codelist1, cart1) << endl; //1
    cout << isWinner(codelist1, cart1) << endl; //1
    
    cart1 = { "banana", "orange", "banana", "apple", "apple" };
    cout << isWinner(codelist1, cart1) << endl; //0
    cart1 = { "apple", "banana", "apple", "banana", "orange", "banana"};
    cout << isWinner(codelist1, cart1) << endl; //0

    codelist1 = {
        {"apple", "apple"},{"apple", "apple", "banana"} 
    };
    cart1 = { "apple", "apple", "apple", "banana" };
    cout << isWinner(codelist1, cart1) << endl; //0
    cart1 = { "orange", "blueberry", "apple", "apple", "apple", "apple", "banana" };
    cout << isWinner(codelist1, cart1) << endl; //1

    system("PAUSE");
}
