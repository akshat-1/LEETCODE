class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int time=0;

        for(int end =0; end<points.size()-1; end++)
        {
            time+= max( abs(points[end][0] - points[end+1][0] ) , abs(points[end][1] - points[end+1][1]) );
        }

        return time;
        


        
    }
};