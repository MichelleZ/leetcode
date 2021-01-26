#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/design-add-and-search-words-data-structure/
# Author: Miao Zhang
# Date:   2021-01-26

class TrieNode(object):
    def __init__(self):
        self.children = {}
        self.is_word = False


class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.is_word = True

    def search(self, word: str) -> bool:
        def dfs(node, i):
            if i == len(word):
                return node.is_word
            if word[i] == '.':
                for next_node in node.children.values():
                    if dfs(next_node, i + 1):
                        return True
            else:
                if word[i] in node.children:
                    if dfs(node.children[word[i]], i + 1):
                        return True
        
        node = self.root
        return dfs(node, 0)

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
