//第七章 类
//练习7.1
#include <iostream>
#include "Sales_data.h"
using namespace std;

int main()
{
	cout<<"请输入交易记录（ISBN、销售量、实际售价）："<<endl;
	Slaes_data total;
	if(cin>>trans)
	{
		Sales_data trans;
		while(cin>>trans)
		{
		if(total.isbn() == trans.isbn())
			total += trans;
		else
		{
			cout<<total<<endl;
			total = trans;
		}
		}
		cout<<total<<endl;
	}
	else
	{
		cerr<<"No data?!"<<endl;
		return -1;
	}
	return 0;
}

//练习7.2
 class Sales_data
 {
	 private:
		string bookNo;
		unsigned units_sold = 0;
		double sellingprice = 0.0;
		double saleprice = 0.0;
		double discount = 0.0;
		
		
	public:
	//isbn 函数只有一句语句，返回bookNo
	string isbn() const {return bookNo;}
	
	
	//combine 函数用于把两个ISBN相同的销售记录合并在一起
	Sales_data& combine(const Sales_data &rhs)
	{
		units_sold += rhs.units_sold;
		saleprice =(rhs.saleprice*rhs.units_sold+saleprice*units_sold)/
					(rhs.units_sold+units_sold);
		if(sellingprice ！= 0)
			discount = saleprice/sellingprice;
			return *this;
	}
 }；

//练习7.3
#include <iostream>
#include "Sales_data.h"
using namespace std;

int main()
{
	cout<<"请输入交易记录（ISBN、销售量、原价、实际售价）："<<endl;
	Sales_data total;
	//读入第一条交易记录，并确保有数据可以处理
	if(cin>>total)
	{
		Sales_data trans;
		//读入并处理剩余交易记录
		while(cin>>trans)
		{
			//如果我们仍在处理相同的书
			if(total.isbn() == trans.isbn())
				total.combine(trans);		//更新总销售额
			else
			{
				//打印前一本书的结果
				cout<<total<<endl;
				total = trans;			//taotal现在表示下一本书的销售额
			}
		}
		cout<<total<<endl;				//打印最后一本书 的结果
	}
	else
	{
		//
		cerr<<"No data?!"<<endl;
		return -1;						//表示失败
	}
	return 0;
}

//练习7.4
class Person
{
	private:
		string strName;		//姓名
		string strAddress;	//地址
}；

//练习7.5
class Person
{
	private:
		string strName;
		string strAddress;
	public:
		string getName() const{return strName;}		//返回姓名
		string getAddress() const {return strAddress;}	//返回地址
}；


//练习7.6
Sales_data add(cosnt Sales_data &lhs,cosnt Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}
std::istream &read(std::istream &is,Sales_data &iteam)
{
	is>>item.bookNo>>iteam.units_sold>>iteam.sellingprice>>item.saleprice;
	return is;
}
std::ostream &print(std::ostream &os,cosnt Sales_data &item)
{
	os<<item.isbn()<<" "<<item.units_sold<<" "<<item.Sellingprice
		<<" "<<item.saleprice<<" "<<item.discount;
	return os;
}

//练习7.7
#include <iostream>
#include "Sales_data.h"
using namespace std;

int main()
{
	cout<<"请输入交易记录（ISBN、销售量、原价、实际售价）："<<endl;
	Sales_data total;
	//
	if(read(cin,total))
	{
		Sales_data trans;		//
		//读入并处理剩余交易记录
		while(read(cin,trans))
		{
			
			if(total.isbn() == trans.isbn())
				total = add(total,trans);		//更新总销售额
			//打印前一本书的结果
			else
			{
			print(cout,total);
			cout<<end;
			total = trans;			//total现在表示下一本书的销售额
			}
			
		}
		print(cout,total);
		cout<<endl;					//打印最后一本书
	}
	else
	{
		//没有输入！警告读者
		cerr<<"No data?!"<<endl;
		return -1;					//表示失败
	}
	return 0;
}

//练习7.8
	read函数将其Sale_data参数定义成普通的引用是因为我们需要从标准输入流中读取
数据并将其写入到给定是Sales_data对象，因此需要有修改对象的权限。而print将其参数
定义成常量引用是因为他只负责数据的输出，不对其做任何更改。


//练习7.9

	//read函数
	std::istream &read(std::istream &is,Person &per)
	{
		is>>per.strName>>per.strAddress;
		return is;
	}
	
	//print函数
	std::ostream &print(std::ostream &os,const Person &per)
	{
		os<<per.getName()<<per.getAddress();
		return os;
	}


