using System;
using static System.Console;

namespace Hello
{
    class MainApp

    {
        enum People { 성은, 동현, 민채, 승원, 채훈, 도균, 영재};
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

            WriteLine("가위바위보 게임: 바위(1) 가위(2) 보(3)");
            int user = int.Parse(ReadLine());
            Random random = new Random();
            int com = random.Next(1, 4);

            switch (user - com)
            {
                case 0:
                    Write("비김 {0} {1}", com, user);
                    break;
                case -1:
                case 2:
                    Write("이김 {0} {1}", com, user);
                    break;
                default:
                    Write("짐 {0} {1}", com, user);
                    break;
            }
        }
    }
}
