
class Solution
{
    //�Ӵ�Сÿ�β²���һ��������λ������²⵽��k��������λ��ʱ�����ʣ�µ�
    //������>=2^k*���������Ķ�Ӧ������λΪ1������Ϊ0
    //��Ϊ��С�����ľ���ֵ>�������������ڲ���longlong��ǰ���£����ø������м��㣬
    //����Ч����ʧ��һ���Ŀɶ���
public:
    int trydivide(int& dividend, int divisor_pow_k, int k)
    {
        if (divisor_pow_k<dividend)
            return 0;

        //��ֹ���int��Χ
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