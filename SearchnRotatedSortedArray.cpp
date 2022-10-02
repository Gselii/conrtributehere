class Solution {
public:
    int search(vector<int>& a, int target) {
        
        int n=a.size();
        int l=0;
        int r=n-1;
        int lar=-1;
        
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(a[m]>=a[0])
            {
                lar=m;
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        
        cout<<lar<<endl;
        
        l=0;r=lar;
        
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(a[m]==target)return m;
            else if(target>a[m])
                l=m+1;
            else 
                r=m-1;
        }
        
        l=lar+1;r=n-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(a[m]==target)return m;
            else if(target>a[m])
                l=m+1;
            else 
                r=m-1;
        }
        
        return -1;
        
    }
};
