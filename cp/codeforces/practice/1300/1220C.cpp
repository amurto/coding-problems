// https://codeforces.com/contest/1220/problem/C
// Substring Game in the Lesson

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    int n = str.length();
    vector<int> pre(n);
    cout << "Mike\n";
    for (int i = 1; i < n; i++)
    {
        pre[i] = (str[pre[i - 1]] < str[i]) ? pre[i - 1] : i;
        pre[i] < i ? cout << "Ann\n" : cout << "Mike\n";
    }
    return 0;
}