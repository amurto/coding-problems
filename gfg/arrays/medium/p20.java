// https://practice.geeksforgeeks.org/problems/inversion-of-array/0
// Inversion of array

import java.util.*;
import java.io.*;

public class p20 {
    public static long ans=0;
    public static void merge(long[] a, int l, int m, int r) {
        int n1= m-l+1;
        int n2=r-m;
        long[] left = new long[n1];
        long[] right = new long[n2];
        for (int i=0; i<n1; i++)
            left[i] = a[l+i];
        for (int i=0; i<n2; i++)
            right[i] = a[m+1+i];
        int i=0, j=0, k=l;
        while (i<n1 && j<n2) {
            if (left[i] <= right[j]) {
                a[k] = left[i];
                i++;
            } else {
                ans=ans+n1-i;
                a[k] = right[j];
                j++;
            }
            k++;
        }
        while (i<n1) {
            a[k] = left[i];
            i++;
            k++;
        }
        while (j<n2) {
            a[k] = right[j];
            j++;
            k++;
        }
    }

    public static void mergesort(long[] a, int l, int r) {
        if (l<r) {
            int m = l + (r - l) / 2; 
            mergesort(a, l, m);
            mergesort(a, m+1, r);
            merge(a, l, m, r);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            long[] a = new long[n];
            for (int i=0; i<n; i++)
                a[i]= Long.parseLong(line[i]);
            ans=0;
            mergesort(a, 0, n-1);
            System.out.println(ans);
        }
    }
}