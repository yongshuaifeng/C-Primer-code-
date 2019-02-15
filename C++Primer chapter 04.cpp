//第四章 表达式
//练习4.1
	105
//练习4.2	
	*(vec.begin())
	(*(vec.begin()))+1
	
//练习4.3	
//练习4.4
		((12/3)*4)+(5*15)+((24%4)/2)
		= 91
//练习4.5
		-86
		-18
		0
		-2
//练习4.6
	if(num%2)
		cout<<num<<"为奇数"<<endl;
	else 
		cout<<num<<"为偶数"<<endl;
	
//练习4.7	
	溢出是一种常见的算术运算错误。因为在计算机中存储某种类型的内存
空间有限，所以该类型的表示能力（范围）也是有限的，当计算的结果值超
出这个范围时，就会产生未定义的数值，这种错误称为溢出。
	假设编译器规定int为32位
	int i = 2417483647 + 1;
	int j = -10000 * 300000;
	int k = 2015 * 2015 * 2015;
	
//练习4.8	
	逻辑与运算符和逻辑或运算符都是先求左侧运算对象的值再求右侧对象的值，
当且仅当左侧运算对象无法确定表达式的结果时才会计算右侧运算对象的值。这种
策略就是短路求值。
	
//练习4.9	
	cp是指向字符串的指针，因此上式的条件部分含义是首先检查指针cp是否有效。
如果cp为空指针或无效指针，则条件不满足。如果cp有效，即cp指向了内存中的某
个有效地址，继续解引用指针cp并检查cp所指的对象是否为空字符'\0'，如果cp所
指的对象不是空字符则条件满足；否则不满足。
	
//练习4.10	
	while(cin>>num && num != 42)
	
	
//练习4.11	
	a>b&&b>c&&c>d
	
//练习4.12
上式等于
		i != (j<k)
	
//练习4.13
		i    d
		3   3
		3   3.5

//练习4.14
		第一条语句编译错误
		第二条语句语法正确，语义不正确
		
		
//练习4.15
		该赋值语句是非法的，虽然连续赋值的形式本身并没错误，但是参与赋值
	的几个变量类型不同。其中，dval是双精度浮点数，ival是整数，pi是整型指
	针。
		
//练习4.16	
	
	
//练习4.17	
	前置版本首先将运算对象加1（或减1），然后把改变后的对象作为求值结果
。后置版本也将运算对象加1（或减1），但是求值结果是运算对象改变之前那个
值的副本。这两种运算符必须作用于左值运算对象。前置版本将对象本身作为左
值返回，后置版本则将对象原始值的副本作为右值返回。

//练习4.18
	第一，无法输出vector对象的第一个元素；
	第二，当所有元素都不为负时，移动到最后一个元素的地方，程序试图继续
向前移动迭代器并解引用一个根本不存在的元素。

//练习4.19
	（a）的含义是先判定指针ptr是否为空，如果不为空，继续判断指针ptr所指
的整数是否为非0数。如果非0，则该表达式的最终值结果是真；否则为假。最后把
指针ptr向后移动一位。
	（b）的含义是先检查ival的值是否非0，如果非0继续检查（ival +1 ）的值是
否非0。
	（c）的含义是比较vec[ival]和vec[ival+1]的大小，如果前者较小则求值结果
为真，否则为假。

//练习4.20
	（a）是合法的，后置递增运算符的优先级高于解引用运算符，其含义是解引用
当前迭代器所处位置的对象内容，然后把迭代器的位置向后移动一位。
	（b）是非法的，解引用iter得到vector对象当前的元素，结果是一个string，
显然string没有后置递增操作。
	（c）是非法的，解引用运算符的优先级低于点运算符，所以该式先计算iter.empty()
,而迭代器并没有定义empty函数，所以无法通过编译。
	（d）是合法的。
	（e）是非法的。该式先解引用iter，得到迭代器当前所指的元素，结果是一个
string，显然string没有后置递增操作。
	（f）合法的
	
//练习4.21
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>	
using namespace std;
int main()
{
	vector<int> vec_num;
	srand(time(NULL));
	for(int i = 0;i<10;i++)
		vec_num.push_back(rand()%100);
	cout<<"容器中的元素分别是："<<endl;
	for(auto c:vec_num)
		cout<<c<<" ";
	cout<<endl;
	cout<<"其中的奇数为："<<endl;
	for(auto &c:vec_num)
		if(c%2==1)
		{
			cout<<c<<" ";
			c *=2;
		}
	cout<<endl;
	
	cout<<"奇数翻倍后容器中的元素分别是："<<endl;
	for(auto c:vec_num)
		cout<<c<<" ";
	cout<<endl;
	
	return 0;
}
	
//练习4.22
#include <iostream>
#include <string>
using namespace std;

int main()
{
	double score;
	string grade,yorn = "y";
	cout<<"请输入成绩："<<endl;
	while( yorn ==  "y"&& cin>>score && score>=0 && score <= 100)
	{
		grade =(score>90)?"hight pass":(score >75)?"pass":
				(score >60)? "low pass":"fail";
		
		cout<<"成绩所处的档次是："<<grade<<endl;
		cout<<"是否继续输入成绩（y/n）:"<<endl;
		cin>>yorn;
		if(yorn == "y")
			cout<<"请输入成绩："<<endl;
		else
			cout<<"结束..."<<endl;
		
	}
	return 0;
}	


#include <iostream>
#include <string>
using namespace std;

int main()
{
	double score;
	string grade,yorn = "y";
	cout<<"请输入成绩："<<endl;
	while( yorn ==  "y"&& cin>>score && score>=0 && score <= 100)
	{
		if(score>90)
			grade = "hight pass";
		else if(score >75)
			grade = "pass";
		else if(score >60)
			grade = "low pass";
		else
			grade = "fail";
		
		cout<<"成绩所处的档次是："<<grade<<endl;
		cout<<"是否继续输入成绩（y/n）:"<<endl;
		cin>>yorn;
		if(yorn == "y")
			cout<<"请输入成绩："<<endl;
		else
			cout<<"结束..."<<endl;
		
	}
	return 0;
}	
	
//练习4.23																																	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	