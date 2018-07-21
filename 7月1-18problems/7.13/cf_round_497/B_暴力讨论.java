import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
    static int T,a,b,c,cnt[] = new int[100005];
    static void gao(int X) {
        for(int i=1;i*i<=X;++i) {
            if(X%i==0) {
                cnt[X]++;
                if(i*i!=X)
                    cnt[X]++;
            }
        }
    }
    static Integer gcd(Integer a,Integer b) { return b != 0?gcd(b,a%b):a;}
    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            for(int i=1;i<=100000;++i)
                gao(i);
            for (T = in.nextInt(); T-- > 0;) {
                a = in.nextInt(); b = in.nextInt(); c = in.nextInt();
                int ab=gcd(a,b);
                int ac=gcd(a,c);
                int bc=gcd(b,c);
                int abc=gcd(ab,c);
                long wa[] = new long[7];
                wa[0] = (cnt[abc]);
                wa[1] = (cnt[ab]-cnt[abc]);
                wa[2] = (cnt[ac]-cnt[abc]);
                wa[3] = (cnt[bc]-cnt[abc]);
                wa[4] = (cnt[a]-cnt[ab]-cnt[ac]+cnt[abc]);
                wa[5] = (cnt[b]-cnt[ab]-cnt[bc]+cnt[abc]);
                wa[6] = (cnt[c]-cnt[ac]-cnt[bc]+cnt[abc]);
                out.println(wa[0]+ (wa[0]-1)*wa[0]+ wa[4]*wa[5]*wa[6]+ wa[4]*wa[5]*wa[2]+ wa[4]*wa[5]*wa[3]+ wa[4]*wa[5]*wa[0]+ wa[4]*wa[1]*wa[6]+ wa[4]*wa[1]*wa[2]+ wa[4]*wa[1]*wa[3]+ wa[4]*wa[1]*wa[0]+ wa[4]*wa[3]*wa[6]+ wa[4]*wa[3]*wa[2]+ wa[4]*wa[3]*wa[0]+ wa[4]*wa[0]*wa[6]+ wa[4]*wa[0]*wa[2]+ wa[1]*wa[5]*wa[6]+ wa[1]*wa[5]*wa[2]+ wa[1]*wa[5]*wa[3]+ wa[1]*wa[5]*wa[0]+ wa[1]*wa[3]*wa[6]+ wa[1]*wa[3]*wa[2]+ wa[1]*wa[3]*wa[0]+ wa[1]*wa[0]*wa[6]+ wa[1]*wa[0]*wa[2]+ wa[2]*wa[5]*wa[6]+ wa[2]*wa[5]*wa[3]+ wa[2]*wa[5]*wa[0]+ wa[2]*wa[1]*wa[6]+ wa[2]*wa[3]*wa[6]+ wa[2]*wa[3]*wa[0]+ wa[2]*wa[0]*wa[6]+ wa[0]*wa[5]*wa[6]+ wa[0]*wa[5]*wa[3]+ wa[0]*wa[3]*wa[6]+ wa[0]*(wa[0]-1)*(wa[0]-2)/6+ (wa[0]+wa[0]*(wa[0]-1)/2)*wa[4]+ (wa[3]+wa[3]*(wa[3]-1)/2)*wa[4]+ (wa[1]+wa[1]*(wa[1]-1)/2)*wa[6]+ (wa[1]+wa[1]*(wa[1]-1)/2)*wa[2]+ (wa[1]+wa[1]*(wa[1]-1)/2)*wa[3]+ (wa[1]+wa[1]*(wa[1]-1)/2)*wa[0]+ (wa[3]+wa[3]*(wa[3]-1)/2)*wa[1]+ (wa[0]+wa[0]*(wa[0]-1)/2)*wa[1]+ (wa[2]+wa[2]*(wa[2]-1)/2)*wa[5]+ (wa[2]+wa[2]*(wa[2]-1)/2)*wa[1]+ (wa[2]+wa[2]*(wa[2]-1)/2)*wa[3]+ (wa[3]+wa[3]*(wa[3]-1)/2)*wa[2]+ (wa[2]+wa[2]*(wa[2]-1)/2)*wa[0]+ (wa[0]+wa[0]*(wa[0]-1)/2)*wa[2]+ (wa[0]+wa[0]*(wa[0]-1)/2)*wa[5]+ (wa[3]+wa[3]*(wa[3]-1)/2)*wa[0]+ (wa[0]+wa[0]*(wa[0]-1)/2)*wa[3]+ (wa[0]+wa[0]*(wa[0]-1)/2)*wa[6]);
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