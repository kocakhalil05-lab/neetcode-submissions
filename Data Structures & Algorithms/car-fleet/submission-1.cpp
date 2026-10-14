class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector < pair <int , int> > vec;
        for(int i=0;i<speed.size();i++)
        {
            vec.push_back({position[i] , speed[i]});
        }
        sort(vec.begin(),vec.end());
        float max = 0,time;
        int rez = speed.size();
        for(int i = speed.size() - 1; i >= 0 ;i--)
        {
            float time = ((target - vec[i].first) /(float) vec[i].second);
            if (max == 0)
            {
                max = time;
                continue;
            }
            if(time <= max)
            {
                rez --;
            }
            else
                max = time;
        }
    return rez;
    }
};
