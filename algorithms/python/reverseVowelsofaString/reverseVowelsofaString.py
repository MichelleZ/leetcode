#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reverse-vowels-of-a-string/
# Author: Miao Zhang
# Date:   2021-02-03

class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = 'aeiouAEIOU'
        lists = list(s)
        i = 0;
        j = len(lists) - 1
        while i < j:
            while s[i] not in vowels and i < j: 
                i += 1
            while s[j] not in vowels and i < j:
                j -= 1
            lists[i], lists[j] = lists[j], lists[i]
            i += 1
            j -= 1
        return ''.join(lists)
