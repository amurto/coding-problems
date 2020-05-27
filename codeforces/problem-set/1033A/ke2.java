// A and C should be in same quadrant O(1)
import java.util.*;
import java.io.*;

public class ke2 {
    public static boolean in_middle(int L, int x, int R) {
        return ((L <= x && x <= R) || (R <= x && x <= L));
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int n = in.nextInt();
        int ax = in.nextInt();
        int ay = in.nextInt();
        int bx = in.nextInt();
        int by = in.nextInt();
        int cx = in.nextInt();
        int cy = in.nextInt();
        in.close();
        boolean qx = in_middle(bx, ax, cx);
        boolean qy = in_middle(by, ay, cy);
        if (qx || qy)
            System.out.println("NO");
        else
            System.out.println("YES");
    }
}