#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define WIDTH 8
#define HEIGHT 8



//定义地图
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

//定义人的位置，用坐标
int x,y;

//定义箱子数
int boxs;

/*对一些参数的解释
0 空
1 墙
2 人
3 箱子
4 目的地
5 已完成的箱子
*/

void initData()
{
    int i,j;

    printf("游戏加载中，请稍后…………");

    //遍历地图中的数据
    for(i=0;i<HEIGHT;i++)
    {
        for(j=0;j<WIDTH;j++)
        //遍历到人（2）的时候，x,y记录下来人的坐标
        {
            if(map[i][j]==2)
                x=j,y=i;
            //遍历到3的时候，箱子数目增加
            if(map[i][j]==3)
                boxs++;
        }
    }
}

//打印地图
void drawMap()
{
    int i,j;
    for(i=0;i<WIDTH;i++)
    {
        for(j=0;j<HEIGHT;j++)
        {
                switch(map[i][j])
            {
                //0代表空
                case 0:printf(" ");break;
                //1代表墙
                case 1:printf(".");break;
                //2代表人
                case 2:printf("*");break;
                //3代表箱子
                case 3:printf("#");break;
                //4代表目的地
                case 4:printf("@");break;
                //5代表已完成的箱子
                case 5:printf("$");break;
            }
        }
    printf("\n");
    }
}

void moveUp()
{
    //定义存放人物上方的坐标
    int ux,uy;

    //当上方没有元素，人在边缘，直接返回
    if(y==0)
        return;

    //记录人上方的坐标，上方坐标横坐标不变，纵坐标减一
    ux=x;
    uy=y-1;

    //上方为已完成的箱子,此步无效
    if(map[uy][ux]==5)
        return;
    //上方为墙
    if(map[uy][ux]==1)
        return;

    //假设上方为箱子
    if(map[uy][ux]==3)
    {
        //判断箱子的上方是否为墙
        if(map[uy-1][ux]==1)
            return;
        //判断上方是否为终点
        if(map[uy-1][ux]==4)
        {
            map[uy-1][ux]=5;//标记为已完成的箱子
            map[uy][ux]=0;
            boxs--;
        }
        else{
            map[uy-1][ux]=3;
        }
    }
    //人前为空，横坐标不变，纵坐标减一，更新纵坐标
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
    //如果左边为箱子
    if(map[ly][lx]==3)
    {
        //先判断箱子左边是否为墙
        if(map[ly][lx-1]==1)
            return;
        //判断左边是否为终点
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
    //定义存在人物下方的坐标
    int dx,dy;

    if(y==HEIGHT-1)
        return;

    //记录下方坐标
    dx=x,dy=y+1;

    //下方的为已完成的方块
    if(map[dy][dx]==5)
        return;
    //下方为墙
    if(map[dy][dx]==1)
        return;
    //下方为箱子
    if(map[dy][dx]==3)
    {
        //判断箱子下方是否为墙
        if(map[dy+1][dx]==1)
            return;
        //判断箱子下方是否为终点
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
    //定义存储人物右边的坐标
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
        //判断右边是否为墙
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

//游戏的main主函数
int main(int argc, char *argv[])
{
    char direction;     //存储键盘的方向
    initData();

    //开始游戏的循环,死循环
    while(1){
        system("cls");
        drawMap();
        //判断boxs数量，若为0，则游戏结束，跳出循环
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
    printf("恭喜你完成游戏!");
    return 0;
}
