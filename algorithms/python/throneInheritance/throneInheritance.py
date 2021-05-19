#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/throne-inheritance/
# Author: Miao Zhang
# Date:   2021-05-19

class ThroneInheritance:

    def __init__(self, kingName: str):
        self.king = kingName
        self.order = collections.defaultdict(list)
        self.dead = set()

    def birth(self, parentName: str, childName: str) -> None:
        self.order[parentName].append(childName)

    def death(self, name: str) -> None:
        self.dead.add(name)

    def getInheritanceOrder(self) -> List[str]:
        self.res = []
        def dfs(king: str) -> None:
            if king not in self.dead:
                self.res.append(king)
            for child in self.order[king]:
                dfs(child)
        dfs(self.king)
        return self.res


# Your ThroneInheritance object will be instantiated and called as such:
# obj = ThroneInheritance(kingName)
# obj.birth(parentName,childName)
# obj.death(name)
# param_3 = obj.getInheritanceOrder()
