// https://practice.geeksforgeeks.org/problems/find-largest-word-in-dictionary/0
// Find largest word in dictionary

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n, max=-1, len;
        cin>>n;
        string dict[n], str;
        for (int i=0; i<n; i++)
            cin>>dict[i];
        cin>>str;
        len=str.length();
        for (int i=0; i<n; i++) {
            int m=0, l=dict[i].length();
            for (int j=0; j<len; j++) {
                if (dict[i][m] == str[j])
                    m++;
                if (m>=l) {
                    if (max==-1 || l>dict[max].length())
                        max=i;
                    break;
                }
            }
        }
        cout<<dict[max]<<endl;
    }
    return 0;
}