class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long og_mass=mass;
        for (auto i: asteroids){
            if (og_mass<i) return false;
            else {
                og_mass+=i;
            }
        }
        return true;
    }
};