#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/rearrange-spaces-between-words/
# Author: Miao Zhang
# Date:   2021-05-19

class Solution:
    def reorderSpaces(self, text: str) -> str:
        spaces = text.count(' ')
        words = text.strip().split()
        if len(words) == 1:
            return words[0] + ' ' * spaces
        interval, remain = divmod(spaces, len(words) - 1)
        return (' ' * interval).join(words) + ' ' * remain
