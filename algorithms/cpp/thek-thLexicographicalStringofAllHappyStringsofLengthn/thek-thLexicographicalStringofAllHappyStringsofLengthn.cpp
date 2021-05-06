// Source: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
// Author: Miao Zhang
// Date:   2021-05-06

class Solution {
public:
    string getHappyString(int n, int k) {
        string res;
        string cur;
        function<void()> dfs = [&] (){
            if (k <= 0) return;
            if (cur.length() == n) {
                if (--k == 0) res = cur;
                return;
            }
            for (char c = 'a'; c <= 'c'; c++) {
                if (!cur.empty() && cur.back() == c) continue;
                cur.push_back(c);
                dfs();
                cur.pop_back();
            }
        };
        dfs();
        return k > 0 ? "" : res;
    }
};
