#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/word-search-ii/
# Author: Miao Zhang
# Date:   2023-02-26

class Trie:
    def __init__(self):
        self.root = {}
    
    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            node = node.setdefault(c, {})
        node['#'] = word


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        def dfs(i: int, j: int, root: Trie) -> None:
            ch = board[i][j]
            nxt = root[ch]
            word = nxt.pop('#', False)
            if word:
                res.append(word)
            board[i][j] = '*'
            dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
            for dx, dy in dirs:
                x, y = i + dx, j + dy
                if 0 <= x < m and 0 <= y < n and board[x][y] in nxt:
                    dfs(x, y, nxt)
            board[i][j] = ch
            if not nxt:
                root.pop(ch)
        
        trie = Trie()
        node = trie.root
        for word in words:
            trie.insert(word)
        
        m, n = len(board), len(board[0])
        res = []
        for i in range(m):
            for j in range(n):
                if board[i][j] in node:
                    dfs(i, j, node)
                
        return res


'''
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
'''
