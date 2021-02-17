#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/construct-the-rectangle/
# Author: Miao Zhang
# Date:   2021-02-17

class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        for w in range(int(math.sqrt(area)), -1, -1):
            if area % w == 0:
                return [area // w, w]
