#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/largest-component-size-by-common-factor/
# Author: Miao Zhang
# Date:   2021-03-28

class DSU:
    def __init__(self, n):
        self.root = [i for i in range(n)]
    
    def union(self, x, y):
        self.root[self.find(x)] = self.find(y)
    
    def find(self, x):
        if self.root[x] != x:
            self.root[x] = self.find(self.root[x])
        return self.root[x]
    
    
class Solution:
    def largestComponentSize(self, A: List[int]) -> int:
        n = max(A)
        uf = DSU(n + 1)
        for a in A:
            for k in range(2, int(sqrt(a)) + 1):
                if a % k == 0:
                    uf.union(a, k)
                    uf.union(a, a // k)
        
        cnt = collections.Counter()
        for a in A:
            cnt[uf.find(a)] += 1
        return cnt.most_common()[0][1]
