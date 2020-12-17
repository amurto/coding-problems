import java.util.*;
import java.lang.*;
import java.io.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long k = Long.parseLong(br.readLine());
        char[] sent = { 'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's' };
        long[] m = { 1L, 1L, 1L, 1L, 1L, 1L, 1L, 1L, 1L, 1L };
        long product = 1L;
        int i = 0;
        while (product < k) {
            product /= m[i];
            m[i]++;
            product *= m[i];
            i++;
            i %= 10;
        }
        for (int j = 0; j < 10; j++) {
            long temp = m[j];
            while (temp > 0) {
                System.out.print(sent[j]);
                temp--;
            }
        }
    }

}
