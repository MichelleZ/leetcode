#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/fizz-buzz-multithreaded/
# Author: Miao Zhang
# Date:   2021-04-16

from threading import Semaphore
class FizzBuzz:
    def __init__(self, n: int):
        self.n = n
        self.semfizz = Semaphore(0)
        self.sembuzz = Semaphore(0)
        self.semfibu = Semaphore(0)
        self.semnum = Semaphore(1)

    # printFizz() outputs "fizz"
    def fizz(self, printFizz: 'Callable[[], None]') -> None:
    	for i in range(1, self.n + 1):
            if i % 3 == 0 and i % 5 != 0:
                self.semfizz.acquire()
                printFizz()
                self.semnum.release()

    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz: 'Callable[[], None]') -> None:
    	for i in range(1, self.n + 1):
            if i % 5 == 0 and i % 3 != 0:
                self.sembuzz.acquire()
                printBuzz()
                self.semnum.release()

    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz: 'Callable[[], None]') -> None:
        for i in range(1, self.n + 1):
            if i % 3 == 0 and i % 5 == 0:
                self.semfibu.acquire()
                printFizzBuzz()
                self.semnum.release()

    # printNumber(x) outputs "x", where x is an integer.
    def number(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1, self.n + 1):
            self.semnum.acquire()
            if i % 3 == 0 and i % 5 == 0:
                self.semfibu.release()
            elif i % 3 == 0:
                self.semfizz.release()
            elif i % 5 == 0:
                self.sembuzz.release()
            else:
                printNumber(i)
                self.semnum.release()
