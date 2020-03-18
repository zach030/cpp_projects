#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define WIDTH 8
#define HEIGHT 8



//�����ͼ
int map[HEIGHT][WIDTH] = {
    {0,0,1,1,1,0,0,0},
    {0,0,1,4,1,0,0,0},
    {0,0,1,0,1,1,1,1},
    {1,1,1,3,0,3,4,1},
    {1,1,1,1,3,1,0,0},
    {1,1,1,1,3,1,0,0},
    {0,0,0,1,4,1,0,0},
    {0,0,0,1,4,1,0,0},
};

//�����˵�λ�ã�������
int x,y;

//����������
int boxs;

/*��һЩ�����Ľ���
0 ��
1 ǽ
2 ��
3 ����
4 Ŀ�ĵ�
5 ����ɵ�����
*/

void initData()
{
    int i,j;

    printf("��Ϸ�����У����Ժ󡭡�����");

    //������ͼ�е�����
    for(i=0;i<HEIGHT;i++)
    {
        for(j=0;j<WIDTH;j++)
        //�������ˣ�2����ʱ��x,y��¼�����˵�����
        {
            if(map[i][j]==2)
                x=j,y=i;
            //������3��ʱ��������Ŀ����
            if(map[i][j]==3)
                boxs++;
        }
    }
}

//��ӡ��ͼ
void drawMap()
{
    int i,j;
    for(i=0;i<WIDTH;i++)
    {
        for(j=0;j<HEIGHT;j++)
        {
                switch(map[i][j])
            {
                //0�����
                case 0:printf(" ");break;
                //1����ǽ
                case 1:printf(".");break;
                //2������
                case 2:printf("*");break;
                //3��������
                case 3:printf("#");break;
                //4����Ŀ�ĵ�
                case 4:printf("@");break;
                //5��������ɵ�����
                case 5:printf("$");break;
            }
        }
    printf("\n");
    }
}

void moveUp()
{
    //�����������Ϸ�������
    int ux,uy;

    //���Ϸ�û��Ԫ�أ����ڱ�Ե��ֱ�ӷ���
    if(y==0)
        return;

    //��¼���Ϸ������꣬�Ϸ���������겻�䣬�������һ
    ux=x;
    uy=y-1;

    //�Ϸ�Ϊ����ɵ�����,�˲���Ч
    if(map[uy][ux]==5)
        return;
    //�Ϸ�Ϊǽ
    if(map[uy][ux]==1)
        return;

    //�����Ϸ�Ϊ����
    if(map[uy][ux]==3)
    {
        //�ж����ӵ��Ϸ��Ƿ�Ϊǽ
        if(map[uy-1][ux]==1)
            return;
        //�ж��Ϸ��Ƿ�Ϊ�յ�
        if(map[uy-1][ux]==4)
        {
            map[uy-1][ux]=5;//���Ϊ����ɵ�����
            map[uy][ux]=0;
            boxs--;
        }
        else{
            map[uy-1][ux]=3;
        }
    }
    //��ǰΪ�գ������겻�䣬�������һ������������
    map[y][x]=0;
    map[uy][ux]=2;
    y=uy;

}

void moveLeft()
{
    int lx,ly;
    if(x==0)
        return;
    lx=x-1;ly=y;

    if(map[ly][lx]==5)
        return;

    if(map[ly][lx]==1)
        return;
    //������Ϊ����
    if(map[ly][lx]==3)
    {
        //���ж���������Ƿ�Ϊǽ
        if(map[ly][lx-1]==1)
            return;
        //�ж�����Ƿ�Ϊ�յ�
        if(map[ly][lx-1]==4)
        {
            map[ly][lx-1]=5;
            map[ly][lx]=0;
            boxs--;
        }
        else{
            map[ly][lx-1]=3;
        }
    }
    map[y][x]=0;
    map[ly][lx]=2;
    x=lx;
}

void moveDown()
{
    //������������·�������
    int dx,dy;

    if(y==HEIGHT-1)
        return;

    //��¼�·�����
    dx=x,dy=y+1;

    //�·���Ϊ����ɵķ���
    if(map[dy][dx]==5)
        return;
    //�·�Ϊǽ
    if(map[dy][dx]==1)
        return;
    //�·�Ϊ����
    if(map[dy][dx]==3)
    {
        //�ж������·��Ƿ�Ϊǽ
        if(map[dy+1][dx]==1)
            return;
        //�ж������·��Ƿ�Ϊ�յ�
        if(map[dy+1][dx]==4)
        {
            map[dy+1][dx]=5;
            map[dy][dx]=0;
            boxs--;
        }
        else{
            map[dy+1][dx]=3;
        }
    }
    map[y][x]=0;
    map[dy][dx]=2;
    y=dy;
}

void moveRight()
{
    //����洢�����ұߵ�����
    int rx,ry;

    if(x==WIDTH-1)
        return;

    rx=x+1,ry=y;

    if(map[ry][rx]==5)
        return;
    if(map[ry][rx]==1)
        return;

    if(map[ry][rx]==3)
    {
        //�ж��ұ��Ƿ�Ϊǽ
        if(map[ry][rx+1]==1)
            return;
        if(map[ry][rx+1]==4)
        {
            map[ry][rx+1]=5;
            map[ry][rx]=0;
            boxs--;
        }
        else{
            map[ry][rx+1]=3;
        }
    }
    map[y][x]=0;
    map[ry][rx]=2;
    x=rx;
}

//��Ϸ��main������
int main(int argc, char *argv[])
{
    char direction;     //�洢���̵ķ���
    initData();

    //��ʼ��Ϸ��ѭ��,��ѭ��
    while(1){
        system("cls");
        drawMap();
        //�ж�boxs��������Ϊ0������Ϸ����������ѭ��
        if(!boxs){
            break;
        }

    direction=getch();

    switch(direction)
    {
        case 'w':moveUp();break;
        case 'a':moveLeft();break;
        case 's':moveDown();break;
        case 'd':moveRight();break;
    }
    }
    printf("��ϲ�������Ϸ!");
    return 0;
}
