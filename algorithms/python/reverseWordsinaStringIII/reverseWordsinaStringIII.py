#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reverse-words-in-a-string-iii/
# Author: Miao Zhang
# Date:   2021-02-22

class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.split(' ')
        for i in range(len(s)):
            s[i] = s[i][::-1]
        return ' '.join(s)

class Solution:
  def reverseWords(self, s):
    return ' '.join(map(lambda x: x[::-1], s.split(' ')))
