#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/word-ladder/
# Author: Miao Zhang
# Date:   2021-01-20

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        from collections import deque
        wordset = set(wordList)
        q = deque()
        q.append((beginWord, 1))
        while q:
            word, length = q.popleft()
            if word == endWord:
                return length
            for i in range(len(word)):
                for c in "abcdefghijklmnopqrstuvwxyz":
                    newword = word[:i] + c + word[i + 1:]
                    if newword in wordset and newword != word:
                        wordset.remove(newword)
                        q.append((newword, length + 1))
        return 0
