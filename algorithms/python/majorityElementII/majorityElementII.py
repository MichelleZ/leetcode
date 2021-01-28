#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/majority-element-ii/
# Author: Miao Zhang
# Date:   2021-01-28

# Boyer–Moore majority vote algorithm
# pairing and counting
# > n / 3, at most two num; 3 * (> n/ 3) > 1
# pick n1 and n2, traverse nums;
# equal, c1++ or c2++; not, c1-- or c2--
# traverse and compute c1 and c2

class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        n1 = 0
        c1 = 0
        n2 = 1
        c2 = 0
        for num in nums:
            if num == n1:
                c1 += 1
            elif num == n2:
                c2 += 1
            elif c1 == 0:
                n1 = num
                c1 += 1
            elif c2 == 0:
                n2 = num
                c2 += 1
            else:
                c1 -= 1
                c2 -= 1
        
        c1 = c2 = 0
        for num in nums:
            if num == n1: c1 += 1
            if num == n2: c2 += 1
        
        res = []
        n = len(nums) // 3
        if c1 > n: res.append(n1)
        if c2 > n: res.append(n2)
        return res
