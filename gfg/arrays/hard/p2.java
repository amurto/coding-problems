// https://practice.geeksforgeeks.org/problems/next-smallest-palindrome/0
// Next Smallest Palindrome

import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class p2 {
    public static Boolean checkAll9s(int[] a) {
        for (int v : a)
            if (v < 9)
                return false;
        return true;
    }

    public static Boolean checkPalindrome(int[] a, int n) {
        int i = n % 2 == 0 ? n / 2 - 1 : n / 2, j = n / 2;
        while (i >= 0 && j < n && a[i] == a[j]) {
            i--;
            j++;
        }
        if (i >= 0 && a[i] > a[j])
            return true;
        else
            return false;
    }

    public static void createPalindrome(int[] a, int n) {
        int i = n % 2 == 0 ? n / 2 - 1 : n / 2, j = n / 2;
        while (i >= 0 && j < n) {
            a[j] = a[i];
            i--;
            j++;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            int[] a = new int[n];
            StringBuffer sb = new StringBuffer();
            for (int i = 0; i < n; i++)
                a[i] = Integer.parseInt(line[i]);

            if (checkAll9s(a)) {
                sb.append(1 + " ");
                for (int i = 0; i < n; i++)
                    sb.append(0 + " ");
                sb.append(1 + " ");
            } else if (checkPalindrome(a, n)) {
                createPalindrome(a, n);
                for (int v : a)
                    sb.append(v + " ");
            } else {
                int m=n % 2 == 0 ? n / 2 - 1:n/2;
                int r=1;
                while (m>=0 && r>0) {
                    r=a[m];
                    r+=1;
                    a[m]=r%10;
                    r/=10;
                    m--;
                }
                createPalindrome(a, n);
                for (int v : a)
                    sb.append(v + " ");
            }
            System.out.println(sb);
        }
    }
}