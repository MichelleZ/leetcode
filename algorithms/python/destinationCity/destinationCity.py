#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/destination-city/
# Author: Miao Zhang
# Date:   2021-05-06

class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        ind = collections.defaultdict(int)
        out = collections.defaultdict(int)
        for u, v in paths:
            ind[v] += 1
            out[u] += 1
        for city, val in ind.items():
            if val == 1 and out[city] == 0:
                return city
        return ''
