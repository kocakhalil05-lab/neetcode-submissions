class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int st = 0,dr = numbers.size() - 1 ,sum ;
        vector<int> rez;
        while(st < dr)
        {
            sum = numbers[st] + numbers[dr];
            if( sum == target )
            {
                rez.push_back(st+1);
                rez.push_back(dr+1);
                return rez;
            }
            if(sum > target)
                dr --;
            else
                st ++;
        }
        return rez;
    }
};
