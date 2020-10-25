#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while (t-->0) {
        int n, m, v = 0;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        vector<int> mc(n*m + 1);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> v;
                mc[v] = j;
            }
        }

        for (int j=0; j<m; j++) {
            for (int i=0; i<n; i++) {
                cin >> v;
                mat[i][mc[v]] = v;
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) 
               cout << mat[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}