class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() -1;
        if(n == 0) return true;
        int rechable= 0;

        for(int i=0 ; i<n+1;i++)
        {   
            if( i + nums[i] > rechable)
            {
                rechable = nums[i] + i;
            }
            if( rechable >= n) return true;  
            if(i>= rechable) return false;


        }
        return false;
    }
};