using System;
using System.Threading;

namespace lesson_3_multi_thread
{
class MultiThreadExample
{
    static int MAX_NUMBER = 500;
    static int proceed_number = 1;

    static void Main(string[] args)
    {
        // Get number of logical processor from CPU
        int NUM_THREAD = Environment.ProcessorCount;
        for (int i = 0; i < NUM_THREAD; i++)
        {
            Thread t = new Thread(delegate() {
                int threadID = (int) AppDomain.GetCurrentThreadId();

                while (proceed_number <= MAX_NUMBER)
                {
                    int n = proceed_number++;
                    if (IsPrime(n))
                    {
                        Console.WriteLine("Thread " + threadID + " -> " + n + " is prime.");
                    }
                    else {
                        Console.WriteLine("Thread " + threadID + " -> " + n + " is not prime.");
                    }
                }
            });
            t.Start();
        }
    }

    static bool IsPrime(int number)
    {
        for (int i = 2; i < number; i++)
        {
            if (number % i == 0 && i != number) return false;
        }
        return true;
    }
}
}
