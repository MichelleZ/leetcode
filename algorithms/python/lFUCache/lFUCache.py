#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/lfu-cache/
# Author: Miao Zhang
# Date:   2021-02-13

class Node:
    def __init__(self, key, val, freq=0, pre=None, nxt=None):
        self.key = key
        self.val = val
        self.freq = freq
        self.pre = pre
        self.nxt = nxt
    
    def insert(self, nex):
        nex.pre = self
        nex.nxt = self.nxt
        self.nxt.pre = nex
        self.nxt = nex
    

def create_linked_list():
    head = Node(0, 0)
    tail = Node(0, 0)
    head.nxt = tail
    tail.pre = head
    return (head, tail)


class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.size = 0
        self.min_freq = 0
        # freq---> list node
        self.freq_map = collections.defaultdict(create_linked_list)
        # key ---> node
        self.key_map = {}

    def get(self, key: int) -> int:
        if key not in self.key_map: return -1
        self.increase(self.key_map[key])
        return self.key_map[key].val

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0: return
        if key in self.key_map:
            node = self.key_map[key]
            node.val = value
        else:
            node = Node(key, value)
            self.key_map[key] = node
            self.size += 1
        if self.size > self.capacity:
            self.size -= 1
            key_del = self.deleteNode(self.freq_map[self.min_freq][0].nxt)
            self.key_map.pop(key_del)
        self.increase(node)
        
    def deleteNode(self, node: Node):
        if node.pre:
            node.pre.nxt = node.nxt
            node.nxt.pre = node.pre
            if node.pre is self.freq_map[node.freq][0] and node.nxt is self.freq_map[node.freq][-1]:
                self.freq_map.pop(node.freq)
        return node.key
    
    def increase(self, node: Node):
        node.freq += 1
        self.deleteNode(node)
        self.freq_map[node.freq][-1].pre.insert(node)
        if node.freq == 1:
            self.min_freq = 1
        elif self.min_freq == node.freq - 1:
            head, tail = self.freq_map[node.freq - 1]
            if head.nxt is tail: self.min_freq = node.freq

        
# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
