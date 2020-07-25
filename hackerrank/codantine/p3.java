import java.util.*;
import java.math.*;
import java.io.*;

public class p3 {
    final static long modulo = 1000000007L;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int q = Integer.parseInt(line[1]);
        int[] w = new int[n];
        while (q>0) {
            String[] query = br.readLine().split(" ");
            int f = Integer.parseInt(query[0]);
            int A = Integer.parseInt(query[1]);
            int B = Integer.parseInt(query[2]);
            if (f==0) {
                for (int i=A; i<=B;i++) {
                    if (w[i] == 0)
                        w[i] = 1;
                    else
                        w[i] = 0;
                }
            } else {
                int open = 0;
                for (int i=A; i<=B;i++) {
                    if (w[i] == 1)
                        open++;
                }
                System.out.println(open);
            }
            q--;
        }
    }
}
