// Source: https://leetcode.com/problems/peeking-iterator/
// Author: Miao Zhang
// Date:   2021-01-30

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
private:
    bool is_peeked;
    int peeked_val;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums), is_peeked(false), peeked_val(0) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!is_peeked && Iterator::hasNext()) {
            peeked_val = Iterator::next();
            is_peeked = true;
        }
        return peeked_val;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if (is_peeked) {
            is_peeked = false;
            return peeked_val;
        } else {
            return Iterator::next();
        }
	    
	}
	
	bool hasNext() const {
	    if (is_peeked) {
            return true;
        } else {
            return Iterator::hasNext();
        }
	}
};
