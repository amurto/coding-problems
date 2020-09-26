// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix/0
// Largest square formed in a matrix 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> C(n, vector<int>(m, 0));
        for (int i=0; i<n; i++) 
            for (int j=0; j<m; j++)
                cin>>C[i][j];

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++)
                cout<<C[i][j]<<" ";
            cout<<endl;
        }

        
        cout<<endl;

    }
    return 0;
}