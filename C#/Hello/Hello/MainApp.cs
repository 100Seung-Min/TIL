using System;
using static System.Console;

namespace Hello
{
    class MainApp

    {
        enum People { 성은, 동현, 민채, 승원, 채훈, 도균, 영재};

        public static void swap(ref int a, ref int b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        public static double Square(double arg)
        {
            return arg * arg;
        }

        class Calculator
        {
            public static int Plus(int a, int b)
            {
                return a + b;
            }
            public static int Minus(int a, int b)
            {
                return a - b;
            }
            public static int Multiply(int a, int b)
            {
                return a * b;
            }
            public static int Division(int a, int b)
            {
                return a / b;
            }
        }
        static void Main(string[] args)
        {
            //char a = '안';
            //char b = '녕';
            //char c = '하';
            //char d = '세';
            //char e = '요';
            //WriteLine(a.ToString() + b.ToString() + c.ToString() + d.ToString() + e.ToString());

            //float ab = 0.1f;
            //double abc = (double)ab;
            //Write(abc);

            ////People nong = People.동현;
            ////WriteLine("농사꾼은 성은 = {0}", nong == People.성은);
            ////WriteLine("농사꾼은 동현 = {0}", nong == People.동현);
            ////WriteLine("농사꾼은 민채 = {0}", nong == People.민채);
            ////WriteLine("농사꾼은 승원 = {0}", nong == People.승원);
            ////WriteLine("농사꾼은 채훈 = {0}", nong == People.채훈);
            ////WriteLine("농사꾼은 도균 = {0}", nong == People.도균);
            ////WriteLine("농사꾼은 영재 = {0}", nong == People.영재);

            //WriteLine("사각형의 너비를 입력하세요 : ");
            //int result = int.Parse(ReadLine());
            //WriteLine("사각형의 높이를 입력하세요 : ");
            //result *= int.Parse(ReadLine());
            //WriteLine("사각형의 넓이는 {0}", result);

            //int a = int.Parse(ReadLine());
            //if(a % 2 == 0)
            //{
            //    WriteLine("짝수");
            //} else
            //{
            //    WriteLine("홀수");
            //}

            //if(a > 0){
            //    WriteLine("양수");
            //} else if (a != 0)
            //{
            //    WriteLine("음수");
            //}
            //else
            //{
            //    WriteLine("0");
            //}

            //Write("요일을 입력하세요 : ");
            //string day = ReadLine();
            //switch (day)
            //{
            //    case "일":
            //        WriteLine("Sunday");
            //        break;
            //    case "월":
            //        WriteLine("Munday");
            //        break;
            //    case "화":
            //        WriteLine("Tuesday");
            //        break;
            //    case "수":
            //        WriteLine("Wednesday");
            //        break;
            //    case "목":
            //        WriteLine("Thursday");
            //        break;
            //    case "금":
            //        WriteLine("Friday");
            //        break;
            //    case "토":
            //        WriteLine("Saturday");
            //        break;
            //}

            //WriteLine("점수를 입력하세요 : ");
            //int score = int.Parse(ReadLine());
            //switch (score)
            //{
            //    case >= 90:
            //        Write("A");
            //        break;
            //    case >= 80:
            //        Write("B");
            //        break;
            //    case >= 70:
            //        Write("C");
            //        break;
            //    case >= 60:
            //        Write("D");
            //        break;
            //    default:
            //        Write("F");
            //        break;
            //}

            //for(int i = 0; i < 5; i++)
            //{
            //    for(int j = 0; j <= i; j++)
            //    {
            //        Write("*");
            //    }
            //    WriteLine();
            //}

            //for (int i = 5; i > 0; i--)
            //{
            //    for (int j = i; j > 0; j--)
            //    {
            //        Write("*");
            //    }
            //    WriteLine();
            //}

            //WriteLine("가위바위보 게임: 바위(1) 가위(2) 보(3)");
            //int user = int.Parse(ReadLine());
            //int com = new Random().Next(1,4);

            //switch (user - com)
            //{
            //    case 0:
            //        Write("비김 {0} {1}", com, user);
            //        break;
            //    case -1:
            //    case 2:
            //        Write("이김 {0} {1}", com, user);
            //        break;
            //    default:
            //        Write("짐 {0} {1}", com, user);
            //        break;
            //}

            //WriteLine("숫자 입력");
            //int a = int.Parse(ReadLine());
            //WriteLine("숫자 입력");
            //int b = int.Parse(ReadLine());
            //WriteLine("기호를 숫자로 입력");
            //WriteLine("1.더하기/ 2.빼기/ 3.곱셈/ 4.나누기");
            //int c = int.Parse(ReadLine());
            //switch (c)
            //{
            //    case 1:
            //        WriteLine("{0}", Calculator.Plus(a, b));
            //        break;
            //    case 2:
            //        WriteLine("{0}", Calculator.Minus(a, b));
            //        break;
            //    case 3:
            //        WriteLine("{0}", Calculator.Multiply(a, b));
            //        break;
            //    case 4:
            //        WriteLine("{0}", Calculator.Division(a, b));
            //        break;
            //    default:
            //        WriteLine("허용되지 않음");
            //        break;
            //}

            //int a = 1, b = 3;
            //WriteLine("{0}, {1}", a, b);
            //swap(ref a, ref b);
            //WriteLine("{0}, {1}", a, b);

            Write("숫자를 입력하세요 : ");
            double a = double.Parse(ReadLine());
            Write("결과 : {0}", Square(a));
        }
    }
}
