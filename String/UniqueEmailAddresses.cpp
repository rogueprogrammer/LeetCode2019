//https://leetcode.com/problems/unique-email-addresses/

string removeChar(string str, char ch){
        string res="";
        for(auto c : str){
            if(c != ch) res += c;
        }
        return res;
    }

int numUniqueEmails(vector<string>& emails) {
        int numEmails = 0;
        unordered_set<string> ht;
        for(int i = 0; i < emails.size(); ++i){
            string email = emails[i];
            int atPosn = email.find('@');
            string hostname = email.substr(0, atPosn);
            hostname = removeChar(hostname, '.');
            cout << hostname << endl;
            string domain = email.substr(atPosn+1, email.size()-atPosn+1);
            cout << domain << endl;
            int posnPl = hostname.find('+');
            if(posnPl >= 0){
                string newHostname= hostname.substr(0, posnPl);
                hostname = newHostname;
                cout << hostname << endl;
            }
            email = hostname;
            email += "@";
            email += domain;
            
            auto it = ht.find(email);
            if(it == ht.end()){ //not in hashtable
                ht.insert(email);
                ++numEmails;
            }
        }
        return numEmails;
    }
