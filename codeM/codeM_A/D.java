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
    String INPUT = "5 5 3\n" +
            "0111\n" +
            "0010\n" +
            "0101\n" +
            "0110\n" +
            "0111\n" +
            "10000\n" +
            "10000\n" +
            "10001\n" +
            "10000\n" +
            "1 4\n" +
            "4 3\n" +
            "4 2";
 
    String mz[] = new String[2005], stop[] = new String[2005];
 
    boolean tag[][] = new boolean[2005][2005];
 
    class Node implements Comparable<Node>{
 
        Node(long dis, int x, int y) {
            this.dis = dis;
            this.x = x;
            this.y = y;
        }
 
        Long dis;
 
        int x, y;
 
        public int compareTo(Node r) {
            return -dis.compareTo(r.dis);
        }
    }
 
    private void solve() {
        for (int i = 0; i < 2002; ++i)
            Arrays.fill(tag[i], false);
        long ret = 0;
        int n = ni(), m = ni(), k = ni();
        for (int i = 0; i < n; ++i)
            mz[i] = ns();
        for (int i = 0; i < n - 1; ++i)
            stop[i] = ns();
        int bx = 0, by = 0;
        for (int i = 0; i < k; ++i) {
            int x = ni(), y = ni();
            x--;
            y--;
            tag[x][y] = true;
            bx = x;
            by = y;
        }
        long dis[][] = new long[n][m];
        for (int i = 0; i < n; ++i)
            Arrays.fill(dis[i], -1);
        PriorityQueue<Node> q = new PriorityQueue<>();
 
        q.add(new Node(0, bx, by));
 
        while (!q.isEmpty()) {
            Node t = q.poll();
            int x = t.x, y = t.y;
            long d = -t.dis;
            if (dis[x][y] >= 0 && dis[x][y] <= d)
                continue;
            if (dis[x][y] >= 0 && tag[x][y])
                continue;
            if (tag[x][y]) {
                ret += d;
                d = 0;
            }
            dis[x][y] = d;
            if (x + 1 < n && stop[x].charAt(y) == '0')
                q.add(new Node(-d - 1,x + 1,y));
            if (x > 0 && stop[x - 1].charAt(y) == '0')
                q.add(new Node(-d - 1, x - 1, y));
            if (y + 1 < m && mz[x].charAt(y) == '0')
                q.add(new Node(-d - 1, x, y + 1));
            if (y > 0 && mz[x].charAt(y - 1) == '0')
                q.add(new Node(-d - 1, x, y - 1));
        }
        out.println(ret);
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
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
 
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
 
    private long nl()
    {
        long num = 0;
        int b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
 
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
 
    private boolean oj = true;
 
    //private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
    private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}