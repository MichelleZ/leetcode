#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/defanging-an-ip-address/
# Author: Miao Zhang
# Date:   2021-04-09

class Solution:
    def defangIPaddr(self, address: str) -> str:
        return address.replace('.', '[.]')
