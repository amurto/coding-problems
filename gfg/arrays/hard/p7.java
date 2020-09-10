// https://practice.geeksforgeeks.org/problems/maximum-subset-xor/1
// Maximum subset XOR

import java.util.*;
import java.io.*;

public class p7 {
    final static int INT_BITS = 32;
    public static int maxSubarrayXOR(int set[], int n) {
        int index = 0;
        for (int i = INT_BITS - 1; i >= 0; i--) {
            int maxInd = index;
            int maxEle = -1;
            for (int j = index; j < n; j++) {
                if ((set[j] & (1 << i)) != 0 && set[j] > maxEle) {
                    maxEle = set[j];
                    maxInd = j;
                }
            }

            if (maxEle == -1)
                continue;

            int temp = set[index];
            set[index] = set[maxInd];
            set[maxInd] = temp;

            maxInd = index;

            for (int j = 0; j < n; j++) {
                if (j != maxInd && (set[j] & (1 << i)) != 0)
                    set[j] = set[j] ^ set[maxInd];
            }
            index++;
        }
        int res = 0;
        for (int i = 0; i < n; i++)
            res ^= set[i];
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = Integer.parseInt(line[i]);
        }
    }
}