#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sum-of-distances-in-tree/
# Author: Miao Zhang
# Date:   2021-03-16

###############################################################################
# res[A] = sum(A) + sum(B) + cnt(B)
# res[B] = sum(B) + sum(A) + cnt(A)
# res[A] - res[B] = cnt(B) - cnt(A)
# res[A] = res[B] - cnt(A) + N - cnt(A)
###############################################################################
class Solution:
    def sumOfDistancesInTree(self, N: int, edges: List[List[int]]) -> List[int]:
        graph = collections.defaultdict(set)
        for u, v in edges:
            graph[u].add(v)
            graph[v].add(u)
        count = [1] * N
        res = [0] * N
        
        def dfs(node = 0, parent = None):
            '''
            cnt: Number of nodes with node as root node
            res: Distance of node as root node
            '''
            for child in graph[node]:
                if child != parent:
                    dfs(child, node)
                    count[node] += count[child]
                    res[node] += res[child] + count[child]
        
        def dfs2(node = 0, parent = None):
            for child in graph[node]:
                if child != parent:
                    res[child] = res[node] - count[child] + N - count[child]
                    dfs2(child, node)
        
        dfs()
        dfs2()
        return res
