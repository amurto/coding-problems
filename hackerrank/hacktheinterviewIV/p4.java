import java.util.*;
import java.io.*;

public class p4 {
    public static ArrayList<ArrayList<ArrayList<Long>>> DP = new ArrayList<ArrayList<ArrayList<Long>>>();
    public static ArrayList<Integer> num = new ArrayList<Integer>();  
    public static int k;
    final static long m  = 1000000007;

    public static long mod(long a) { 
        return a % m; 
    }

    public static long minusmod(long a) { 
        return (a%m - m) % m; 
    }

    public static long call(int pos, int cnt, int f) {
        if(cnt > k) return 0L;

        if(pos == num.size()){
            if(cnt == k) return 1L;
            return 0L;
        }

        if(DP.get(pos).get(cnt).get(f) != -1L) return DP.get(pos).get(cnt).get(f);
        long res = 0L;

        int LMT;

        if(f == 0){
            LMT = num.get(pos);
        } else {
            LMT = 9;
        }

        for(int dgt = 0; dgt<=LMT; dgt++){
            int nf = f;
            int ncnt = cnt;
            if(f == 0 && dgt < LMT) nf = 1;
            if(dgt > 0) ncnt++;
            if(ncnt <= k) {
                res = mod(res + call(pos+1, ncnt, nf));
            } 
        }
        DP.get(pos).get(cnt).set(f, res);
        return res;
    }

    public static long solve(String[] b) {
        num.clear();
        DP.clear();
        for (int i=0; i<b.length; i++){
            num.add(Integer.parseInt(b[i]));
        }

        for (int i=0; i<101;i++) {
            ArrayList<ArrayList<Long>> arr = new ArrayList<ArrayList<Long>>();
            for (int j=0; j<101;j++) {
                ArrayList<Long> larr = new ArrayList<Long>(Arrays.asList(-1L, -1L));
                arr.add(larr);
            }
            DP.add(arr);
        }
        long res = call(0, 0, 0);
        return res;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] a = br.readLine().split("");
        String[] b = br.readLine().split("");
        k = Integer.parseInt(br.readLine());
        long res = solve(b) - solve(a);
        System.out.println(solve(b) + " " + solve(a));
        System.out.println(res);
    }
}

