class Solution {
public:

    void solve(string digits , int index , string map[] ,vector<string>& ans , string output)
    {
        if(index>= digits.length())
        {
            ans.push_back(output);
            return ;
        }

        int number = digits[index] -'0';
        string mapping = map[number -2];

        for(int i=0 ; i < mapping.length() ; i++)
        {
            output.push_back(mapping[i]);
            solve(digits , index+1  , map, ans , output);
            output.pop_back();
        }



    }
    vector<string> letterCombinations(string digits) {
        int index =0;
        string map[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string output;
    if(digits == "")
    {
        return ans;
    }
      else{
         solve(digits , index , map,ans , output);

        return ans;
      }
    }
        
    
};