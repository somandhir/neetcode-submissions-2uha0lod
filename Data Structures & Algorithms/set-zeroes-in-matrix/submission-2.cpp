class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row0 = false, col0 = false;
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 or j==0){
                    if(i==0 and j==0 and matrix[i][j]==0){
                        row0=true;col0=true;continue;
                    }
                    if(i==0){
                        if(matrix[0][j]==0) row0 = true;
                    }else{
                        if(matrix[i][0]==0) col0 = true;
                    }
                    continue;
                }
                if(matrix[i][j]==0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                
                if(matrix[i][0]==0 or matrix[0][j]==0) matrix[i][j] = 0;
            }
        }
        for(int i=0;(i<m or i<n);i++){
            if(i<n){
                if(row0){
                    matrix[0][i] = 0;
                }
            }
            if(i<m){
                if(col0){
                    matrix[i][0] = 0;
                }
            }
        }
    }
};
