import java.util.*;
import java.io.*;

public class F {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int t = in.nextInt();
        while (t>0) {
            int n = in.nextInt();
            int a[] = new int[n];
            int b[] = new int[n];
            Boolean possible = true;
            for (int i=0; i<n; i++) 
                a[i] = in.nextInt();
            for (int i=0; i<n; i++) 
                b[i] = in.nextInt();

            if(n % 2 == 1 && a[n/2] != b[n/2])
                possible = false;
            
            int used[] = new int[n];

            for (int i=0; i<n/2; i++) {
                Boolean check = false;
                for (int j=0; j<n; j++) {
                    if (a[i] == b[j] && a[n - i - 1] == b[n - j - 1] && used[j] == 0 && used[n - j - 1] == 0) {
                        check = true;
                        used[j] = 1;
                        used[n - j - 1] = 1;
                        break;
                    }

                }
                if (!check) {
                    possible = false;
                    break;
                }
            }
            

            System.out.println(possible ? "yes" : "No");
            t--;
        }
        in.close();
    }
    
}