class Solution {
public:
    string longestPalindrome(string s) {
        
        int ans_l=0,ans_r=0;
        
        int len=1;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            //odd;
            
            int l=i-1,r=i+1;
            while(l>=0 && r<n)
            {
                if(s[l]==s[r])
                {
                    if(r-l+1>len)
                    {
                        len=r-l+1;
                        ans_l=l;
                        ans_r=r;
                    }
                }
                else
                    break;
                l--;
                r++;
            }
            l=i;r=i+1;
            //even
            while(l>=0 && r<n)
            {
                if(s[l]==s[r])
                {
                    if(r-l+1>len)
                    {
                        len=r-l+1;
                        ans_l=l;
                        ans_r=r;
                    }
                }
                else
                    break;
                l--;
                r++;
            }
            
        }
        return s.substr(ans_l,len);
        
    }
};
