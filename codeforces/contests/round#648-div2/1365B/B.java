import java.util.*;
import java.io.*;

public class B {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int t = in.nextInt();
        while(t>0) {
            int n = in.nextInt();
            int a[] = new int[n];
            for (int i=0;i<n;i++) 
                a[i] = in.nextInt();

            int zeros =0, ones =0;
            for (int i=0;i<n;i++) {
                int temp = in.nextInt();
                if (temp==0)
                    zeros++;
                else
                    ones++;
            }
            if (zeros == 0 || ones == 0) {
                Boolean ans = true;
                for (int i=0;i<n-1;i++) {
                    if (a[i] > a[i+1]) {
                        ans = false;
                        break;
                    }

                }
                if (ans) 
                    System.out.println("Yes");
                else 
                    System.out.println("No");
            } else {
                System.out.println("Yes");
            }

            t--;
        }
        in.close();
    }
}