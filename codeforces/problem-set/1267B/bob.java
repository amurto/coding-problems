import java.util.*;

public class bob {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String line = in.next();
        in.close();
        ArrayList<List> segments = new ArrayList<List>();
        char[] arr = line.toCharArray();
        int i = 0, c = 0;
        int fin = 0;
        while (i < arr.length) {
            if (i+1 < arr.length && arr[i] == arr[i+1]) {
                i++;
                c++;
            } else {
                segments.add(Arrays.asList(c + 1, arr[i]));
                i++;
                c = 0;
            }
        }
        if (segments.size() % 2 > 0) {
            Boolean ans = true;
            int d = segments.size()/2;
            int n = d;
            int check = 0;
            while (n>0) {
                check = (int) segments.get(d-n).get(0) + (int) segments.get(d+n).get(0);
                if (segments.get(d-n).get(1) != segments.get(d+n).get(1) || check < 2 || (check == 2 && segments.get(d-n+1).get(1) != segments.get(d-n).get(1)))
                    ans = false;
                n--;
            }
            if ((int) segments.get(d).get(0) < 2)
                ans = false;
            if (ans)  
                fin = (int) segments.get(d).get(0) + 1;
            segments.clear();
        } else {
            segments.clear();
        }
        System.out.println(fin);
    }
}