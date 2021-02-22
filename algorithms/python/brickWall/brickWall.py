#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/brick-wall/
# Author: Miao Zhang
# Date:   2021-02-22

class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        res = 0
        dic = collections.defaultdict(int)
        for row in wall:
            sums = 0
            for i in range(len(row) - 1):
                sums += row[i]
                dic[sums] += 1
                res = max(res, dic[sums])
        return len(wall) - res
