#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/design-skiplist/
# Author: Miao Zhang
# Date:   2021-04-17

maxLevel = 16
power = 2
maxRand = power ** maxLevel - 1
randLevel = lambda: maxLevel - int(math.log(random.randint(1, maxRand), power))

class Node:
    def __init__(self, val):
        self.val = val
        self.right = None
        self.down = None
        

class Skiplist:

    def __init__(self):
        left = [Node(float('-inf')) for _ in range(maxLevel)]
        right = [Node(float('inf')) for _ in range(maxLevel)]
        for i in range(maxLevel - 1):
            left[i].right = right[i]
            left[i].down = left[i + 1]
            right[i].down = right[i + 1]
        left[-1].right = right[-1]
        self.head = left[0]

    def search(self, target: int) -> bool:
        node = self.head
        while node:
            if node.right.val > target:
                node = node.down
            elif node.right.val < target:
                node = node.right
            else:
                return True
        return False

    def add(self, num: int) -> None:
        prev = []
        node = self.head
        while node:
            if node.right.val >= num:
                prev.append(node)
                node = node.down
            else:
                node = node.right
        arr = [Node(num) for _ in range(randLevel())]
        t = Node(None)
        for node, addnode in zip(prev[maxLevel - len(arr): ], arr):
            addnode.right = node.right
            node.right = addnode
            t.down = addnode
            t = addnode

    def erase(self, num: int) -> bool:
        found = False
        node = self.head
        while node:
            if node.right.val > num:
                node = node.down
            elif node.right.val < num:
                node = node.right
            else:
                found = True
                node.right = node.right.right
                node = node.down
        return found


# Your Skiplist object will be instantiated and called as such:
# obj = Skiplist()
# param_1 = obj.search(target)
# obj.add(num)
# param_3 = obj.erase(num)
