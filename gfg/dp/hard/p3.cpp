// https://practice.geeksforgeeks.org/problems/boolean-parenthesization/0
// Boolean Parenthesization

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e3+3;
int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int m;
        cin>>m;
        char v;
        vector<int> op, sym; 
        for (int i=0; i<m; i++) {
            cin>>v;
            if (v=='T' || v=='F')
                op.push_back(v);
            else
                sym.push_back(v);
        }

        int n=op.size();    
        int T[n][n], F[n][n];

        // Gaps of 0
        // Check for same element
        for (int i=0; i<n; i++) {
            if (op[i] == 'T') {
                T[i][i] = 1;
                F[i][i] = 0;
            } else {
                T[i][i] = 0;
                F[i][i] = 1;
            }
        }

        for (int gap=1; gap<n;gap++) {
            for (int i=0, j=gap; j<n; i++, j++) {
                T[i][j] = F[i][j] = 0;
                for (int g=0; g<gap; g++) {
                    int k=i+g;
                    int ik = T[i][k] + F[i][k];
                    int kj = T[k+1][j] + F[k+1][j];
                    if (sym[k] == '&') {
                        T[i][j] += (T[i][k]*T[k+1][j])%MOD;
                        F[i][j] += (ik*kj - T[i][k]*T[k+1][j])%MOD;
                    }
                    if (sym[k] == '|') {
                        T[i][j] += (ik*kj - F[i][k]*F[k+1][j])%MOD;
                        F[i][j] += (F[i][k]*F[k+1][j])%MOD;
                    }
                    if (sym[k] == '^') {
                        T[i][j] += (T[i][k]*F[k+1][j] + F[i][k]*T[k+1][j])%MOD;
                        F[i][j] += (T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j])%MOD;
                    }
                }
            }
        }
        cout<<(T[0][n-1]%MOD)<<endl;
    }
    return 0;
}