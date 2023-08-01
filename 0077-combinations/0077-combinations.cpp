class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> >res;
        if(n<k)return res;
        vector<int> temp;
        combine(res,temp,0,0,n,k);
        //for(int i=0;i<result[0].size())
        return res;
    }
    
    void combine(vector<vector<int> > &res,vector<int> &temp,int start,int num,int n ,int k){
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }
        for(int i = start;i<n;i++){
            temp.push_back(i+1);
            combine(res,temp,i+1,num+1,n,k);
            temp.pop_back();
            }
        }
};