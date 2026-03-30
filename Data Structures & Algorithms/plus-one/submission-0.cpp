class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int borrow = 1;
        for(int i=digits.size()-1;i>=0;i--){
            int sum = digits[i]+borrow;
            if(sum<10){
                borrow = 0;
                digits[i] = sum;break;
            }else{
                digits[i] = 0;
                borrow = 1;
            }
        }
        if(borrow){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
