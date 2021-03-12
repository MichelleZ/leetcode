#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-eventual-safe-states/
# Author: Miao Zhang
# Date:   2021-03-12

from enum import Enum
class State(Enum):
    UNKNOWN  = 1
    VISITING = 2
    SAFE     = 3
    UNSAFE   = 4

    
class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        states = [State.UNKNOWN for _ in range(len(graph))]
        res = []
        for i in range(len(graph)):
            if self.dfs(graph, i, states) == State.SAFE:
                res.append(i)
        return res
    
    def dfs(self, graph: List[List[int]], cur: int, states: List[State]) -> State:
        if states[cur] == State.VISITING:
            states[cur] = State.UNSAFE
            return states[cur]
        if states[cur] != State.UNKNOWN:
            return states[cur]
        states[cur] = State.VISITING
        for nxt in graph[cur]:
            if self.dfs(graph, nxt, states) == State.UNSAFE:
                states[cur] = State.UNSAFE
                return states[cur]
        states[cur] = State.SAFE
        return states[cur]
        
