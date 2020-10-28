// Friend Circles
// https://leetcode.com/problems/friend-circles/

#include <bits/stdc++.h>
using namespace std;

// DFS using stack
// O(n*m) time and space
int findCircleNum(vector<vector<int>> &M)
{
    int circles = 0, n = M.size(), m = M[0].size();
    vector<bool> vis(n);
    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            circles++;
            stack<int> st;
            st.push(i);
            vis[i] = true;
            while (!st.empty())
            {
                int cur = st.top();
                st.pop();
                for (int j = 0; j < m; j++)
                    if (!vis[j] && M[cur][j] == 1)
                    {
                        st.push(j);
                        vis[j] = true;
                    }
            }
        }
    return circles;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> M(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> M[i][j];
    cout << findCircleNum(M) << "\n";
    return 0;
}