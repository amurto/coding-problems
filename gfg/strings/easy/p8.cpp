// https://practice.geeksforgeeks.org/problems/remove-b-and-ac-from-a-given-string/0
// Remove “b” and “ac” from a given string

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        string s;
        cin>>s;
        int n = s.length();
        for (int i=0; i<n ; ) {
            if (s[i] == 'b')
                s.erase(i, 1);
            else if (s[i] == 'a')
                if (i<n-1 && s[i+1]=='c')
                    s.erase(i, 2);
                else
                    i++;
            else
                i++;
        }
        cout<<s<<endl;
    }
    return 0;
}