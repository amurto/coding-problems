// https://leetcode.com/problems/flood-fill/
// Flood Fill

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
void dfs(vector<vector<int>> &image, int sr, int sc, int startColor, int newColor)
{
    if (image[sr][sc] == startColor)
    {
        image[sr][sc] = newColor;
        for (int dir = 0; dir < 4; dir++)
        {
            int nsr = sr + di[dir], nsc = sc + dj[dir];
            if (nsr >= 0 && nsr < image.size() && nsc >= 0 && nsc < image[0].size())
                dfs(image, nsr, nsc, startColor, newColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int startColor = image[sr][sc];
    if (startColor != newColor)
        dfs(image, sr, sc, startColor, newColor);
    return image;
}

int main()
{
    int sr = 1, sc = 1, newColor = 2;
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    vector<vector<int>> ans = floodFill(image, sr, sc, newColor);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
            cout << image[i][j] << " ";
        cout << "\n";
    }
    return 0;
}