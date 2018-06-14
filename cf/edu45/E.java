import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.PriorityQueue;

public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "4 3 4\n" +
            "1 2 3\n" +
            "1 10 100 1000\n";

    final long inf = 0x3f3f3f3f3f3f3f3fL;

    private void solve() {
        int n = ni(), m = ni(), k = ni();
        n++;
        boolean a[] = new boolean[1000002];
        int b[] = new int[1000007];
        int c[] = new int[1000007];
        long ans = inf;
        Arrays.fill(a, false);
        for (int i = 1; i <= m; ++i) {
            a[ni() + 1] = true;
        }
        if(a[1])
        {
            out.println(-1);
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if(a[i])
                b[i] = b[i - 1];
            else
                b[i] = i;
        }
        for (int i = 1; i <= k; ++i)
            c[i] = ni();
        for (int i = 1; i <= k; ++i)
        {
            int tmp = 1;
            long cnt = 1;
            while(true)
            {
                if(tmp + i >= n) {
                    ans = Math.min(ans, cnt * c[i]);
                    break;
                }
                if(b[tmp + i]==tmp)
                    break;
                tmp = b[tmp + i];
                cnt++;
            }
        }
        if (ans == inf)
            ans = -1;
        out.println(ans);
    }

    void run() throws Exception
    {
        is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
        out = new PrintWriter(System.out);

        long s = System.currentTimeMillis();
        solve();
        out.flush();
        tr(System.currentTimeMillis()-s+"ms");
    }

    public static void main(String[] args) throws Exception { new Main().run(); }

    private byte[] inbuf = new byte[1024];
    public int lenbuf = 0, ptrbuf = 0;

    private int readByte()
    {
        if(lenbuf == -1)throw new InputMismatchException();
        if(ptrbuf >= lenbuf){
            ptrbuf = 0;
            try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
            if(lenbuf <= 0)return -1;
        }
        return inbuf[ptrbuf++];
    }

    private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
    private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }

    private double nd() { return Double.parseDouble(ns()); }
    private char nc() { return (char)skip(); }

    private String ns()
    {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    private char[] ns(int n)
    {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while(p < n && !(isSpaceChar(b))){
            buf[p++] = (char)b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }

    private char[][] nm(int n, int m)
    {
        char[][] map = new char[n][];
        for(int i = 0;i < n;i++)map[i] = ns(m);
        return map;
    }

    private int[] na(int n)
    {
        int[] a = new int[n];
        for(int i = 0;i < n;i++)a[i] = ni();
        return a;
    }

    private int ni()
    {
        int num = 0, b;
        boolean minus = false;
        for(;(b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'););
        if(b == '-'){
            minus = true;
            b = readByte();
        }
        for(;;){
            if(Character.isDigit(b)){
                num = num * 10 + (b - '0');
            } else
                return minus ? -num : num;
            b = readByte();
        }
    }

    private long nl()
    {
        long num = 0;
        int b;
        boolean minus = false;
        for(;(b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'););
        if(b == '-'){
            minus = true;
            b = readByte();
        }
        for(;;){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }

    //private boolean oj = true;

    private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
    private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}
