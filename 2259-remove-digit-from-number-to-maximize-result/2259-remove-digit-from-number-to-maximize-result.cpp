class Solution {
public:
    string removeDigit(string number, char digit) {
        int last;
        for(int i=0 ; i<number.length();i++)
        {
            if(number[i] == digit)
            {
                if(number[i] < number[i+1])
                {
                    number.erase(number.begin() + i);
                    return number;
                }
                last = i;
               
            }
        }

        number.erase(number.begin()+ last);
        return number;
        
    }
};