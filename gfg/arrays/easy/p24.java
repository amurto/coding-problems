// https://practice.geeksforgeeks.org/problems/unsorted-array/0
// Element with left side smaller and right side greater

import java.util.*;
import java.io.*;

public class p24 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String[] line = br.readLine().trim().replaceAll("  "," ").split(" ");
            int[] a = new int[n];
            int[] m= new int[n];
            for (int i=0; i<n; i++) 
                a[i]= Integer.parseInt(line[i]);

            for (int i=n-2; i>0; i--) {
                if (i==n-2)
                    m[i]=a[n-1];
                else
                    m[i]=Math.min(a[i+1], m[i+1]);
            }
            int ans=-1;
            int max=a[0];
            for (int i=1; i<n-1; i++) {
                if (max <= a[i] && a[i] <= m[i]) {
                    ans=a[i];
                    break;
                }
                max=Math.max(max, a[i]);
            }
            System.out.println(ans);
        }
    }
}