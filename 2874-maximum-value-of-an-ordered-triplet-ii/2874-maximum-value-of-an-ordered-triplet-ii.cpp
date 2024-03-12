class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
         long long int ans = 0;
         int max_i = max(nums[0] , nums[1]);
        
       
       int max_diff = nums[0] - nums[1];

        for(int k=2; k<nums.size() ; k++)
        {    
            long long val = (long long) max_diff*nums[k];
            if(val > ans) ans = val;
           
           max_diff = max(max_diff , max_i - nums[k] );
           max_i = max(max_i ,nums[k] );
        }

        return ans;
    }

    
};