// Source: https://leetcode.com/problems/can-place-flowers/
// Author: Miao Zhang
// Date:   2021-02-24

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        int size = flowerbed.size();
        int res = 0;
        for (int i = 1; i < size - 1; i++) {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                res++;
            }
        }
        return res >= n;
    }
};
