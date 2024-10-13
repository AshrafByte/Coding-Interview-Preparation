//
// Created by Ahmed hesen on 10/11/2024.
//

class Solution {
public:
    void soln(vector<vector<int>> &image, int sr, int sc, int color, int newColor){
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != color)return;
        image[sr][sc] = newColor;
        soln(image, sr-1, sc, color, newColor);
        soln(image, sr+1, sc, color, newColor);
        soln(image, sr, sc-1, color, newColor);
        soln(image, sr, sc+1, color, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] != color) soln(image, sr, sc, image[sr][sc], color);
        return image;
    }
};