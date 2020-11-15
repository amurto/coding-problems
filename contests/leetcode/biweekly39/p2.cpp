#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int minimumDeletions(string s)
{
    int ac = 0, bc = 0, da = 0, db = 0;
    for (char ch : s)
        if (ch == 'a')
            ac++;
        else
            bc++;
    if (ac == 0 || bc == 0)
        return 0;
    int i = 0, j = s.length() - 1;
    while (s[i] == 'b')
    {
        db++;
        i++;
    }
    while (s[i] == 'a')
        i++;
    while (s[j] == 'a')
    {
        da++;
        j--;
    }
    while (s[j] == 'b')
        j--;

    int cnta = 0, cntb = 0;
    while (i <= j)
    {
        if (s[i] == 'a')
            cnta++;
        else
            cntb++;
        i++;
    }
    return min({ac, bc, da + cnta, db + cntb});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s = "ababaaaabbbbbaaababbbbbbaaabbaababbabbbbaabbbbaabbabbabaabbbababaa";
    cout << minimumDeletions(s) << "\n";
    return 0;
}