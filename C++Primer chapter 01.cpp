//练习1.3
	#include <iostream>
	int main()
	{
		std::cout<<"Hello,World."<<endl;
		return 0;
	}
	
//练习1.4
	#include <iostream>
	int main()
	{
		std::cout<<"请输入两个数:"<<std::endl
		int v1 =0,v2 =0;
		std::cin>>v1>>v2;
		std::cout<<v1<<"和"<<v2<<"的乘积为："<<v1*v2<<endl;
		return 0;
	}
	
//练习1.5
	#include <iostream>
	int main()
	{
		std::cout<<"请输入两个数："；
		std::cout<<sdt::endl;
		int v1 =0,v2 =0;
		std::cin>>v1>>v2;
		std::cout<<v1<<"和"<<v2<<"的积为:"<<v1*v2<<std::endl;
		return 0;
	}
//练习1.6
//不合法
	std::cout<<"The sum of"<<v1;		//不需要添加分好
			 <<"and"<<v2;				//不需要添加分好
			 <<"is"<<v1+v2<<std::endl;
			 
//练习1.8
	std::cout<<"/*";					//输出为：/*
	std::cout<<"*/";					//输出为：*/
	std::cout<</*"*/"*/;				//输出错误
	std::cout<</*"*/"/*"/*"*/;			//输出为：/*

//练习1.9
	#include <iostream>
	int main()
	{
		int sum =0；
		int num = 50;
		while(num<=100)
		{
			sum += num;
			num++;
		}
		return 0;
	}

//练习1.10
	#include <iostream>
	int main()
	{
		int p =10;
		while(p>=0)
		{
			std::cout<<p--<<std::endl;
		}
		return 0;
	}
//练习1.11
	#include <iostream>
	int main()
	{
		int v1 = 0,v2 =0;
		std::cout<<"Please enter two numbers:"<<endl;
		std::cin>>v1>>v2;
		if(v1>=v2)
			while(v1>=v2)
				std::cout<<v2++<<std::endl;
			
		else
			while(v1<=v2)
				std::cout<<v1++<<endl;
		return 0;
	}
	
//练习1.12
		完成了从-100 加到 100 的求和过程
		终值为0
	
//练习1.13
	#include <iostream>
	int main()
	{
		
		int sum =50;
		for(int num = 50;num<=100；++num)
		{
			sum += num;
		}
		return 0;
	}
	
	
	#include <iostream>
	int main()
	{
		int p =0;
		for(p =10;p>=0;p--)
			std::cout<<p<<std::endl;
		return 0;
	}
	
	#include <iostream>
	int main()
	{
		int v1 = 0,v2 =0;
		std::cout<<"Please enter two numbers:"<<endl;
		std::cin>>v1>>v2;
		if(v1>=v2)
			for(;v1>=v2;v2++)
				std::cout<<v2<<std::endl;
		else
			for(;v1<=v2;v1++)
				std::cout<<v1<<endl;
		return 0;
	}
//练习1.14


//练习1.15
	//键盘输入结束标志 Windows "Ctrl+Z"+Enter
	//键盘输入结束标志 Unix "Ctrl+D"

//练习1.16
	#include <iostream>
	int main()
	{
		int num =0,sum =0;
		
		std::cout<<"Please enter a seriers of numbers:"
		while(std::cin>>num)
		{
			sum += num;
		}
		std::cout<<"The sum of these numbers is :";
		std::cout<<sum<<endl;
		
		return 0;
	}
	
//练习1.17
	
//练习1.18

//练习1.19
		//练习1.10 已经包含此项功能

//练习1.20
	#include <iostream>
	#include "Sales_item.h"
	int main()
	{
		Sales_item book;
		while (std::cin >> book)
		{
			std::cout << "ISBN、售出本数、销售额和平均售价为"
				<< book << std::endl;
		}
		return 0;
	}
	
//练习1.21

	#include <iostream>
	#include "Sales_item.h"
	int main()
	{
		Sales_item book1,book2,sum;
		std::cout << "请输入两条销售记录：" << std::endl;
		std::cin >> book1 >> book2;
		sum = book1 + book2;
		std::cout << "ISBN、总售出本数、总销售额和平均售价为: " << sum << std::endl;
		system("pause");
		return 0;
	 }

//练习1.22
#include <iostream>
#include "Sales_item.h"
int main()
{
	Sales_item book,sum;
	std::cout << "请输入多条ISBN号相同的销售记录：" << std::endl;
	while (std::cin >> book)
		sum += book;
	std::cout << "ISBN、总售出本数、总销售额和平均售价为: " << sum << std::endl;
	system("pause");
	return 0;
 }

//练习1.23
#include <iostream>
#include "Sales_item.h"
int main()
{
	Sales_item book1,book2;
	int num = 0;
	std::cout << "请输入多条的销售记录：" 
		<< std::endl;
	if (std::cin >> book1) 
	{
		while (std::cin >> book2)
		{
			if (book1.same_isbn(book2))//ISBN相同
				num++;
			else {	//ISBN不同
				std::cout <<book1.isbn()<<"共有"<<num<<"销售记录"<<std::endl;
				book1 =book2;
				num =1
			}
			std::cout<<book1.isbn()<<"共有"<<num<<"销售记录"<<std::endl;
		}
		else{
			std::cout<<"没有数据"<<std::endl;
			return -1;
		}
	}
	system("pause");
	return 0;
 }






















			 