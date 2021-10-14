using System;
using System.Diagnostics;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Threading;
using System.Linq;
using System.Text;


namespace v3_multithread
{

    class Program
    {
        //Config Variable
        static int Num_Thread = 20;
        static int Num_Data = 1000000000;
        static int Pre_scale = Num_Data/Num_Thread;
        static byte[] Data_Global = new byte[Num_Data];
        //static int[] Sum_Global = new int[Num_Thread];
        static long Sum_Global;
        static int Total_sum = 0;

        static int number = Environment.ProcessorCount;

        static void sum(object arg)
        {
            int i = (int) arg;
            int min = Pre_scale*i;
            int max = (Pre_scale*(i+1)-1);
            long sum_i = 0;

            //Console.WriteLine("Thread: {0} running...", i);
            //Console.WriteLine("sum_index : {0} min : {1} max : {2}",i,min,max);
            for(int Data_index = min ; Data_index <= max ; Data_index++)
            {
                if (Data_Global[Data_index] == 2 || Data_Global[Data_index] == 4 || Data_Global[Data_index] == 6 || Data_Global[Data_index] == 8)
                {
                    sum_i -= Data_Global[Data_index];
                }
                else if (Data_Global[Data_index] == 3 || Data_Global[Data_index] == 9)
                {
                    sum_i += (Data_Global[Data_index]*2);
                }
                else if (Data_Global[Data_index] == 5)
                {
                    sum_i += (Data_Global[Data_index] / 2);
                }
                else if (Data_Global[Data_index] == 7)
                {
                    sum_i += (Data_Global[Data_index] / 3);
                }
                Data_Global[Data_index] = 0;     
            }
            Sum_Global += sum_i;
        }

        static int ReadData()
        {
            int returnData = 0;
            FileStream fs = new FileStream("Problem01.dat", FileMode.Open);
            BinaryFormatter bf = new BinaryFormatter();

            try 
            {
                Data_Global = (byte[]) bf.Deserialize(fs);
            }
            catch (SerializationException se)
            {
                Console.WriteLine("Read Failed:" + se.Message);
                returnData = 1;
            }
            finally
            {
                fs.Close();
            }

            return returnData;
        }

        static void Main(string[] args)
        {
            Stopwatch sw = new Stopwatch();
            Console.Write("[System] Total thread : {0} \r\n", number);

            int worker; 
            int ioCompletion;
            //ThreadPool.GetMaxThreads(out worker, out ioCompletion);
            //Console.WriteLine("Worker: {0} | I/O : {1}", worker, ioCompletion);

            /* Read data from file */
            Console.Write("Data read...");
            int y = ReadData();
            if (y == 0)
            {
                Console.WriteLine("Complete.");
            }
            else
            {
                Console.WriteLine("Read Failed!");
            }

            Thread[] newThreads = new Thread[Num_Thread];
            sw.Start();
            for (int i = 0; i < newThreads.Length; i++)
            {
                newThreads[i] = new Thread(sum);
                //tunning
                newThreads[i].Priority = ThreadPriority.Highest;
                newThreads[i].Start(i);
            }
            for (int i = 0; i < newThreads.Length; i++)
            {
                if (newThreads[i].IsAlive)
                {
                    //Console.WriteLine("Thread: {0} joining...", i);
                    newThreads[i].Join();
                }
                
            }

            // Parallel.For(0,Num_Thread, k =>
            // {
            //     Total_sum += Sum_Global[k];
            // });

            // for (int o= 0; o < Num_Thread; o++)
            // {
            //     Total_sum += Sum_Global[o];
            // }
            
            sw.Stop();
            Console.WriteLine("Summation result: {0}", Sum_Global);
            Console.WriteLine("Time used: " + sw.ElapsedMilliseconds.ToString() + "ms");

        }

    }

}
