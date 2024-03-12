class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int j=0;

        int m = word1.length();
        int n = word2.length();
        string merged ="";

        while(i<m && j<n)
        {
            merged += word1[i];
            i++;
            merged += word2[j];
            j++;
        }

        if(i<m)
        {
            for(i ; i<m;i++)
            {
            merged += word1[i];
            }
        }
        if(j<n)
        {
            for(j ; j<n;j++)
            {
            merged += word2[j];
            }
        }

        return merged;
        
    }
};