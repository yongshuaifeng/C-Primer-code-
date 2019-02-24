//第六章 函数
//练习6.1
	形参出现在函数定义的地方，形参列表可以包含0个、1个或多个形参，多个形参之间以
逗号分隔。形参规定了一个函数所接受数据的类型和数量。
	实参出现在函数调用的地方，实参的数量与形参一样多。实参的主要作用是初始形参，
并且这种初始化过程是一一对应的，即第一个实参初始化第一个形参、第二个实参初始化
第二个形参，以此类推。实参的类型必须与对应到形参类型匹配。

//练习6.2
（a）函数返回值类型与函数体内返回结果的类型不同
	修改：改为一致；
（b）没有返回值类型
	 修改：添加返回值类型 void
（c）1.形参名不能相同
	 2.缺少左侧的花括号
（d）函数体必须添加花括号

//练习6.3
 int fact(int val)
 {
	int sum;
	while(val>0)
	{
		sum +=val;
		val--;
	}
	return sum;
 }
 
 //练习6.4
 int factorial (int val)
 {
	 int result = 1;
	 if(val<0)
	 {
		 std::cout<<"输入的数据有误！"<<std::endl;
		 return -1;
	 }
	 else if(val == 0)
		 result  = 1;
	 else
		 for(;val>0;val--)
			resutl *= val;
		
	 return result;
 }
 
 //练习6.5
 double absoluteValue(double val)
 {
	 if(val<0)
		 val = -val;
	 return val;
 }
 
 
//练习6.6
	形参是一种自动对象，函数开始时为形参申请内存空间，我们用调用函数时提供
的实参初始化形成对应的自动对象。
	普通变量对应的自动对象也容易理解，我们在定义该变量的语句处创建自动对象，
如果定义语句提供了初始值，则用改制初始化；否则，执行默认初始化。当该变量所在
的块结束后，变量失效。
	局部静态变量比较特殊，它的生命周期贯穿函数调用及之后的时间。局部静态变量
对应的对象称为局部静态对象，它的生命周期从定义语句处开始，直到程序结束终止。
 
 #include <iostream>
 using namespace std;
 
 double myADD(double val1, double val2)
 {
	 double result = val1+ val2;
	 static unsigned iCnt = 0;
	 ++iCnt;
	 cout<<"该函数已经累计执行了"<<iCnt<<"次"<<endl;
	 return result;
 }
 
 int main()
 {
	 double num1,num2;
	 cout<<"请输入两个数：";
	 while(cin>>num1>>num2)
	 {
		 cout<<num1<<"与"<<num2<<"的求和结果是："
			<<myADD(num1,num2)<<endl;
	 }
	 return 0;
 }
 
 
 //练习6.7
 int myfunction()
 {
	 static int cnt = -1;
	 ++cnt;
	 return cnt;
 }
 
 
//练习6.8
#ifndef CHAPTER_H_INCLUDED
#define CHAPTER_H_INCLUDED

int fact(int);
double absoluteValue(double);

#endif //CHAPTER_H_INCLUDED
  
 
//练习6.9 
fact.cc文件的内容是：
#include "Chapter6.h"
using namespace std;

int fact(int val)
{
	if(val<0)
		return -1;
	int ret = 1;
	for(int i = 1;i != val+1;++i)
		ret *= i;
	return ret;
}
 
 factMain.cc的内容是：
 #include <iostream>
 #include "Chapter6.h"
 using namespace std;
 
 int main()
 {
	 int num;
	 cout<<"请输入一个整数：";
	 cin>>num;
	 cout<<num<<"的阶乘是："<<fact(num)<<endl;
	 return 0;
 }
 
 //练习6.10
 使用指针作为参数时，在函数内部交换指针的值自能改变局部变量，不会影响实参
原本的值，无法满足题目要求。我们应该在函数内部通过解引用操作改变指针所指的内容。

满足的程序如下：
#incldue <iostream>
using namespace std;

