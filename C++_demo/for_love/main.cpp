#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cstdio>

using namespace std;

int main()
{
    string s1 = "��������";
    string s2 = "���С����";
    string test_string1,test_string2;
    SetConsoleTitle("��Ϧ�ڵ�С����");
    cout << "��ӭ����С���˿����ı��ϵͳ!" << endl;
    printf("\n");
    cout << "�������׶���:" ;
    while(test_string2 != "��������")
    {
        cin >> test_string2;
        printf("\n");
        if(test_string2 != "��������")
            cout << "???����˵һ��?��˭:" ;
    }
    cout << "��������������:" ;
    while(test_string2 != "���С����")
    {
        cin >> test_string2;
        printf("\n");
        if(test_string2 != "���С����")
            cout << "���������!��������:" ;
    }
    cout << "������ȷ!��������ʲôҪ˵����?" << endl;
    system("pause>null");
    printf("\n");
    cout << s2 << setw(3)<< "��ϲ��" << setw(8) << s1 << endl;
    cout << "ף����Ϧ����!" << endl;
    system("pause>null");
    printf("\n");
    cout << s1 << ":̫������!!!!!�㻹��ʲôҪ˵����???" << endl;
    system("pause>null");
    printf("\n");
    cout << s2 << ":��...���Ҹ��㻭�����İ�!" << endl;
    system("pause>null");
    printf("\n");
    cout << s1 << ":�ߣ�����" << endl;
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

    char c=3; //ASCII������ 3 ����һ���ַ�С����

    for (i=1; i<=5; i++)    printf("\n"); //��ͷ�ճ�5��

    for (i=1; i<=3; i++)   //ǰ3���м��п�϶�ֿ���д
    {

        for (j=1; j<=32-2*i; j++)  printf(" "); //��ߵĿո�ÿ��һ����ߵĿո����һ����2�� //8*n-2*i

        for (k=1; k<=4*i+1; k++)  printf("%c", c);//�����벿���ַ�С����

        for (l=1; l<=13-4*i; l++)  printf(" "); //�м�Ŀո�ÿ��һ�еĿո����һ����4��

        for (m=1; m<=4*i+1; m++)  printf("%c", c);//����Ұ벿���ַ�С����

        printf("\n");  //ÿһ�������ϻ���

    }

    for (i=1; i<=3; i++)   //��3���м�û�пո�
    {

        for (j=1; j<=24+1; j++)   printf(" "); //��ߵĿո� //8*(n-1)+1

        for (k=1; k<=29; k++)   printf("%c", c);//����ַ�С����

        printf("\n");  //ÿһ�������ϻ���

    }

    for (i=7; i>=1; i--)   //��7��
    {

        for (j=1; j<=40-2*i; j++)  printf(" "); //��ߵĿո�ÿ��һ����ߵĿո����һ����2��//8*(n+1)-2*i

        for (k=1; k<=4*i-1; k++)  printf("%c", c);//ÿ��һ�е��ַ�С���ı���һ����4�������ѭ����i--��

        printf("\n");  //ÿһ�������ϻ���

    }

    for (i=1; i<=39; i++)    printf(" "); //���һ����ߵĿո�

    printf("%c\n", c);  //���һ���ַ�С����

    for (i=1; i<=5; i++)    printf("\n"); //���ճ�5��

    system("pause>null");

    return 0;
}
