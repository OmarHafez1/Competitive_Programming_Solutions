/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/* Name of the class has to be "Main" only if the class is public. */
public class Main
{



    private static boolean solve(int a, int b) {
        if (a < b) {
            return false;
        }
        if(a%2==1)
            return false;
        if (a == b) {
            return true;
        }
        if((a+b)%2==1)
            return false;
        if((a-b)%2==1)
            return false;
        return true;
    }
    public static void main (String[] args) throws java.lang.Exception
    {
        try{
            FastReader sc = new FastReader();
            // BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
            // //output.write(text+ "\n");
            // //output.flush();


            PrintWriter out =new PrintWriter(System.out);
            //out.println();
            //out.print();
            //out.flush();
            int T=sc.nextInt();
            while(T-->0)
            {
int n=sc.nextInt();
int k=sc.nextInt();
int a[][]=new int[n][2];
int b[]=new int[n];
for(int i=0;i<n;i++)
{
    a[i][0]=sc.nextInt();
    a[i][1]=i;
}


                for(int i=0;i<n;i++)
                    b[i]=sc.nextInt();


                Arrays.sort(a,(x,y)->Integer.compare(x[0],y[0]));

                Arrays.sort(b);
                int c[]=new int[n];
                for(int i=0;i<n;i++)
                {
                    c[a[i][1]]=b[i];
                }
                for(int i:c)
                    System.out.print(i+" ");
                out.println();









                out.flush();
            }
            out.close();
        }
        catch(Exception e)
        {
            return;
        }
    }


    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }

        long nextLong() { return Long.parseLong(next()); }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }



}