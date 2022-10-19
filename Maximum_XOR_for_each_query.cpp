class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
            int MaXor = 0;
            int n = nums.size();
            for(int i=0;i<n;i++){
                    MaXor = MaXor^nums[i];
            }
            int temp = pow(2,maximumBit) - 1;
            vector<int> ans;
            for(int i=n-1;i>=0;i--){
                    ans.push_back(MaXor^temp);
                    MaXor^=nums[i];
            }
            return ans;
    }
};
