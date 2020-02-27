//https://leetcode.com/problems/find-duplicate-file-in-system/submissions/
class Solution {
public:

    /*
		  1. Create HT: <file_content> -> <vector of files with that content>
		  2. Iterate through HT. For each index, return all list of files with len > 1
	  */
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> ht;
        for (auto path : paths) {
            stringstream ss(path);
            string dir;
            string file;
            string fileContents;
            getline(ss, dir, ' ');
            dir += '/'; 
            while (getline(ss, file, '(')) {
                if (file[0] == ' ') {
                    file = file.substr(1, file.size() - 1);
                }
                getline(ss, fileContents, ')');
                string pathPlusFile = dir + file;
                ht[fileContents].push_back(pathPlusFile); file = "";
            }
        }

        for (auto it = ht.begin(); it != ht.end(); ++it) {
            if (it->second.size() > 1) {
                res.push_back(it->second);
            }
        }
		    return res;
	  }
};
