#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/delete-columns-to-make-sorted-ii/
# Author: Miao Zhang
# Date:   2021-03-28

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        cuts = [False] * (len(strs) - 1)

        res = 0
        for col in zip(*strs):
            if all(cuts[i] or col[i] <= col[i + 1] for i in range(len(col) - 1)):
                for i in range(len(col) - 1):
                    if col[i] < col[i + 1]:
                        cuts[i] = True
            else:
                res += 1
        return res
