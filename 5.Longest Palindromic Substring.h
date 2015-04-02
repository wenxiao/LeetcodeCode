
class Solution
{
    //ʱ�䣬�ռ临�Ӷȣ�O(n)
public:
    string longestPalindrome(string s)
    {
        //�������ַ�����β�Լ������ַ�֮����������ַ�'0'���������ַ��Ļ��Ĵ���ż���ַ��Ļ��Ĵ�һ����
        
        int extended_length = s.size() * 2 + 1;
        
        //��չ����ַ���
        vector<char> ts(extended_length);
        //ÿ���ַ�Ϊ���ĵ�����Ĵ��İ뾶�����Ե�ǰ�ַ�Ϊ���ĵĻ��Ĵ�����Ϊ2l+1������뾶Ϊl��
        vector<int> pal(extended_length);
        
        //��ǰ�����������ҵĻ��Ĵ����е����Ҷ˵�
        //�����ǰ���ǵĵ�i<rightmost_right
        //��ô��pal[i]=min(pal[2*rightmost_mid-i],rightmost_right-i)
        //���i+pal[i]==rightmost_mid�������ܽ�����ֵ����Ҫ��һ���ǡ�
        
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
        
        //����չ����ַ�����ԭ
        string ret;
        for (int i = longest_mid - longest_p + 1; i <= longest_mid + longest_p - 1; i += 2)
            ret.push_back(ts[i]);

        return ret;
    }
};