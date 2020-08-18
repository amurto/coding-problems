// Maximum average subarray
// https://practice.geeksforgeeks.org/problems/maximum-average-subarray/0

import java.util.*;
import java.io.*;

public class p21 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int k = Integer.parseInt(br.readLine());
            int n = Integer.parseInt(br.readLine());
            int[] a = new int[n];
            String[] arr = br.readLine().split(" ");
            for (int i = 0; i < n; i++)
                a[i] = Integer.parseInt(arr[i]);
            
            int sum=0;
            for (int i=0; i<k; i++) 
                sum+=a[i];
            int avg = sum/k, left=0, right=k;
            
            for (int i=k; i<n; i++) {
                sum-=a[i-k];
                sum+=a[i];
                int temp = sum/k;
                if (temp>avg) {
                    avg=temp;
                    left=i-k+1;
                    right=i+1;
                }
            }
            StringBuffer sb = new StringBuffer();
            for (int i = left; i < right; i++) 
                sb.append(a[i] + " ");
            System.out.println(sb);
        }
    }
}