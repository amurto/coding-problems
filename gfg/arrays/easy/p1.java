// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
// Sort an array of 0s, 1s and 2s

import java.util.*;
import java.io.*;

public class p1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line  = br.readLine().split(" ");
            int[] a = new int[n];
            for (int i=0; i<n; i++) 
                a[i] = Integer.parseInt(line[i]);
            int temp, low=0,mid=0,high= n-1;
            while (mid<=high) {
                if (a[mid] == 0) {
                    a[mid] = a[low];
                    a[low] = 0;
                    low++;
                    mid++;
                } else if (a[mid] == 2) {
                    a[mid] = a[high];
                    a[high] = 2;
                    high--;
                } else {
                    mid++;
                }
            }
            for (int v: a)
                System.out.print(v+" ");
            System.out.println();
        }
    }
}