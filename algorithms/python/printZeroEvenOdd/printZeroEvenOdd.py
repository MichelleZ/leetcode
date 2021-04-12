#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/print-zero-even-odd/
# Author: Miao Zhang
# Date:   2021-04-12

from threading import Lock
class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.mzero = Lock()
        self.modd = Lock()
        self.meven = Lock()
        self.modd.acquire()
        self.meven.acquire()
        
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(self.n):
            self.mzero.acquire()
            printNumber(0)
            if i % 2 == 0:
                self.modd.release()
            else:
                self.meven.release()
        
    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(2, self.n + 1, 2):
            self.meven.acquire()
            printNumber(i)
            self.mzero.release()
        
    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1, self.n + 1, 2):
            self.modd.acquire()
            printNumber(i)
            self.mzero.release()
        
