// Source: https://leetcode.com/problems/design-skiplist/
// Author: Miao Zhang
// Date:   2021-04-17

class Skiplist {
public:
    Skiplist() {
        head_ = make_shared<Node>();
    }
    
    bool search(int target) {
        for (auto node = head_; node; node = node->down) {
            while (node->next && node->next->val < target) {
                node = node->next;
            }
            if (node->next && node->next->val == target)
                return true;
        }
        return false;
    }
    
    void add(int num) {
        stack<shared_ptr<Node>> st;
        shared_ptr<Node> down;
        bool insert = true;
        
        for (auto node = head_; node; node = node->down) {
            while (node->next && node->next->val < num) {
                node = node->next;
            }
            st.push(node);
        }
        
        while (!st.empty() && insert) {
            auto cur = st.top(); st.pop();
            cur->next = make_shared<Node>(num, cur->next, down);
            down = cur->next;
            insert = rand() & 1;
        }
        
        if (insert) {
            head_ = make_shared<Node>(-1, nullptr, head_);
        }
    }
    
    bool erase(int num) {
        bool found = false;
        for (auto node = head_; node; node = node->down) {
            while (node->next && node->next->val < num) {
                node = node->next;
            }
            if (node->next && node->next->val == num) {
                found = true;
                node->next = node->next->next;
            }
        }
        return found;
    }

private:
    struct Node {
        Node (int val = -1,
              shared_ptr<Node> next = nullptr,
              shared_ptr<Node> down = nullptr) :
              val(val), next(next), down(down) {}
        int val;
        shared_ptr<Node> next;
        shared_ptr<Node> down;
    };
    
    shared_ptr<Node> head_;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
