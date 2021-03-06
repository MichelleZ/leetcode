#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-smallest-letter-greater-than-target/
# Author: Miao Zhang
# Date:   2021-03-06

class Solution(object):
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """
        for l in letters:
            if l > target: return l
        return letters[0]
        
