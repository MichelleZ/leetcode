#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/word-search-ii/
# Author: Miao Zhang
# Date:   2021-01-26

class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_word = False


class TrieTree:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word):
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.is_word = True

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        m = len(board)
        n = len(board[0])
        trie = TrieTree()
        node = trie.root
        for word in words:
            trie.insert(word)
        
        res = []
        for i in range(m):
            for j in range(n):
                self.dfs(board, node, i, j, "", res)
        return res
    
    def dfs(self, board, node, i, j, path, res):
        if node.is_word:
            res.append(path)
            node.is_word = False
        
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]):
            return
        
        tmp = board[i][j]
        node = node.children.get(tmp, None)
        if not node:
            return
        
        board[i][j] = '#'
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        for dx, dy in dirs:
            self.dfs(board, node, i + dx, j + dy, path + tmp, res)
        board[i][j] = tmp
