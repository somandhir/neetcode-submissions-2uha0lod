class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            vis[0][i]=1;
            q.push(make_pair(0,i));
        }   
        for(int i=0;i<n;i++){
            vis[i][0]=1;
            q.push(make_pair(i,0));
        }   
        vector<pair<int,int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
        while(q.size()){
            auto pr = q.front();q.pop();
            int r = pr.first;
            int c = pr.second;
            for(auto&dirs:directions){
                int nr = r+dirs.first;
                int nc = c+dirs.second;
                if(nr>=0 and nc>=0 and nr<n and nc<m and !vis[nr][nc]){
                    if(heights[nr][nc]>=heights[r][c]){
                        vis[nr][nc]=1;
                        q.push(make_pair(nr,nc));
                    }
                }
            }
        }
        vector<vector<int>>visa(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            visa[n-1][i]=1;
            q.push(make_pair(n-1,i));
        }   
        for(int i=0;i<n;i++){
            visa[i][m-1]=1;
            q.push(make_pair(i,m-1));
        }   
        while(q.size()){
            auto pr = q.front();q.pop();
            int r = pr.first;
            int c = pr.second;
            for(auto&dirs:directions){
                int nr = r+dirs.first;
                int nc = c+dirs.second;
                if(nr>=0 and nc>=0 and nr<n and nc<m and !visa[nr][nc]){
                    if(heights[nr][nc]>=heights[r][c]){
                        visa[nr][nc]=1;
                        q.push(make_pair(nr,nc));
                    }
                }
            }
        }
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] and visa[i][j])res.push_back({i,j});
            }
        }
        return res;

    }
};
