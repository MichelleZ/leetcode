#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
# Author: Miao Zhang
# Date:   2021-04-21

class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        res = []
        dic = collections.defaultdict(list)
        for i, x in enumerate(groupSizes):
            dic[x].append(i)
            if len(dic[x]) == x:
                res.append(dic[x])
                dic[x] = []
        return res
