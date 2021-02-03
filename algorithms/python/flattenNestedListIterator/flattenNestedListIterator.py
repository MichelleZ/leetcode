#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/flatten-nested-list-iterator/
# Author: Miao Zhang
# Date:   2021-02-03

# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """

from collections import deque
class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.q = deque()
        def makequeue(nestedList: [NestedInteger]):
            for n in nestedList:
                if n.isInteger():
                    self.q.append(n.getInteger())
                else:
                    makequeue(n.getList())
        makequeue(nestedList)
    
    def next(self) -> int:
        return self.q.popleft()
        
    def hasNext(self) -> bool:
        return len(self.q) > 0

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
