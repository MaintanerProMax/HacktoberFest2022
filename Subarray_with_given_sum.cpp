
#include <bits/stdc++.h>
using namespace std;




class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
      vector <int > v;
     long long  int sum=0,l=0,high=0;
     for(int i=0;i<n;i++){
       sum+=arr[i];
         
         if(sum==s){
             v.push_back(l+1);
             v.push_back(i+1);
             return v;
         }
       
         else if(sum>s){
             sum=0;
             //sum+=arr[i];
             i=l;
             l++;
             
         }
        
          
     }
      v.push_back(-1);
      return v;
      
    }
};



int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
