// Maximum Product Subarray
// https://practice.geeksforgeeks.org/problems/maximum-product-subarray/0

import java.util.*;
import java.io.*;

public class p3 {
    final static long m = 1000000007L;
    public static long getProdMod(long v1, long v2) {
        return ((v1%m)*(v2%m))%m;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line  = br.readLine().split(" ");
            long[] a = new long[n];
            for (int i=0;i<n;i++) 
                a[i] = Long.parseLong(line[i]);
            
            if (n==1)
                System.out.println(a[0]);
            else {
                long max = 1, min = 1, ans=a[0];
                for (int i=0;i<n;i++) {
                    if (a[i]<0) {
                        long temp=min;
                        min=max;
                        max=temp;
                    }
                    System.out.println(max+" "+min);
                    max=Math.max(getProdMod(max, a[i]),a[i]);
                    min=Math.min(getProdMod(min, a[i]),a[i]);
                    ans=Math.max(ans%m,max%m);
                }
                System.out.println(ans);
            }
        }
    }
}