class Solution {
public:
    //�������ִ��һ�������������ֻ��Ҫ��ǰ���ɨ�裬��lowest_buy=min(prices[i],lowest_buy)��¼��ǰʱ�̿����򵽵���С��profit=max(profit,prices[i]-lowest_buy);��ʾ������档
    //����ִ����������������������Ȼ��lowest_buy�Լ�profit��ʾɨ�赽��ǰλ��ʱ��һ�ֽ��׵���͹���۸��Լ�����ʵ�ֵ����������ĳһʱ��t�������ڶ��֣��൱�ڲ���t-1ʱ��֮ǰ�������������Ի�õ�������󣬲��ڻ�ø�������򣬼��൱����prices[t]-profit[t-1]�۸�����һ�֣���ʱ��T�����Ժ��������൱��prices[T]-prices[t]+profit[t-1].
    //�����lowest_buy2��ʾ�ڶ��ֹ���ʱ��Ч�����Ź���۸�profit2��ʾ�������ֵ�����������
    //lowest_buy2=min(prices[i]-profit,lowest_buy2);
    //profit2=max(profit2,prices[i]-lowest_buy2);
    int maxProfit(vector<int>& prices) {
        if(prices.empty())return 0;
        int lowest_buy=prices[0], lowest_buy2=prices[0], profit=0, profit2=0;
        for(int i=1;i<prices.size();i++){
            profit2=max(profit2,prices[i]-lowest_buy2);
            lowest_buy2=min(prices[i]-profit,lowest_buy2);
            profit=max(profit,prices[i]-lowest_buy);
            lowest_buy=min(prices[i],lowest_buy);
        }
        return profit2;
    }
};