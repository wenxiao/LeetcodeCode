class Solution
{
    //时间复杂度O(log(k)=log((m+n)/2)=log(m+n))
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
    //找两个数组中的第k小数
    double findKthInSortedArrays(int A[], int m, int B[], int n, int k)
    {
        //特殊情况处理

        if (m == 0)
            return B[k - 1];
        if (n == 0)
            return A[k - 1];
        if (k == 1)
            return min(A[0], B[0]);

        //比较A[i]和B[j]的时候，如果A[i]>B[j]，
        //说明B[0..j]属于最小的i+j+1个数当中。反之亦然。
        //因此可以令i,j=k/2-1，这样如果A[i]>B[j]，
        //那么B[0..j]一定在最小的k-1个数中。

        //为了防止两个数组大小不均，需要处理边界情况
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