import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
import java.math.*;


public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "6 8\n";
    long INF = (long)1e18+100L;
    long sum(long x){
        if(x>2e9)return INF;
        return ((x&1) == 1)?(x+1)/2*x:x/2*(x+1);
    }


    void solve()
    {
        long n = nl(), h = nl();
        long l=h;
        long r = (long)2e9;
        if(n<sum(h)){
            l=0;
            r=h;
            while (r-l>1){
                long mid =l+r >>1;
                long cost = sum(mid);
                if(n>=cost){
                    l = mid;
                }else{
                    r = mid;
                }
            }
            long ans=0;
            long maxH =0;
            if(n>=sum(r)){
                n-=sum(r);
                maxH =r;
                ans = r;
            }else{
                n-=sum(l);
                maxH =l;
                ans =l;
            }
            ans+=n/maxH;
            n%=maxH;
            if(n != 0)ans++;
            out.println(ans);
            return;
        }
        while (r-l>1){
            long mid = l+r >>1;
            long cost = sum(mid)+sum(mid-1)-sum(h-1);
            if(n>=cost){
                l = mid;
            }else{
                r = mid;
            }
        }
        long ans=0;
        long maxH = -1;
        long costr = sum(r)+sum(r-1)-sum(h-1);
        if(n>=costr){
            ans = r+(r-h);
            maxH=r;
            n-=costr;
        }else{
            long costl =sum(l)+sum(l-1)-sum(h-1);

            ans = l+(l-h);
            maxH =l;
            n-=costl;
        }
        ans+=n/maxH;
        n%=maxH;
        if(n != 0)ans++;
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

    private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
    private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}
