#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/
# Author: Miao Zhang
# Date:   2021-04-02

class Solution:
    def queryString(self, S: str, N: int) -> bool:
        for x in range(1, N + 1):
            if S.find("{0:b}".format(x)) == -1:
                return False
        return True
