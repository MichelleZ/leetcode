#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/iterator-for-combination/
# Author: Miao Zhang
# Date:   2021-04-21

class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        import itertools
        self.chars = list(itertools.combinations(characters, combinationLength))
        self.index = 0

    def next(self) -> str:
        self.index += 1
        return ''.join(self.chars[self.index - 1])

    def hasNext(self) -> bool:
        return self.index < len(self.chars)


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()
