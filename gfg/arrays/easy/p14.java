// https://practice.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays/0
// Sum of Middle Elements of two sorted arrays

import java.util.*;
import java.io.*;

public class p14 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] arr1 = br.readLine().split(" ");
            int[] a = new int[n];
            for (int i = 0; i < n; i++) 
                a[i] = Integer.parseInt(arr1[i]);
            
            String[] arr2 = br.readLine().split(" ");
            int[] b = new int[n];
            for (int i = 0; i < n; i++) 
                b[i] = Integer.parseInt(arr2[i]);

            int i= 0, j = 0, temp =0;
            while (i+j < n) {
                if (a[i] < b[j]) 
                    temp=a[i++];
                else
                    temp=b[j++];
            }
            System.out.println(temp + Math.min(a[i], b[j]));
        }
    }
}