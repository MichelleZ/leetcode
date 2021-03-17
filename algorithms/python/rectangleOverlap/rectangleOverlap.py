#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/rectangle-overlap/
# Author: Miao Zhang
# Date:   2021-03-16

class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        if rec1[0] == rec1[2] or rec1[1] == rec1[3] or \
            rec2[0] == rec2[2] or rec2[1] == rec2[3]:
            return False
        
        return rec1[0] < rec2[2] and rec1[1] < rec2[3] and \
               rec2[0] < rec1[2] and rec2[1] < rec1[3]
