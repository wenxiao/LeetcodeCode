
class Solution
{
    //从大到小每次猜测解的一个二进制位，假设猜测到第k个二进制位的时候，如果剩下的
    //被除数>=2^k*除数，则解的对应二进制位为1，否则为0
    //因为最小负数的绝对值>最大正数，因此在不用longlong的前提下，采用负数进行计算，
    //最求效率损失了一定的可读性
public:
    int trydivide(int& dividend, int divisor_pow_k, int k)
    {
        if (divisor_pow_k<dividend)
            return 0;

        //防止溢出int范围
        long long ans = INT_MIN / 2 > divisor_pow_k ? 0 : trydivide(dividend, divisor_pow_k * 2, k * 2);

        if (dividend <= divisor_pow_k)
        {
            dividend -= divisor_pow_k;
            ans -= k;
        }
        return ans;
    }
    int divide(int dividend, int divisor)
    {

        if (divisor == 0)
            return INT_MAX;
        
        int sign = 1;
        if (dividend>0)
        {
            dividend = -dividend;
            sign = -sign;
        }

        if (divisor>0)
        {
            divisor = -divisor;
            sign = -sign;
        }

        int ret = trydivide(dividend, divisor, 1);
        if (ret==INT_MIN && sign==1)ret = INT_MAX;
        else ret = -sign*ret;
        return ret;
    }
};