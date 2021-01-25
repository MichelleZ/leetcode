// Source: https://leetcode.com/problems/happy-number/
// Author: Miao Zhang
// Date:   2021-01-25

class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        while (st.find(n) == st.end()) {
            st.insert(n);
            int num = 0;
            while (n != 0) {
                int digit = n % 10;
                num += digit * digit;
                n /= 10;
            }
            n = num;
        }
        return n == 1;
    }
};
