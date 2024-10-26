#include <iostream> 
#include <vector> 

using namespace std;

    string longestCommonPrefix(vector<string>& strs) {
        int least;
        std::string ans; 
        std::vector<string> leastarr;
        leastarr = strs;
        std::string temp;
        int q =0;
        std::string ans1 = "";
        if(strs.empty()){
            return ans1;
        }
        int n = strs.size(); 
        if(n==2){
            if(strs[0].size() > strs[1].size()){
               least = strs[1].size(); 
            }
            else{
                least = strs[0].size();
            }
            for(int j = 0; j<least; j++){
            while(strs[0][j] == strs[1][j]){
                ans.push_back(strs[0][j]);
                     
            }
                if(ans.empty()){
return ans1;
                }
            }
            return ans;
            }
        
        
        if(n>2){
        for(int i = 0; i<n-1; i++){
            for(int l = 0; l<n-i - 1; l++){
                if(leastarr[l].size() > leastarr[l+1].size()){
                    temp = leastarr[l];
                    leastarr[l] = leastarr[l+1];
                    leastarr[l+1] = temp;
                }
            }
            least = leastarr[0].size();
        }
        
            
          for(int i = 0; i<n; i++){
              for(int j = 0; j<least; j++){
                  while(strs[i][j] == strs[i+1][j]){
                      ans[q] = strs[i][j];
                      q++;
                  }
              }
          }
            if(ans.empty()){
                return ans1;
            }
            else{
            return ans;
            }
            
    }
        return ans;
    }


int main(){


    return 0;
}