// Source: https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/
// Author: Miao Zhang
// Date:   2021-06-11

class Solution {
public:
    int getMinSwaps(string num, int k) {
        string numk = num;
        for (int i = 0; i < k; i++) nextPermutation(num);
        int n = num.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (num[i] != numk[i]) {
                for (int j = i + 1; j < n; j++) {
                    if (numk[i] == num[j]) {
                        for (int k = j - 1; k >= i; k--) {
                            swap(num[k], num[k + 1]);
                            res++;
                        }
                        break;
                    }
                }
            }
        }
        return res;
    }

private:
    void nextPermutation(string& num) {
        int i = num.length() - 2;
        while (i >= 0 && num[i] >= num[i + 1])
            i--;
        if (i < 0) return sort(begin(num), end(num));
        int j = num.size() - 1;
        while (j >= 0 and num[i] >= num[j])
                j--;
        swap(num[i], num[j]);
        sort(num.begin() + i + 1, num.end());
    }
};
