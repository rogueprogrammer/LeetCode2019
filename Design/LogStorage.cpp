//https://leetcode.com/problems/design-log-storage-system/submissions/

class LogSystem {
public:
    LogSystem() {  
    }
    map<string, int> m; //timestamp -> id
    void put(int id, string timestamp) {
        m[timestamp] = id;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        
        if(gra == "Year"){
            s = s.substr(0, 4) + ":01:01:00:00:00";
            e = e.substr(0, 4) + ":12:31:23:59:59";
        } else if(gra == "Month"){
            s = s.substr(0, 7) + ":01:00:00:00";
            e = e.substr(0, 7) + ":31:23:59:59";
        } else if (gra == "Day"){
            s = s.substr(0, 10) + ":00:00:00";
            e = e.substr(0, 10) + ":23:59:59";
        } else if (gra == "Hour"){
            s = s.substr(0, 13) + ":00:00";
            e = e.substr(0, 13) + ":59:59";
        } else if (gra == "Minute"){
            s = s.substr(0, 16) + ":00";
            e = e.substr(0, 16) + ":59";
        }
        auto begin = m.lower_bound(s);
        auto end = m.upper_bound(e);
        vector<int> ids;
        for(auto it = begin; it != end; ++it){
            ids.push_back(it->second);
        }
        return ids;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(s,e,gra);
 */
