// Source: https://leetcode.com/problems/maximum-value-after-insertion/
// Author: Miao Zhang
// Date:   2021-06-16

class Solution {
public:
    string maxValue(string n, int x) {
        int l = n.length();
        if (n[0] != '-') {
            for (int i = 0; i < l; i++) {
                if (n[i] - '0'  < x) {
                    n.insert(i, 1, '0' + x);
                    return n;
                }
            }
            n.push_back(x + '0');
                return n;
        } else {
            for (int i = 1; i < l; ++i){
                if (n[i] - '0' > x){
                    n.insert(i, 1, '0' + x);
                    return n;
                }
            }
            n.push_back('0' + x);
            return n;
        }
        return "";
    }
};
