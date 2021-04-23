#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/get-watched-videos-by-your-friends/
# Author: Miao Zhang
# Date:   2021-04-23

class Solution:
    def watchedVideosByFriends(self, watchedVideos: List[List[str]], friends: List[List[int]], id: int, level: int) -> List[str]:
        n = len(friends)
        visited = [0 for _ in range(n)]
        q = collections.deque()
        q.append(id)
        visited[id] = 1
        for _ in range(level):
            qlen = len(q)
            for _ in range(qlen):
                u = q.popleft()
                for v in friends[u]:
                    if visited[v]: continue
                    visited[v] = 1
                    q.append(v)

        cnt = collections.Counter()
        while q:
            u = q.popleft()
            for w in watchedVideos[u]:
                cnt[w] += 1

        videos = list(cnt.items())
        videos.sort(key = lambda x: [x[1], x[0]])
        return [v[0] for v in videos]
