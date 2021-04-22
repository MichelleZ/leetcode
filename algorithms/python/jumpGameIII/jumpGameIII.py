#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/jump-game-iii/
# Author: Miao Zhang
# Date:   2021-04-22

class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        visited = set()
        q = collections.deque()
        q.append(start)
        visited.add(start)
        while q:
            cur = q.popleft()
            if arr[cur] == 0:
                return True
            for i in [-1, 1]:
                nxt = cur + i * arr[cur]
                if nxt < 0 or nxt >= len(arr) or nxt in visited:
                    continue
                visited.add(nxt)
                q.append(nxt)
        return False
