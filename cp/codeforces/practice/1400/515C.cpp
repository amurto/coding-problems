// https://codeforces.com/contest/515/problem/C
// Drazil and Factorial

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<vector<int>> MAP = {
        {},
        {},
        {2},
        {3},
        {3, 2, 2},
        {5},
        {5, 3},
        {7},
        {7, 2, 2, 2},
        {7, 3, 3, 2}};
    vector<int> res;
    for (char ch : str)
        for (int v : MAP[ch - '0'])
            res.pb(v);
    sort(res.begin(), res.end(), greater<int>());
    for (int v : res)
        cout << v;
    cout << "\n";
    return 0;
}