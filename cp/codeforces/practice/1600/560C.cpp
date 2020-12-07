// https://codeforces.com/contest/560/problem/C
// Gerald's Hexagon

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int sap(int a, int n)
{
    return n * (a + n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> s(6);
    cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4] >> s[5];
    // upper trapezium with ap
    int t1 = sap(s[0] * 2 + 1, min(s[1], s[5]));

    // lower trapezium with ap
    int t2 = sap(s[3] * 2 + 1, min(s[2], s[4]));

    // middle rhombus
    int t3 = (max(s[1], s[5]) - min(s[1], s[5])) * (s[0] + min(s[1], s[5])) * 2;
    cout << t1 + t2 + t3 << "\n";
    return 0;
}