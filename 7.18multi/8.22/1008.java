import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.InputMismatchException;


public class Main {
    InputStream is;
    PrintWriter out;

    void solve()
    {
        int n = ni();
        while (n-->0)
        {
            BigInteger t = BigInteger.valueOf(2);
            int m = ni();
            out.println(t.pow(m));
        }
    }
    void run() throws Exception
    {
        is = System.in;
        out = new PrintWriter(System.out);
        solve();
        out.flush();
    }

    public static void main(String[] args) throws Exception { new Main().run(); }

    private byte[] inbuf = new byte[1 << 22];
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
    private int ni()
    {
        int num = 0, b;
        for(;(b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'););
        for(;;){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return num;
            }
            b = readByte();
        }
    }
}