// https://codeforces.com/contest/486/problem/C
// Palindrome Transformation

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int diff(int c1, int c2)
{
    c1 -= 'a';
    c2 -= 'a';
    if (c1 > c2)
        swap(c1, c2);
    return min(c2 - c1, c1 + 26 - c2);
}

int solve()
{
    int n, p;
    cin >> n >> p;
    string str;
    cin >> str;
    int mid = (n + 1) / 2;
    if (p >= mid)
        p = n - p + 1;
    p--;
    int left = p, right = p, moves = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        int req = diff(str[i], str[j]);
        if (req > 0)
        {
            moves += req;
            left = min(left, i);
            right = max(right, i);
        }
    }
    left = p - left;
    right = right - p;
    moves += min(2 * left + right, left + 2 * right);
    return moves;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}