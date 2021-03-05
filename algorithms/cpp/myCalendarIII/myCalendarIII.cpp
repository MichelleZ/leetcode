// Source: https://leetcode.com/problems/my-calendar-iii/
// Author: Miao Zhang
// Date:   2021-03-04

class MyCalendarThree {
public:
    MyCalendarThree() {
        root_.reset(new Node(0, 1000000000, 0));
    }
    
    int book(int start, int end) {
        Add(start, end, root_.get());
        return max_cnt_;
    }

private:
    struct Node {
        int l;
        int m;
        int r;
        int count;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
        Node(int l, int r, int count) : l(l), m(-1), r(r), count(count) {}
    };
    
    std::unique_ptr<Node> root_;
    int max_cnt_;
    
    void Add(int start, int end, Node* root) {
        if (root->m != -1) {
            if (end <= root->m) 
                Add(start, end, root->left.get());
            else if(start >= root->m)
                Add(start, end, root->right.get());
            else {
                Add(start, root->m, root->left.get());
                Add(root->m, end, root->right.get());
            }
            return;
        }
        
        if (start == root->l && end == root->r) {
            max_cnt_ = max(max_cnt_, ++root->count);
        } else if (start == root->l) {
            root->m = end;
            root->left.reset(new Node(start, root->m, root->count + 1));
            root->right.reset(new Node(root->m, root->r, root->count));
            max_cnt_ = max(max_cnt_, root->count + 1);
        } else if (end == root->r) {
            root->m = start;
            root->left.reset(new Node(root->l, root->m, root->count));
            root->right.reset(new Node(root->m, root->r, root->count + 1));
            max_cnt_ = max(max_cnt_, root->count + 1);
        } else {
            root->m = start;
            root->left.reset(new Node(root->l, root->m, root->count));
            root->right.reset(new Node(root->m, root->r, root->count));
            Add(start, end, root->right.get());
        }
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */ 
