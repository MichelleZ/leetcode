#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-of-smaller-numbers-after-self/
# Author: Miao Zhang
# Date:   2021-02-01

class BinaryIndexTree:
    def __init__(self, n: int):
        self._nums = [0 for _ in range(n + 1)]
    
    def update(self, i: int, delta: int) -> None:
        while i < len(self._nums):
            self._nums[i] += delta
            i += i & (-i)
    
    def query(self, i: int) -> int:
        sum = 0
        while i > 0:
            sum += self._nums[i]
            i -= i & (-i)
        return sum

    
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        from collections import defaultdict
        sort = sorted(list(set(nums)))
        ranks = defaultdict(int)
        rank = 0
        for num in sort:
            rank += 1
            ranks[num] = rank

        res = []
        tree = BinaryIndexTree(len(ranks))
        for i in range(len(nums) - 1, -1, -1):
            res.append(tree.query(ranks[nums[i]] - 1))
            tree.update(ranks[nums[i]], 1)
        
        res.reverse()
        return res
