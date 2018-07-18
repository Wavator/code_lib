import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

public class Main {
    public static void main(String[] args) {
        //InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        //InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(new Scanner(System.in), out);
        out.close();
    }

    static class TaskA {

        final int N = 4005;

        BigInteger dp[];

        final int prev[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

        public void solve(Scanner in, PrintWriter out) {
            dp = new BigInteger[N];
            dp[0] = BigInteger.valueOf(1);
            for (int i = 1; i < N; ++i)
                dp[i] = BigInteger.ZERO;
//            v = new BigInteger[10];
//            for (int i = 0; i < v.length; ++i) {
//                v[i] = BigInteger.valueOf(prev[i]);
//            }
            for(int i = 0;i < N - 2000;i++){
                for(int j=0;j < 10;j++){
                    if(i == 0 && j == 0) continue;
                    if(i + prev[j] < N) dp[i + prev[j]]=dp[i + prev[j]].add(dp[i]);
                }
            }
            dp[6] = dp[6].add(BigInteger.valueOf(1));
            for (int i = 2; i < N; ++i) dp[i] = dp[i].add(dp[i - 1]);
            while (in.hasNext()) {
                out.println(dp[in.nextInt()]);
                //out.flush();
            }
        }
    }
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}