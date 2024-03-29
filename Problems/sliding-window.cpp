vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        priority_queue<pair<int,int>> q;
        int n = arr.size();
        vector<int>ans;

        for(int i = 0; i < k; i++){
            q.push({arr[i], i});
        }

        ans.push_back(q.top().first);

        for(int i = k; i < n; i++){
            q.push({arr[i], i});

            while(i - q.top().second >= k){
                q.pop();
            }

            ans.push_back(q.top().first);
        }

        return ans;
    }
