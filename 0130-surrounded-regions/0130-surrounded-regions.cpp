class Solution {
public:
void dfs(vector<vector<char>>& board, int row,int col)
{ int n=board.size();
        int m=board[0].size();
    board[row][col]='*';
    int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, +0, -1}; 
    for(int i=0;i<4;i++)
    {
        int newr=delrow[i]+row;
        int newc=delcol[i]+col;
        if( newc>0 && newc<m && newr>0 && newr<n && board[newr][newc]=='O')
        dfs(board,newr,newc);
    }
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if( i==0 || i==n-1 || j==0 || j==m-1)
            {
                if(board[i][j]=='O')
                {
                    dfs(board,i,j);
                }
            }

            }
        }  for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='*') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
            
        }

    }
};