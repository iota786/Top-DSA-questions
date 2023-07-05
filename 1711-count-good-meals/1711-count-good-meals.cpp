class Solution {
public:
const int mod=1e9+7;

    int countPairs(vector<int>& del) {
        
        vector<int> power(22);
        for(int i=0 ;i<22 ;i++)
        power[i] = (1<<i);

        unordered_map<int, int> mp;

        //for(int i=0 ;i<del.size() ;i++)
       // mp[del[i]]++;

        int ans = 0;
        for(int i=0 ;i<del.size() ;i++){
            long long count = 0;
            int val = del[i];

            for(int j=0 ;j<22 ;j++){
                long long pw = power[j];

                int rem = pw - del[i];
                
                if(mp.find(rem)!=mp.end()){
                    count += mp[rem];
                 //   if(rem==del[i] && mp[rem]>0)  // to avoid duplicate like index 0 have 2 and rem value is also 2 then it take same value from index 0. For example in case -> 1, 1, 1
                   // count--;
                }
            }
            ans = (ans%mod + count%mod)%mod;
            mp[del[i]]++;  // to avoid reverse pair like (1,7) and (7,1)
        }
        return ans;
    }
};