#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int K = 26;
void solve()
{
    string x;
    cin >> x;
    vector<int> pos(K);
    for (int i = 0; i < K; i++)
        pos[x[i] - 'a'] = i;
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), [&](string &s1, string &s2)
         {
             int len1 = s1.length(), len2 = s2.length();
             for (int i = 0; i < min(len1, len2); i++)
                 if (s1[i] != s2[i])
                     return pos[s1[i] - 'a'] < pos[s2[i] - 'a'];
             return len1 < len2;
         });
    for (string s : arr)
        cout << s << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}