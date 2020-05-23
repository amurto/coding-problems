import java.util.*;

public class lazyland {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        int a[] = new int[n];
        int b[] = new int[n];
        ArrayList<Integer> c = new ArrayList<Integer>();
        ArrayList<Integer> t = new ArrayList<Integer>();
        for (int i=0; i<n; i++) 
            a[i] = in.nextInt() - 1;
        for (int i=0; i<n; i++) 
            b[i] = in.nextInt();
        in.close();
        for (int i=0; i<n; i++) {
            if (!c.contains(a[i])) {
                c.add(a[i]);
                ArrayList<Integer> time = new ArrayList<Integer>();
                for (int j=i; j<n; j++) {
                    if (a[j] == a[i]) {
                        time.add(b[j]);
                    }
                }
                if (time.size() > 1) {
                    Collections.sort(time);
                    time.remove(time.size() - 1); 
                    t.addAll(time);
                }
                time.clear();
            }
        }
        Collections.sort(t);
        int sum = 0;
        for (int i=0; i<k-c.size();i++) {
            sum = sum + t.get(i);
        }
        System.out.println(sum);
    }
}