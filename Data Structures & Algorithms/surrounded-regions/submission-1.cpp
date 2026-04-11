class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
        auto helper = [&](auto&&self,int i,int j)->void{
            for(auto&dirs:directions){
                int ni = i+dirs.first;
                int nj = j+dirs.second;
                if(ni<0 or nj<0 or ni>=n or nj>=m){
                }else{
                    if(board[ni][nj]=='O'){
                        board[ni][nj]='s';
                        self(self,ni,nj);
                    }
                }
            }
        };
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                board[i][0]='s';
                helper(helper,i,0);
            }
            if(board[i][m-1]=='O'){
                board[i][m-1]='s';
                helper(helper,i,m-1);
            }
        }
        
        for(int i=1;i<m-1;i++){
            if(board[0][i]=='O'){
                board[0][i]='s';
                helper(helper,0,i);
            }
            if(board[n-1][i]=='O'){
                board[n-1][i]='s';
                helper(helper,n-1,i);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<board[i][j]<<" ";
                if(board[i][j]=='s'){
                    board[i][j]='O';
                }else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }cout<<endl;
        }
        return;
    }
};
