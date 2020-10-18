// https://practice.geeksforgeeks.org/problems/tic-tac-toe/0
// Tic-Tac-Toe

import java.util.*;
import java.io.*;

public class p25 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            char[] a = br.readLine().trim().replaceAll(" ", "").toCharArray();
            int x = 0, o = 0, xw = 0, ow = 0;
            for (char c : a)
                if (c == 'X')
                    x++;
                else
                    o++;
            if (x != 5 || o != 4)
                System.out.println("Invalid");
            else {
                // Row check
                for (int i = 0; i < 9; i += 3) {
                    if (a[i] == a[i + 1] && a[i + 1] == a[i + 2]) {
                        if (a[i] == 'X')
                            xw++;
                        else
                            ow++;
                    }
                }

                // Column check
                for (int i = 0; i < 3; i++) {
                    if (a[i] == a[i + 3] && a[i + 3] == a[i + 6]) {
                        if (a[i] == 'X')
                            xw++;
                        else
                            ow++;
                    }
                }

                // Diagonal check
                if (a[0] == a[4] && a[4] == a[8]) {
                    if (a[0] == 'X')
                        xw++;
                    else
                        ow++;
                }
                if (a[2] == a[4] && a[4] == a[6]) {
                    if (a[2] == 'X')
                        xw++;
                    else
                        ow++;
                }
                if (ow > 0)
                    System.out.println("Invalid");
                else
                    System.out.println("Valid");
            }

        }
    }
}