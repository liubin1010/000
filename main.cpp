#include"process.h";
void mune()
{
    cout<<"        ��ӭ����ͣ������        "<<endl;
	cout<<"1.��������Ǽ�"<<endl;
	cout<<"2.�����뿪�Ǽ�"<<endl;
	cout<<"3.����ͣ����ѯ"<<endl;
	cout<<"4.�˳�ϵͳ"<<endl;//ϵͳѡ������
}

void main()
{
    SeqStackCar Enter,Temp;//��ʼջ����תջ
	LinkQueueCar Wait;//�������
	int a;
	InitStack(&Enter);
	InitStack(&Temp);
	InitQueue(&Wait);//��ʼ��
	mune();
	while(true)
	{
		cout<<"��ѡ��";
		cin>>a;
		if(a == 1)
		{
			Reach(&Enter,&Wait);
			continue;
		}
		else if(a == 2)
		{
			Leave(&Enter,&Temp,&Wait);
			continue;
		}
		else if(a == 3)
		{
			List(Enter,Wait);
			continue;
		}
		else if(a == 4)
		{
			exit(0);
		}
		else
		{
			break;
		}
	}
}

