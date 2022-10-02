class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
         vector<vector<int>>ans;
        vector<pair<int,int>>v;
        for(int i=0;i<b.size();i++)
        {
            v.push_back({b[i][0],-b[i][2]});
            v.push_back({b[i][1],b[i][2]});
        }
        sort(v.begin(),v.end());
        
        int height_change=0;
        
        map<int,int>mp;  
        mp[0]++;  //0 is initial height;
        for(int i=0;i<v.size();i++)
        {
            int k1=v[i].first,k2=v[i].second;
            if(k2<0)
            {
                mp[-k2]++;
            }
            else
            {
                if(mp.find(k2)!=mp.end())
                {
                    mp[k2]--;
                    if(mp[k2]==0)mp.erase(k2);
                }
            }
            map<int,int>::iterator it=mp.end();
            it--;
            if(height_change!=it->first)
            {
                height_change=it->first;
                ans.push_back({k1,height_change});
            }
        }
        return ans;
        
    }
};

/*



2 -5
3  5


*/

