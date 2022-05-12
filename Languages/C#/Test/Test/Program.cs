using System;
using static System.Console;

namespace Test
{
    class Program
    { 
        //static double Square(double arg)
        //{
        //    return arg*arg;
        //}
        static void Main(string[] args)
        {
            Write("사각형의 너비를 입력하세요 : ");
            double result = double.Parse(ReadLine());
            Write("사각형의 높이를 입력하세요 : ");
            result *= double.Parse(ReadLine());
            WriteLine("사각형의 넓이는 : {0}", result);
            //Write("수를 입력하세요 : ");
            //string input = ReadLine();
            //double arg = Convert.ToDouble(input);
            //WriteLine("결과: {0}", Square(arg));
            //void get_max_min(int[] arr, ref int min, ref int max)
            //{
            //    foreach (int a in arr)
            //    {
            //        if (min > a)
            //        {
            //            min = a;
            //        }
            //        else if(max < a)
            //        {
            //            max = a;
            //        }
            //    }
            //}
            //for(int i = 0; i < 5; i++)
            //{
            //    for(int j = i; j < 4; j++)
            //    {
            //        Write(" ");
            //    }
            //    for(int j = 0; j <= (i*2); j++)
            //    {
            //        Write("*");
            //    }
            //    WriteLine();
            //}

            //int[] arr = { 10, 20, 30, 40, 50 };
            //int min = arr[0], max = arr[0];
            //get_max_min(arr, ref min, ref max);
            //Write("{0}\n{1}", min, max);
        }
    }
}
