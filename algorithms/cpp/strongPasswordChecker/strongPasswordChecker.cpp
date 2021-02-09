// Source: https://leetcode.com/problems/strong-password-checker/
// Author: Miao Zhang
// Date:   2021-02-09

class Solution {
public:
    int strongPasswordChecker(string password) {
        int res = 0;
        int n = password.size();
        int lower = 1;
        int upper = 1;
        int digit = 1;
        vector<int> v(n, 0);
        for (int i = 0; i < n;) {
            if (password[i] >= 'a' && password[i] <= 'z') lower = 0;
            if (password[i] >= 'A' && password[i] <= 'Z') upper = 0;
            if (password[i] >= '0' && password[i] <= '9') digit = 0;
            int j = i;
            while (i < n && password[i] == password[j]) ++i;
            v[j] = i - j;
        }
        int missing = (lower + upper + digit);
        if (n < 6) {
            int diff = 6 - n;
            res += diff + max(0, missing - diff);
        } else {
            int over = max(n - 20, 0);
            int left = 0;
            res += over;
            for (int k = 1; k < 3; k++) {
                for (int i = 0; i < n && over > 0; i++) {
                    if (v[i] < 3 || v[i] % 3 != (k - 1)) continue;
                    v[i] -= min(over, k);
                    over -= k;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (v[i] >= 3 && over > 0) {
                    int need = v[i] - 2;
                    v[i] -= over;
                    over -= need;
                }
                if (v[i] >= 3) left += v[i] / 3;
            }
            res += max(missing, left);
        }
        return res;
    }
};
