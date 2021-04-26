#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/tweet-counts-per-frequency/
# Author: Miao Zhang
# Date:   2021-04-26

class TweetCounts:

    def __init__(self):
        self.record = collections.defaultdict(list)
        self.timestamp = {'minute': 60, 'hour': 3600, 'day': 24*3600}

    def recordTweet(self, tweetName: str, time: int) -> None:
        bisect.insort(self.record[tweetName], time)

    def getTweetCountsPerFrequency(self, freq: str, tweetName: str, startTime: int, endTime: int) -> List[int]:
        tweet = self.record[tweetName]
        f = self.timestamp[freq]
        res = []
        t = startTime
        while t <= endTime:
            res.append(bisect.bisect_right(tweet, min(t + f - 1, endTime)) - bisect.bisect_left(tweet, t))
            t += f
        return res

# Your TweetCounts object will be instantiated and called as such:
# obj = TweetCounts()
# obj.recordTweet(tweetName,time)
# param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime)
