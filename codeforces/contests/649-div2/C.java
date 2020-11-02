import java.util.*;
import java.lang.*;
import java.io.*;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] line = br.readLine().split(" ");
        int[] a = new int[n + 1];
        int[] b = new int[n + 1];
        int[] h = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            a[i] = Integer.parseInt(line[i - 1]);
            h[a[i]] = i;
        }

        int c = 0;
        while (h[c] > 0)
            c++;

        int next = -1;

        for (int i = 1; i <= n; i++) {
            if (next == -1) {
                b[i] = c;
                c++;
            } else
                b[i] = next;

            if (h[a[i]] == i)
                next = a[i];
            else {
                while (c <= n && h[c] > 0)
                    c++;
                next = -1;
            }
        }

        for (int x = 1; x <= n; x++)
            System.out.print(b[x] + " ");
    }

}
