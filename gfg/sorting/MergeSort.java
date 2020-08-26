import java.util.*;
import java.io.*;

public class MergeSort {
    public static void merge(int[] a, int l, int m, int r) {
        int n1= m-l+1;
        int n2=r-m;
        int[] left = new int[n1];
        int[] right = new int[n2];
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

    public static void mergesort(int[] a, int l, int r) {
        if (l<r) {
            int m = l + (r - l) / 2; 
            mergesort(a, l, m);
            mergesort(a, m+1, r);
            merge(a, l, m, r);
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        String[] arr = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(arr[i]);
        }
        mergesort(a, 0, n-1);
        StringBuffer sb = new StringBuffer();
        for (int v: a)
            sb.append(v+" ");
        System.out.println(sb);
    }
}