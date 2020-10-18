// Stair Paths

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void getStairPaths(string soFar, int cur, int n, vector<string> &ans)
{
    if (cur > n)
        return;
    if (cur == n)
    {
        ans.pb(soFar);
        return;
    }
    for (int i = 1; i <= 3; i++)
        getStairPaths(soFar + to_string(i), cur + i, n, ans);
}

int main()
{
    int n;
    cin >> n;
    vector<string> ans;
    getStairPaths("", 0, n, ans);
    for (string v : ans)
        cout << v << "\n";
    return 0;
}