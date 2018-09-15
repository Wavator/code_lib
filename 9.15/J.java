import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;
import static java.lang.Math.*;

public class Main {
    public static void main(String[] args){
        InputStream inputStream = System.in;//new FileInputStream("C:\\Users\\wavator\\Downloads\\test.in");
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }

    static class Task {

        long pow_mod(long a, long b, long mod) {
            long res = 1;
            for (a %= mod; b != 0; b >>= 1, a = a * a % mod) {
                if (b % 2 == 1) {
                    res = res * a % mod;
                }
            }
            return res;
        }

        int __builtin_ctzll(long x){
            int ans = 0;
            while (x != 0) {
                if (x % 2 == 0) {
                    ++ans;
                } else {
                    return ans;
                }
                x >>= 1;
            }
            return ans;
        }

        long test(long n,long p)
        {
            if(p==2)
                return (n&1) == 1?1:-1;
            if(pow_mod(n,p>>1,p)!=1) return -1;
            if((p&2) != 0) {
                return pow_mod(n,(p+1)>>2,p);
            }
            int s=__builtin_ctzll(p^1);
            long q=p>>s,z=2;
            for(;pow_mod(z,p>>1,p)==1;++z);
            long c=pow_mod(z,q,p),r=pow_mod(n,(q+1)>>1,p),t=pow_mod(n,q,p),tmp;
            for(int m=s,i;t!=1;)
            {
                for(i=0,tmp=t;tmp!=1;++i) tmp=tmp*tmp%p;
                for(;i<--m;) c=c*c%p;
                r=r*c%p;c=c*c%p;t=t*c%p;
            }
            return r;
        }

        final long primes[] = {
                954854573, 967607731, 973215833,
                975831713, 978949117, 980766497,
                983879921, 985918807, 986608921,
                991136977, 991752599, 997137961,
                1003911991, 1009775293, 1012423549,
                1021000537, 1023976897, 1024153643,
                1037027287, 1038812881, 1044754639,
                1045125617, 1047411427, 1047753349,
        };

        boolean testsrc(char[] str) {
            for (long p : primes) {
                long r = 0;
                for (char aStr : str) {
                    r = r * 10 + aStr - '0';
                    r %= p;
                }
                if (r == 0) continue;
                if (test(r, p) < 0) return false;
            }
            return true;
        }

        boolean testsum(char[] str) {
            for (long p : primes) {
                long r = 0;
                for (char aStr : str) {
                    r = r * 10 + aStr - '0';
                    r %= p;
                }
                r = r * (r - 1 + p) % p;
                r = r * ((p + 1) / 2) % p;
                if (r == 0) continue;
                if (test(r, p) < 0) return false;
            }
            return true;
        }

        public void solve(InputReader in, PrintWriter out) {
            for (int T = in.nextInt(); T-- > 0; ) {
                char[] num = in.next().toCharArray();
                int res = 0;
                if (testsrc(num)) res |= 1;
                if (testsum(num)) res |= 2;
                switch (res) {
                    case 0:
                        out.println("League of Legends");
                        break;
                    case 1:
                        out.println("Hearth Stone");
                        break;
                    case 2:
                        out.println("Clash Royale");
                        break;
                    case 3:
                        out.println("Arena of Valor");
                        break;
                }
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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public char[] nextCharArray() {
            return next().toCharArray();
        }
    }
}
