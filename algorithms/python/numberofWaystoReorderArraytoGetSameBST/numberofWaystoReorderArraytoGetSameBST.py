#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/
# Author: Miao Zhang
# Date:   2021-05-16

class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        n = len(nums)
        kMod = 10 ** 9 + 7
        cnk = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
        for i in range(n + 1):
            for j in range(i + 1):
                if j == 0: 
                    cnk[i][j] = 1
                else:
                    cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % kMod
        
        def trees(nums: List[int]) -> int:
            n = len(nums)
            if n <= 2: return 1
            left = []
            right = []
            for i in range(1, len(nums)):
                if nums[i] < nums[0]:
                    left.append(nums[i])
                else:
                    right.append(nums[i])
            res = cnk[n - 1][len(left)]
            res = (res * trees(left)) % kMod
            res = (res * trees(right)) % kMod
            return int(res)

        return trees(nums) - 1
