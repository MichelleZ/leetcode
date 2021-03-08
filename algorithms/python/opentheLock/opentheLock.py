#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/open-the-lock/
# Author: Miao Zhang
# Date:   2021-03-07

class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        deadends = set(deadends)
        if '0000' in deadends: return -1
        q = collections.deque()
        q.append(['0000', 0])
        cnt = 0
        while q:
            node, cnt = q.popleft()
            if node == target: return cnt
            for i in range(4):
                for j in [1, -1]:
                    next_node = node[:i] + str((int(node[i]) + j) % 10) + node[i + 1:]
                    if next_node not in deadends:
                        deadends.add(next_node)
                        q.append([next_node, cnt + 1])
        return -1
