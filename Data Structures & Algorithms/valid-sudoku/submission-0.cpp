class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool lin[10][10] = {0},col[10][10] = {0},patrat[10][10] = {0};
        int x,cont=0;
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                if(j == 1 && i%3 != 1)
                    cont -=3;
                if(j%3 == 1)
                    cont ++;
                if(board[i-1][j-1] == '.')
                    continue;
                x = board[i-1][j-1] - '0';  
                if(lin[i][x] == false)
                    lin[i][x] = true;
                else
                    return false;
                if(col[j][x] == false)
                    col[j][x] = true;
                else
                    return false;
                if(patrat[cont][x] == false)
                    patrat[cont][x] = true;
                else
                    return false;
            }
        }
        return true;
    }
};
