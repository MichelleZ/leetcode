#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/all-paths-from-source-to-target/
# Author: Miao Zhang
# Date:   2021-03-11

class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        res = []
        self.dfs(graph, [0], res)
        return res
    
    def dfs(self, graph: List[List[int]], path: List[int], res: List[List[int]]) -> None:
        if path[-1] == len(graph) - 1:
            res.append(path)
            return
        
        for nxt in graph[path[-1]]:
            self.dfs(graph, path + [nxt], res)
