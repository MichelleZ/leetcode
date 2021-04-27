#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/rank-teams-by-votes/
# Author: Miao Zhang
# Date:   2021-04-27

class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        rank = {v: [0] * len(votes[0]) for v in votes[0]}
        for v in votes:
            for i, c in enumerate(v):
                rank[c][i] -= 1
        res = list(votes[0])
        res.sort(key=lambda x: (rank[x], x))
        return ''.join(res)
