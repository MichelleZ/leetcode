// Source: https://leetcode.com/problems/rectangle-area/
// Author: Miao Zhang
// Date:   2021-01-27

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long area1 = (D - B) * (C - A);
        long area2 = (H - F) * (G - E);
        int xright = min(C, G);
        int xleft =  max(A, E);
        int yup = min(D, H);
        int ydown = max(B, F);
        long area = 0;
        if (xright > xleft && yup > ydown) {
            area = (xright - xleft) * (yup - ydown);
        }
        return (long)area1 + area2 - area;
    }
};
