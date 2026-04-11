class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    q.push(make_pair(0,make_pair(i,j)));
                }
            }
        }
        vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
        while(q.size()){
            auto pr = q.front();q.pop();
            int dist = pr.first;
            int r = pr.second.first;
            int c = pr.second.second;
            for(auto&dirs:directions){
                int nr = r+dirs.first, nc = c+dirs.second;
                if(nr>=0 and nc>=0 and nr<grid.size() and nc<grid[0].size() and grid[nr][nc]>0){
                    if(dist+1<grid[nr][nc]){
                        grid[nr][nc]=dist+1;
                        q.push(make_pair(dist+1,make_pair(nr,nc)));
                    }
                }
            }
        }
        return;
    }
};
