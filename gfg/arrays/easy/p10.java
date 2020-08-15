// https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x/0
// Smallest subarray with sum greater than x

import java.util.*;
import java.io.*;

public class p10 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] params = br.readLine().split(" ");
            int n = Integer.parseInt(params[0]);
            int k = Integer.parseInt(params[1]);
            String[] line  = br.readLine().split(" ");
            int[] a = new int[n];
            for (int i=0;i<n;i++) 
                a[i] = Integer.parseInt(line[i]);
            
            int sum=0, beg=0, ans = Integer.MAX_VALUE;
            for (int i=0; i<n; i++) {
                sum+=a[i];
                while (beg <= i && sum > k) {
                    ans = Math.min(ans, i-beg+1);
                    sum = sum - a[beg++];
                }
            }
            System.out.println(ans);
        }
    }
}