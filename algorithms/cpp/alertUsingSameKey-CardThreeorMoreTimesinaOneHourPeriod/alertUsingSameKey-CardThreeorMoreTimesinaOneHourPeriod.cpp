// Source: https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/
// Author: Miao Zhang
// Date:   2021-05-20

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> m;
        for (int i = 0; i < keyName.size(); i++) {
            int h = stoi(keyTime[i].substr(0, 2));
            int min = stoi(keyTime[i].substr(3));
            m[keyName[i]].push_back(h * 60 + min);
        }
        vector<string> res;
        for (auto& [name, times]: m) {
            sort(begin(times), end(times));
            for (int i = 2; i < times.size(); i++) {
                if (times[i] - times[i - 2] <= 60) {
                    res.push_back(name);
                    break;
                }
            }
        }
        sort(begin(res), end(res));
        return res;
    }
};
