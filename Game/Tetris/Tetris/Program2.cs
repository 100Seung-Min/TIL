using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading.Tasks;
using System.Threading;

namespace Tetris
{
    class Program2
    {

        static byte[,] background = new byte[22, 12]
        {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
        };

        static byte[,,] block_L = new byte[4, 4, 4]
        {
            {
                {0, 0, 0, 0 },
                {0, 1, 0, 0 },
                {0, 1, 1, 1 },
                {0, 0, 0, 0 }
            },
            {
                {0, 0, 0, 0 },
                {0, 1, 1, 0 },
                {0, 1, 0, 0 },
                {0, 1, 0, 0 }
            },
            {
                {0, 0, 0, 0 },
                {1, 1, 1, 0 },
                {0, 0, 1, 0 },
                {0, 0, 0, 0 }
            },
            {
                {0, 0, 1, 0 },
                {0, 0, 1, 0 },
                {0, 1, 1, 0 },
                {0, 0, 0, 0 }
            }
        };

        static ConsoleKeyInfo key_value;
        static String ch;
        static int x = 3, y = 3;
        static int selector = 0;
        static void Main(string[] args)
        {
            print_background();
            make_block();
            while (true)
            {
                int count = 0;
                while(count <= 100)
                {
                    read_key();
                    Thread.Sleep(10);
                    count++;
                }
                if (overlap_check(0, 1, 0) == 0)
                {
                    delete_block();
                    y++;
                    make_block();
                }
                Thread.Sleep(1000);
            }
        }

        static void print_background()
        {
            for (int j = 0; j < 22; j++)
            {
                for (int i = 0; i < 12; i++)
                {
                    if (background[j, i] == 1)
                    {
                        Console.SetCursorPosition(i, j);
                        Console.Write("*");
                    }
                    else
                    {
                        Console.SetCursorPosition(i, j);
                        Console.Write("-");
                    }
                }
            }
        }

        static void make_block()
        {
            for (int j = 0; j < 4; j++)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (block_L[selector, j, i] == 1)
                    { 
                        Console.SetCursorPosition(i + x, j + y);
                        Console.Write("*");
                    }
                }
            }
        }

        static void read_key()
        {
            if (Console.KeyAvailable)
            {

                key_value = Console.ReadKey(true);
                ch = key_value.Key.ToString();

                if (ch == "A")
                {
                    if(overlap_check(-1, 0, 0) == 0)
                    {
                        delete_block();
                        x--;
                        make_block();
                    }
                }
                else if (ch == "D")
                {
                    if (overlap_check(1, 0, 0) == 0)
                    {
                        delete_block();
                        x++;
                        make_block();
                    }
                }
                else if (ch == "S")
                {

                    if (overlap_check(0, 1, 0) == 0)
                    {
                        delete_block();
                        y++;
                        make_block();
                    }
                }
                else if (ch == "W")
                {

                    if (overlap_check(0, 1, 1) == 0)
                    {
                        delete_block();
                        selector = selector <= 2 ? selector + 1 : 0;
                        make_block();
                    }
                }
            }
        }

        static void delete_block()
        {
            for (int j = 0; j < 4; j++)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (block_L[selector, j, i] == 1)
                    {
                        Console.SetCursorPosition(i + x, j + y);
                        Console.Write("-");
                    }
                }
            }
        }

        static int overlap_check(int tmp_x, int tmp_y, int tmp_selector)
        {
            int overlap_count = 0;
            for (int j = 0; j < 4; j++)
            {
                for (int i = 0; i < 4; i++)
                {
                    if(block_L[selector <= 2 ? selector + tmp_selector : 0, j, i] == 1 && background[j+y+tmp_y, i+x+tmp_x] == 1)
                    {
                        overlap_count++;
                    }
                }
            }
            return overlap_count;
        }
    }
}
