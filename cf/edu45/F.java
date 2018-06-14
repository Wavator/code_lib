import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.PriorityQueue;

public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "4\n" +
            "3 -10 6 1\n" +
            "5\n" +
            "1 2\n" +
            "3 2\n" +
            "2 4\n" +
            "3 4\n" +
            "3 1\n";

    final long inf = 0x3f3f3f3f3f3f3f3fL;
    int MAXN = 200010;
    int dsu[] = new int[MAXN];
    void Init(){
        for (int i = 0; i <= MAXN-1; ++i) dsu[i] = i;
    }
    int Findfa( int pos ){
        if( dsu[pos] == pos ) return pos;
        return dsu[pos] = Findfa(dsu[pos]);
    }
    boolean Unite( int a , int b ){
        a = Findfa(a);
        b = Findfa(b);
        if( a == b ) return false;
        dsu[a] = b;
        return true;
    }

    class Edge{
        int to,flow,id;
        Edge(){}
        Edge( int tt , int ii ){
            to = tt; flow = 0;
            id = ii;
        }
    };
    ArrayList<Edge> e[] = new ArrayList[MAXN];
    int n,m;
    int s[] = new int[MAXN];

    int f[] = new int[MAXN];

    int UE = 233333333;
    void Findans(){
        out.printf("Possible\n");
        Arrays.fill(f, 0);
        for (int i = 1; i <= n; ++i){
            for(int j = 0; j < e[i].size(); ++j){
                if( e[i].get(j).id >= UE ) continue;
                if( e[i].get(j).flow == 0 ) continue;
                //O(e[i][j].id);
                //cout << i << " " << e[i][j].to << endl;
                if( e[i].get(j).id > m ){
                    f[e[i].get(j).id-m] = -e[i].get(j).flow;
                }else{
                    f[e[i].get(j).id] = e[i].get(j).flow;
                }
            }
        }
        for (int i = 1; i <= m; ++i)
        out.println(f[i]);
    }

    int Dp( int pos , int fa ){
        int sum = s[pos];
        for(int i = 0; i < e[pos].size(); ++i){
            int v = e[pos].get(i).to;
            if( v == fa ) continue;
            int td = Dp(v,pos);
            e[pos].get(i).flow = td;
            sum += td;
        }
        return sum;
    }
    private void solve() {
        n = ni();
        for (int i = 0; i < MAXN; ++i)
            e[i] = new ArrayList<>();
        int tot = 0;
        for (int i = 1; i <= n; ++i){
            s[i] = ni();
            tot += s[i];
        }
        if( tot != 0 ){
            out.printf("Impossible\n");
            return;
        }
        Init();
        m = ni();
        for (int i = 1; i <= m; ++i){
            int s = ni(),t = ni();
            if( !Unite(s,t) ) continue;
            e[s].add( new Edge(t,i) );
            e[t].add( new Edge(s,i+m) );
        }

        int root = 1;
        Dp(root,-1);

        Findans();

        //END();
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
