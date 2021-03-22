#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/groups-of-special-equivalent-strings/
# Author: Miao Zhang
# Date:   2021-03-22

class Solution:
    def numSpecialEquivGroups(self, A: List[str]) -> int:
        return len(set([''.join(sorted(a[0::2]) + sorted(a[1::2])) for a in A]))
