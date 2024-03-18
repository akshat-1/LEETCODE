class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <=1) return 0;
        if(nums.size() == 2) return 1; 
        int right=0,left=0,ans=0,max_rechable=0;

        while(right<nums.size()-1)
        {
            for(int i=left ; i<=right;i++)
            {
                max_rechable = max(max_rechable , i + nums[i]);
            }
            left = right+1;
            right = max_rechable;
            ans++;
        }
        return ans;

        // algo-> for min jumps we need to catch the number with max i+nums[i] value 
    }
};