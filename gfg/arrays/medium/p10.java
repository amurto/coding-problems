// https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem/0
// Nuts and Bolts Problem

import java.util.*;
import java.io.*;

public class p10 {
    public static void swap(char[] a, int x, int y) {
        char temp = a[x];
        a[x]=a[y];
        a[y]=temp;
    }
    
    public static int partition (char[] a, int low, int high) {
        char pivot=a[high];
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

    public static char[] nbSort(char[] a, int low, int high) {
        if (low<high) {
            int pi = partition(a, low, high);
            nbSort(a, low, pi-1);
            nbSort(a, pi+1, high);
        }
        return a;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            char[] nuts = br.readLine().replaceAll(" ", "").toCharArray();
            char[] bolts = br.readLine().replaceAll(" ", "").toCharArray();
            nbSort(nuts, 0, n-1);
            nbSort(bolts, 0, n-1);
            for (char v: nuts)
                System.out.print(v+ " ");
            System.out.println();
            for (char v: bolts)
                System.out.print(v+ " ");
            System.out.println();
        }
    }
}