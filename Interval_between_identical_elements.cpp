class Solution {
public:
    
    void solve(vector<int>& arr,vector<long long>& ans){
        int n = arr.size();
         map<int,int> Index,freq;
         for(int i=0;i<n;i++){
             if(Index.find(arr[i])!=Index.end()){
                 ans[i] += (freq[arr[i]])*(i - Index[arr[i]]) + ans[Index[arr[i]]];
             }
             Index[arr[i]] = i;
             freq[arr[i]]++;
         }
    }
    void solve_reverse(vector<int>& arr,vector<long long>& ans){
        int n = arr.size();
        vector<long long> temp(n,0);
         map<int,int> Index,freq;
         for(int i=n-1;i>=0;i--){
             if(Index.find(arr[i])!=Index.end()){
                 temp[i] += (freq[arr[i]])*( Index[arr[i]] - i) + temp[Index[arr[i]]];
                 ans[i]+=temp[i];
             }
             Index[arr[i]] = i;
             freq[arr[i]]++;
         }
    }
    
    
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        // map<int,int> Index,freq;
        vector<long long> ans(n,0);
        solve(arr,ans);
        solve_reverse(arr,ans);
        return ans;
    }
};
