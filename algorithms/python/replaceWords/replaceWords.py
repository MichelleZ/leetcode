#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/replace-words/
# Author: Miao Zhang
# Date:   2021-02-26

class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        rootset = set(dictionary)
        def replace(word: str) -> str:
            for i in range(len(word)):
                if word[:i] in rootset:
                    return word[:i]
            return word

        return ' '.join(list(map(replace, sentence.split())))