void mySWAP(int *p,int *q)
{
	int temp = *p;
	*p =*q;
	*q = temp;
}
 
 int main()
 {
	 int a = 5,b=10;
	 int *r = &a,*s = &b;
	 cout<<"交换前：a = "<<a<<",b = "<<b<<endl;
	 mySWAP(r,s);
	 cout<<"交换前：a = "<<a<<",b = "<<b<<endl;
	 return 0;
 }
 
 //练习6.11
 #include <iostream>
 using namespace std;
 
 void reset(int &i)
 { i=0; }
 
 int main()
 {
	 int num = 10;
	 cout<<"重置前：num"<<num<<endl;
	 reset(num);
	 cout<<"重置后：num"<<num<<endl;
	 return 0;
 }
 
//练习6.12
#incldue <iostream>
using namespace std;

void mySWAP(int &p,int &q)
{
	int temp = p;
	p =q;
	q = temp;
}
 
 int main()
 {
	 int a = 5,b=10;
	 cout<<"交换前：a = "<<a<<",b = "<<b<<endl;
	 mySWAP(a,b);
	 cout<<"交换前：a = "<<a<<",b = "<<b<<endl;
	 return 0;
 }
 
//练习6.13
    void f(T)的形参采用的是传值方式，也就是说，实参的值被拷贝给形参，形参和实参是
 两个互相独立的变量，在函数f内部对形参所做的任何改动都不会影响实参的值。
	void f(T&)的形参采用的是传引用方式，此时形参是对应的实参的别名，形参绑定到初
始化他的对象。如果我们改变了形参的值，也就改变了对应实参的值。

//练习6.14
	引用类型：当函数的目的是交换两个参数的内容时
				当参数时string对象时，为避免拷贝很长的字符串。
	其他情况下可以使用值传递的方式。
	
//练习6.15
	find_char 函数的三个参数的类型设定与该函数的处理逻辑密切相关，原因如下：
	对于待查找的字符串s来说，为了避免拷贝长字符串，使用引用类型；同时我们只
执行查找操作，无须改变字符串的内容，所以将其声明为常量引用。
	对于待查找的字符c来说，它的类型是char，只占1字节，拷贝的代价很低，而且我们
无须操作实参在内存中实际存储的内容，只把它的值拷贝给形参即可，所以不需要使用引
用类型。
	对于字符出现的次数occurs来说，因为需要把函数内对实参值的更改反映在函数外部，
所以必须将其定义成引用类型；但是不能把它定义成常量引用，否则就不能改变所引用的
内容。

//练习6.16
	该函数把参数类型设为非常量引用，这样做有几个缺陷：1.容易给使用者一种误导，
即程序允许修改变量s的内容；二是限制了该函数所能接受的实参类型，无法把const对象、
字面值常量或者需要进行类型转换的对象传递给普通的引用形参。
	修改为：
		bool is_empty(const string& s){return s.empty();}
		
//练习6.17
	
	#include <iostream>
	#include <string>
	using namespace std;
	//判断大写函数：
	bool HasUpper(connst string& str)
	{
		for(auto c:str)
			if(isupper(c)) 		
				return true;
		return false;
	}
	//改大写为小写
	void changeUpperToLower(string& str)
	{
		for(auto c:str)
			if(isupper(c)) 		
				c = tolower(c);
	}

//练习6.18
(a)
	bool compare(const matrix&,const matrix&)
(b)
	vector<int>::iterator change_val(int,vector<int>::iterator)
 
//练习6.19
 (a)非法。一个形参，两个实参。
 (b)合法
 (c)合法
 (d)合法
 
//练习6.20
	当函数对参数多做的操作不同时，应该选择适当的参数类型。如果需要修改参数的内容，
则将其设置为普通引用类型；否则，如果不需要对参数内容做任何更改，最好设为常量引用。
	
 
//练习6.21
int get_bigger(const int num1,const int* num2)
{
	if(num1>*num2)
		return num1;
	else
		return *num2;
}
 
 //练习6.22
 #include <iostream>
