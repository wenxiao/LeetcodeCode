class Solution {
public:
    //对于最多执行一次买卖的情况，只需要从前向后扫描，用lowest_buy=min(prices[i],lowest_buy)记录当前时刻可能买到的最小金额，profit=max(profit,prices[i]-lowest_buy);表示最大收益。
    //对于执行最多两次买卖的情况，依然用lowest_buy以及profit表示扫描到当前位置时，一手交易的最低购买价格以及可以实现的最大利润。在某一时刻t如果买入第二手，相当于查找t-1时刻之前的所以买卖可以获得的最大利润，并在获得改利润后购买，即相当于以prices[t]-profit[t-1]价格购买了一手，在时刻T抛售以后，总利润相当于prices[T]-prices[t]+profit[t-1].
    //因此令lowest_buy2表示第二手购买时等效的最优购买价格，profit2表示购买两手的最有利润，有
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