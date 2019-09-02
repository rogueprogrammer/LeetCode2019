#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;


vector<pair<int, int>> optimalUtilization(int maxTravelDistance, vector<pair<int, int>> forwardRouteList, vector<pair<int, int>>
        returnRouteList){
        //to do: implement sort function for forwardRouteList and
returnRouteList to sort them in descending order to make runtime
O(nlogn)
        unordered_map<int, int> forward;
        unordered_map<int, int> reverse;
        for (pair<int, int> f : forwardRouteList){
                forward[f.first] = f.second;
        }
        for (pair<int, int> r : returnRouteList){
                reverse[r.first] = r.second;
        }

        int i = 0;

        vector<pair<int, int>> res;
        for (; i < forwardRouteList.size(); ++i){
                int j = 0;
                for (; j < returnRouteList.size(); ++j){
                        pair<int, int> f = forwardRouteList[i];
                        pair<int, int> r = returnRouteList[j];
                        if (f.second + r.second <= maxTravelDistance){
                                if (res.size() == 0){
                                        res.push_back(make_pair(f.first, r.first));
                                }
                                else{
                                        int res_f_dist = forward[res[0].first];
                                        int res_r_dist = reverse[res[0].second];
                                        if (f.second + r.second > res_f_dist + res_r_dist){
                                                while (res.size() > 0 && f.second + r.second > res_f_dist + res_r_dist){
                                                        res.pop_back();
                                                        if (res.size() > 0){
                                                                res_f_dist = forward[res[0].first];
                                                                res_r_dist = reverse[res[0].second];
                                                        }
                                                }
                                                res.push_back(make_pair(f.first, r.first));
                                        }
                                        else if (f.second + r.second == res_f_dist + res_r_dist){
                                                res.push_back(make_pair(f.first, r.first));
                                        }
                                }
                        }
                        else{
                                break;
                        }
                }
        }
        return res;
}

//https://leetcode.com/discuss/interview-question/318918/Amazon-or-Online-Assessment-2019-or-Optimal-Aircraft-Utilization
int main() {
        int maxTravelDist = 7000;
        vector<pair<int, int>> forwardRouteList = { { 1, 2000 }, { 2, 4000 },
        { 3, 6000 } };
        vector<pair<int, int>> returnRouteList = { { 1, 2000 } };
        int maxTravelDist = 10000;
        vector<pair<int, int>> forwardRouteList = { { 1, 3000 }, { 2, 5000 },
        { 3, 7000 }, { 4, 10000 } };
        vector<pair<int, int>> returnRouteList = { { 1, 2000 }, { 2, 3000 },
{ 3, 4000 }, { 4, 5000 } };
        vector<pair<int, int>> res = optimalUtilization(maxTravelDist,
                forwardRouteList, returnRouteList);
        for (pair<int, int> p : res){
                cout << p.first << " , " << p.second << endl;
        }
}
