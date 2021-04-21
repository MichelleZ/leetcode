#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
# Author: Miao Zhang
# Date:   2021-04-21

class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        res = [0 for _ in range(len(arr))]
        res[-1] = -1
        for i in range(len(arr) - 2, -1, -1):
            res[i] = max(res[i + 1], arr[i + 1])
        return res
