#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/clone-graph/
# Author: Miao Zhang
# Date:   2021-01-20

"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None
        dicts = dict()
        q = deque()
        q.append(node)
        visited = set()
        visited.add(node)
        while q:
            n = len(q)
            for _ in range(n):
                cur_node = q.popleft()
                copy_node = Node(cur_node.val, [])
                dicts[cur_node] = copy_node
                for neighbor in cur_node.neighbors:
                    if neighbor not in visited:
                        visited.add(neighbor)
                        q.append(neighbor)
        
        for old, new in dicts.items():
            for neighbor in old.neighbors:
                new.neighbors.append(dicts[neighbor])
        return dicts[node]
