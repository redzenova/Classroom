using System;
using System.Threading;

namespace ex_05
{
    class Program
    {
  private static string x = "";
        private static int exitflag = 0;
        private static int updateFlag = 0;
        private static object _Lock = new object();

        static void ThReadX(object i)
        {
            while (exitflag == 0)
            {
                Monitor.Enter(_Lock);
                try
                {
                    Monitor.Wait(_Lock);

                    if (x != "exit")
                    {
                        Console.WriteLine("***Thread {0} : x={1}***", i, x);
                    }
                    
                }
                finally{
                    Monitor.Exit(_Lock);
                }
            }
            Console.WriteLine("---Thread {0} exit---", i);
        }

        static void ThWriteX()
        {
            string xx;
            while (exitflag == 0)
            {
                lock (_Lock)
                {
                    Monitor.Pulse(_Lock);
                    Console.Write("Input: ");
                    xx = Console.ReadLine();
                    if (xx == "exit")
                        exitflag = 1;
                    x = xx;
                }
            }
        }
        static void Main(string[] args)
        {
            Thread A = new Thread(ThWriteX);
            Thread B = new Thread(ThReadX);
            Thread C = new Thread(ThReadX);
            Thread D = new Thread(ThReadX);

            A.Start();
            B.Start(1);
            C.Start(2);
            D.Start(3);
        }
    }
}
