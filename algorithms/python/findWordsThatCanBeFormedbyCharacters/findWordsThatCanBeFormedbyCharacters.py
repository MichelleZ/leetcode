#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
# Author: Miao Zhang
# Date:   2021-04-13

class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        cnt = collections.Counter(chars)
        res = 0
        for word in words:
            wcnt = collections.Counter(word)
            for c in wcnt:
                if wcnt[c] > cnt[c]:
                    break
            else:
                res += len(word)
        return res
