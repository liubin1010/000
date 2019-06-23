#include<iostream>
#include<string>
using namespace std;
#define MAX 5//停车场车位数
#define print 0.05//每分钟收取的费用

typedef struct time 
{
    int hour,min;
}Time;//定义时间结点

typedef struct node
{
    string num;
	Time reach,leave;
}CarNode;//定义每辆车的车牌号，进入时刻，离开时刻

typedef struct NODE
{
    CarNode *stack[MAX+1];
	int top;
}SeqStackCar;//用栈定义，构造停车场

typedef struct car
{
    CarNode *data;
	struct car*next;
}QueueNode;//用队列结点定义，构造停车场外的单个等候车辆

typedef struct Node
{
    QueueNode *head,*rear;
}LinkQueueCar;//用队列定义，构造停车场外的等候便道

void InitStack(SeqStackCar*);//初始化堆栈函数声明
int InitQueue(LinkQueueCar*);//初始化队列头结点函数声明
int Reach(SeqStackCar*,LinkQueueCar*);//车辆进入时登记函数声明
void Leave(SeqStackCar*,SeqStackCar*,LinkQueueCar*);//车辆离开时函数声明
void List(SeqStackCar,LinkQueueCar );//查看停车场内车辆情况及便道上车辆情况的函数声明
void PRINT(CarNode*p,int room);//输出离开停车场的车辆情况
