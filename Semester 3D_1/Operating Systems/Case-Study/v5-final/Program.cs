using System;
using System.Diagnostics;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Threading;
using System.Threading.Tasks;

namespace v5_final
{
    class Program
    {
        // Config Variable
        static int number = Environment.ProcessorCount;
        static int Num_Thread = 10;

        // Data size
        static int Num_Data = 1000000000;
        static int Pre_scale = Num_Data/Num_Thread;
        static byte[] Data_Global = new byte[Num_Data];
        // Sum_Global for total of sum value
        static long Sum_Global;

        // sum() function
        static void sum(object arg)
        {
            // Calculate for range min value to max value 
            int i = (int) arg;
            int min = Pre_scale*i;
            int max = (Pre_scale*(i+1)-1);
            // Initial sum_i for store in any Thread
            long sum_i = 0;

            for(int Data_index = min ; Data_index <= max ; Data_index++)
            {
                if (Data_Global[Data_index] %2 ==0)
                {
                    sum_i -= Data_Global[Data_index];
                }
                else if (Data_Global[Data_index] %3 == 0)
                {
                    sum_i += (Data_Global[Data_index]*2);
                }
                else if (Data_Global[Data_index] %5 == 0)
                {
                    sum_i += (Data_Global[Data_index] / 2);
                }
                else if (Data_Global[Data_index] %7 == 0)
                {
                    sum_i += (Data_Global[Data_index] / 3);
                }
                Data_Global[Data_index] = 0;     
            }
            // Update Sum_Global Value
            Sum_Global += sum_i;
        }

        // Read DATA from Program01.dat
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
            int worker; 
            int ioCompletion;

            // Print system resource 
            ThreadPool.GetMaxThreads(out worker, out ioCompletion);
            Console.Write("[System] Total thread : {0} \r\n", number);
            Console.WriteLine("[System] Worker: {0} \r\n[System] I/O : {1}", worker, ioCompletion);

            /* Read data from file */
            Console.Write("[Process] Data read...");
            int y = ReadData();
            if (y == 0)
            {
                Console.WriteLine("Complete.");
            }
            else
            {
                Console.WriteLine("Read Failed!");
            }

            //Create Thread Array
            Thread[] WorkThreads = new Thread[Num_Thread];
            sw.Start();

            Console.Write("[Process] Computing...");
            //Create worker Thread for work sum() function
            for (int i = 0; i < WorkThreads.Length; i++)
            {
                WorkThreads[i] = new Thread(sum);
                //Tunning - for setting Thread to high priority
                WorkThreads[i].Priority = ThreadPriority.Highest;
                //Passing parameter object to every Thread
                WorkThreads[i].Start(i);
            }

            //Check Thread alive and join
            for (int i = 0; i < WorkThreads.Length; i++)
            {
                if (WorkThreads[i].IsAlive)
                {
                    //Console.WriteLine("Thread: {0} joining...", i);
                    WorkThreads[i].Join();
                }
                
            }
            Console.WriteLine("Complete.");
            sw.Stop();
            Console.WriteLine("[Result] Summation result: {0}", Sum_Global);
            Console.WriteLine("[Result] Time used: " + sw.ElapsedMilliseconds.ToString() + "ms");

        }

    }
}
