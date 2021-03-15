// Source: https://leetcode.com/problems/friends-of-appropriate-ages/
// Author: Miao Zhang
// Date:   2021-03-15

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int kMaxAge = 200;
        vector<int> cnts(kMaxAge + 1, 0);
        for (const int age: ages) cnts[age]++;
        int res = 0;
        for (int A = 1; A <= kMaxAge; A++) {
            for (int B = 0.5 * A + 7 + 1; B <= A; B++) {
                res += cnts[A] * (cnts[B] - (A == B));
            }
        }
        return res;
    }
};
