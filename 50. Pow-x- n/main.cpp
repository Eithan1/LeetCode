//bool minus = false;
//因为int范围负数比整数多一个，故不可行，故分成两个函数处理(特殊处理INT_MIN)
//if(n < 0) {   //现将负数变为整数处理，并标记minus为true
//    n = -n;
//    minus = true;
//}

class Solution {
public:
    double Pow(double x, int n) {
        double half;
        double res;
        if(n == 0)
            return 1;
        half = myPow(x, n / 2); //每次折半递归
        if(n % 2 == 0)   //n为奇偶数分情况讨论
            res = half * half;
        else
            res = x * half * half; //奇数需要多乘个x
        return res;
    }

    double myPow(double x, int n) {

        if(n < 0) {
            if(n == INT_MIN)
                return 1 / (Pow(x, INT_MAX) * x); //特殊处理INT_MIN
            return 1 / Pow(x, -n);
        }
        return Pow(x, n);
    }
};
