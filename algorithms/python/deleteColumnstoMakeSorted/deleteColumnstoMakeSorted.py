#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/delete-columns-to-make-sorted/
# Author: Miao Zhang
# Date:   2021-03-27

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        res = 0
        for j in range(len(strs[0])):
            for i in range(1, len(strs)):
                if strs[i][j] < strs[i - 1][j]:
                    res += 1
                    break
        return res
