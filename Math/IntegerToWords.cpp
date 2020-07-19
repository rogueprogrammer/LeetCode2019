// https://leetcode.com/problems/integer-to-english-words/
// so far only implemented for numbers up to 1000
vector<string> lessthan10 = { "one", "two", "three", "four", "five", "six", "seven", "eight",
                      "nine" };

vector<string> lessthan20 = { "ten", "eleven", "twelve", "thirteen", "forteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };

vector<string> lessthan100 = { "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

vector<string> lessthan1000 = { "one hundred", "two hundred", "three hundred", "four hundred",
"five hundred", "six hundred", "seven hundred", "eight hundred", "nine hundred" };

//643
void helper(int& n, string& s) {
    int firstDig;
    if (n == 0) {
        return;
    }
    else if (n >= 100) { //n is greater or equal to 100
        firstDig = n / 100;
        s += " ";
        s += lessthan1000[firstDig - 1];
        n = n - (firstDig * 100);
        helper(n, s);
    }
    else if (n >= 20 && n < 100) {
        firstDig = n / 10;
        s += " ";
        s += lessthan100[firstDig - 1];
        n = n - (firstDig * 10);
        helper(n, s);
    }
    else if (n >= 10 && n < 20) {
        firstDig = n - 10;
        s += " ";
        s += lessthan20[firstDig];
    }
    else { // n < 10
        firstDig = n;
        s += " ";
        s += lessthan10[firstDig - 1];
    }
}

string numberToWords(int num) {

    string res = "";
    helper(num, res);
    return res.substr(1);
}

void main() {

    cout << numberToWords(643) << endl;
    cout << numberToWords(800) << endl;
    cout << numberToWords(22) << endl;
    cout << numberToWords(8) << endl;
    cout << numberToWords(12) << endl;

    system("PAUSE");
}