using namespace std;
 
 void change_p(const int* &p1,const int* &p2)
 {
	 const int* p;
	 p = p1;
	 p1 = p2;
	 p2 = p;
	 
 }
 
 int main()
 {
	 int a =20,b=50;
	 const int *p1 =&a,*p2=&b;
	 cout<<"改变之前的值是："<<endl;
	 cout<<"p1指向： "<<*p1<<endl;
	 cout<<"p2指向： "<<*p2<<endl;
	 
	 change_p(p1,p2);
	 cout<<"改变之后的值是："<<endl;
	 cout<<"p1指向： "<<*p1<<endl;
	 cout<<"p2指向： "<<*p2<<endl;
	 return 0;
 }
 
 //练习6.23
 #include <iostream>
 using namespace std;
 //参数是常量整型指针
 void printf1(const int* p)
 {
	 cout<<*p<<endl;
 }
 //参数有两个，分别是常量整型指针和数组的容量
 void printf2(const int* p,const int sz)
 {
	 int i =0;
	 while(i != sz)
	 {
		 cout<<*p++<<endl;
		 ++i;
	 }
 }
 //参数有两个，分别是数组的首尾边界
 void printf3(const int* b,const int* e)
 {
	 for(auto q = b;q != e;++q)
		 cout<<*q<<end;
 } 
 
 int main()
 {
	 int i = 0,j[2]={0,1};
	 printf1(&i);
	 printf2(j);
	 printf2(&i,1);
	 //计算得到数组j的容量
	 printf2(j,sizeof(j)/sizeof(*j));
	 auto b = begin(j);
	 auto e = end(j);
	 printf3(b,e);
	 return 0;
 }
 
 //练习6.24
	上述print函数的定义存在一个潜在风险，即虽然我们期望传入的数组维度是10，但实际上
任意维度的数组都可以传入。如果传入的数组维度较大，print函数输出数组的前十个元素，不
至于引发错误；相反如果传入的数组维度不足，则print函数将强行输出一些未定义的值。
	修改后的程序是：
	void print(const int ia[],const int sz)
	{
		for(size_t i = 0;i != sz;++i)
			cout<<ia[i]<<endl;
	}
 
 
 //练习6.25
 #include <iostream>
 using namespace std;
 
 int main(int argc,char **argv)
 {
	 string str;
	 for(int i = 0;i != argc;++i)
		 str += argv[i];
	 cout<<str<<endl;
	 return 0;
 }
 
  //练习6.26
 #include <iostream>
 using namespace std;
 int main(int argc,int **argv)
 {
	 for(int i = 0;i != argc;i++)
	 {
		 cout<<"argc["<<i<<"]:"<<argv[i]<<endl;
	 }
	 return 0;
 }
 
 
  //练习6.27
 #include <iostream>
 using namespace std; 
 
 int iCount(initializer_list<int> il)
 {
	 int count = 0;
	 //
	 for(auto val:il)
		 count += val;
	 return count;
 }
 
 int main()
 {
	 //使用列表初始化的方式构建 initializer_list<list>对象
	 //然后把它作为实参传递给函数iCount
	 cout<<"1,6,9 的和是: "<<iCount({1,6,9})<<endl;
	 cout<<"4,5,9,18的和是："<<iCount({4,5,9,18})<<endl;
	 cout<<"10,10,10,10,10,,10,10的和是："
			<<iCount({10,10,10,10,10,10,10})<<endl;
	return 0;
	 
 }
 
 
 //练习6.28 
	initializer_list<string>的所有元素类型都是string，因此const auto &elem:il
推断得到的elem的类型是const string&。使用引用是为了避免拷贝长字符串，把它定义
为常量的原因使我们只需要读取字符串的内容，不需要修改它。

  //练习6.29
  引用类型的优势主要是可以直接操作所引用的对象以及避免拷贝较为复杂的类型对象和容
器对象。因为 initializer_list对象的元素永远是常量值，所以我们不可能通过设定引用
类型来更改循环控制变量的内容。只有当 initializer_list对象的元素类型是类类型或容
器类型时，才有必要把范围for循环的循环控制变量设为引用类型。

