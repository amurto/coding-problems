// https://codeforces.com/problemset/problem/1360/E
// Polygon

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve(vector<vector<int>> &mat, int n) {
    for (int i=n-1; i>=0; i--) {
        for (int j=n-1;j>=0;j--) {
            if (mat[i][j] == 0 || i==n-1 || j==n-1)
                continue;
            if (mat[i][j+1] == 0 && mat[i+1][j] == 0) 
                return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-->0) {
        int n;
        cin >> n;
        string str;
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i=0; i<n; i++) {
            cin >> str;
            for (int j=0; j<n; j++)
                if (str[j] == '1')
                    mat[i][j] = 1;
        }
        solve(mat, n) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}