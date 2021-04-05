#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> cnt(3), seq = {0, 1, 2};
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cnt[(i + j) % 3] += (grid[i][j] == '.');
    sort(seq.begin(), seq.end(), [&](int &i1, int &i2) {
        return cnt[i1] < cnt[i2];
    });
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if ((i + j) % 3 == seq[0])
                grid[i][j] = '#';
    for (int i = 0; i < n; i++)
        cout << grid[i] << "\n";
    return 0;
}