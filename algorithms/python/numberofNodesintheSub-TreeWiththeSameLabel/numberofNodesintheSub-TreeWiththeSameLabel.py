#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
# Author: Miao Zhang
# Date:   2021-05-13

class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        g = [[] for _ in range(n)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        seen = [0] * n
        cnt = [0] * 26
        res = [0] * n
        
        def postOrder(i):
            if seen[i]: return
            seen[i] = 1
            before = cnt[ord(labels[i]) - ord('a')]
            for j in g[i]:
                postOrder(j)
            cnt[ord(labels[i]) - ord('a')] += 1
            res[i] = cnt[ord(labels[i]) - ord('a')] - before
        
        postOrder(0)
        return res
