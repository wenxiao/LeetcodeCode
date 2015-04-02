
class Solution
{
    //时间，空间复杂度：O(n)
public:
    string longestPalindrome(string s)
    {
        //首先在字符串首尾以及任意字符之间加入特殊字符'0'，将奇数字符的回文串于偶数字符的回文串一起考虑
        
        int extended_length = s.size() * 2 + 1;
        
        //扩展后的字符串
        vector<char> ts(extended_length);
        //每个字符为中心的最长回文串的半径，若以当前字符为中心的回文串长度为2l+1，则定义半径为l。
        vector<int> pal(extended_length);
        
        //当前覆盖区间最右的回文串的中点与右端点
        //如果当前考虑的点i<rightmost_right
        //那么其pal[i]=min(pal[2*rightmost_mid-i],rightmost_right-i)
        //如果i+pal[i]==rightmost_mid，还可能较上述值大，需要逐一考虑。
        
        int rightmost_mid = 0, rightmost_right = 0, longest_p = 0, longest_mid;

        for (int i = 0; i<s.size(); i++)
        {
            ts[i * 2] = 0;
            ts[i * 2 + 1] = s[i];
        }
        ts[s.size() * 2] = 0;

        for (int i = 0; i<extended_length; i++)
        {
            if (i <= rightmost_right)
            {
                pal[i] = min(pal[2*rightmost_mid-i],rightmost_right-i);
            }
            else
            {
                pal[i] = 0;
            }
            while (i-pal[i]>0 && i + pal[i] + 1<extended_length && ts[i + pal[i] + 1] == ts[i - pal[i] - 1])
            {
                pal[i]++;
                if (i + pal[i]>rightmost_right)
                {
                    rightmost_right = i + pal[i];
                    rightmost_mid = i;

                    if (pal[i]>longest_p)
                    {
                        longest_p = pal[i];
                        longest_mid = i;
                    }
                }
            }
        }
        
        //将扩展后的字符串还原
        string ret;
        for (int i = longest_mid - longest_p + 1; i <= longest_mid + longest_p - 1; i += 2)
            ret.push_back(ts[i]);

        return ret;
    }
};