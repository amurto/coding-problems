import java.util.*;
import java.io.*;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] bags = new int[n];
        ArrayList<List<Integer>> weights = new ArrayList<List<Integer>>();
        for (int i = 0; i < n; i++) {
            bags[i] = Integer.parseInt(br.readLine());
            ArrayList<Integer> w = new ArrayList<Integer>();
            String[] wts = br.readLine().split(" ");
            for (String s : wts)
                w.add(Integer.parseInt(s));
            weights.add(w);
        }
        System.out.println(weights);
        
    }
}