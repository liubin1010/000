#include"process.h"

void InitStack(SeqStackCar*s)//堆栈初始化
{
	s->top=0;
	s->stack[s->top]=NULL;
}

int InitQueue(LinkQueueCar*Q)//队列初始化
{
	Q->head=new QueueNode;
	if(Q->head!=NULL)
	{
		Q->head->next=NULL;
		Q->rear=Q->head;
		return 1;
	}
	else
		return -1;
}

void PRINT(CarNode*p,int room)//输出离开停车场的车辆情况
{
    int A,B,C,D,F;
	cout<<"车辆离开时间："<<endl;
	cout<<"输入小时： ";
	cin>>p->leave.hour;
	cout<<"输入分钟： ";
	cin>>p->leave.min;
	cout<<"离开车辆的车牌号为："<<p->num<<endl;
	cout<<"其到达时间为： "<<p->reach.hour<<":"<<p->reach.min<<endl;
	cout<<"离开时间为： "<<p->leave.hour<<":"<<p->leave.min<<endl;
	A=p->reach.hour;
	B=p->reach.min;
	C=p->leave.hour;
	D=p->leave.min;
	F=(C-A)*60+(D-B);
    cout<<"应交费用为："<<F<<"元"<<endl;
	cout<<"车辆离开登记完毕！"<<endl;
	cout<<"-------------------------------------------------"<<endl;
	delete p;
}

int Reach(SeqStackCar*Enter,LinkQueueCar*W)
{
    CarNode *p;
	QueueNode *t;
	p=new CarNode;
	cout<<"-------------------------------------------------"<<endl;
	cout<<"车辆到达 登记开始："<<endl;
	cout<<"请输入车牌号：";
	cin>>p->num;
	if(Enter->top<MAX)//如果车位未满进入停车场
	{
		Enter->top++;
		cout<<"车辆在车场第"<<Enter->top<<"位置"<<endl;
		cout<<"车辆到达时间："<<endl;
		cout<<"输入小时：";
		cin>>p->reach.hour;
		cout<<"输入分钟：";
		cin>>p->reach.min;
        cout<<"车辆到达登记完毕！"<<endl;
		cout<<"---------------------------------------------"<<endl;
		Enter->stack[Enter->top]=p;
		return 1;
	}
	else//如果车位已满，则停在便道上
	{
	    cout<<"---------------------------------------------"<<endl;
		//cout<<"---------------------------------------------"
		cout<<"该车必须停在便道上，有车位时进入停车场"<<endl;
		t=new QueueNode;
		t->data=p;
		t->next=NULL;
		W->rear->next=t;
		W->rear=t;
		return 1;
	}
}

void Leave(SeqStackCar*Enter,SeqStackCar*Temp,LinkQueueCar*W)
{
    int room;
	CarNode *p,*t;
	QueueNode *q;

	if(Enter->top>0)
	{
	    while(1)
		{
		    cout<<"---------------------------------------------"<<endl;
			cout<<"车辆离开 登记开始："<<endl;
			cout<<"请输入车在车场的位置/1--"<<Enter->top<<"/:";
			cin>>room;
			if(room>=1&&room<=Enter->top)
				break;
		}
		while(Enter->top>room)//从停车场堆栈向中转堆栈移动车辆，直到要离开车辆的位置停止
		{
			Temp->top++;
			Temp->stack[Temp->top]=Enter->stack[Enter->top];
			Enter->stack[Enter->top]=NULL;
			Enter->top--;
		}
		p=Enter->stack[Enter->top];
		Enter->stack[Enter->top]=NULL;
		Enter->top--;
		while(Temp->top>=1)//将中转堆栈中的车辆移到停车场堆栈
		{
			Enter->top++;
			Enter->stack[Enter->top]=Temp->stack[Temp->top];
			Temp->stack[Temp->top]=NULL;
			Temp->top--;
		}
		cout<<"------------------------------------------------"<<endl;
		cout<<"车辆离开登记结算："<<endl;
		PRINT(p,room);
		if((W->head!=W->rear)&&Enter->top<MAX)
		{
			q=W->head->next;
			t=q->data;
			Enter->top++;
			cout<<"便道的"<<t->num<<"号车进入车场第"<<Enter->top<<"位置"<<endl;
			cout<<"请输入"<<t->num<<"号车进入车场时间："<<endl;
			cout<<"输入小时：";
			cin>>t->reach.hour;
			cout<<"输入分钟：";
			cin>>t->reach.min;
			W->head->next=q->next;
			if(q=W->rear)
				W->rear=W->head;
			Enter->stack[Enter->top]=t;
			delete q;
		}
		else
			cout<<"便道里没有车！"<<endl;
	}
	else
		cout<<"车场里没有车"<<endl;
}

void List1(SeqStackCar *S)//查看停车场内车辆情况的函数定义
{
    int i;
	if(S->top>0)
	{
	    cout<<"---------------------------------------------"<<endl;
		cout<<"车场内部车辆停靠情况："<<endl;
		cout<<"位置       到达时间       车牌号"<<endl;
		for(i=1;i<=S->top;i++)
		{
		    cout<<i;
			cout<<"             "<<S->stack[i]->reach.hour<<":"<<S->stack[i]->reach.min;
			cout<<"             "<<S->stack[i]->num<<endl;
		}
	}
	else
		cout<<"车场里没有车"<<endl;
	cout<<"---------------------------------------------"<<endl;
}

void List2(LinkQueueCar *W)//查看便道上停靠车辆的情况的函数定义
{
    QueueNode *p;
	p=W->head->next;
	if(W->head!=W->rear)
	{
	    cout<<"---------------------------------------------"<<endl;
		cout<<"便道停靠车辆情况："<<endl;
		while(p!=NULL)
		{
		     cout<<"车辆牌号：";
			 cout<<p->data->num<<endl;
			 p=p->next;
		}
	}
	else
		cout<<"便道里没有车。"<<endl;
	cout<<"--------------------------------------------------"<<endl;
}

void List(SeqStackCar S,LinkQueueCar W)//车辆列表显示函数
{
    int flag,tag;
	flag=1;
	while(flag)
	{
	    cout<<"--------------------------------------------------"<<endl;
		cout<<"车辆停靠查询开始："<<endl;
		cout<<"请选择1|2|3："<<endl;
		cout<<"1.车场列表"<<endl;
		cout<<"2.便道列表"<<endl;
		cout<<"3.返回主菜单"<<endl;
		while(1)
		{
		    cin>>tag;
			if(tag>=1||tag<=3)
				break;
			else
				cout<<endl;
			cout<<"请选择1~3：";
		}
		switch(tag)
		{
		case 1:List1(&S);
			cout<<"车辆停靠查询结束！"<<endl;
			break;
		case 2:List2(&W);
			cout<<"车辆停靠查询结束！"<<endl;
			break;
		case 3:
			flag=0;
			break;
		default:break;
		}
	}
	cout<<"------------------------------------------"<<endl;
}