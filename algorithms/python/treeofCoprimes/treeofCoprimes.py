#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/tree-of-coprimes/
# Author: Miao Zhang
# Date:   2021-06-04

class Solution:
    def getCoprimes(self, nums: List[int], edges: List[List[int]]) -> List[int]:
        g = collections.defaultdict(list)
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        # value, nodeid, level
        ancestor = []
        res = [-1] * len(nums)
        
        coprime = [[0 for _ in range(51)] for _ in range(51)]
        for i in range(1, 51):
            for j in range(1, 51):
                if math.gcd(i, j) == 1: coprime[i][j] = 1
        
        def dfs(node, parent, depth):
            closestp = -1
            distance = float('inf')
            for v, p, d in ancestor:
                if coprime[nums[node]][v] and depth - d < distance:
                    distance = depth - d
                    closestp = p
            res[node] = closestp
            ancestor.append([nums[node], node, depth])
            for nxt in g[node]:
                if nxt == parent: continue
                dfs(nxt, node, depth + 1)
            ancestor.pop()
        dfs(0, -1, 0)
        return res
        
