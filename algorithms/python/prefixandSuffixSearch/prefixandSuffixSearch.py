#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/prefix-and-suffix-search/
# Author: Miao Zhang
# Date:   2021-03-06

class WordFilter:

    def __init__(self, words: List[str]):
        self.filters = {}
        index = 0
        for word in words:
            n = len(word)
            prefixes = [""] * (n + 1)
            suffixes = [""] * (n + 1)
            for i in range(n):
                prefixes[i + 1] = prefixes[i] + word[i]
                suffixes[i + 1] = word[n - i - 1] + suffixes[i]
            for prefix in prefixes:
                for suffix in suffixes:
                    self.filters[prefix + '_' + suffix] = index
            index += 1

    def f(self, prefix: str, suffix: str) -> int:
        key = prefix + '_' + suffix
        if key in self.filters:
            return self.filters[key]
        return - 1


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)
