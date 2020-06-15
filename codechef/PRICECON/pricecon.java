import java.util.*;
import java.io.*;

public class pricecon {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int t = in.nextInt();
        while (t>0) {
            int n = in.nextInt();
            int k = in.nextInt();
            int loss = 0;
            for (int i=0; i<n; i++) {
                int temp = in.nextInt();
                if (temp>k)
                    loss = loss + temp-k;
            }
            System.out.println(loss);
            t--;
        }
        in.close();
    }
}