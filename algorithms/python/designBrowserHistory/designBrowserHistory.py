#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/design-browser-history/
# Author: Miao Zhang
# Date:   2021-05-09

class BrowserHistory:

    def __init__(self, homepage: str):
        self.urls = []
        self.urls.append(homepage)
        self.idx = 0

    def visit(self, url: str) -> None:
        while len(self.urls) > self.idx + 1:
            self.urls.pop()
        self.idx += 1
        self.urls.append(url)

    def back(self, steps: int) -> str:
        self.idx = max(self.idx - steps, 0)
        return self.urls[self.idx]

    def forward(self, steps: int) -> str:
        self.idx = min(self.idx + steps, len(self.urls) - 1)
        return self.urls[self.idx]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
