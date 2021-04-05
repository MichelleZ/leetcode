#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/stream-of-characters/
# Author: Miao Zhang
# Date:   2021-04-05

class TrieNode:
    def __init__(self):
        self.TrieNode = {}

    def insert(self, word):
        cur = self.TrieNode
        for w in word:
            if w not in cur:
                cur[w] = {}
            cur = cur[w]
        cur['#'] = 1

    def search(self, word):
        cur = self.TrieNode
        for w in word:
            if w not in cur:
                return False
            if '#' in cur[w]:
                return True
            cur = cur[w]
        return False


class StreamChecker:

    def __init__(self, words: List[str]):
        self.trie = TrieNode()
        self.stream = deque([])
        for word in set(words):
            self.trie.insert(word[::-1])

    def query(self, letter: str) -> bool:
        self.stream.appendleft(letter)
        return self.trie.search(self.stream)


# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
