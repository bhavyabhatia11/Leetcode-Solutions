class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       int n = nums.size();

       deque<int> s;
       vector<int> ans;
       for(int i=0; i<n; i++){
            while(!s.empty() && i-s.front() >= k){
                s.pop_front();
            }
            while(!s.empty() && nums[s.back()] < nums[i]){
                    s.pop_back();
            }
            s.push_back(i);

            if(i >= k-1){
                ans.push_back(nums[s.front()]);
            }
            
       }

       return ans; 
    }
};