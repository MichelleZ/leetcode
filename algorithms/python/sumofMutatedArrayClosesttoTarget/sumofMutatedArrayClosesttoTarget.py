#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
# Author: Miao Zhang
# Date:   2021-04-21

class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        arr.sort()
        n = len(arr)
        sums = [0]
        for i in range(n):
            sums.append(sums[-1] + arr[i])

        def check(num: int) -> int:
            idx = bisect.bisect_left(arr, num)
            return sums[idx] + (n - idx) * num

        l = 1
        r = max(arr) + 1
        while l < r:
            mid = l + (r - l) // 2
            if check(mid) > target:
                r = mid
            else:
                l = mid + 1
        sum1 = check(l)
        sum2 = check(l - 1)
        return l - 1 if abs(sum2 - target) <= abs(sum1 - target) else l
