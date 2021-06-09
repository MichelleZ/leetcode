#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-pairs-with-xor-in-a-range/
# Author: Miao Zhang
# Date:   2021-06-09

class TrieNode:
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.cnt = 0


class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, num):
        p = self.root
        for i in reversed(range(15)):
            bitnum = (num >> i) & 1
            p.children[bitnum].cnt += 1
            p = p.children[bitnum]
    
    def count(self, num, limit):
        cnt = 0
        p = self.root
        for i in reversed(range(15)):
            bitnum = (num >> i) & 1
            bitlimit = (limit >> i) & 1
            if bitlimit == 1:
                cnt += p.children[bitnum].cnt
                p = p.children[1 - bitnum]
            else:
                p = p.children[bitnum]
            if not p:
                break
        return cnt

    
class Solution:
    def countPairs(self, nums: List[int], low: int, high: int) -> int:
        trie = Trie()
        res = 0
        for num in nums:
            res += trie.count(num, high + 1) - trie.count(num, low)
            trie.insert(num)
        return res
