// KMP (Knuth Morris Pratt) Algorithm for Pattern Searching
// Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void computeLPS(char *pat, int m, int *LPS)
{
    LPS[0] = 0;
    int len = 0, i = 1;
    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            LPS[i] = ++len;
            i++;    
        }
        else
        {
            if (len == 0)
            {
                LPS[i] = 0;
                i++;
            }
            else
            {
                len = LPS[len - 1];
            }
        }
    }
}

int KMPSearch(char *text, char *pat, int n, int m)
{
    int LPS[m];
    computeLPS(pat, m, LPS);
    int i = 0, j = 0, ans = 0;
    while (i < n)
    {
        if (text[i] == pat[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            j = LPS[j - 1];
            ans++;
        }
        else if (i < n && text[i] != pat[j])
        {
            if (j > 0)
                j = LPS[j - 1];
            else
                i++;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string t1, t2;
        cin >> t1 >> t2;
        int n = t1.length(), m = t2.length();
        char text[n], pat[m];
        for (int i = 0; i < n; i++)
            text[i] = t1[i];
        for (int i = 0; i < m; i++)
            pat[i] = t2[i];
        cout << KMPSearch(text, pat, n, m) << endl;
    }
    return 0;
}