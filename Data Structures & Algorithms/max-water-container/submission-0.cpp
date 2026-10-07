class Solution {
public:
    int maxArea(vector<int>& heights) {
        int st = 0, dr = heights.size() - 1,max = 0, vol;
        while(st < dr)
        {
            vol = (dr - st) * min(heights[st],heights[dr]);
            if ( vol > max)
                max = vol;
            if (heights[st] < heights [dr])
                st ++;
            else
                dr --;
        }
        return max;
    }
};
