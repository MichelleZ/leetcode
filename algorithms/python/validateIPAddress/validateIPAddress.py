#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/validate-ip-address/
# Author: Miao Zhang
# Date:   2021-02-14

class Solution:
    def validIPAddress(self, IP: str) -> str:
        if '.' in IP and self.checkIPv4(IP):
            return "IPv4"
        elif ':' in IP and self.checkIPv6(IP):
            return "IPv6"
        else:
            return "Neither"
    
    def checkIPv4(self, IP: str) -> bool:
        nums = IP.split('.')
        if len(nums) != 4: return False
        for n in nums:
            if not n or (not n.isdecimal()) or (n[0] == '0' and len(n) != 1) or int(n) > 255:
                return False
        return True
    
    def checkIPv6(self, IP: str) -> bool:
        IP = IP.lower()
        valid16 = "0123456789abcdef"
        if "::" in IP: return False
        nums = IP.split(':')
        if len(nums) > 8: return False
        for n in nums:
            if not n: return False
            if len(n) >= 5: return False
            for c in n:
                if c not in valid16:
                    return False
        return True
