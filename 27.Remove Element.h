class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int end_ptr=n-1;
        //�����һ��������Ҫɾ�������ƶ�������β��
        for(int i=0;i<=end_ptr;)
            if(A[i]==elem)
                swap(A[i],A[end_ptr--]);
            else 
                i++;
        return end_ptr+1;
    }
};