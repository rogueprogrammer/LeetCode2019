
//https://leetcode.com/problems/decode-string/
/*
    EX 1 - 3[a]2[bc]

    cur = a
    ss          is
    a           3
    encounter ']' -> aaa, cur = ""

    cur = bc
    ss        is
    aaa        2
    encounter ']' -> append bcbc to top of stack

    EX 2 - 3[a2[c]]

    cur = a
    ss            is
    a              3
    cur = c
    ss
    acc


    */
    /*
    Idea is to maintain two stacks, one for all the counts, and one for keeping the string computed so far.
    Why do we need stack for string computed so far?
             ->We need to maintain ordering of nexted levels. For example, consider: 3[a2[b[2[c]]]. We need to maintain a, b on the stack and remember that
             3 and 2 corresponded to them.
    Maintain the current string in res variable and create it based on the top of the integer stack.
   Reset res to be the top of the strings stack plus the current string.
   For example:
   3[a2[b[2[c]]]
   ss: a,         is: 3
   ss: a, b,      is: 3, 2
   res: c
   res: cc
   bccbcc
   ss: a          is: 3
   abccbccabccbccabccbcc
    */

string decodeString(string s) {
    

    stack<int> is; //integer stack for all the counts
    stack<string> ss; //string stack for the accumulated string computed so far

    string res=""; //resulting string
    int i = 0;
    while(i < s.size()){
        char c = s[i];

        if (isdigit(c)) {
            int num = 0;
            while (isdigit(s[i])) {
                int digit = s[i] - '0';
                num = num * 10 + digit;
                ++i;
            }
            is.push(num);
        }
        //"3[a]2[bc], 3[a2[c]]

        // 3[a2[b[2[c]]]
        //      abccbccabccbccabccbcc
        else if (c == '[') {
            ss.push(res);
            res = "";          
            ++i;
        }
        else if (c == ']') {
            string temp = "";
            int k = is.top(); is.pop();
            for (int i = 0; i < k; ++i) {
                temp += res;
            }
            string soFar = ss.top(); ss.pop();
            res = soFar + temp;
            ++i;
        }
        else { //letter
            res += c;
            ++i;
        }
    }
    return res;
}


void main() {
    cout << decodeString("3[a]2[bc]") << endl; ///aaabcbc
    cout << decodeString("3[a2[c]]") << endl; //accaccacc
    system("PAUSE");
}
