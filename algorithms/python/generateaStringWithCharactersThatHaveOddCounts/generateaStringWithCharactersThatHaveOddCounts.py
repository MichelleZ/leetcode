#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/
# Author: Miao Zhang
# Date:   2021-04-27

class Solution:
    def generateTheString(self, n: int) -> str:
        if n % 2:
            return 'a' * n
        return 'a' * (n - 1) + 'b'
