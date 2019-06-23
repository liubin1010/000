#include"process.h";
void mune()
{
    cout<<"        欢迎光临停车场！        "<<endl;
	cout<<"1.车辆到达登记"<<endl;
	cout<<"2.车辆离开登记"<<endl;
	cout<<"3.车辆停靠查询"<<endl;
	cout<<"4.退出系统"<<endl;//系统选项设置
}

void main()
{
    SeqStackCar Enter,Temp;//初始栈，中转栈
	LinkQueueCar Wait;//便道队列
	int a;
	InitStack(&Enter);
	InitStack(&Temp);
	InitQueue(&Wait);//初始化
	mune();
	while(true)
	{
		cout<<"请选择：";
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

