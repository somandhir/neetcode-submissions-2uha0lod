class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int res = 0;

        for(int i = 0; i < 32; i++) {
            int abit = (a >> i) & 1;
            int bbit = (b >> i) & 1;

            int sum = abit ^ bbit ^ carry;

            res |= (sum << i);

            carry = (abit & bbit) | (bbit & carry) | (abit & carry);
        }

        return res;

    }
};
