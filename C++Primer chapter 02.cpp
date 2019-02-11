//第Ⅰ部分
//C++基础
//第2章
//变量和基本类型

//练习2.1
	int			整型		16位
	long		长整型		32位
	long long 	长整型		64位
	short		短整型		16位
	
	无符号类型与有符号类型
			无符号类型中所有比特都用来存储数值，仅能表示非负数值
			而有符号类型则可以表示负数
			
	float 和 double  
	float 为单精度浮点数     6 位有效数字
	double 为双精度浮点数	10 位有效数字
	
//练习2.2
	利率、本金、付款都可能是整数或普通实数，应该选取一种浮点数类型。
	浮点数类型有float、double、long double
	其中long double的计算代价相对较大，一般情况下不选择。
	double的计算代价和float相近，但double表示的范围更广。
	终上所述，选择 double 类型比较合适
	
//练习2.3
	输出结果：
		32
		65504 （ -32 ）（int 为16位时）
	输出结果：
		32
		-32
		0		//无符号整数与带符号整数运算时，先把带符号整数转换为无符号整数
		0
//练习2.4	

//练习2.5
		（a）
			'a'				表示字符a
			L'a'			表示宽字符型字面值a
			"a"				表示字符串a
			L"a"			表示宽字符型字符串a
		(b)
			10				表示一个普通的整数类型字面值
			10u				表示一个无符号数
			10L				表示一个长整型
			10uL			表示一个无符号长整形
			012				表示一个八进制
			0xC				表示一个十六进制

		(c)
			3.14			表示一个普通的浮点数字面值
			3.14f			表示单精度浮点数
			3.14L			表示一个 long double 类型的扩展精度浮点数
		
		(d)
			10				表示整数
			10uL			表示一个无符号整数
			10.				表示一个浮点数
			10e-2			表示科学计数法 0.1
//练习2.6
		//有区别：第一行表示十进制，正确，第二行表示八进制，编译会出现错误

//练习2.7
			 (a)是一个字符串 转义字符 \145 表示e  转义字符\012 表示换行符
				 该字符串的输出结果是 Who goes with Fergus?
			 (b)是一个科学计数法表示的扩展精度浮点数
			 (c)表示单精度浮点数，但是在某些编辑器中将报错，应该写为1024.f
			 (d)表示扩展精度浮点数，类型是 long double
//练习2.8
#include <iostream>

int main()
{
	std::cout<<"2\x4d\n";		//输出2M，然后换行
	std::cout<<"2\tM\012"；		//输出2、制表符、M，然后换行
	return 0;
}
		
//练习2.9
	(a)std::cin>>int input_value;  //错误
	
	(b)int i = {3.14};			//错误，引发警告，定义一个整型变量i，使用列表初
								//始化把浮点数赋值给整型造成小数丢失
	
	(c)double salary = wange = 9999.99;
								//错误，在声明语句中声明多个变量时
								//需要用逗号将变量名隔开，而不能直
								//接用赋值运算符链接
	(d)int i = 3.14；			//引发警告，小数部分丢失
	
//练习2.10
		string 类型初始化为空串
		函数体之外 global_int 初始化为0
		局部变量 local_int 不被初始化
		
//练习2.11
		声明使得名字为程序所知，而定义负责创建与名字关联的实体
		(a)extern int ix = 1024 ; 定义了变量ix
		(b)int iy;        声明并定义了变量iy
		(c)extern int iz; 声明了变量iz
//练习2.12
		a、c、d非法
		b、e合法
		
//练习2.13
		j的值为100；
		
//练习2.14
		合法
		输出：
			100 45
	
//练习2.15
       b、d非法
		a、c合法

//练习2.16
			都合法

//练习2.17
			输出：
				10 10
				
//练习2.18
	#include <iostream>
	int main()
	{
		
		int i = 10;
		int j = 100;
		int *p = &i;		//指针指向i
		std::cout<<"i: "<<i<<" j: "<<j<<" p: "<<*p<<"\n";
		p = &j;         //更改指针的值，指向j
		std::cout<<"i: "<<i<<" j: "<<j<<" p: "<<*p<<"\n";
		*p = 50;		//指针所指对象的值
		std::cout<<"i: "<<i<<" j: "<<j<<" p: "<<*p<<"\n";
		j = 20;		//指针所指对象的值
		std::cout<<"i: "<<i<<" j: "<<j<<" p: "<<*p<<"\n";
		return 0;
	}
	
//练习2.19
	指针“指向”内存中的某个对象，而引用“绑定到”内存中的某个对象，他们都实现了
对其他对象的间接访问，二者的区别主要有两方面：
	第一，指针本身就是一个对象，允许对指针赋值和拷贝，在指针的生命周期内它可以
