class Solution {
public:
bool mySqrt(int x) {
        int l=1; int h=x; int ans=0;
        while(l<=h)
        {  long long mid=l+ (h-l)/2;
            if((long long)mid*mid==x) return true;//ans=mid; l=mid+1;}
            else if(mid*mid<x) l=mid+1;
            else
            h=mid-1;
        }
        return false;
    }
    bool isPerfectSquare(int num) {
        return  mySqrt(num);
    }
};