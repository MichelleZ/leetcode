#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/implement-strstr/
# Author: Miao Zhang
# Date:   2021-01-07

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)
