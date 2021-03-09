// Source: https://leetcode.com/problems/global-and-local-inversions/
// Author: Miao Zhang
// Date:   2021-03-09

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size();
        int local = 0;
        for (int i = 0; i < n - 1; i++) {
            if (A[i] > A[i + 1]) local++;
        }
        tmp = vector<int>(n);
        int global = mergeSort(A, 0, n - 1);
        return global == local;
    }

private:
    vector<int> tmp;

    int mergeSort(vector<int>& A, int l, int r) {
        if (l >= r) return 0;
        int len = r - l + 1;
        int mid = l + (r - l) / 2;
        int inv = mergeSort(A, l, mid) + mergeSort(A, mid + 1, r);

        int i = l;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= r) {
            if (A[i] <= A[j]) {
                tmp[k++] = A[i++];
            } else {
                tmp[k++] = A[j++];
                inv += mid - i + 1;
            }
        }
        while (i <= mid) tmp[k++] = A[i++];
        while (j <= r) tmp[k++] = A[j++];
        std::copy(tmp.begin(), tmp.begin() + len, A.begin() + l);
        return inv;
    }
};
