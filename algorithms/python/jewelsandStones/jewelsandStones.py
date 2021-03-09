#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/jewels-and-stones/
# Author: Miao Zhang
# Date:   2021-03-09

class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        j = set(jewels)
        return sum([s in j for s in stones])
