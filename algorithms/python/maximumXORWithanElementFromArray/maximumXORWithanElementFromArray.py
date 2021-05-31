#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
# Author: Miao Zhang
# Date:   2021-05-31

class Trie:
    def __init__(self):
        self.children = [None for _ in range(2)]
    
class Solution:
    def maximizeXor(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        n = len(nums)
        nums.sort()
        m = len(queries)
        for i in range(m):
            queries[i].append(i)
        queries.sort(key=lambda x: x[1])
        root = Trie()
        
        def insert(num):
            node = root
            for i in range(31, -1, -1):
                bit = (num >> i) & 1
                if not node.children[bit]:
                    node.children[bit] = Trie()
                node = node.children[bit]
        
        def query(num):
            node = root
            sums = 0
            for i in range(31, -1, -1):
                if not node: return -1
                bit = (num >> i) & 1
                if node.children[1 - bit]:
                    sums |= (1 << i)
                    node = node.children[1 - bit]
                else:
                    node = node.children[bit]
            return sums
        
        res = [0] * m
        i = 0
        for q in queries:
            while i < n and nums[i] <= q[1]:
                insert(nums[i])
                i += 1
            res[q[2]] = query(q[0])
        return res
            
                
