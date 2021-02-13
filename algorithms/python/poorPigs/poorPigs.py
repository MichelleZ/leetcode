#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/poor-pigs/
# Author: Miao Zhang
# Date:   2021-02-13

class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        states = minutesToTest // minutesToDie + 1;
        return math.ceil(math.log(buckets) / math.log(states));
