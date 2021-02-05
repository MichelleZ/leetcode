#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/insert-delete-getrandom-o1/
# Author: Miao Zhang
# Date:   2021-02-05

from collections import defaultdict
class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dic = defaultdict(int)
        self.vals = []

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if val in self.dic:
            return False
        self.dic[val] = len(self.vals)
        self.vals.append(val)
        return True

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if val not in self.dic:
            return False
        idx = self.dic[val]
        self.dic[self.vals[-1]] = idx
        self.dic.pop(val)
        self.vals[idx], self.vals[-1] = self.vals[-1], self.vals[idx]
        self.vals.pop()
        return True

    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        idx = random.randint(0, len(self.vals) - 1)
        return self.vals[idx]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
