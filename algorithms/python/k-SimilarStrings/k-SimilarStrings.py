#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/k-similar-strings/
# Author: Miao Zhang
# Date:   2021-03-18

class Solution:
    def kSimilarity(self, s1: str, s2: str) -> int:
        if s1 == s2: return 0
        q = collections.deque()
        q.append(s1)
        step = 0
        visited = set()
        visited.add(s1)
        while q:
            n = len(q)
            for _ in range(n):
                s3 = q.popleft()
                i = 0
                while s3[i] == s2[i]: i += 1
                for j in range(i + 1, len(s3)):
                    if s3[j] != s2[i]: continue
                    s4 = list(s3)
                    s4[i], s4[j] = s4[j], s4[i]
                    s4 = ''.join(s4)
                    if s4 == s2: return step + 1
                    if s4 in visited: continue
                    visited.add(s4)
                    q.append(s4)
            step += 1
        return -1
        
