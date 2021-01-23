// https://codeforces.com/contest/1064/problem/C
// Oh Those Palindromes

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
    string str;
    cin >> n >> str;
    sort(str.begin(), str.end());
    cout << str << "\n";
    return 0;
}