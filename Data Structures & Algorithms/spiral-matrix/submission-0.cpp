class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int minR = 0, maxR = n-1;
        int minC = 0, maxC = m-1;
        int cnt = 0;
        int idx = 0;
        vector<int>res(n*m);
        while(minR<=maxR and minC<=maxC){
            if(cnt==0){ // go right
                for(int i=minC;i<=maxC;i++){
                    res[idx++] = matrix[minR][i];
                }
                minR++;
            }else if(cnt==1){ // go down
                for(int i=minR;i<=maxR;i++){
                    res[idx++] = matrix[i][maxC];
                }
                maxC--;
            }else if(cnt==2){ // go left
                for(int i=maxC;i>=minC;i--){
                    res[idx++] = matrix[maxR][i];
                }
                maxR--;
            }else{ // go up
                for(int i=maxR;i>=minR;i--){
                    res[idx++] = matrix[i][minC];
                }
                minC++;
            }
            cnt++;cnt%=4;
        }
        return res;
    }
};
