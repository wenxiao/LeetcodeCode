class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int end_ptr=n-1;
        //如果有一个数字需要删除，则移动到队列尾部
        for(int i=0;i<=end_ptr;)
            if(A[i]==elem)
                swap(A[i],A[end_ptr--]);
            else 
                i++;
        return end_ptr+1;
    }
};