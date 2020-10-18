// Maximum Difference
// https://practice.geeksforgeeks.org/problems/maximum-difference/0

import java.util.*;
import java.io.*;

public class p5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            int[] a = new int[n];
            for (int i=0; i<n; i++) 
                a[i] = Integer.parseInt(line[i]);
            
            int ans = -1, max = 0;
            for (int i=n-1; i>=0; i--) {
                if (a[i] >= max)
                    max = a[i];
                else {
                    ans = Math.max(ans, max-a[i]);
                }
            }
            System.out.println(ans);
        }
    }
}