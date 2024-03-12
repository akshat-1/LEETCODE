class Solution {
public:
    vector<int> next_min_index(vector<int> heights , int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i= n-1; i>=0 ; i--)
        {
            while(s.top() != -1 && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
           
            
                ans[i] = s.top();
                s.push(i);
            

        }
        return ans;

    }

     vector<int> prev_min_index(vector<int> heights , int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i= 0; i<n ; i++)
        {
            while(s.top() != -1 && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
           
            
                ans[i] = s.top();
                s.push(i);
            

        }
        return ans;

    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int area = INT_MIN;
        vector<int> next = next_min_index(heights , n);
        vector<int> prev = prev_min_index(heights, n);
        for(int i=0 ; i<n ; i++)
        {
            int length = heights[i];

            if(next[i] == -1)
            {
                next[i] = n;
            }
             int width = next[i] - prev[i] - 1;
            int new_area = length*width;

            area = max(area , new_area);

        }
        return area;
    }
};