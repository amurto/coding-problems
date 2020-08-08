import java.util.*;
import java.io.*;


public class A {
    public static class SortMarks implements Comparator<ArrayList<Integer>> {
        public int compare(ArrayList<Integer> a1, ArrayList<Integer> a2) {
            if (a1.get(0) < a2.get(0))
                return 1;
            else if (a1.get(0) == a2.get(0) && a1.get(1) > a2.get(1))
                return 1;
            return -1;
        }
    }

    public static void main(String[] args) throws IOException {
        ArrayList<ArrayList<Integer>> a = new ArrayList<ArrayList<Integer>>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int k = Integer.parseInt(line[1]);
        for (int i=0; i<n;i++) {
            String[] newline = br.readLine().split(" ");
            ArrayList<Integer> arr = new ArrayList<Integer>();
            arr.add(Integer.parseInt(newline[0]));
            arr.add(Integer.parseInt(newline[1]));
            a.add(arr);
        }
        Collections.sort(a, new SortMarks());
        ArrayList<Integer> v = a.get(k-1);
        for (int i=0;i<n;i++) {
            if (a.get(i).equals(v)) {
                int c = 0;
                while (i<n && a.get(i).equals(v)) {
                    c++;
                    i++;
                }
                System.out.println(c);
            }
        }
    }
}
