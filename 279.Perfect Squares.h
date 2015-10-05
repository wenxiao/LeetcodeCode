class Solution {
public:
    int numSquares(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        for(int i=1;i<=n;i++){
            ans[i]=ans[i-1]+1;
            for(int j=2;j*j<=i;j++){
                ans[i]=min(ans[i],ans[i-j*j]+1);
            }
        }
        return ans[n];
    }
};