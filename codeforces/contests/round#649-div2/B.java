import java.util.*;
import java.io.*;

public class B {
    public static int compare(int a, int b) {
        if (a > b)
            return -1;
        else
            return 1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t > 0) {
            int n = Integer.parseInt(br.readLine());
            ArrayList<Integer> arr = new ArrayList<Integer>();
            ArrayList<Integer> ans = new ArrayList<Integer>();
            String[] line = br.readLine().split(" ");
            for (String s : line)
                arr.add(Integer.parseInt(s));
            int par = 0;
            if (arr.get(0) > arr.get(1))
                par = -1;
            else
                par = 1;
            ans.add(arr.get(0));
            for (int i = 1; i < arr.size(); i++) {
                int c = compare(arr.get(i - 1), arr.get(i));
                if (c != par) {
                    ans.add(arr.get(i - 1));
                    par = c;
                }
            }
            ans.add(arr.get(arr.size() - 1));
            System.out.print(ans.size() + "\n");
            for (int i = 0; i < ans.size(); i++)
                System.out.print(ans.get(i) + " ");
            System.out.print("\n");
            t--;
        }
    }
}