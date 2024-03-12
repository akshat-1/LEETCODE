class Solution {
public:
    string largestGoodInteger(string num) {
        int start =0;
        int n = num.length();
        int ans = -1;

        while(start < n-2)
        {
            if(num[start+1] == num[start] && num[start+2] == num[start])
            {
                    ans = max(int(num[start]), ans);   
            }
            start++;
        }


        return (ans == -1) ? "": string(3,ans);
        
    }
};