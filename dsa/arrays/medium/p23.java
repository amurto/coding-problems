// Design a tiny URL or URL shortener
// https://practice.geeksforgeeks.org/problems/design-a-tiny-url-or-url-shortener/0
// Convert base 10 to base 62

import java.util.*;
import java.io.*;

public class p23 {
    public static void main(String[] args) throws IOException {
        char[] map = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789".toCharArray();
        int[] revMap = new int[256];
        for (int i=0; i<map.length; i++) {
            revMap[map[i]] = i;
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            long n= Long.parseLong(br.readLine());
            StringBuffer url = new StringBuffer();
            while (n>0) {
                url.append(map[(int) (n%62)]);
                n=n/62;
            }
            System.out.println(url.reverse());
            long ans=0;
            for (int i=0; i<url.length(); i++) {
                ans+=revMap[url.charAt(url.length()-i-1)]*Math.pow(62, i);
            }
            System.out.println(ans);
        }
    }
}