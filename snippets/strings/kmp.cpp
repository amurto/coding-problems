// KMP String Searching Algorithm

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Prefix Function from cp-algorithms
vector<int> prefix_function(string s)
{
    int n = (int)s.length();
    vector<int> pre(n);
    for (int i = 1; i < n; i++)
    {
        int j = pre[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pre[j - 1];
        if (s[i] == s[j])
            j++;
        pre[i] = j;
    }
    return pre;
}

const int N = 1e5 + 5;
int t[N][26];
int transition(vector<int> &pre, string &pat, int k, char ch)
{
    if (t[k][ch - 'A'] == -1)
    {
        int v = k;
        if (v == pat.length())
            v = pre[v - 1];
        if (ch == pat[v])
            v++;
        else
        {
            while (v > 0 && ch != pat[v])
                v = pre[v - 1];
            v += (ch == pat[v]);
        }
        t[k][ch - 'A'] = v;
    }
    return t[k][ch - 'A'];
}

// Count frequency of pat in tex
int KMPSearch(string text, string pat)
{
    int m = pat.length(), j = 0, cnt = 0;
    vector<int> pre = prefix_function(pat);
    for (char ch : text)
    {
        // If current matching has reached end of pat, use link to previous prefix
        if (j == m)
        {
            j = pre[j - 1];
            cnt++;
        }
        // Same character, then increase current match
        if (ch == pat[j])
            j++;
        else
        {
            // Iterate over previous prefix matches
            while (j > 0 && ch != pat[j])
                j = pre[j - 1];
            // Update j if a valid match is found, else no prefix exists at current char
            j += (ch == pat[j]);
        }
    }
    cnt += (j == m);
    return cnt;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    // Count of string s2 in s1
    cout << KMPSearch(s1, s2) << "\n";
    return 0;
}