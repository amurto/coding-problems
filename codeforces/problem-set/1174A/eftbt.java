import java.io.*;
import java.util.*;

public class eftbt {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int n = in.nextInt();
        ArrayList<Integer> a = new ArrayList<Integer>();
        for (int i = 0; i < 2*n; i++) {
            a.add(in.nextInt());
        }
        in.close();
        Collections.sort(a);                
        if ((int) a.get(0) == (int) a.get(a.size()-1)) 
            System.out.print(-1);
        else {
            for (int j = 0; j < a.size(); j++) {
                System.out.print(a.get(j) + " ");
            }
        }
    }
}