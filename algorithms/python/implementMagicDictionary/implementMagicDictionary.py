#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/implement-magic-dictionary/
# Author: Miao Zhang
# Date:   2021-02-28

class MagicDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dic = collections.defaultdict(set)

    def buildDict(self, dictionary: List[str]) -> None:
        for word in dictionary:
            for i in range(len(word)):
                c = word[i]
                self.dic[word[:i] + '*' + word[i+1:]].add(c)

    def search(self, searchWord: str) -> bool:
        for i in range(len(searchWord)):
            c = searchWord[i]
            newword = searchWord[:i] + '*' + searchWord[i + 1:]
            if newword in self.dic:
                if c not in self.dic[newword] or len(self.dic[newword]) > 1:
                    return True
        return False

# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dictionary)
# param_2 = obj.search(searchWord)
