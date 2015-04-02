class Solution
{
    //ʱ�临�Ӷ�O(log(k)=log((m+n)/2)=log(m+n))
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        if ((m + n) % 2 == 0)
        {
            return (findKthInSortedArrays(A, m, B, n, (m + n) / 2 + 1) +
                    findKthInSortedArrays(A, m, B, n, (m + n) / 2)) / 2.0;
        }
        return findKthInSortedArrays(A, m, B, n, (m + n) / 2 + 1);
    }
    //�����������еĵ�kС��
    double findKthInSortedArrays(int A[], int m, int B[], int n, int k)
    {
        //�����������

        if (m == 0)
            return B[k - 1];
        if (n == 0)
            return A[k - 1];
        if (k == 1)
            return min(A[0], B[0]);

        //�Ƚ�A[i]��B[j]��ʱ�����A[i]>B[j]��
        //˵��B[0..j]������С��i+j+1�������С���֮��Ȼ��
        //��˿�����i,j=k/2-1���������A[i]>B[j]��
        //��ôB[0..j]һ������С��k-1�����С�

        //Ϊ�˷�ֹ���������С��������Ҫ����߽����
        int i = min(m - 1, k / 2-1);
        int j = min(n - 1, k / 2-1);

        if (A[i]>B[j])
        {
            return findKthInSortedArrays(A, m, B + j + 1, n - j - 1, k - j - 1);
        }
        else
        {
            return findKthInSortedArrays(A + i + 1, m - i - 1, B, n, k - i - 1);
        }
    }
};