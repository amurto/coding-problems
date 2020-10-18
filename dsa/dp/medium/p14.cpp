// https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1
// Maximum path sum in matrix

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int DP[101][101];

int MP(vector<vector<int>> &M, int r, int c, int N) {
    if (c<0 || c>=N)    
        return 0;
    if (r==N-1)
        return M[r][c];
    if (DP[r][c] < 0) 
        DP[r][c] = M[r][c] + max(MP(M, r+1, c-1, N), max(MP(M, r+1, c, N),MP(M, r+1, c+1, N)));
    return DP[r][c];
}

int maximumPath(int N, vector<vector<int>> Matrix)
{
    memset(DP, -1, sizeof(DP));
    int MAX=0;
    for (int i=0; i<N; i++)
        MAX= max(MAX, MP(Matrix, 0, i, N));
    return MAX;
}

int main()
{
    int N = 2;
    vector<vector<int>> Matrix = {{348, 391},
                                  {618, 193}};
    cout<<maximumPath(N, Matrix)<<endl;
    return 0;
}