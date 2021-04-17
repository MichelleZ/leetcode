#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
# Author: Miao Zhang
# Date:   2021-04-17

class Solution:
    def sortItems(self, n: int, m: int, group: List[int], beforeItems: List[List[int]]) -> List[int]:
        # 1. data preprocessing
        for i in range(len(group)):
            if group[i] == -1:
                group[i] = m
                m += 1
        # 2. adjacency table for item and group
        itemAdj = [[] for _ in range(n)]
        groupAdj = [[] for _ in range(m)]
        # 3. indegree array and graph
        itemIndegree = [0 for _ in range(n)]
        groupIndegree = [0 for _ in range(m)]
        
        for i in range(len(group)):
            curGroup = group[i]
            for beforeItem in beforeItems[i]:
                beforeGroup = group[beforeItem]
                if beforeGroup != curGroup:
                    groupAdj[beforeGroup].append(curGroup)
                    groupIndegree[curGroup] += 1
        
        for i in range(n):
            for beforeItem in beforeItems[i]:
                itemAdj[beforeItem].append(i)
                itemIndegree[i] += 1
        # 4. get topology res
        groupres = self.topologicalSort(groupAdj, groupIndegree)
        itemres = self.topologicalSort(itemAdj, itemIndegree)
        # 5. get map: key: group -> val: items
        group2items = collections.defaultdict(list)
        for item in itemres:
            group2items[group[item]].append(item)
        
        # 6. transfer the last res according to groupres
        res = []
        for group in groupres:
            if group in group2items:
                for item in group2items[group]:
                    res.append(item)
        return res
    
    def topologicalSort(self, adj: List[List[int]], indegree: List[int]) -> List[int]:
        res = []
        q = collections.deque()
        for i in range(len(indegree)):
            if indegree[i] == 0:
                q.append(i)
        while q:
            cur = q.pop()
            res.append(cur)
            for nxt in adj[cur]:
                indegree[nxt] -= 1
                if indegree[nxt] == 0:
                    q.append(nxt)
        return res if len(res) == len(indegree) else []
        
