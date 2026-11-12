class Solution {
public:
    int longestCommonPrefix(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int x=a[i];
            while(x){
                mp[x]=to_string(x).size();
                x/=10;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            int y=b[i];
            while(y){
                if(mp.count(y)){
                    ans=max(ans,mp[y]);  
                }
                y/=10;
            }
        }
        return ans;
    }
};