// https://practice.geeksforgeeks.org/problems/minimum-points-to-reach-destination0540/1
// Minimum Points To Reach Destination

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int mp(vector<vector<int>> &points, vector<vector<int>> &dis, int i, int j, int &M, int &N)
{
    if (dis[i][j] == INT_MAX)
    {
        int right = INT_MAX, down = INT_MAX;
        // right
        if (i + 1 < M)
        {
            int res = mp(points, dis, i + 1, j, M, N);
            if (points[i][j] >= 0) 
                if (points[i][j] >= res)
                    right = 1;
                else
                    right = res - points[i][j]; 
            else 
                right = res + points[i][j]*-1;
        }

        // down
        if (j + 1 < N)
        {
            int res = mp(points, dis, i, j + 1, M, N);
            if (points[i][j] >= 0)
                if (points[i][j] >= res)
                    down = 1;
                else
                    down = res - points[i][j];
            else
                down = res + points[i][j]*-1;
        }
        dis[i][j] = min(right, down);
    }
    return dis[i][j];
}

int minPoints(vector<vector<int>> points, int M, int N)
{
    vector<vector<int>> dis(M, vector<int>(N, INT_MAX));
    if (points[M-1][N-1] >= 0)
        dis[M-1][N-1] = 1;
    else
        dis[M-1][N-1] = points[M-1][N-1] * -1 + 1;
    return mp(points, dis, 0, 0, M, N);
}

int main()
{
    int M, N;
    cin >> M >> N;
    vector<vector<int>> points(M, vector<int>(N));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> points[i][j];
    cout << minPoints(points, M, N) << "\n";
    return 0;
}