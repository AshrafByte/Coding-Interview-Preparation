class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int color) 
    {
        fill(image, sr, sc, color, image[sr][sc]);
        return image;
    }

    void fill(vector<vector<int>>& image, int r, int c, int color,int srcColor) 
    {   
        // rl -> rows limit , cl -> cols limit
        int rl = image.size() - 1;
        int cl = image[0].size() - 1;

        if (!validCell(r,c,rl,cl))
            return;

        if (image[r][c] != srcColor || image[r][c] == color)
            return;

        image[r][c] = color;

        fill(image, r - 1, c, color, srcColor);
        fill(image, r + 1, c, color, srcColor);
        fill(image, r, c - 1, color, srcColor);
        fill(image, r, c + 1, color, srcColor);
    }
    bool validCell(int r, int c, int rl, int cl) 
    {
        return ( (0 <= r && r <= rl) && (0 <= c && c <= cl) );
    }
};