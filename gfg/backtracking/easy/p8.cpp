// four moves are available make moves in the order 't', 'l', 'd' and 'r'
// Flood Fill

#include <bits/stdc++.h>
using namespace std;

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
string D = "tldr";
bool valid(int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void floodfill(string soFar, vector<vector<int>> &MAT, int curI, int curJ, int n, int m)
{
    if (curI == n - 1 && curJ == m - 1)
        cout << soFar << "\n";
    else if (MAT[curI][curJ] == 0)
    {
        MAT[curI][curJ] = 1;
        for (int dir = 0; dir < 4; dir++) {
            if (valid(curI + di[dir], curJ + dj[dir], n, m))
                floodfill(soFar + D[dir], MAT, curI + di[dir], curJ + dj[dir], n, m);
        }
        MAT[curI][curJ] = 0;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> MAT(n, (vector<int>(m)));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> MAT[i][j];
    floodfill("", MAT, 0, 0, n, m);
    return 0;
}