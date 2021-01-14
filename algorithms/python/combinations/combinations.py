#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/combinations/
# Author: Miao Zhang
# Date:   2021-01-14

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []
        self.dfs(range(1, n+1), k, res, [])
        return res
    
    def dfs(self, arr, k, res, path):
        if k > len(arr):
            return
        if k == 0:
            res.append(path)
            return
        for i in range(len(arr)):
            self.dfs(arr[i + 1:], k - 1, res, path + [arr[i]])
