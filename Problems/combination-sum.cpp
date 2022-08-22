class Solution {
public:

    void print( vector<int> &sol )
    {
        for( int x: sol )
        {
            cout << x << " ";
        }
        if( sol.size() > 0 )
            cout << endl;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        candidates.insert( candidates.begin(), 0);
        vector< vector<int> > dp[33][505];
        vector< int > empty;
        dp[0][0].push_back( empty );
        //cout << dp[0][0].size() << " " << dp[30][500].size() << endl;
        int n = candidates.size();
        for( int i = 1; i < n; i++ )
        {
            int v = candidates[i];
            vector<int> temp{candidates[i]};
            for( int cur = 0; cur <= target; cur++ )
            {
                dp[i][cur] = dp[i-1][cur];
                if( cur - v < 0 )
                {
                    continue;
                }
                if( cur - v == 0 )
                {
                    dp[i][cur].push_back( temp );
                    continue;
                }
                //cout << cur << " # " << v << endl;

                for( vector<int> vec: dp[i][cur-v] )
                {
                    vector<int> sol;
                    sol.insert( sol.end(), vec.begin(), vec.end() );
                    sol.push_back(v);
                    dp[i][cur].push_back(sol);
                }
            }

            for( int cur = 0; cur <= target; cur++ )
            {
                cout << i << "#" << cur << endl;
                for( vector<int> vec: dp[i][cur] )
                {
                    print(vec);
                }
            }

        }
        return dp[n-1][target];
    }
};
