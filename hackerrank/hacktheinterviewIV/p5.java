import java.util.*;
import java.io.*;

public class p5 {
    public static ArrayList<ArrayList<ArrayList<Integer>>> DP = new ArrayList<ArrayList<ArrayList<Integer>>>();
    public static ArrayList<Integer> num = new ArrayList<Integer>();  
    public static int a, b, d, k;

    public static int call(int pos, int cnt, int f) {
        if(cnt > k) return 0;

        if(pos == num.size()){
            if(cnt == k) return 1;
            return 0;
        }

        if(DP.get(pos).get(cnt).get(f) != -1) return DP.get(pos).get(cnt).get(f);
        int res = 0;

        int LMT;

        if(f == 0){
            /// Digits we placed so far matches with the prefix of b
            /// So if we place any digit > num[pos] in the current position, then the number will become greater than b
            LMT = num.get(pos);
        } else {
            /// The number has already become smaller than b. We can place any digit now.
            LMT = 9;
        }

        /// Try to place all the valid digits such that the number doesn't exceed b
        for(int dgt = 0; dgt<=LMT; dgt++){
            int nf = f;
            int ncnt = cnt;
            if(f == 0 && dgt < LMT) nf = 1; /// The number is getting smaller at this position
            if(dgt > 0) ncnt++;
            if(ncnt <= k) res += call(pos+1, ncnt, nf);
        }
        DP.get(pos).get(cnt).set(f, res);
        return res;
    }

    public static int solve(int b) {
        num.clear();
        DP.clear();
        while(b>0){
            num.add(b%10);
            b/=10;
        }
        Collections.reverse(num);
        /// Stored all the digits of b in num for simplicity
        // DP[12][12][2]

        for (int i=0; i<12;i++) {
            ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
            for (int j=0; j<12;j++) {
                ArrayList<Integer> larr = new ArrayList<Integer>(Arrays.asList(-1, -1));
                arr.add(larr);
            }
            DP.add(arr);
        }
        System.out.println(num);
        int res = call(0, 0, 0);
        return res;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        a = Integer.parseInt(br.readLine());
        b = Integer.parseInt(br.readLine());
        // d = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());
        int res = solve(b) - solve(a);
        System.out.println(res);
    }
}