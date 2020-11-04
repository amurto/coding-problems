import java.util.*;
import java.io.*;

public class sh {
    public static boolean isHash(String p, String h) {
        List<Character> P = new ArrayList<Character>();
        List<Character> H = new ArrayList<Character>();
        for (int i=0;i<p.length(); i++) {
            P.add(p.charAt(i));
        }
        for (int i=0;i<h.length(); i++) {
            H.add(h.charAt(i));
        }
        Collections.sort(P);
        for (int i=0; i<=H.size() - P.size(); i++) {
            if (P.contains(H.get(i))) {
                List<Character> arr = new ArrayList<Character>();
                for (int j=i; j<i+P.size(); j++) {
                    arr.add(H.get(j));
                }
                Collections.sort(arr);
                if (P.equals(arr))
                    return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int t = in.nextInt();
        boolean ans[] = new boolean[t];
        for (int i=0; i<t;i++) {
            ans[i] = isHash(in.next(), in.next());
        }
        in.close();
        for (int i=0; i<t; i++) {
            if (ans[i])
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}