//练习7.10
	因为read函数的返回类型是引用，所以read(cin,data1)的返回值可以继续作为外层
read函数的实参使用。该条件检验读入data1和data2的过程是否正确，如果正确，条件满
足；否则条件不满足。

//练习7.11
class Sales_data
{
	public:
		Sales_data() = default;
		Sales_data(const std::string &book)；bookNo(book){}
		Sales_data(const std::string &book,const unsigned num,
					const double sellp,const double salep);
		Sales_data(std::istream &is);
	public:
		std::string bookNo;			//书籍编号
		unsigned units_sold = 0;	//销售量
		double sellingprice = 0.0;	//原始价格
		double saleprice = 0.0;		//实售价格
		double discount = 0.0;		//折扣
};

Sale_data::Sales_data(const std::string &book,const unsigned num,
					const double sellp,const double salep)

{
	bookNo = book;
	units_sold = num;
	sellingprice = sellp;
	saleprice = sellp;
	saleprice = salep;
	if(sellingprice != 0)
		discount = saleprice/sellingprice;	//计算实际折扣
	
}
Sale_data::Sale_data(std::istream &is)
{
	is>>*this;
}

#include <iostream>
#include "Sale_data.h"
using namespace std;

int main()
{
	Sale_data data1;
	Sale_data data2("978-121-15535-2");
	Sale_data data3("978-121-15535-2",100,128,109);
	Sale_data data4(cin);
	
	cout<<"书籍的销售情况是："<<endl;
	cout<<data1<<"\n"<<data2<<"\n"<<data3<<"\n"<<data4<<"\n";
	return 0;
}

//练习7.12
class Sales_data
{
	public:
		Sales_data() = default;
		Sales_data(const std::string &book)；bookNo(book){}
		Sales_data(const std::string &book,const unsigned num,
					const double sellp,const double salep);
		Sales_data(std::istream &is){is>>*this};
	public:
		std::string bookNo;			//书籍编号
		unsigned units_sold = 0;	//销售量
		double sellingprice = 0.0;	//原始价格
		double saleprice = 0.0;		//实售价格
		double discount = 0.0;		//折扣
};
//练习7.13
#incldue <iostream>
#incldue "Sales_data.h"
using namespace std;

int main()
{
		Sale_data total(cin);						//保存当前求和结果
		if(cin)
		{											//读入第一笔交易记录
			Sale_data trans(cin);					//保存下一条交易数据的变量
			do
			{										//读入剩余的交易
				if(total.isbn() == trans.isbn())	//检查isbn
					total.combine(trans);			//更新变量total当前的值
				else
				{
					print(cout,total)<<endl;		//输出结果
					total = trans;					//处理下一本书
				}
			}while(read(cin,trans));
			print(cout,total)<<endl;				//输出最后一条交易
		}
		else										//没有输入任何信息
		{
			cerr<<"No data?!"<<endl;				//通知用户
		}
		return 0;
	
}

//练习7.14
使用初始值列表的构造函数是：
Sale_data (const std::string &book)
	:bookNo(book),units_sold(0),sellingprice(0),saleprice(0),discount(0){}

//练习7.15
class Person
{
	private:
		string strName;		//姓名
		string strAddress;  //地址
	public:
		Person() = default;
		Person(const string &name,const string &add)
		{
			strName = name;
			strAddress = add;
			Person(std::istream &is){is>>*this;}
		}
		public:
		string getName() const {return strName;}			//返回姓名
		string getAddress() const {return strAddress;}	//返回地址
}


//练习7.16
	在类的定义中，可以包含0个或者多个访问说明符，并且对于某个访问说明符
能出现多少次以及能出现在哪里都没有严格规定。每个访问说明符指定接下来的成
员的访问级别，有效范围直到出现下一个访问说明符或者到达类的结尾为止。
	一般来说，作为接口的一部分，构造函数和一部分成员函数应该定义在public
说明符之后，而数据成员和作为实现部分的函数则应该跟在private说明符之后。

//练习7.17
	如果使用struct关键字，则定义在第一个访问说明符之前的成员是public
	相反，如果使用class关键字，则这些成员是private的。
	
//练习7.18
	封装是指保护类的成员不被随意访问的能力。通过把类的实现细节设置为private，
我们就能完成类的封装。封装实现了类的接口和实现的分离。
	封装有两个重要的优点：一是确保用户代码不会无意间破坏封装对象的状态；二是
