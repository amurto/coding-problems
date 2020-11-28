// https://codeforces.com/contest/518/problem/B
// Tanya and Postcard

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.length(), y = 0, w = 0;
    vector<int> f11(26), f12(26), f21(26), f22(26);
    for (char ch : s)
    {
        if (ch >= 'A' && ch <= 'Z')
            f11[ch - 'A']++;
        if (ch >= 'a' && ch <= 'z')
            f12[ch - 'a']++;
    }
    for (char ch : t)
    {
        if (ch >= 'A' && ch <= 'Z')
            f21[ch - 'A']++;
        if (ch >= 'a' && ch <= 'z')
            f22[ch - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        int temp = 0;

        y += min(f11[i], f21[i]);
        temp = f11[i];
        f11[i] = max(0, f11[i] - f21[i]);
        f21[i] = max(0, f21[i] - temp);
        y += min(f12[i], f22[i]);
        temp = f12[i];
        f12[i] = max(0, f12[i] - f22[i]);
        f22[i] = max(0, f22[i] - temp);

        w += min(f11[i], f22[i]);
        temp = f11[i];
        f11[i] = max(0, f11[i] - f22[i]);
        f22[i] = max(0, f22[i] - temp);
        w += min(f12[i], f21[i]);
        temp = f12[i];
        f12[i] = max(0, f12[i] - f21[i]);
        f21[i] = max(0, f21[i] - temp);
    }
    cout << y << " " << w << "\n";
    return 0;
}