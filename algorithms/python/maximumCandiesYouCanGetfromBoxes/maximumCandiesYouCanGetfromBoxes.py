#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/
# Author: Miao Zhang
# Date:   2021-04-21

class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        q = collections.deque()
        myBoxes = [0 for _ in range(len(status))]
        myKeys = status[:]
        for b in initialBoxes:
            myBoxes[b] = 1
            if myKeys[b]:
                q.append(b)
        res = 0
        while q:
            b = q.popleft()
            res += candies[b]
            for c in containedBoxes[b]:
                myBoxes[c] = 1
                if myKeys[c]:
                    q.append(c)
            for k in keys[b]:
                if not myKeys[k] and myBoxes[k]:
                    q.append(k)
                myKeys[k] = 1

        return res
