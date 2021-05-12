#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/
# Author: Miao Zhang
# Date:   2021-05-12

class BIT:
    def __init__(self, n: int) -> None:
        self.sums = [0] * (n + 1)
    
    def update(self, i: int, delta: int) -> None:
        i += 1
        while i < len(self.sums):
            self.sums[i] += delta
            i += i & -i
    
    def query(self, i: int) -> int:
        i += 1
        res = 0
        while i > 0:
            res += self.sums[i]
            i -= i & -i
        return res
            
            
class Solution:
    def minInteger(self, num: str, k: int) -> str:
        n = len(num)
        pos = [[] for _ in range(10)]
        for i in range(n):
            pos[int(num[i])].append(i)
        
        tree = BIT(n)
        seen = [0] * n
        res = ''
        while k > 0 and len(res) < n:
            for d in range(10):
                if not pos[d]: continue
                i = pos[d][0]
                cost = i - tree.query(i - 1)
                if cost > k: continue
                k -= cost
                res += str(d)
                tree.update(i, 1)
                seen[i] = 1
                pos[d].pop(0)
                break
        for i in range(n):
            if not seen[i]:
                res += str(num[i])
        return res