指向几个不同的对象：引用不是一个对象，无法令引用重新绑定到另外一个对象。
	第二，指针无需定义时赋值，和其他内置类型一样，在块作用域内定义的指针如果没
有被初始化，也将拥有一个不确定的值：引用则必须在定义时赋初值。

//练习2.20
		声明定义
		指针定义
		p1指向的值的乘以自身再赋值给自身
		
//练习2.21
		a、b不合法 c合法
//练习2.22
		如果指针指向一个真实存在的变量，其值不为0，此时条件为真
		没有指向对象或者是无效指针，则对p的使用将引发不可预计的结果
		
		*p是检验指针所指向的对象的内容
		
//练习2.23		
		初始化为
		nullptr
		
		置于try结构中进行检查
		
//练习2.24
		指针类型不同，void*是一种特殊的指针类型，可用于存放任意对象的地址
		
//练习2.25
		(a)ip是一个整型指针，它的值是所指整型在内存中的地址；
			i是一个整型数；
			r是一个引用，绑定好了i，r的值就是i的值
		(b)i是一个整型数；ip是一个整型指针，但不指向具体对象，值被初始化为0；
		(c)ip是一个整型指针，它的值是所指整型在内存中的地址；
			ip2是一个整型数。
//练习2.26
		a、d不合法
		b、c合法
		
//练习2.27
		(a)非法
		(b)合法
		(c)合法
		(d)合法
		(e)合法
		(f)非法
		(g)合法
//练习2.28
	(a) int i,*const cp;
		非法，cp是常量指针，必须初始化
	(b) int *p1,*const p2;
		非法，p2是常量指针，必须初始化
	(c)const int ic,&r =ic;
		非法，ic是常量，因其值不能被改变，所以必须被初始化
	(d)const int *const p3;
		非法，p3是常量指针，必须初始化。同时，p3指向的是常量，不能通过p3
		修改对象的值
	
	
//练习2.29
		合法
		非法
		非法
		非法
		非法
		非法
//练习2.30	
		v2和p3是顶层const
		p2和r2是底层const
//练习2.31
		r1=r2；是合法的
		p1=p2; 是非法的
		p2=p1；是合法的
		p1=p3; 是非法的
		p2=p3; 是合法的
		
		
//练习2.32
		代码非法
		null 是一个 int 变量，p 是一个 int 指针，二者不能直接绑定
		修改为
		int null = 0，*p = nullptr;

//类型别名
//练习2.33		
//练习2.34		
//练习2.35		
	i是一个整型常量
	j的类型的推断结果是整数
	k的类型推断结果是整型常量
	p的类型推断结果是指向整形常量的指针
	j2的类型推断结果是整数
	k2的类型推断结果是整数
		
		验证程序：
	#include <iostream>
	#include <typeinfo>
	
	int main()
	{
		const int i = 42;
		auto j =i;
		const auto &k = i;
		auto *p = &i;
		const auto j2 i,&k2 =i ;
		std::cout<<typeid(i).name()<<std::endl;
		std::cout<<typeid(j).name()<<std::endl;
		std::cout<<typeid(k).name()<<std::endl;
		std::cout<<typeid(p).name()<<std::endl;
		std::cout<<typeid(j2).name()<<std::endl;
		std::cout<<typeid(k2).name()<<std::endl;
		
		return 0;
	}
		
//练习2.36
		c的类型就是a的类型
		d的类型是引用，及d是变量a的别名
		结束后
		a = d = 4
		c = 4
		b = 4
		
//练习2.37
		c 为 int ，值为3
		a的值不变，仍为3
		d的类型是 int& ，d是a的别名，值为3
		b的值一直没有发生改变，为4
//练习2.38
		1. auto 类型说明符用编译器计算变量的初始值来判断其类型，而decltype
		虽然也让编译器分析表达式并得到他的类型，但是不实际计算表达式的值
		2. 编译器推断出来的auto类型有时候是初始值的类型并不完全一样，编译器
		会适当地改变结果类型使其更符合初始化原则。
		3. 与auto不同，delctype的结果类型与表达式形式密切相关，如果变量名加
		上了一对括号，则得到的类型与不加括号时会有不同。
//练习2.39	
		无法通过编译	
		
//练习2.40
		struct Sale_Data{
			std::string ISBN;
			std::string bookName;
			unsigned  units_sold = 0;
			unsigned  units_left = 0;
			double originalPrice = 0.0;
			bool _have_discount = false;
			double discount = 10.0;
			double saleprice = 0.00;
		};
		
//练习2.41
		#inclde <iostream>
			class Sale_Data{
			std::string ISBN;
			std::string bookName;
			unsigned  units_sold = 0;
			unsigned  units_left = 0;
			double originalPrice = 0.0;
			bool _have_discount = false;
			double discount = 10.0;
			double saleprice = 0.00;
		};
		int main()
		{
			
			return 0;
		}
		
//练习2.42		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		