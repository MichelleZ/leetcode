#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-frequency-stack/
# Author: Miao Zhang
# Date:   2021-03-22

class FreqStack:
    '''
    self.freq: val: frequency
    self.stacks: frequecty: [stack]
    '''

    def __init__(self):
        self.freq = collections.Counter()
        self.stacks = collections.defaultdict(list)
        self.maxfreq = 0

    def push(self, val: int) -> None:
        freq = self.freq[val] + 1
        self.freq[val] = freq
        if freq > self.maxfreq:
            self.maxfreq = freq
        self.stacks[freq].append(val)

    def pop(self) -> int:
        val = self.stacks[self.maxfreq].pop()
        self.freq[val] -= 1
        if not self.stacks[self.maxfreq]:
            self.maxfreq -= 1
        return val

# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()