//练习6.30
	该函数在编译环境中无法编译通过，编译器发现了一个严重错误，即for循环中的return
语句是非法的。函数的返回值类型是布尔值，而该条return语句没有返回任何值。
 
//练习6.31
	如果引用所引的函数开始之前就已经存在的对象，则返回该引用是有效的；如果
引用所引的是函数的局部变量，则随着函数结束局部变量也失效了，此时返回的引用无效。
	当不希望返回的对象被修改时，返回对常量的引用。
 
 //练习6.32
	该函数是合法的。get函数接受一个整型指针，该指针实际指向一个整型数组的首元素，
 另外还接受一个整数表示数组中某个元素的索引值。它的返回值类型是整型引用，引用的
 对象是array数组的某个元素。当get函数执行完毕后，调用者得到实参数组array中索引为
 index的元素的引用。
 
  //练习6.33
  void print(vector<int> vInt,unsigned index)
  {
	  unsigned sz = vInt.size();
	  if(!vInt.empty() && index < sz)
	  {
		  cout<<vInt[index]<<endl;
		  print(vInt,index+1);
	  }
  }
 
//练习6.34
	因为原文中递归函数的参数类型是int，所以理论上用户传入factorial函数的参数
 可以是负数按照原程序的逻辑，参数为负数时函数的返回值是1。
	如果修改递归函数的停止条件，则当参数的值为负时，会依次递归下去，执行连续
乘法操作直至溢出。因此，不能把if语句的条件改成上述形式。
 
 //练习6.35
	如果把val-1 改成val--，则出现一种我们不期望看到的情况，即变量的递减操作与读取
 变量值的操作共存于同意表达式中，这时有可能产生未定义的值。
  //练习6.36
  因为数组不能被拷贝，所以函数不能直接返回数组，但是可以返回数组的指针和引用
  string (&func())[10];
 //练习6.37
 使用类型别名：
 typedef string arr[10];
 arr& func();
 使用尾置返回类型：
 auto func()->string(&) [10];
 使用decltype关键字：
 string str[10];
 decltype (str) &func();
 
  //练习6.38
  int odd[] = {1,3,5,7,9};
  int even[] = {0,2,4,6,8};
  decltype (odd) &arrPtr(int i)
  {
	  return (i%2)?odd:even;
  }
 
  //练习6.39
  (a)非法 
  
  (b)非法 
  
  (c)重载
 
 //练习6.40
 
 （a）正确
 （b）错误
		C++规定一旦某个形参被赋予了默认实参，则它后面的所有形参都必须有默认参数。
 
 
 //练习6.41
 （a）非法
 （b）合法
 （c）语法上合法，但与程序的原意不符合。从语法上来说，第一个实参对应第一个形参ht
，第二个实参的类型虽然是char，但是它可以自动转换为第二个形参wd所需的int类型，所以
编译时可以通过，但这显然违背了程序的原意。
 
  //练习6.42
  #include <iostream>
  #include <string>
  using namespace std;
  
  string make_plural(size_t ctr,const string &word,const string &ending = 's')
  {
	  return (ctr>1)?word +ending:word;
  }
 
 int main()
 {
	 cout<<"success的单数形式是: "<<make_plural(1,"success","es")<<endl;
	 cout<<"success的复数形式是: "<<make_plural(2,"success","es")<<endl;
	 
	 cout<<"faliure的单数形式是: "<<make_plural(1,"faliure")<<endl;
	 cout<<"faliure的复数形式是: "<<make_plural(2,"faliure")<<endl;
	 return0;
 }
 
 //练习6.43
 函数的声明放在头文件中，同时内联函数的定义也应该放在头文件中
 因此(a)(b)都应该放在头文件中。
 
 
  //练习6.44
  只需要在普通函数的前面加上关键字inline
  inline bool isShorter(const string &s1,const string &s2)
  {
	  return s1.size()<s2.size();
  }
 
  //练习6.45
  内联应用于规模小、流程直接、频繁调用的函数。
 
  //练习6.46
  显然 isShorter函数不符合constexpr函数的要求，它虽然只有一条return语句，但是返
