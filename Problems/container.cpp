class Solution {
public:

    int solve( vector<int>&height )
    {
        vector< pair<int,int> > leftBars ;

        int ans = 0 ;

        for(int i=0 ; i<height.size() ; i++)
        {
            if( leftBars.size()==0 || leftBars.back().first < height[i] ) leftBars.push_back( make_pair(height[i],i) ) ;
            else{
                int idx = lower_bound(leftBars.begin(),leftBars.end(),make_pair(height[i],-1) ) - leftBars.begin() ;
                ans = max( ans , height[i]*(i-leftBars[idx].second) ) ;
            }
        }

        return ans ;
    }

    int maxArea(vector<int>& height) {
        int ans = solve(height) ;
        reverse(height.begin(),height.end()) ;
        ans = max(ans, solve(height)) ;

        return ans ;
    }
}
