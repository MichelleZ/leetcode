#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/dota2-senate/
# Author: Miao Zhang
# Date:   2021-02-26

class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        n = len(senate)
        radiant = collections.deque()
        dire = collections.deque()
        for i, v in enumerate(senate):
            if v == 'R':
                radiant.append(i)
            else:
                dire.append(i)
        while radiant and dire:
            if radiant[0] < dire[0]:
                radiant.append(radiant[0] + n)
            else:
                dire.append(dire[0] + n)
            radiant.popleft()
            dire.popleft()
        return 'Radiant' if radiant else 'Dire'
