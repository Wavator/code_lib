import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Set;

public class D {
    InputStream is;
    PrintWriter out;
    String INPUT = "4 2 2 100\n" +
            "1 1\n" +
            "100 99\n" +
            "70 70\n" +
            "40 -1\n" +
            "100 39";

    private class P implements Comparable<P>
    {
        BigDecimal first;
        int second;
        public int compareTo(P o) {
            if (first.compareTo(o.first) == 0)
            {
                if (second < o.second)
                    return 1;
                else
                    return -1;
            }
            return first.compareTo(o.first);
        }
        P(){

        }
        P(BigDecimal x, int y) {
            this.first =  x;
            this.second = y;
        }
    }

    BigDecimal w[] = new BigDecimal[1000];
    int n,m,k,C;
    int cpt[][] = new int[505][7];
    int missi,missj;
    int mxCpt[] = new int[7];
    BigDecimal score[] = new BigDecimal[505];
    BigDecimal missScore[] = new BigDecimal[505];
    int mark[] = new int[505];
    P SCORE[] = new P[505];
    int win[] = new int[505],lose[] = new int[505],noknow[] = new int[505];
    final int round = 100;
    final BigDecimal eps = BigDecimal.valueOf(1).divide(BigDecimal.valueOf(Math.pow(10L, 14)), round, 5);
    int sgn(BigDecimal x){
        if (x.abs().compareTo(eps) < 0)
            return 0;
        return 1;
    }
    private void solve() {
        tr(eps);
        Arrays.fill(score, BigDecimal.ZERO);
        Arrays.fill(missScore, BigDecimal.ZERO);
        Arrays.fill(w, BigDecimal.ZERO);
        n = ni();
        m = ni();
        k = ni();
        C = ni();
        BigDecimal wsm=BigDecimal.ZERO;
        for(int i=1;i<=m;i++){
            w[i] = new BigDecimal(ns());
            wsm = wsm.add(w[i]);
        }
        Set<Integer> ss = new HashSet<>();
        for(int i=1;i<=m;i++) w[i]=w[i].divide(wsm, round, 5);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cpt[i][j] = ni();
                if(cpt[i][j]==-1){
                    missi=i;
                    missj = j;
                }
                mxCpt[j]=Math.max(mxCpt[j],cpt[i][j]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)if(j!=missj){
                if(mxCpt[j]>0)score[i] = score[i].add(w[j].multiply(BigDecimal.valueOf(cpt[i][j]).divide(BigDecimal.valueOf(mxCpt[j]), round, 5)));
            }
        }
        for(int miss=0;miss<=C;miss++){
            double mxs=Math.max(1.0*mxCpt[missj],1.0*miss);
            cpt[missi][missj]=miss;
            for(int i=1;i<=n;i++){
                if(mxs>0)
                {
                    missScore[i]=w[missj].multiply(BigDecimal.valueOf(cpt[i][missj]).divide(BigDecimal.valueOf(mxs), round, 5));
                }
                else missScore[i]=BigDecimal.ZERO;
            }
            for(int i=1;i<=n;i++) {
                SCORE[i] = new P ((score[i].add(missScore[i])).negate(), i);
            }
            Arrays.sort(SCORE,1, n + 1);
            if(k+1<=n && sgn(SCORE[k].first.add(SCORE[k+1].first.negate()))==0) {
                BigDecimal scoreline=SCORE[k].first;
                for(int i=1;i<=n;i++) if(sgn(SCORE[i].first.add(scoreline.negate()))==0){
                    noknow[SCORE[i].second]++;
                }
                for(int i=1;i<=k;i++) if(sgn(SCORE[i].first.add(scoreline.negate()))!=0){
                    win[SCORE[i].second]++;
                }
                for(int i=k+1;i<=n;i++)if(sgn(SCORE[i].first.add(scoreline.negate()))!=0){
                    lose[SCORE[i].second]++;
                }

            }else{
                for(int i=1;i<=k;i++){
                    win[SCORE[i].second]++;
                }
                for(int i=k+1;i<=n;i++){
                    lose[SCORE[i].second]++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(noknow[i]>0||(win[i]>0 && lose[i]>0)) mark[i]=3;
            else if(win[i]>0&&lose[i]==0) mark[i]=1;
            else if(win[i]==0&&lose[i]>0) mark[i]=2;
        }
        for(int i=1;i<=n;i++){
            out.println(mark[i]);
        }
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

    public static void main(String[] args) throws Exception { new D().run(); }

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

   // private boolean oj = true;

    private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
    private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}
