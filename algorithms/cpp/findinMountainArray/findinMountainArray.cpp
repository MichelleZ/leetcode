// Source: https://leetcode.com/problems/find-in-mountain-array/
// Author: Miao Zhang
// Date:   2021-04-08

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        auto binary_search = [&](int l, int r, function<bool(int)> cond) {
            while (l < r) {
                int m = l + (r - l) / 2;
                if (cond(m)) r = m;
                else l = m + 1;
            }  
            return l;
        };
    
        int n = mountainArr.length();
        int p = binary_search(0, n - 1, [&](int i) -> bool {
            return mountainArr.get(i) > mountainArr.get(i + 1);
        });    
        int l = binary_search(0, p, [&](int i) -> bool {
            return mountainArr.get(i) >= target;
        });
        if (mountainArr.get(l) == target) return l;
        int r = binary_search(p, n - 1, [&](int i) -> bool {
            return mountainArr.get(i) <= target;
        });        
        if (mountainArr.get(r) == target) return r;
        return -1;
    }
};
