#include <bits/stdc++.h>
using namespace std;

class Solution{
    vector<vector<int>> val;
    vector<int> curr;
    int pos[11];
public:

    //function to check if the move is safe
    bool isSafe(int row, int col,int n) {
        for(int i=0;i<row;i++){
            if(i!=row){
                if(pos[i]==col) return false;
                if(abs(row-i)==abs(col-pos[i])) return false;
            }
        }
        return true;
    }

    //recursion + backtracking
    bool backtrack_rec(int row,int n) {

        if(row>=n){
            val.push_back(curr);
            curr.pop_back();
            return true;
        }

        for(int i=0;i<n;i++){

            if(isSafe(row,i,n))
            {
                pos[row]=i;
                curr.push_back(i+1);
                backtrack_rec(row+1,n);
            }
        }

        curr.pop_back();
        return false;
    }

    //utility function
    vector<vector<int>> nQueen(int n) {
        vector<int> v;
        int pos[n];
        memset(pos,-1,sizeof(pos));
        backtrack_rec(0,n);
        return val;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
} 
