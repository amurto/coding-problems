// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell2615/1
// Stock buy and sell

import java.util.*;
import java.io.*;

public class p7 {
    public static void stockBuySell(int[] a, int n) {
        ArrayList<Integer> ans= new ArrayList<Integer>();
        int i=0;
        while (i<n-1) {
            int b=i;
            while (i<n-1 && a[i+1]<=a[i]) 
                i++;
            if (i==n-1)
                break;
            ans.add(i++);
            while ((i<n && i>0) && a[i]>=a[i-1])
                i++;
            ans.add(i-1);
        }
        StringBuffer sb = new StringBuffer();
        if (ans.isEmpty())
            System.out.println("No Profit");
        else {
            for (int j=0;j<ans.size();j+=2) 
            sb.append("("+ans.get(j)+" "+ans.get(j+1)+") ");
            System.out.println(sb);
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
            stockBuySell(a, n);
        }
    }
}