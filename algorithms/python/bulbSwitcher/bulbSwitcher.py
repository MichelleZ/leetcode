#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/bulb-switcher/
# Author: Miao Zhang
# Date:   2021-02-02

class Solution:
    def bulbSwitch(self, n: int) -> int:
        return int(math.sqrt(n))
