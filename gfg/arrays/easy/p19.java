// https://practice.geeksforgeeks.org/problems/max-sum-path-in-two-arrays/1
// Max sum path in two arrays

import java.util.*;
import java.io.*;

public class p19 {
    public static int max_path_sum(int A[], int B[], int l1, int l2) {
        int i = 0, j = 0, max = 0, sum1 = 0, sum2 = 0;
        while (i < l1 && j < l2) {
            if (A[i] < B[j]) {
                sum1 += A[i++];
            } else if (A[i] > B[j]) {
                sum2 += B[j++];
            } else {
                sum1+=A[i];
                sum2+=B[j];
                if (sum1>sum2)
                    max+=sum1;
                else
                    max+=sum2;
                i++;
                j++;
                sum1 = 0;
                sum2 = 0;
            }
        }
        while (i < l1) {
            sum1 += A[i++];
        }
        while (j < l2) {
            sum2 += B[j++];
        }
        if (sum1>sum2)
            max+=sum1;
        else
            max+=sum2;
        return max;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] line = br.readLine().split(" ");
            int l1 = Integer.parseInt(line[0]);
            int l2 = Integer.parseInt(line[1]);
            int[] A = new int[l1];
            int[] B = new int[l2];
            String[] arr1 = br.readLine().split(" ");
            for (int i = 0; i < l1; i++)
                A[i] = Integer.parseInt(arr1[i]);
            String[] arr2 = br.readLine().split(" ");
            for (int i = 0; i < l2; i++)
                B[i] = Integer.parseInt(arr2[i]);
            System.out.println(max_path_sum(A, B, l1, l2));
        }
    }
}
