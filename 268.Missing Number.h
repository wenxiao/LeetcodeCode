class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=1;i<=n;i++)
            ans^=i;
        for(int i:nums)
            ans^=i;
        return ans;
    }
};