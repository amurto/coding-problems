// https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression/0
// Longest Arithmetic Progression

import java.util.*;
import java.io.*;

public class p29 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String[] line = br.readLine().trim().replaceAll("  ", " ").split(" ");
            ArrayList<Integer> A = new ArrayList<Integer>();

            for (int i=0; i<n; i++)
                A.add(Integer.parseInt(line[i]));

            int[][] dp = new int[n][n];
            int max=2;
            for (int i=0; i<n; i++) 
                dp[i][n-1] = 2;

            for (int j=n-2;  j>0; j--) {
                int i=j-1, k=j+1;
                while (i>=0 && k<n) {
                    if (A.get(i) + A.get(k) < 2*A.get(j))
                        k++;
                    else if (A.get(i) + A.get(k) > 2*A.get(j)) {
                        dp[i][j]=2;
                        i--;
                    } else {
                        dp[i][j] = dp[j][k] + 1;
                        max=Math.max(max, dp[i][j]);
                        i--;
                        k++;
                    }
                }
                while (i>=0) {
                    dp[i][j]=2;
                    i--;
                }
            }
            if (n<=2) 
                System.out.println(n);
            else {
                System.out.println(max);
            }   
        }
    }
}