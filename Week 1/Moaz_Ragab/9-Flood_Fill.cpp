class Solution {
public:
int n,m;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n=image.size();
        m=image[0].size();

        stack<pair<int,int>>st;
        int original=image[sr][sc];
        if (original == color) return image;
        st.push({sr,sc});
        while(!st.empty())
        {
            auto [first,second]=st.top();
            st.pop();
            image[first][second]=color;
            if(isvalid(first+1,second,n,m)&&image[first+1][second]==original)
            {
                    st.push({first+1,second});
            }
            if(isvalid(first-1,second,n,m)&&image[first-1][second]==original)
            {
                     st.push({first-1,second});
            }
            if(isvalid(first,second+1,n,m)&&image[first][second+1]==original)
            {
                 st.push({first,second+1});
            }
            if(isvalid(first,second-1,n,m)&&image[first][second-1]==original)
            {
                 st.push({first,second-1});
            }

        }
        return image;
    }
    bool isvalid(int i,int j,int n,int m)
    {
        if(i >= n ||j>=m ||i<0 ||j<0) return false;

        return true;
    }
};