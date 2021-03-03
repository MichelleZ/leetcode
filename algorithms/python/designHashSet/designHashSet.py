#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/design-hashset/
# Author: Miao Zhang
# Date:   2021-03-03

class TreeNode:
    def __init__(self, val: int):
        self.val = val
        self.left = None
        self.right = None


class BSTree:
    def __init__(self):
        self.root = None

    def _searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if root is None or val == root.val: return root
        if root.val > val:
            return self._searchBST(root.left, val)
        else:
            return self._searchBST(root.right, val)

    def searchBST(self, val: int) -> TreeNode:
        return self._searchBST(self.root, val)

    def _insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root:
            return TreeNode(val)
        if root.val > val:
            root.left = self._insertIntoBST(root.left, val)
        elif root.val < val:
            root.right = self._insertIntoBST(root.right, val)
        return root

    def insertIntoBST(self, val: int) -> TreeNode:
        return self._insertIntoBST(self.root, val)

    def _deleteFromBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root: return None

        if root.val > val:
            root.left = self._deleteFromBST(root.left, val)
        elif root.val < val:
            root.right = self._deleteFromBST(root.right, val)
        else:
            if not root.left and not root.right:
                root = None
            elif root.right:
                root.val = self.successor(root)
                root.right = self._deleteFromBST(root.right, val)
            else:
                root.val = self.predecessor(root)
                root.left = self._deleteFromBST(root.left, val)
        return root

    def successor(self, root: TreeNode) -> int:
        root = root.right
        while root.left:
            root = root.left
        return root.val

    def predecessor(self, root: TreeNode) -> int:
        root = root.left
        while root.right:
            root = root.right
        return root.val

    def deleteFromBST(self, val: int) -> TreeNode:
        return self._deleteFromBST(self.root, val)


class Bucket:
    def __init__(self):
        self.tree = BSTree()

    def insert(self, val: int) -> None:
        self.tree.root = self.tree.insertIntoBST(val)

    def delete(self, val: int) -> None:
        self.tree.root = self.tree.deleteFromBST(val)

    def contains(self, val: int) -> bool:
        return (self.tree.searchBST(val) is not None)


class MyHashSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.keyRange = 769
        self.bucket = [Bucket() for i in range(self.keyRange)]

    def _hash(self, key: int) -> int:
        return key % self.keyRange

    def add(self, key: int) -> None:
        idx = self._hash(key)
        self.bucket[idx].insert(key)

    def remove(self, key: int) -> None:
        idx = self._hash(key)
        self.bucket[idx].delete(key)

    def contains(self, key: int) -> bool:
        """
        Returns true if this set contains the specified element
        """
        idx = self._hash(key)
        return self.bucket[idx].contains(key)


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
