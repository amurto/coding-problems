// https://codeforces.com/problemset/problem/1327/B
// Princesses and Princes

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k, p, daughter = -1;
        cin >> n;
        vector<vector<int>> g(n+1);
        for (int i=1; i<=n; i++) {
            cin>>k;
            while (k-->0) {
                cin >> p;
                g[i].push_back(p);
            }
        }
        vector<bool> kingdom(n+1);

        for (int i=1; i<=n; i++) {
            bool flag =false;
            for (int prince: g[i]) {
                if (kingdom[prince])
                    continue;
                flag = true;
                kingdom[prince] = true;
                break;
            }
            if (!flag) 
                daughter = i;
        }

        int prince = 0;
        for (int i=1; i<=n; i++)
            if (!kingdom[i]) {
                prince = i;
                break;
            }
        if (prince > 0) 
            cout << "IMPROVE\n" << daughter << " " << prince << "\n";
        else
            cout << "OPTIMAL\n";
    }
    return 0;
}