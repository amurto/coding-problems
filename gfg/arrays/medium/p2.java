// Kth smallest element
// https://practice.geeksforgeeks.org/problems/kth-smallest-element/0

import java.util.*;
import java.io.*;

public class p2 {
    public static void swap(int a[], int x, int y) {
        int tmp = a[x];
        a[x] = a[y];
        a[y] = tmp;
    }

    public static int partition(int[] a, int low, int high) {
        int pivot = a[high];
        int i=low-1;

        for (int j=low; j<high; j++) {
            if (a[j] <= pivot) {
                i++;
                swap(a, i, j);
            }
        }
        swap(a, i+1, high);
        return i+1;
    }

    public static void randomizedQuicksort(int[] a, int low, int high) {
        if (low<high) {
            Random r = new Random();
            int i = r.nextInt(high+1 - low) + low;
            swap(a, i, high);
            int pi = partition(a, low, high);
            randomizedQuicksort(a, low, pi-1);
            randomizedQuicksort(a, pi+1, high);
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] a = new int[n];
            String[] arr = br.readLine().split(" ");
            for (int i = 0; i < n; i++) 
                a[i] = Integer.parseInt(arr[i]);
            int k = Integer.parseInt(br.readLine());
            randomizedQuicksort(a, 0, n-1);
            System.out.println(a[k-1]);
        }
    }
}