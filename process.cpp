#include"process.h"

void InitStack(SeqStackCar*s)//��ջ��ʼ��
{
	s->top=0;
	s->stack[s->top]=NULL;
}

int InitQueue(LinkQueueCar*Q)//���г�ʼ��
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

void PRINT(CarNode*p,int room)//����뿪ͣ�����ĳ������
{
    int A,B,C,D,F;
	cout<<"�����뿪ʱ�䣺"<<endl;
	cout<<"����Сʱ�� ";
	cin>>p->leave.hour;
	cout<<"������ӣ� ";
	cin>>p->leave.min;
	cout<<"�뿪�����ĳ��ƺ�Ϊ��"<<p->num<<endl;
	cout<<"�䵽��ʱ��Ϊ�� "<<p->reach.hour<<":"<<p->reach.min<<endl;
	cout<<"�뿪ʱ��Ϊ�� "<<p->leave.hour<<":"<<p->leave.min<<endl;
	A=p->reach.hour;
	B=p->reach.min;
	C=p->leave.hour;
	D=p->leave.min;
	F=(C-A)*60+(D-B);
    cout<<"Ӧ������Ϊ��"<<F<<"Ԫ"<<endl;
	cout<<"�����뿪�Ǽ���ϣ�"<<endl;
	cout<<"-------------------------------------------------"<<endl;
	delete p;
}

int Reach(SeqStackCar*Enter,LinkQueueCar*W)
{
    CarNode *p;
	QueueNode *t;
	p=new CarNode;
	cout<<"-------------------------------------------------"<<endl;
	cout<<"�������� �Ǽǿ�ʼ��"<<endl;
	cout<<"�����복�ƺţ�";
	cin>>p->num;
	if(Enter->top<MAX)//�����λδ������ͣ����
	{
		Enter->top++;
		cout<<"�����ڳ�����"<<Enter->top<<"λ��"<<endl;
		cout<<"��������ʱ�䣺"<<endl;
		cout<<"����Сʱ��";
		cin>>p->reach.hour;
		cout<<"������ӣ�";
		cin>>p->reach.min;
        cout<<"��������Ǽ���ϣ�"<<endl;
		cout<<"---------------------------------------------"<<endl;
		Enter->stack[Enter->top]=p;
		return 1;
	}
	else//�����λ��������ͣ�ڱ����
	{
	    cout<<"---------------------------------------------"<<endl;
		//cout<<"---------------------------------------------"
		cout<<"�ó�����ͣ�ڱ���ϣ��г�λʱ����ͣ����"<<endl;
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
			cout<<"�����뿪 �Ǽǿ�ʼ��"<<endl;
			cout<<"�����복�ڳ�����λ��/1--"<<Enter->top<<"/:";
			cin>>room;
			if(room>=1&&room<=Enter->top)
				break;
		}
		while(Enter->top>room)//��ͣ������ջ����ת��ջ�ƶ�������ֱ��Ҫ�뿪������λ��ֹͣ
		{
			Temp->top++;
			Temp->stack[Temp->top]=Enter->stack[Enter->top];
			Enter->stack[Enter->top]=NULL;
			Enter->top--;
		}
		p=Enter->stack[Enter->top];
		Enter->stack[Enter->top]=NULL;
		Enter->top--;
		while(Temp->top>=1)//����ת��ջ�еĳ����Ƶ�ͣ������ջ
		{
			Enter->top++;
			Enter->stack[Enter->top]=Temp->stack[Temp->top];
			Temp->stack[Temp->top]=NULL;
			Temp->top--;
		}
		cout<<"------------------------------------------------"<<endl;
		cout<<"�����뿪�Ǽǽ��㣺"<<endl;
		PRINT(p,room);
		if((W->head!=W->rear)&&Enter->top<MAX)
		{
			q=W->head->next;
			t=q->data;
			Enter->top++;
			cout<<"�����"<<t->num<<"�ų����복����"<<Enter->top<<"λ��"<<endl;
			cout<<"������"<<t->num<<"�ų����복��ʱ�䣺"<<endl;
			cout<<"����Сʱ��";
			cin>>t->reach.hour;
			cout<<"������ӣ�";
			cin>>t->reach.min;
			W->head->next=q->next;
			if(q=W->rear)
				W->rear=W->head;
			Enter->stack[Enter->top]=t;
			delete q;
		}
		else
			cout<<"�����û�г���"<<endl;
	}
	else
		cout<<"������û�г�"<<endl;
}

void List1(SeqStackCar *S)//�鿴ͣ�����ڳ�������ĺ�������
{
    int i;
	if(S->top>0)
	{
	    cout<<"---------------------------------------------"<<endl;
		cout<<"�����ڲ�����ͣ�������"<<endl;
		cout<<"λ��       ����ʱ��       ���ƺ�"<<endl;
		for(i=1;i<=S->top;i++)
		{
		    cout<<i;
			cout<<"             "<<S->stack[i]->reach.hour<<":"<<S->stack[i]->reach.min;
			cout<<"             "<<S->stack[i]->num<<endl;
		}
	}
	else
		cout<<"������û�г�"<<endl;
	cout<<"---------------------------------------------"<<endl;
}

void List2(LinkQueueCar *W)//�鿴�����ͣ������������ĺ�������
{
    QueueNode *p;
	p=W->head->next;
	if(W->head!=W->rear)
	{
	    cout<<"---------------------------------------------"<<endl;
		cout<<"���ͣ�����������"<<endl;
		while(p!=NULL)
		{
		     cout<<"�����ƺţ�";
			 cout<<p->data->num<<endl;
			 p=p->next;
		}
	}
	else
		cout<<"�����û�г���"<<endl;
	cout<<"--------------------------------------------------"<<endl;
}

void List(SeqStackCar S,LinkQueueCar W)//�����б���ʾ����
{
    int flag,tag;
	flag=1;
	while(flag)
	{
	    cout<<"--------------------------------------------------"<<endl;
		cout<<"����ͣ����ѯ��ʼ��"<<endl;
		cout<<"��ѡ��1|2|3��"<<endl;
		cout<<"1.�����б�"<<endl;
		cout<<"2.����б�"<<endl;
		cout<<"3.�������˵�"<<endl;
		while(1)
		{
		    cin>>tag;
			if(tag>=1||tag<=3)
				break;
			else
				cout<<endl;
			cout<<"��ѡ��1~3��";
		}
		switch(tag)
		{
		case 1:List1(&S);
			cout<<"����ͣ����ѯ������"<<endl;
			break;
		case 2:List2(&W);
			cout<<"����ͣ����ѯ������"<<endl;
			break;
		case 3:
			flag=0;
			break;
		default:break;
		}
	}
	cout<<"------------------------------------------"<<endl;
}