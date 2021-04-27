#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/validate-binary-tree-nodes/
# Author: Miao Zhang
# Date:   2021-04-26

class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        indegrees = [0 for _ in range(n)]
        for l in leftChild:
            if l >= 0:
                indegrees[l] += 1
        for r in rightChild:
            if r >= 0:
                indegrees[r] += 1
        zeros = 0
        root = -1
        for i, d in enumerate(indegrees):
            # indegrees is 1
            if d > 1: return False
            # root node
            if d == 0:
                root = i
                zeros += 1
        if zeros > 1: return False
        # circle
        visited = set()
        q = collections.deque()
        q.append(root)
        visited.add(root)
        while q:
            cur = q.popleft()
            if leftChild[cur] != -1 and leftChild[cur] not in visited:
                q.append(leftChild[cur])
                visited.add(leftChild[cur])
            if rightChild[cur] != -1 and rightChild[cur] not in visited:
                q.append(rightChild[cur])
                visited.add(rightChild[cur])
        return len(visited) == n
