#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/design-authentication-manager/
# Author: Miao Zhang
# Date:   2021-06-08

class AuthenticationManager:

    def __init__(self, timeToLive: int):
        self.tokens = {}
        self.ttl = timeToLive

    def generate(self, tokenId: str, currentTime: int) -> None:
        self.clear(currentTime)
        self.tokens[tokenId] = currentTime + self.ttl

    def renew(self, tokenId: str, currentTime: int) -> None:
        self.clear(currentTime)
        if tokenId not in self.tokens: return
        self.tokens[tokenId] = currentTime + self.ttl

    def countUnexpiredTokens(self, currentTime: int) -> int:
        self.clear(currentTime)
        return len(self.tokens)

    def clear(self, currentTime: int) -> None:
        ids = []
        for id, t in self.tokens.items():
            if t <= currentTime:
                ids.append(id)
        for i in ids:
            self.tokens.pop(i)



# Your AuthenticationManager object will be instantiated and called as such:
# obj = AuthenticationManager(timeToLive)
# obj.generate(tokenId,currentTime)
# obj.renew(tokenId,currentTime)
# param_3 = obj.countUnexpiredTokens(currentTime)
