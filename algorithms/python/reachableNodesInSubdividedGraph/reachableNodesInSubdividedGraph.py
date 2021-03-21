#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/
# Author: Miao Zhang
# Date:   2021-03-20

class Solution:
    def reachableNodes(self, edges: List[List[int]], maxMoves: int, n: int) -> int:
        graph = [list() for _ in range(n)]
        for e in edges:
            graph[e[0]].append([e[1], e[2]])
            graph[e[1]].append([e[0], e[2]])
        q = []
        moves = collections.defaultdict(int)
        heapq.heappush(q, [-maxMoves, 0])
        while q:
            tmp, cur = heapq.heappop(q)
            move = -tmp
            if cur in moves: continue
            moves[cur] = move
            for g in graph[cur]:
                nxt = g[0]
                nxt_move = move - g[1] - 1
                if nxt in moves or nxt_move < 0: continue
                heapq.heappush(q, [-nxt_move, nxt])
        res = len(moves)
        for e in edges:
            uv = moves[e[0]] if e[0] in moves else 0
            vu = moves[e[1]] if e[1] in moves else 0
            res += min(e[2], uv + vu)
        return res
