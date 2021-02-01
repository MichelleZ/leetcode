// Source: https://leetcode.com/problems/additive-number/
// Author: Miao Zhang
// Date:   2021-02-01

class Solution {
public:
    bool isAdditiveNumber(string num) {
        vector<long long> path;
        long_max = to_string(LLONG_MAX);
        return dfs(num, 0, num.size(), path);
    }

private:
    string long_max;
    bool isValid(vector<long long> &path) {
        if (path.size() < 3) return false;
        for (int i = 2; i < path.size(); i++) {
            long long a = path[i - 2];
            long long b = path[i - 1];
            long long c = path[i];
            if (a + b != c) return false;
        }
        return true;
    }
    
    bool dfs(string &s, int start, int n, vector<long long> &path) {
        if (start == n) {
            return isValid(path);
        }
        for (int i = 1; i <= n - start; i++) {
            if (s[start] == '0' && i > 1) break;
            string cur = s.substr(start, i);
            if (cur.size() > long_max.size() || cur.size() == long_max.size() && cur.compare(long_max) > 0) break;
            path.push_back(stoll(cur));
            if ((path.size() > 2 && !isValid(path)) || !dfs(s, start + i, n, path)) {
                path.pop_back();;
            } else {
                return true;
            }
        }
        return false;
    }
};
