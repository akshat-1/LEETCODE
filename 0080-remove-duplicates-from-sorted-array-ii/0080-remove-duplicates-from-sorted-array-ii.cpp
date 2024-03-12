class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1;
        int cnt=0;
        int k=1;
    while(i<nums.size() && j<nums.size())
    {
        if(nums[i] == nums[j] && cnt<1)
        {  if(j == i+1)
            {
            j++;
            i++;
            k++;
            cnt++;
            }
          else
            {
            nums[++i] = nums[j++];
            k++;
            cnt++;
            }
        }
        else if(nums[i] == nums[j] && cnt>=1)
        {
            j++;
        }
        else if(nums[i]!= nums[j])
        {
            nums[++i] = nums[j++];
            cnt=0;
            k++;
        }
    }

return k;
    }

    
};