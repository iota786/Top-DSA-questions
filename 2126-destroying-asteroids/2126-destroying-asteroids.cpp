class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end()); long long m=(long long)mass;
        for(int i=0;i<asteroids.size();i++)
        {
            if(m<asteroids[i]) return false;
            m+=asteroids[i];
        }
        return true;
    }
};