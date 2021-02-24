#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-index-sum-of-two-lists/
# Author: Miao Zhang
# Date:   2021-02-24

class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        d1, d2 = ({r: i for (i, r) in enumerate(l)} for l in (list1, list2))
        c = set(list1).intersection(list2)
        m = min(d1[x] + d2[x] for x in c)
        return [x for x in c if m == d1[x] + d2[x]]
