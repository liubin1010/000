#include<iostream>
#include<string>
using namespace std;
#define MAX 5//ͣ������λ��
#define print 0.05//ÿ������ȡ�ķ���

typedef struct time 
{
    int hour,min;
}Time;//����ʱ����

typedef struct node
{
    string num;
	Time reach,leave;
}CarNode;//����ÿ�����ĳ��ƺţ�����ʱ�̣��뿪ʱ��

typedef struct NODE
{
    CarNode *stack[MAX+1];
	int top;
}SeqStackCar;//��ջ���壬����ͣ����

typedef struct car
{
    CarNode *data;
	struct car*next;
}QueueNode;//�ö��н�㶨�壬����ͣ������ĵ����Ⱥ���

typedef struct Node
{
    QueueNode *head,*rear;
}LinkQueueCar;//�ö��ж��壬����ͣ������ĵȺ���

void InitStack(SeqStackCar*);//��ʼ����ջ��������
int InitQueue(LinkQueueCar*);//��ʼ������ͷ��㺯������
int Reach(SeqStackCar*,LinkQueueCar*);//��������ʱ�ǼǺ�������
void Leave(SeqStackCar*,SeqStackCar*,LinkQueueCar*);//�����뿪ʱ��������
void List(SeqStackCar,LinkQueueCar );//�鿴ͣ�����ڳ������������ϳ�������ĺ�������
void PRINT(CarNode*p,int room);//����뿪ͣ�����ĳ������
