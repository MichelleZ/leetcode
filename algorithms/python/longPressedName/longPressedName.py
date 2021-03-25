#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/long-pressed-name/
# Author: Miao Zhang
# Date:   2021-03-25

class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        i = j = 0
        while i < len(name) and j < len(typed):
            if name[i] == typed[j]:
                i += 1
                j += 1
            elif j > 0 and typed[j] == typed[j - 1]:
                j += 1
            else:
                return False
        while j < len(typed) and typed[j] == typed[j - 1]: j += 1
        return i == len(name) and j == len(typed)
