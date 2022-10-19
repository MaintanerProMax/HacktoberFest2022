class Solution {
public:
    map<string,int> m;
    int n;
    bool compare(string a,string b){
        int n = a.length();
        int i = 0;
        int count = 0;
        while(i<n){
            if(a[i]!=b[i]){
                count++;
            }
            i++;
        }
        if(count==1) return true;
        return false;
    }
    
    int bfs(vector<int> adj[],string beginWord, string endWord){
        vector<int> distance(n+1,1e9);
        queue<int> q;
        distance[m[endWord]] = 0;
        q.push(m[endWord]);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto a:adj[node]){
                if(distance[a] > distance[node] + 1){
                    distance[a] = distance[node] + 1;
                    q.push(a);
                }
            }
        }
        // for(int i=0;i<=n;i++){
        //     cout<<i<<" "<<distance[i]<<endl;
        // }
         return distance[m[beginWord]];
        
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         n = wordList.size();
        vector<int> adj[n+1];
        for(int i=0;i<n;i++){
            m[wordList[i]] = i;
        }
        int idx = n;
        if(m.find(beginWord)==m.end()) m[beginWord] = idx;
        else idx = m[beginWord];
        // cout<<m[beginWord]<<endl;
       for(int i=0;i<n;i++){
           for(int j = i+1;j<n;j++){
               if(compare(wordList[i],wordList[j])){
                   adj[i].push_back(j);
                   adj[j].push_back(i);
               }
               
           }
           if(compare(wordList[i],beginWord)) {
               adj[i].push_back(idx);
               adj[idx].push_back(i);
           }
       }
        // for(int i=0;i<=n;i++){
        //     cout<<i<<" ";
        //     for(auto a:adj[i]){
        //         cout<<a<<" ";
        //     }
        //     cout<<endl;
        // }
        
        if(m.find(endWord)!=m.end()){
            int a = bfs(adj,beginWord,endWord);
            if(a!=1e9) return a+1;
        }
        return 0;
    }
};
