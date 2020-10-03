import java.util.*;
import java.io.*;

public class A {
    public static int count(int p) {
        if (p%2 == 0)
            return p;
        else 
            return p-1;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int t = in.nextInt();
        int n,x;
        while (t>0 ) {
            ArrayList<Integer> arr = new ArrayList<Integer>();
            n = in.nextInt();
            x = in.nextInt();
            int evn = 0, odd = 0;
            for (int i=0; i<n; i++) {
                int val = in.nextInt();
                if (val%2 == 0)
                    evn++;
                else 
                    odd++;
                arr.add(val);
            }
            if (odd == 0)
                System.out.println("No");
            else {
                odd--;
                if (evn + count(odd) >= x-1)
                    System.out.println("Yes");
                else
                    System.out.println("No");
            }
            t--;
        }
        in.close();
    }
}