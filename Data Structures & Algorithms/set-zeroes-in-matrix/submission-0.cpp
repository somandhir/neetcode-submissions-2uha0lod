class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int>zeroRow(m),zeroCol(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    zeroRow[i] = 1;
                    zeroCol[j] = 1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(zeroRow[i] or zeroCol[j]) matrix[i][j] = 0;
            }
        }
    }
};
