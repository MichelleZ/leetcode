// Source: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/
// Author: Miao Zhang
// Date:   2021-04-21

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        vector<int> myBoxes(status.size());
        vector<int> myKeys(status);
        for (int b: initialBoxes) {
            myBoxes[b] = 1;
            if (myKeys[b])
                q.push(b);
        }
        int res = 0;
        while (!q.empty()) {
            int b = q.front();
            q.pop();
            res += candies[b];
            for (int c: containedBoxes[b]) {
                myBoxes[c] = 1;
                if (myKeys[c])
                    q.push(c);
            }
            for (int k: keys[b]) {
                if (!myKeys[k] && myBoxes[k])
                    q.push(k);
                myKeys[k] = 1;
            }
        }
        return res;
    }
};
