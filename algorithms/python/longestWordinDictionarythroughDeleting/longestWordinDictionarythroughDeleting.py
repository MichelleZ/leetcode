#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
# Author: Miao Zhang
# Date:   2021-02-20

class Solution:
    def findLongestWord(self, s: str, d: List[str]) -> str:
        res = ''
        for dc in d:
            i = 0
            for sc in s:
                if i < len(dc) and sc == dc[i]: i+= 1
            if i == len(dc) and len(dc) >= len(res):
                if len(dc) > len(res) or dc < res:
                    res = dc
        return res
