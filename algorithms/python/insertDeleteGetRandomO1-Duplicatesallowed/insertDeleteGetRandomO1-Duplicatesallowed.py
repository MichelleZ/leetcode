#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
# Author: Miao Zhang
# Date:   2021-02-05

from collections import defaultdict
class RandomizedCollection:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dic = defaultdict(list)
        self.vals = []

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        """
        self.dic[val].append(len(self.vals))
        self.vals.append([val, len(self.dic[val]) - 1])
        return len(self.dic[val]) == 1

    def remove(self, val: int) -> bool:
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        """
        if val not in self.dic: return False
        index_in_array = self.dic[val][len(self.dic[val]) - 1]
        last_val = self.vals[-1]
        self.dic[last_val[0]][last_val[1]] = index_in_array
        self.vals[-1], self.vals[index_in_array] = self.vals[index_in_array], self.vals[-1]
        self.dic[val].pop()
        self.vals.pop()
        if len(self.dic[val]) == 0: self.dic.pop(val)
        return True

    def getRandom(self) -> int:
        """
        Get a random element from the collection.
        """
        index = random.randint(0, len(self.vals) - 1)
        return self.vals[index][0]

# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
