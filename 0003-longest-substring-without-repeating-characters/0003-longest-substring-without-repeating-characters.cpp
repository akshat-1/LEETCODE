class Solution {
public:

bool donotrepeat(int& start, int& end, int index, string& s)
{
    for(int i=start ; i<=end ; i++)
    {
        if(s[i] == s[index]) return false;
    }
    return true;
}
    int lengthOfLongestSubstring(string s) {
        int start =0;
        int end =0;
        int n = s.length()-1;

        int ans=0;
        int temp=0;
        if(n == 0)
        {
            return 1;
        }
        else
        {

        while(end < n)
        {
            if(donotrepeat(start , end , end+1 ,s))
            {
                end++;
                temp = (end - start +1 );

                if(temp>ans) {
                    ans = temp;
                }
            }
            else{
                start++;
            }

            
           
        }
        return ans;
    }
    }
};