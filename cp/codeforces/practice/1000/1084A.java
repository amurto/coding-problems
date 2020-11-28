import java.util.*;
import java.io.*;

public class tfnea {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int n = in.nextInt();
        ArrayList<Integer> arr = new ArrayList<Integer>();
        arr.add(0);
        for (int i = 1; i <= n; i++) {
            arr.add(in.nextInt());
        }
        in.close();
        int idx = 1;
        int elec = 0;
        for (int i = 1; i <= n; i++) {
            if (i == 1)
                elec += 0;
            else {
                int dis = 2 * Math.abs(idx - i) + 2 * (i - 1) + 2 * (idx - 1);
                dis = dis * arr.get(i);
                elec += dis;
            }
        }
        System.out.println(elec);

    }
}