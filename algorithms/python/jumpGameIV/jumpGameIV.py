#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/jump-game-iv/
# Author: Miao Zhang
# Date:   2021-04-25

class Solution:
    def minJumps(self, arr: List[int]) -> int:
        n = len(arr)
        m = collections.defaultdict(list)
        for i in range(n):
            m[arr[i]].append(i)
        q = collections.deque()
        q.append(0)
        seen = [0 for _ in range(n)]
        seen[0] = 1
        steps = 0
        while q:
            qlen = len(q)
            for _ in range(qlen):
                cur = q.popleft()
                if cur == n - 1: return steps
                if cur - 1 >= 0 and not seen[cur - 1]: 
                    q.append(cur - 1)
                    seen[cur - 1] = 1
                if cur + 1 < n and not seen[cur + 1]: 
                    q.append(cur + 1)
                    seen[cur + 1] = 1
                if arr[cur] not in m:
                    continue
                for nxt in m[arr[cur]]:
                    if not seen[nxt]:
                        seen[nxt] = 1
                        q.append(nxt)
                m.pop(arr[cur])
            steps += 1
        return -1
