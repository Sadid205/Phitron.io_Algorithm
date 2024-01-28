class Solution {
public:
    vector<pair<int,int>>v = {{0,1},{0,-1},{-1,0},{1,0}};
    void dfs(vector<vector<int>>& image,int i,int j,int mainColor,int color,int row,int col)
    {
        image[i][j] = color;
        for(pair<int,int>child:v)
        {
            int si = i+child.first;
            int sj = j+child.second;
            if(si>=0 && si<row &&sj>=0 && sj<col && image[si][sj]==mainColor)
            {
                dfs(image,si,sj,mainColor,color,row,col);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int mainColor = image[sr][sc];
        int row = image.size();
        int col = image[0].size();
        if(image[sr][sc]==color)return image;
        dfs(image,sr,sc,mainColor,color,row,col);
        return image;
    }
};