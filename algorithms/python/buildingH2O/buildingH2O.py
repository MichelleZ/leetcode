#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/building-h2o/
# Author: Miao Zhang
# Date:   2021-04-12

class H2O:
    def __init__(self):
        self.h = collections.deque()
        self.o = self.h.copy()

    def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
        
        # releaseHydrogen() outputs "H". Do not change or remove this line.
        #releaseHydrogen()
        self.h.append(releaseHydrogen)
        self.res()

    def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
        
        # releaseOxygen() outputs "O". Do not change or remove this line.
        #releaseOxygen()
        self.o.append(releaseOxygen)
        self.res()
    
    def res(self):
        if len(self.h) >= 2 and len(self.o) >= 1:
            self.h.popleft()()
            self.h.popleft()()
            self.o.popleft()()
