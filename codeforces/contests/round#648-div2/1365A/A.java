import java.util.*;
import java.io.*;

public class A {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int t = in.nextInt();
        while (t > 0) {
            int n = in.nextInt();
            int m = in.nextInt();
            Set<Integer> claimed_rows = new HashSet<Integer>();
            Set<Integer> claimed_cols = new HashSet<Integer>();
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    int temp = in.nextInt();
                    if (temp == 1) {
                        claimed_rows.add(i);
                        claimed_cols.add(j);
                    }
                }
            }
            int move = 0;
            while (claimed_rows.size() < n && claimed_cols.size() < m) {
                outerloop: 
                for (int i = n; i > 0; i--) {
                    if (!claimed_rows.contains(i)) {
                        for (int j = m; j > 0; j--) {
                            if (!claimed_cols.contains(j)) {
                                claimed_rows.add(i);
                                claimed_cols.add(j);
                                move++;
                                break outerloop;
                            }
                        }
                    }
                }
            }
            System.out.println(move%2 == 1 ? "Ashish" : "Vivek");
            t--;
        }
        in.close();
    }
}