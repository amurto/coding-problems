import java.util.*;
import java.io.*;

public class p2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int t = in.nextInt();

        while (t > 0) {
            int n = in.nextInt();
            int b[] = new int[n];
            int g[] = new int[n];
            for (int i = 0; i < n; i++)
                b[i] = in.nextInt();
            for (int i = 0; i < n; i++)
                g[i] = in.nextInt();
            boolean greater = false;
            Arrays.sort(b);
            Arrays.sort(g);
            ArrayList<Integer> a1 = new ArrayList<Integer>();
            for (int i = 0; i < n; i++) {
                if (b[i] > g[i]) {
                    greater = true;
                    break;
                }

            }
            for (int i = 0; i < n; i++) {
                if (greater) {
                    a1.add(g[i]);
                    a1.add(b[i]);
                } else {
                    a1.add(b[i]);
                    a1.add(g[i]);
                }
            }
            ArrayList a2 = new ArrayList<Integer>();
            a2 = (ArrayList) a1.clone();
            Collections.sort(a1);

            if (a1.equals(a2))
                System.out.println("YES");
            else
                System.out.println("NO");
            t--;
        }
    }
}