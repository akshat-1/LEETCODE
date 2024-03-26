class Solution {
    private:
    void solve(vector<vector<int>> rooms , int i,int n, bool visited[])
    {
        visited[i] = 1;
        for(int j : rooms[i])
        {
            if(!visited[j])
            {
         
            
                solve(rooms , j ,n, visited);
            }
            
        }

        
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int i=0;
       bool visited[rooms.size()];
       fill(visited, visited+rooms.size() , false);
        
        solve(rooms , i ,rooms.size() , visited);
        for(int k =0 ; k<rooms.size() ; k++)
        {
            if(!visited[k])
            {
                return false;
            }
        }
        return true;
        
    }
};