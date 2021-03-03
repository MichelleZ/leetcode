#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/design-hashmap/
# Author: Miao Zhang
# Date:   2021-03-03

class MyHashMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.buckets = 1000
        self.items_per_bucket = 10001
        self.hashmap = [[] for _ in range(self.buckets)]
    
    def hash(self, key: int) -> int:
        return key % self.buckets
    
    def pos(self, key: int) -> int:
        return key // self.buckets

    def put(self, key: int, value: int) -> None:
        """
        value will always be non-negative.
        """
        k = self.hash(key)
        if not self.hashmap[k]:
            self.hashmap[k] = [None] * self.items_per_bucket
        self.hashmap[k][self.pos(key)] = value

    def get(self, key: int) -> int:
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        k = self.hash(key)
        if (not self.hashmap[k]) or self.hashmap[k][self.pos(key)] == None:
            return -1
        return self.hashmap[k][self.pos(key)]

    def remove(self, key: int) -> None:
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        k = self.hash(key)
        if self.hashmap[k]:
            self.hashmap[k][self.pos(key)] = None


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
