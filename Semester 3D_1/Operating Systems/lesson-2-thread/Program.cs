using System;
using System.Threading;

namespace lesson_2_thread
{
    class Threads
    {
        static void Main(string[] args)
        {
            Thread t1 = new Thread(new ThreadStart(Thread1));
            Thread t2 = new Thread(new ThreadStart(Thread2));
            Thread t3 = new Thread(new ThreadStart(Thread3));
            Thread t4 = new Thread(new ThreadStart(Thread4));

            t1.Start();
            t2.Start(); 
            t3.Start();
            t4.Start(); 
        }

        static void Thread1() {
            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine("Thread 1");
            }
        }

        static void Thread2()
        {
            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine("Thread 2");
            }
        } 

        static void Thread3()
        {
            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine("Thread 3");
            }
        }

        static void Thread4()
        {
            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine("Thread 4");
            }
        }
   }
}
