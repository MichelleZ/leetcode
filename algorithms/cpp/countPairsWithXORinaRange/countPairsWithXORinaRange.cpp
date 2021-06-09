// Source: https://leetcode.com/problems/count-pairs-with-xor-in-a-range/
// Author: Miao Zhang
// Date:   2021-06-09

const int HEIGHT = 14;
class TrieNode {
public:
    TrieNode() : cnt(0), children(2, nullptr) {
    }

    ~TrieNode() {
        for (TrieNode* ch: children) {
            if (ch) delete ch;
        }
    }

public:
    vector<TrieNode*> children;
    // TrieNode* children[2];
    int cnt;
};


class Trie {
public:
    Trie() : root_(new TrieNode()) {
    }

    void insert(int num) {
        TrieNode* p = root_.get();
        for (int j = HEIGHT; j >= 0; j--) {
            int index = (num >> j) & 1;
            if (p->children[index] == nullptr) {
                p->children[index] = new TrieNode();
            }
            p = p->children[index];
            p->cnt++;
        }
    }

    int getCount(int num, int limit) {
        TrieNode* p = root_.get();
        int cnt = 0;
        for (int j = HEIGHT; j >= 0; j--) {
            int bitnum = (num >> j) & 1;
            int bitlimit = (limit >> j) & 1;
            if (bitlimit == 1) {
                if (p->children[bitnum] != nullptr) {
                    cnt += p->children[bitnum]->cnt;
                }
                p = p->children[1 - bitnum];
            }
            else {
                p = p->children[bitnum];
            }
            if (p == nullptr) break;
        }
        return cnt;
    }

private:
    std::unique_ptr<TrieNode> root_;
};


class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        Trie* trie = new Trie();
        int res = 0;
        for (int num: nums) {
            res += trie->getCount(num, high + 1) - trie->getCount(num, low);
            trie->insert(num);
        }
        return res;
    }
};