回的的结果调用了标准库string类的size()函数和<比较符，无法构成常量表达式，因此不
能改写成constexpr函数。

   //练习6.47
 #include <iostream>
 #include <vector>
 using namespace std;
 
 void print(vector<int> vInt,unsigned index)
 {
	 unsigned sz = vInt.size();
	 #ifndef NDEBUG
	 cout<<"vector 对象的大小是："<<sz<<endl;
	 #endif//NDEBUG
	 if(!vInt.empty() && index<sz)
	 {
		 cout<<vInt[index]<<endl;
		 print(vInt,index+1);
	 }
 }
 
 int main()
 {
	 vector<int> v = {1,3,5,,7,9,11,13,15};
	 print(v,0);
	 return 0;
 }
 
  //练习6.48
  该程序对assert的使用有不合理之处。在调试器打开的情况下，当用户输入字符串s
并且s的内容与sought不相等时，执行循环体，否则继续执行assert(cin);语句。
	当调试器关闭时，assert什么也不做。
 
  //练习6.49
  当程序中存在多个同名的重载函数时，编译器需要判断调用的是其中那个函数，这时候就有了
  候选函数和可执行函数两个概念。
  
 //练习6.50
 （a）二义性
 （b）最佳匹配 void f(int)
 （c）最佳匹配 void f(int,int)
 （d）最佳匹配 void f(double,double)
 
 //练习6.51
 #include <iostream>
 using namespace std;
 
 void f()
 {cout<<"该函数无需参数"<<endl;}
 
 void f(int)
 {cout<<"该函数有一个整型参数"<<endl;}
 
 void f(int,int)
 {cout<<"该函数有两个整型参数"<<endl;}
 
 void f(double double b = 3.14)
 {cout<<"该函数有两个双精度浮点型参数"<<endl;}
 
 int main()
 {
	 f(2.56,42);
	 f(42);
	 f(2.56,3.14);
	 return 0;
 }
 
  //练习6.52
 (a)发生的参数类型转换是类型提升，字符型实参自动提升成整型。
 (b)发生的参数类型转换是算术类型转换，双精度浮点型自动转换成整型。
 
  //练习6.53
  （a）（b）合法，const为底层const
  （c）不合法
 
  //练习6.54
 int func(int,int)
 
 vector<decltype(func)*> vF;
 
 
   //练习6.55
   #include <iostream>
   #include <vector>
   using namespace std;
   //
   int func1(int a,int b)
   {
	   return a+b;
   }
   //
   int func2(int a,int b)
   {
	   return a-b;
   }
	//
	int func3(int a,int b)
   {
	   return a*b;
   }
	//
	int func1(int a,int b)
   {
	   return a/b;
   }
 int main()
 {
	 decltype(func1) *p1 = func1,*p2 = func2,*p3=func3,*p4=func4;
	 vector<decltype(func1)*> vF = {p1,p2,p3,p4};
	 return 0;
 }
 
 //练习6.56
  #include <iostream>
   #include <vector>
   using namespace std;
   //
   int func1(int a,int b)
   {
	   return a+b;
   }
   //
   int func2(int a,int b)
   {
	   return a-b;
   }
	//
	int func3(int a,int b)
   {
	   return a*b;
   }
	//
	int func1(int a,int b)
   {
	   return a/b;
   }
   void Compute(int a,int b,int (*p)(int,int))
   {
	   cout<<p(a,b)<<endl;
   } 
   
   int main()
   {
	   int i =5,j=10;
	  decltype(func1) *p1 = func1,*p2 = func2,*p3=func3,*p4=func4;
	  vector<decltype(func1)*> vF = {p1,p2,p3,p4};
	  for(auto p:vF)
	  {
		  Compute(i,j,p);
	  }
	  return 0;
   }
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   