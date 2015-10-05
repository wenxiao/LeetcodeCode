class Solution {
public:
	//用两个指针，一个表示当前扫描到的位置，一个表示下一个非0元素需要插入的位置。
	//注意扫描完以后对剩余数组进行填充。
    void moveZeroes(vector<int>& nums) {
        int l=0,r=0;
        while(r<nums.size()){
            if(nums[r])
                nums[l++]=nums[r];
            r++;
        }
        while(l<nums.size())nums[l++]=0;
    }
};