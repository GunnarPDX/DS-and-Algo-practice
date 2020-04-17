class Solution {
public:
    bool isHappy(int n) {
        if (n == 0) return false;
        int value = n;
        while(
                value != 1
                && value != 4
                && value != 16
                && value != 37
                && value != 58
                && value != 89
                && value != 145
                && value != 42
                && value != 20
                ){
            value = applySquares(value);
        }

        return value == 1;
    }

    int applySquares(int num) {
        int res = 0;
        while(num > 0){
            res += pow(num % 10, 2);
            num = num / 10;
        }
        return res;
    }

};