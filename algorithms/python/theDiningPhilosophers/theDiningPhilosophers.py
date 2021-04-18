#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/the-dining-philosophers/
# Author: Miao Zhang
# Date:   2021-04-18

from threading import Lock
class DiningPhilosophers:
    def __init__(self):
        self.forks = [Lock() for _ in range(5)]

    # call the functions directly to execute, for example, eat()
    def wantsToEat(self,
                   philosopher: int,
                   pickLeftFork: 'Callable[[], None]',
                   pickRightFork: 'Callable[[], None]',
                   eat: 'Callable[[], None]',
                   putLeftFork: 'Callable[[], None]',
                   putRightFork: 'Callable[[], None]') -> None:
        left = self.forks[philosopher]
        right = self.forks[(philosopher + 4) % 5]
        
        # even left -> right
        if philosopher % 2 == 0:
            left.acquire()
            pickLeftFork()
            right.acquire()
            pickRightFork()
        else:
            right.acquire()
            pickRightFork()
            left.acquire()
            pickLeftFork()
        
        eat()
        putLeftFork()
        left.release()
        putRightFork()
        right.release()
