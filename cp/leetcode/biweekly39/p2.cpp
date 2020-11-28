#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int minimumDeletions(string s)
{
    int i = 0, j = s.length() - 1, a = 0, b = 0;
    while (i < s.length() && s[i] == 'a')
        i++;
    // i -> rightmost 'b'
    while (j >= 0 && s[j] == 'b')
        j--;
    // j -> leftmost 'a'
    if (j < i)
        return 0;
    for (int k = i; k <= j; k++)
        if (s[k] == 'a')
            a++;
        else 
            b++;
    int res = min(a,b), cb=0;
    while (i <= j)
    {
        while (i <= j && s[i] == 'b')
        {
            cb++;
            i++;
        }
        while (i <= j && s[i] == 'a')
        {
            a--;
            i++;
        }
        res = min(res, cb + a);
    }
    return res;
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