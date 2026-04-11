class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>time(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==2){time[i][j]=0;q.push(make_pair(i,j));}
            }
        }
      
        vector<pair<int,int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
        while(q.size()){
            auto pr = q.front();q.pop();
            int r = pr.first;
            int c = pr.second;
            // cout<<r<<" "<<c<<endl;
            // cout<<time[r][c]<<endl;
            for(auto&dirs:directions){
                int nr = r+dirs.first;
                int nc = c+dirs.second;
                if(nr>=0 and nc>=0 and nr<n and nc<m and grid[nr][nc]==1){
                    if(time[r][c]+1<time[nr][nc]){
                        time[nr][nc]=time[r][c]+1;
                        q.push(make_pair(nr,nc));
                    }
                }
            }
        }
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)res=max(res,time[i][j]);
            }
        }
        res=res==INT_MAX?-1:res;
        return res;
    }
};
