class Solution
{
public:
  vector<vector<int>> generateMatrix(int n)
  {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int r, c, i, j;
    i = j = r = c = 0;
    int k = 1;
    while (i < n * n)
    {
      // left to right
      while (c < n && matrix[r][c] == 0)
      {

        matrix[r][c] = k++;
        ;
        c++;
        i++;
      }
      r++;
      c--;

      // top to down
      while (r < n && matrix[r][c] == 0)
      {

        matrix[r][c] = k++;
        r++;
        i++;
      }
      r--;
      c--;

      // right to left
      while (c >= 0 && matrix[r][c] == 0)
      {

        matrix[r][c] = k++;
        c--;
        i++;
      }
      r--;
      c++;

      // down to top
      while (r >= 0 && matrix[r][c] == 0)
      {

        matrix[r][c] = k++;
        r--;
        i++;
      }
      r++;
      c++;
    }
    return matrix;
  }
};