#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cstdio>

using namespace std;

int main()
{
    string s1 = "晶晶公主";
    string s2 = "你的小王八";
    string test_string1,test_string2;
    SetConsoleTitle("七夕节的小礼物");
    cout << "欢迎来到小王八开发的表白系统!" << endl;
    printf("\n");
    cout << "请输入表白对象:" ;
    while(test_string2 != "晶晶公主")
    {
        cin >> test_string2;
        printf("\n");
        if(test_string2 != "晶晶公主")
            cout << "???你再说一遍?是谁:" ;
    }
    cout << "请输入表白者姓名:" ;
    while(test_string2 != "你的小王八")
    {
        cin >> test_string2;
        printf("\n");
        if(test_string2 != "你的小王八")
            cout << "请谨言慎行!重新输入:" ;
    }
    cout << "输入正确!请问你有什么要说的吗?" << endl;
    system("pause>null");
    printf("\n");
    cout << s2 << setw(3)<< "最喜欢" << setw(8) << s1 << endl;
    cout << "祝你七夕快乐!" << endl;
    system("pause>null");
    printf("\n");
    cout << s1 << ":太敷衍了!!!!!你还有什么要说的吗???" << endl;
    system("pause>null");
    printf("\n");
    cout << s2 << ":那...那我给你画个爱心吧!" << endl;
    system("pause>null");
    printf("\n");
    cout << s1 << ":哼！！！" << endl;
    /*for (float y = 1.5f ; y > -1.5f ; y -= 0.1f)
    {
        for (float x = -1.5f ; x < 1.5f ; x += 0.05f)
        {

            float z = x*x + y*y -1;
            float f = z*z*z -x*x*y*y*y;
            putchar(f <= 0.0f ? ".:-=+*#%@" [(int)(f * -8.0f)] : ' ');
        }
        putchar(' ');
    }*/
    system("pause>null");
    int  i, j, k, l, m;

    char c=3; //ASCII码里面 3 就是一个字符小爱心

    for (i=1; i<=5; i++)    printf("\n"); //开头空出5行

    for (i=1; i<=3; i++)   //前3行中间有空隙分开来写
    {

        for (j=1; j<=32-2*i; j++)  printf(" "); //左边的空格，每下一行左边的空格比上一行少2个 //8*n-2*i

        for (k=1; k<=4*i+1; k++)  printf("%c", c);//输出左半部分字符小爱心

        for (l=1; l<=13-4*i; l++)  printf(" "); //中间的空格，每下一行的空格比上一行少4个

        for (m=1; m<=4*i+1; m++)  printf("%c", c);//输出右半部分字符小爱心

        printf("\n");  //每一行输出完毕换行

    }

    for (i=1; i<=3; i++)   //下3行中间没有空格
    {

        for (j=1; j<=24+1; j++)   printf(" "); //左边的空格 //8*(n-1)+1

        for (k=1; k<=29; k++)   printf("%c", c);//输出字符小爱心

        printf("\n");  //每一行输出完毕换行

    }

    for (i=7; i>=1; i--)   //下7行
    {

        for (j=1; j<=40-2*i; j++)  printf(" "); //左边的空格，每下一行左边的空格比上一行少2个//8*(n+1)-2*i

        for (k=1; k<=4*i-1; k++)  printf("%c", c);//每下一行的字符小爱心比上一行少4个（这个循环是i--）

        printf("\n");  //每一行输出完毕换行

    }

    for (i=1; i<=39; i++)    printf(" "); //最后一行左边的空格

    printf("%c\n", c);  //最后一个字符小爱心

    for (i=1; i<=5; i++)    printf("\n"); //最后空出5行

    system("pause>null");

    return 0;
}
