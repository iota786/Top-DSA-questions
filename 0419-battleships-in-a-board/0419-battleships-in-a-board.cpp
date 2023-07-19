class Solution {
private:
	void dfs(int i, int j, vector<vector<char>>& adj) {
		int n = adj.size(), m = adj[0].size();
		if((i >= 0) && (j >= 0) && (i < n) && (j < m) && adj[i][j] == 'X') {
			adj[i][j] = '#';
			dfs(i+1, j, adj);
			//dfs(i-1, j, adj);
			dfs(i, j+1, adj);
			//dfs(i, j-1, adj);
		}
	}
public:
    int countBattleships(vector<vector<char>>& adj) {
        int n = adj.size(), m = adj[0].size();
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(adj[i][j] == 'X') {
                    ++cnt;
                    dfs(i, j, adj);
                }
            }
        }
        return cnt;
    }
};