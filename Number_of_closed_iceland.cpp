class Solution {
public:
    vector<pair<int,int>>v = {{0,1},{0,-1},{-1,0},{1,0}};
    void dfs(int i,int j,vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col  = grid[0].size();
        if(i<0||i>=row||j<0||j>=col||grid[i][j]==1) return;
        grid[i][j] = 1;
        for(pair<int,int>child:v)
        {
            int si = i+child.first;
            int sj = j+child.second;
            dfs(si,sj,grid);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col  = grid[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0||i==row-1||j==0||j==col-1)
                {
                    if(grid[i][j]==0)
                    {
                        dfs(i,j,grid);
                    }
                }
            }
        }

        int count = 0;
        for(int i=1;i<row-1;i++)
        {
            for(int j=1;j<col-1;j++)
            {
                if(grid[i][j]==0)
                {
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};