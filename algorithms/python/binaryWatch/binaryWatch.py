#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/binary-watch/
# Author: Miao Zhang
# Date:   2021-02-08

class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
        res = []
        for hour in range(12):
            for minute in range(60):
                if (bin(hour) + bin(minute)).count('1') == num:
                    res.extend(["%d:%02d" % (hour, minute)])
        return res
