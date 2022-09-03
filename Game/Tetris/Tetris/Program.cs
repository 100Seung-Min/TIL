using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Tetris
{
    class Program
    {
        static void Main1(string[] args)
        {
            TextCounter();
        }

        static void Hello()
        {
            Console.WriteLine("Hello World");
            Thread.Sleep(1000);
            Console.Clear();
            Console.WriteLine("Hi !!!");

            Console.ReadLine();
        }
        static void Text()
        {
            int i, j;
            int num = 0;

            byte[,] font = new byte[2, 8] {
                {0x00,0x38,0x44,0x04,0x08,0x10,0x20,0x7c},
                {0x00,0x38,0x44,0x04,0x18,0x04,0x44,0x38} };

            Console.Clear();


             while (true){
                for (j = 0; j < 8; j++)
                {
                    for (i = 0; i < 8; i++)
                    {
                        if ((font[num, j] & (0x01 << (7 - i))) > 0)
                        {
                             Console.Write("*");
                        }
                        else
                        {
                            Console.Write(" ");
                        }
                    }
                    Console.WriteLine("");
                }
                num++;
                if (num > 1) num = 0;
                Thread.Sleep(1000);
                Console.Clear();
             }
        }

        static void Text23()
        {
            byte[] num = new byte[8] { 0x00, 0x38, 0x44, 0x04, 0x08, 0x10, 0x20, 0x7c };
            byte[,] num2 = new byte[2, 8] {
            { 0x00, 0x38, 0x44, 0x04, 0x08, 0x10, 0x20, 0x7c },
            { 0x00,0x38,0x44,0x04,0x18,0x04,0x44,0x38 } };


            for (int j = 0; j < 8; j++)
            {
                for (int i = 0; i < 8; i++)
                {
                    if ((num2[0, j] & (0x80 >> i)) > 0)
                    {
                        Console.Write("*");
                    }
                    else
                    {
                        Console.Write("-");
                    }
                }

                for (int i = 0; i < 8; i++)
                {
                    if ((num2[1, j] & (0x80 >> i)) > 0)
                    {
                        Console.Write("*");
                    }
                    else
                    {
                        Console.Write("-");
                    }
                }
                Console.WriteLine("");
            }

            Console.ReadLine();
        }

        static void TextCounter()
        {
            byte[] num = new byte[8] { 0x00, 0x38, 0x44, 0x04, 0x08, 0x10, 0x20, 0x7c };
            byte[,] num2 = new byte[10, 8] {
{ 0x00,0x38,0x44,0x4c,0x54,0x64,0x44,0x38 },
            { 0x00, 0x10, 0x30, 0x50, 0x10, 0x10, 0x10, 0x7c },
{ 0x00, 0x38, 0x44, 0x04, 0x08, 0x10, 0x20, 0x7c },
{ 0x00,0x38,0x44,0x04,0x18,0x04,0x44,0x38 },
{ 0x00,0x08,0x18,0x28,0x48,0x7c,0x08,0x08 },
{ 0x00,0x7c,0x40,0x78,0x04,0x04,0x44,0x38 },
{ 0x00,0x38,0x40,0x40,0x78,0x44,0x44,0x38 },
{ 0x00,0x7c,0x04,0x08,0x10,0x20,0x20,0x20 },
{ 0x00,0x38,0x44,0x44,0x38,0x44,0x44,0x38 },
{ 0x00,0x38,0x44,0x44,0x3c,0x04,0x44,0x38 }};

            int count = 0;

                while (true)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        for (int i = 0; i < 8; i++)
                        {
                            if ((num2[count / 10, j] & (0x80 >> i)) > 0)
                            {
                                Console.Write("*");
                            }
                            else
                            {
                                Console.Write(" ");
                            }
                        }
                        for (int i = 0; i < 8; i++)
                        {
                            if ((num2[count % 10, j] & (0x80 >> i)) > 0)
                            {
                                Console.Write("*");
                            }
                            else
                            {
                                Console.Write(" ");
                            }
                        }

                        Console.WriteLine("");
                    }

                    Thread.Sleep(100);
                    Console.Clear();
                    count++;
                    if (count > 100) count = 0;

                }


                Console.ReadLine();
        }
    }
}
