//https://leetcode.com/problems/prison-cells-after-n-days/submissions/

/*
    [0,1,0,1,1,0,0,1]
    [0,1,1,0,0,0,0,0]
    [0,0,0,0,1,1,1,0]
    [0,1,1,0,0,1,0,0]
    [0,0,0,0,0,1,0,0]
    [0,1,1,1,0,1,0,0]
    [0,0,1,0,1,1,0,0]
    [0,0,1,1,0,0,0,0]
*/

string cellToString(vector<int> cells) {
    string res = "";
    for (int i = 0; i < cells.size(); ++i) {
        int cell = cells[i];
        char c = '1';
        if (cell == 0) {
            c = '0';
        }
        res += c;
    }
    return res;
}

vector<int> nextDay(vector<int> cells) {
    vector<int> temp = cells;
    for (int j = 0; j < cells.size(); ++j) {
        if (j == 0 || j == cells.size() - 1) {
            if (j == 0) {
                temp[j] = 0;
            }
            else {
                temp[j] = 0;
            }
        }
        else {
            if (cells[j - 1] == cells[j + 1]) {
                temp[j] = 1;
            }
            else {
                temp[j] = 0;
            }
        }
    }
    return temp;
}

vector<int> prisonAfterNDays(vector<int> cells, int N) {
    bool hasCycle = false;
    int numCycles = 0;
    set<string> ht;
    for (int i = 0; i < N; i++) {
        vector<int> next = nextDay(cells);
        string s = cellToString(next);
        auto it = ht.find(s);
        if (it != ht.end()) {
            hasCycle = true;
            break;
        }
        else { 
            ht.insert(s);
            numCycles++;
        }
        cells = next;
    }
    if (hasCycle) {
        N = N % numCycles;
        for (int i = 0; i < N; i++) {
            cells = nextDay(cells);
        }
    }
    return cells;
}

void main() {
    vector<int> cells = { 0,1,0,1,1,0,0,1 };
    int n = 7;
    prisonAfterNDays(cells, n);
}
