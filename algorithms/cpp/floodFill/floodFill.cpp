// Source: https://leetcode.com/problems/flood-fill/
// Author: Miao Zhang
// Date:   2021-03-05

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        floodFill(image, sr, sc, image[sr][sc], newColor);
        return image;
    }

private:
    void floodFill(vector<vector<int>>& image, int i, int j, int orgColor, int newColor) {
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] != orgColor) {
            return;
        }
        image[i][j] = newColor;
        floodFill(image, i + 1, j , orgColor, newColor);
        floodFill(image, i - 1, j , orgColor, newColor);
        floodFill(image, i, j + 1, orgColor, newColor);
        floodFill(image, i, j - 1, orgColor, newColor);
    }
};
