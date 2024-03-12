class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int n = nums.size();
       int index=0;
        int count=0;
        for(int i=0 ; i<n ; i++)
        {
            if(nums[i] != val)
            {
               count++;
               nums[index] = nums[i];
               index++;

            }
            
        }

        return count;
    }
};