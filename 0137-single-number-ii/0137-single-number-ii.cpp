

class Solution {
public:
int singleNumber(vector<int>& nums) {
    int n = nums.size();

    vector<int>cnt(32,0);   
    
    for( int i=0 ; i<n ; i++){
        for( int j=0 ; j<=31 ; j++){
            if(nums[i] & (1<<j)){           
                cnt[j]++;
            }
        }
    }
    int a=0;
    for( int i=0 ; i<=31 ; i++){
        if(cnt[i]%3!=0){            
            a |=(1<<i);
        }
    }
     
    return a;
}};