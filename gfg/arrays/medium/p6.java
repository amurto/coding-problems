// https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1
// Smallest Positive missing number

import java.util.*;
import java.io.*;

public class p6 {
    public static int missingNumber(int arr[], int n) { 
        HashSet<Integer> h = new HashSet<>();
        for (int v: arr)
            if (v>0)
                h.add(v);
        if (h.isEmpty())
            return 1;
        for (int i=1;i<=Integer.MAX_VALUE;i++) 
            if (!h.contains(i))
                return i;
        return -1;
    } 

    public static void main(String[] args) throws IOException {
        int N = 5;
        int[] arr = {0,-10,1,3,-20};
        System.out.println(missingNumber(arr, N));
    }
}