被封装的类的具体实现细节可以随时改变，而无需调整用户级别的代码。
	一旦把数据成员定义成private的，类的作者就比较自由地修改数据了。当实现部分
发生改变时，只需要检查类的代码本身以确认这次改变有什么影响。换句话说，只要类
的接口不变，用户代码就无需改变。如果数据是public的，则所有使用了原来数据成员的
代码都可能失效，这时我们必须定位并重写所有依赖于老版本实现的代码，才能重新使用
该应用程序。
	把数据成员的访问权限设成private还有另一个好处，这么做能防止由于用户的原因造成
数据被破坏。如果我们发现有程序缺陷破坏了对象的状态，则可以在有限的范围内定位缺陷
：因为只有实现部分的代码可能产生这样的错误。因此，将错误的搜索限制在有限范围内将
能极大地简化更改问题及修正程序等工作。

//练习7.19
	构造函数和一部分成员函数应该定义在public说明符之后，而数据成员和作为实现
部分的函数则应该跟在private说明符之后。
	private:
		strName、strAddress
	public:
		构造函数和两个获取数据成员的接口函数设置为public

//练习7.20
	当非成员函数确实需要访问类的私有成员时，我们可以把它声明成该类的友元。

//练习7.21
class Sales_data
{
	friend	Sales_data add(const Sale_data &lhs,const Sale_data &rhs);
	friend	std::istream &read(std::istream &is,Sale_data &item);
	friend	std::ostream &print(std::ostream &os,const Sale_data &iteam);
	public:
		std::string bookNo;			//书籍编号
		unsigned units_sold = 0;	//销售量
		double sellingprice = 0.0;	//原始价格
		double saleprice = 0.0;		//实售价格
		double discount = 0.0;		//折扣
};

//练习7.22
class Person
{
	private:
	string strName;
	string strAddress;
	public:
	Person() = default;
	Person(const string &name,const string &add)
	{
		strName = name;
		strAddress = add;
	}
	Person(std::istream &is){is>>*this;}
	public:
		string getName() const{return strName;}				//返回姓名
		string getAddress() const {return strAddress;}		//返回地址
};

//练习7.23
class Screen
{
	private:
		unsigned height = 0,width = 0;
		unsigned cursor = 0;
		string contents;
};

//练习7.24
class Screen
{
	private:
		unsigned height = 0,width = 0;
		unsigned cursor = 0;
		string contents;
	public:
	Screen() = default;
	Screen(unsigned ht,unsigned wd):height(ht),width(wd),contents(ht *wd,' '){}
	Screen(unsigned ht,unsigned wd,char c)
			:height(ht),width(wd),contents(ht *wd,c){}
};

//练习7.25
		Screen 的4个数据成员都是内转子类型，因此直接利用类对象执行拷贝和赋值
操作是可以的。

//练习7.26
隐式内联函数
	class Sale_data
	{
		public:
			double avg_price() const
			{
				if(units_sold)
					return revenue/units_sold;
				else
					return 0;
			}
	}

//练习7.27
class Source
{
	private:
		unsigned ht = 0,wd = 0;
		unsigned cursor = 0;
		string contents;
	
	public:
		Screen() = default;
		Screen(unsigned ht,unsigned wd):height(ht),width(wd),
			constents(ht *wd,' '){}
		Screen(unsigned ht,unsigned wd,char c)
			:height(ht),width(wd),contents(ht * wd,c){}
	public:
		Screen& move(unsigned r,unsigned c)
		{
			cursor = r*width+c;
			return *this;
		}
		Screen& set(char ch)
		{
			contents[cursor] = ch;
			return *this;
		}
		Screen& set(usigned r,unsigned c,char ch)
		{
			contents[r*width+c] = ch;
			return *this;
		}
		Screen& dispaly()
		{
			cout<<contents;
			return *this;
		}
	
};

//练习7.28
	函数的返回值如果是引用，则表明函数返回的是对象本身；函数的返回值如果不是
引用，则表明函数返回的是对象的副本。
	返回引用的函数是左值的，意味着这些函数返回的是对象本身而非对象的副本。
如果把一系列这样的操作链接在一起，所有这些操作将在同一个对象上执行。
	

//7.29

//练习7.30
	this指针优点是明确，缺点是不够简明；
//练习7.31
class X;
class Y
{
	X* x;
};
class X
{
	Y y;
};









































































