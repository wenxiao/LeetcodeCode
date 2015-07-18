class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //找到最靠后的num[i]<num[i+1]的坐标，并将大于这个元素的最小的一项与其互换位置，并将剩下的元素按照从小到大排列
        int i;
        
        for(i=nums.size()-2;i>=0;i--)
            if(nums[i]<nums[i+1])
                break;
        if(i<0){
            //如果找不到这个坐标，就
            sort(nums.begin(),nums.end());
        }else{
			int j;
			for(j=nums.size()-1;;j--)
				if(nums[i]<nums[j])
					break;
            swap(nums[i],nums[j]);
            sort(nums.begin()+i+1,nums.end());
        }
    }
};