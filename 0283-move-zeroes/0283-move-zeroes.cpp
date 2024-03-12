class Solution {
public:


    void moveZeroes(vector<int>& nums) {
    int i=0;
    int n = nums.size() -1;
    int m =0;
    
    while(i<=n)
    {
        if(nums[i] !=0)
        {
            nums[m] = nums[i];
            m++;
        }
        i++;
    }
      for(int j = m;j<=n;j++)
      {
          nums[j]=0;
      }  
    } 
};