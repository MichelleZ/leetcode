#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-height-trees/
# Author: Miao Zhang
# Date:   2021-02-01

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        '''
        leaves[u] = v: v->u
        remove leaf nodes
        '''
        from collections import defaultdict
        from collections import deque
        if n == 1 and len(edges) == 0: return [0]
		leaves = defaultdict(set)
        for u, v in edges:
            leaves[u].add(v)
            leaves[v].add(u)
        q = deque()
        for u, v in leaves.items():
            if len(v) == 1:
                q.append(u)
        while n > 2:
            n -= len(q)
            for _ in range(len(q)):
                u = q.popleft()
                for v in leaves[u]:
                    leaves[v].remove(u)
                    if len(leaves[v]) == 1:
                        q.append(v)
        return list(q)
