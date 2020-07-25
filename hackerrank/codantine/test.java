import java.util.*;
import java.io.*;

public class test {
    public static ArrayList<ArrayList<ArrayList<Long>>> DP = new ArrayList<ArrayList<ArrayList<Long>>>();
    public static long num = 0L;  
    public static int k;
    final static long m = 1000000007L;

    public static long mod(long a) { 
        return a % m; 
    }

    public static long minusmod(long a) { 
        return (a%m - m) % m; 
    }

    public static long call(int pos, int ndgt) {
        if(pos == num){
            return 1L;
        }

        long res = 0L;

        int LMT=3;

        for(int dgt = 0; dgt<=LMT; dgt++){
            if (dgt != ndgt) 
                res = res + call(pos+1, dgt); 
        }
        res = res%m;
        return res;
    }

    public static long solve(long n) {
        DP.clear();
        num = n;
        long res = call(0, 6);
        return res;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine()) - 1L;
        long res = solve(n);
        if (res < 0)
            res+=m;
        System.out.println(res);
    }
}

