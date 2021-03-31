#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/interval-list-intersections/
# Author: Miao Zhang
# Date:   2021-03-31

class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        res = []
        i = j = 0
        while i < len(firstList) and j < len(secondList):
            s = max(firstList[i][0], secondList[j][0])
            e = min(firstList[i][1], secondList[j][1])
            if s <= e: res.append([s, e])
            if firstList[i][1] < secondList[j][1]:
                i += 1
            else:
                j += 1
        return res
