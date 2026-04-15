class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int lo = 0 , hi = m*n-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            int r = mid/n;
            int c = mid%n;
            cout<<mid<<" "<<r<<" "<<c<<endl;
            cout<<lo<<" "<<hi<<endl;
            // 3 rows , 10 cols
            // 9/10
            if(matrix[r][c]==target)return true;
            else if (matrix[r][c]<target)lo=mid+1;
            else hi=mid-1;
            cout<<lo<<" "<<hi<<endl;
        }
        return false;
    }
};
