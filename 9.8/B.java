import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

public class Main {


    public static void main(String[] args) {
        new Task().solve();
    }

    static class Task {

        boolean isdigit(char c) {
            return c >= '0' && c <= '9';
        }

        void solve() {
            Scanner in = new Scanner(System.in);
            optrToi['+'] = 0;
            optrToi['-'] = 1;
            optrToi['*'] = 2;
            optrToi['d'] = 3;
            optrToi['('] = 4;
            optrToi[')'] = 5;
            optrToi['%'] = 6;
            while (in.hasNext()) {
                //String str = in.next();
                s = in.next().toCharArray();
                Arrays.fill(judge, false);
                Arrays.fill(op, 0);
                while (!optstk.empty()) optstk.pop();
                while (!opnd.empty()) opnd.pop();
                int len = s.length;
                p = 0;
                for (int i = 0; i < len; i++) {
                    if (!isdigit(s[i])) {
                        judge[p] = true;
                        op[p++] = (int) s[i];
                    } else {
                        int j = i;
                        op[p] = s[i] - '0';
                        while (j < len - 1 && (isdigit(s[j + 1]))) {
                            j++;
                            op[p] = op[p] * 10 + s[j] - '0';
                            i = j;
                        }
                        p++;
                    }
                }
                judge[p] = true;
                op[p++] = (int) '%';
                gao();
                P ans = opnd.peek();
                System.out.println(ans.first + " " + ans.second);
            }
        }

        class P {
            int first, second;

            P(int first, int second) {
                this.first = first;
                this.second = second;
            }
        }
        
        final int MAXN = 10005;
        boolean judge[] = new boolean[MAXN];
        int op[] = new int[MAXN];
        char s[] = new char[MAXN];
        Stack<Integer> optstk = new Stack<>();
        Stack<P> opnd = new Stack<>();
        int p;

        void gao2() {
            P ans = null;
            P b = opnd.pop();
            P a = opnd.pop();
            int t = optstk.pop();
            if (t == '+') {
                ans = new P(a.first + b.first, a.second + b.second);
            } else if (t == '-') {
                ans = new P(a.first - b.second, a.second - b.first);
            } else if (t == '*') {
                int t1 = a.first * b.first;
                int mn = t1, mx = t1;
                int t2 = a.first * b.second;
                mn = Math.min(mn, t2);
                mx = Math.max(mx, t2);
                int t3 = a.second * b.first;
                mn = Math.min(mn, t3);
                mx = Math.max(mx, t3);
                int t4 = a.second * b.second;
                mn = Math.min(mn, t4);
                mx = Math.max(mx, t4);
                ans = new P(mn, mx);
            } else if (t == 'd') {
                ans = new P(a.first, a.second * b.second);
            }
            opnd.push(ans);
        }

        char C_M_P[][] = {
                {'>', '>', '<', '<', '<', '>', '>'},
                {'>', '>', '<', '<', '<', '>', '>'},
                {'>', '>', '>', '<', '<', '>', '>'},
                {'>', '>', '>', '>', '<', '>', '>'},
                {'<', '<', '<', '<', '<', '=', '0'},
                {'>', '>', '>', '>', '0', '>', '>'},
                {'<', '<', '<', '<', '<', '0', '='}
        };
        int optrToi[] = new int[200];

        char cmp(int a, int b) {
            return C_M_P[optrToi[a]][optrToi[b]];
        }

        void gao() {
            optstk.push((int) '%');
            for (int i = 0; i < p; i++) {
                if (judge[i]) {
                    if (op[i] == '%') {
                        if (optstk.size() > 0) {
                            int tmp = optstk.peek();
                            while (tmp != '%') {
                                gao2();
                                tmp = optstk.peek();
                            }
                        }
                        return;
                    }
                    int tmp = optstk.peek();
                    char relation = cmp(tmp, op[i]);
                    if (relation == '>') {
                        gao2();
                        --i;
                    } else if (relation == '<') {
                        optstk.push(op[i]);
                    } else {
                        optstk.pop();
                    }
                } else {
                    opnd.push(new P(op[i], op[i]));
                }
            }
        }


    }
}