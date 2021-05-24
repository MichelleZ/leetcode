// Source: https://leetcode.com/problems/slowest-key/
// Author: Miao Zhang
// Date:   2021-05-24

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        char c = ' ';
        int maxtime = 0;
        for (int i = 0; i < n; i++) {
            char k = keysPressed[i];
            int time = releaseTimes[i] - (i > 0 ? releaseTimes[i - 1] : 0);
            if (maxtime < time || (maxtime == time && k > c)) {
                maxtime = time;
                c = k;
            }
        }
        return c;
    }
};
