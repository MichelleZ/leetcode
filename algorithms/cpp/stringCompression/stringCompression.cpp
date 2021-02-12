// Source: https://leetcode.com/problems/string-compression/
// Author: Miao Zhang
// Date:   2021-02-12

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int j = 0;
        for (int i = 1; i <=n; i++) {
            int cnt = 1;
            while (i < n && chars[i] == chars[i - 1]) {
                i++;
                cnt++;
            }
            chars[j++] = chars[i - 1];
            if (cnt == 1) continue;
            for (char c: to_string(cnt)) {
                chars[j++] = c;
            }
        }
        return j;
    }
};
