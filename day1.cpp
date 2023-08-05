class Solution {
public:
    void dfs(int i, int j, int n, int m,  vector<vector<int>> &image, int color, int curr, vector<vector<int>> &vis ){
        if(i<0 || j<0 || i>=n || j>=m || image[i][j]!=curr ||vis[i][j]!=0)
            return;

            if(image[i][j]==curr){
               image[i][j] = color;
               vis[i][j]=1;
            }
        
        dfs(i+1, j, n, m, image, color, curr, vis);
        dfs(i, j+1, n, m, image, color, curr, vis);
        dfs(i-1, j, n, m, image, color, curr, vis);
        dfs(i, j-1, n, m, image, color, curr, vis);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        int curr = image[sr][sc];
        vector<vector<int>> vis(n, vector<int>(m, 0));
        dfs(sr, sc, n, m, image, color, curr, vis);

        return image;
    }
};