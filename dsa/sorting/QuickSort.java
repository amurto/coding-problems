import java.util.*;
import java.io.*;

public class QuickSort {
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

    public static void quicksort(int[] a, int low, int high) {
        if (low<high) {
            int pi = partition(a, low, high);
            quicksort(a, low, pi-1);
            quicksort(a, pi+1, high);
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
        quicksort(a, 0, n-1);
        StringBuffer sb = new StringBuffer();
        for (int v: a)
            sb.append(v+" ");
        System.out.println(sb);
    }
}