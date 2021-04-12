#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/print-foobar-alternately/
# Author: Miao Zhang
# Date:   2021-04-12

from threading import Lock
class FooBar:
    def __init__(self, n):
        self.n = n
        self.m1 = Lock()
        self.m2 = Lock()
        self.m2.acquire()

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            self.m1.acquire()
            # printFoo() outputs "foo". Do not change or remove this line.
            printFoo()
            self.m2.release()

    def bar(self, printBar: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            self.m2.acquire()
            # printBar() outputs "bar". Do not change or remove this line.
            printBar()
            self.m1.release()
