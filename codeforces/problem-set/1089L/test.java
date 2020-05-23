import java.io.*;
import java.util.*;

public class Main {

    final static int MAX = 100000;

    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        PrintStream out = System.out;
        int n = cin.nextInt(), k = cin.nextInt(); // idlers num , jobs num
        HashSet<Integer> set = new HashSet<>(); // judge
        int[] a = new int[n], b = new int[n];
        int[] times = new int[MAX];
        for (int i = 0; i < n; i++) {
            a[i] = cin.nextInt();
            set.add(a[i]);
            times[a[i]]++; // record the job be chosen number of times
        }
        for (int i = 0; i < n; i++)
            b[i] = cin.nextInt();
        int noChose = k - set.size(); 
        if (noChose == 0) { // all idlers have job
            out.println(0);
            return;
        }
        Queue<Integer> pq = new PriorityQueue<>((o1, o2) -> o2 - o1); // the big heap
        HashMap<Integer, Integer> maxMap = new HashMap<>();

        for(int i = 0; i < n; i++){
            if(times[a[i]] <= 1)
                continue;
            if(maxMap.get(a[i]) == null){
                maxMap.put(a[i], b[i]);
            }else{
                Integer pMax = maxMap.get(a[i]); 
                if(pMax < b[i]){
                    if(noChose == pq.size()){
                        if(pMax < pq.peek()) {
                            pq.poll();
                            pq.add(pMax);
                        }
                    }else { // if pq.size < noChoseJob, add directly
                        pq.add(pMax);
                    }
                    maxMap.put(a[i], b[i]); // update max
                }else {  // add b[i] to the pq directly
                    if(noChose == pq.size()){
                        if(b[i] < pq.peek()) {
                            pq.poll();
                            pq.add(b[i]);
                        }
                    }else {
                        pq.add(b[i]);
                    }
                }
            }
        }
        long res = 0;  // notice, must long
        while(!pq.isEmpty())
            res += pq.poll();
        out.println(res);
    }
}