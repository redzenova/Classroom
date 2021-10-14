using System;
using System.Diagnostics;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Threading;
using System.Collections.Concurrent;
using System.Collections.Generic;

namespace v2_thread
{
    class Program
    {
        static byte[] Data_Global = new byte[1000000000];
        static long Sum_Global = 0;
        static int G_index = 0;

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
       static void sum(int G_index)
        {
            if (Data_Global[G_index] == 2 || Data_Global[G_index] == 4 || Data_Global[G_index] == 6 || Data_Global[G_index] == 8)
            {
                Sum_Global -= Data_Global[G_index];
            }
            else if (Data_Global[G_index] == 3 || Data_Global[G_index] == 9)
            {
                Sum_Global += (Data_Global[G_index]*2);
            }
            else if (Data_Global[G_index] == 5)
            {
                Sum_Global += (Data_Global[G_index] / 2);
            }
            else if (Data_Global[G_index]  == 7)
            {
                Sum_Global += (Data_Global[G_index] / 3);
            }
            Data_Global[G_index] = 0;
            //G_index++;   
        }
        
        static void TestThread1()
        {
            int j;
            for (j = 0; j < 500000000; j++)
            {
                //Console.WriteLine("Value: {0}", Data_Global[i]);
                sum(j);
            }
        }

        static void TestThread2()
        {
            int i;
            for (i = 500000000; i < 1000000000; i++)
            {
                //Console.WriteLine("Value: {0}", Data_Global[i]);
                sum(i);
            }
        }

        static void Main(string[] args)
        {
            Stopwatch sw1 = new Stopwatch();
            Stopwatch sw2 = new Stopwatch();
            Stopwatch sw3 = new Stopwatch();
            Thread th1 = new Thread(TestThread1);
            Thread th2 = new Thread(TestThread2);
            int i, y;
            /* Read data from file */
            Console.Write("Data read...");
            sw1.Start();
            y = ReadData();
            if (y == 0)
            {
                Console.WriteLine("Complete.");
            }
            else
            {
                Console.WriteLine("Read Failed!");
            }
            sw1.Stop();
            /* Start */
            Console.Write("\n\nWorking...");
            sw2.Start();
            th1.Start();
            th2.Start(); 
            Console.WriteLine("Done.");
            th1.Join();
            th2.Join();
            sw2.Stop();
            Console.WriteLine("Done.");

            /* Result */
            Console.WriteLine("Summation result: {0}", Sum_Global);
            Console.WriteLine("IO Time used: " + sw1.ElapsedMilliseconds.ToString() + "ms");
            Console.WriteLine("Time used: " + sw2.ElapsedMilliseconds.ToString() + "ms");
        }
    
    }
}