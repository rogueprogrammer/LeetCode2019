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

//use combination of N-ary tree and hash table
// https://leetcode.com/problems/design-in-memory-file-system
// doesn't seem to work on OJ but compiles / runs fine locally
class FileSystem {
public:
    struct node {
        string fileName;
        bool isDirectory; //if its a directory then content is null.
        unordered_map<string, node*> children; //file name -> file
        string content;

    };
    node* root;


    FileSystem() {
        root = new node();
    }


    vector<string> splitPath(string path) {
        vector<string> res;
        string curFile = "";
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] != '/') {
                curFile += path[i];
            }
            else {
                if (i != 0) {
                    res.push_back(curFile);
                    curFile = "";
                }
            }
        }
        if (curFile != "") {
            res.push_back(curFile);
        }
        return res;
    }
    /*
      ls("/") -> null
      mkdir("/a/b/c")
      addContentToFile("/a/b/c/d", "hello")
      ls("/") -> "a"
      readContentFromFile("/a/b/c/d") -> "hello"
      ls("/a/") -> "b"
      mkdir("a/x/y")
      ls("/a/") -> "b", "x"
      need to maintain a tree like directory structure
      */


    vector<string> ls(string path) {
        vector<string> res; //all files in path
        vector<string> files = splitPath(path);
        node* cur = root;
        for (string file : files) {
            cur = cur->children[file];
        }
        for (auto i : cur->children) {
            res.push_back(i.first);
        }
        sort(res.begin(), res.end());
        return res;
    }

    void mkdir(string path) {
        node* cur = root;
        vector<string> files = splitPath(path);

        for (string curFile : files) {
            auto it = cur->children.find(curFile);
            if (it == cur->children.end()) {
                cur->children[curFile] = new node();
                cur->children[curFile]->fileName = curFile;
            }
            cur = cur->children[curFile];
        }


    }

    void addContentToFile(string filePath, string content) {
        vector<string> files = splitPath(filePath);
        node* cur = root;
        for (string curFile : files) {
            auto it = cur->children.find(curFile);
            if (it == cur->children.end()) {
                cur->children[curFile] = new node();
            }
            cur = cur->children[curFile];

        }
        cur->content += content;
        cur->isDirectory = false;
    }

    string readContentFromFile(string filePath) {
        vector<string> files = splitPath(filePath);
        node* cur = root;
        for (string curFile : files) {
            cur = cur->children[curFile];
        }
        return cur->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */



void main() {
    
    FileSystem* obj = new FileSystem();
    obj->mkdir("/a/b/c");
    obj->addContentToFile("/a/b/c/d", "hello");
    obj->ls("/");
    cout << obj->readContentFromFile("/a/b/c/d") << endl;
    system("PAUSE");
}
