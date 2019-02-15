//第五章 语句
//练习5.1
	空语句是简单的语句，空语句由一个单独的分号构成。如果在程序的某个地方，语法上
需要一条语句但是逻辑上不需要，此时应该使用空语句，空语句什么也不做。
	一种常见的情况是，当循环的全部工作在条件部分就可以完成时，我们通常会用到空
语句。使用空语句时最好加上注释，从而令代码的阅读者知道这条语句是有意省略内容的。
//练习5.2
	块是指用花括号括起来的语句和声明的序列，也称为复合语句。一个块就是一个作用域
，在块中引入的名字只能在块内部以及嵌套在块中的子块里访问。如果在程序的某个地方，
语句上需要一条语句，但是逻辑上需要多条语句，此时应该使用块。块不需要以分号结束。
	例如，循环体必须是一条语句，但是我们通常需要在循环体内做很多事情，此时就应该
把多条语句用花括号括起来，从而把语句序列转化成块。
//练习5.3
	修改前：
	while(val <= 10)
	{
		sum += val;
		++val;
	}
	
	修改后：
	while(val <= 10)
		sum += val,++val;
	
很明显，改写之后的代码不够清晰，可读性下降。

//练习5.4
	(a)是非法的，它的原意是希望在while语句的控制结构当中定义一个
string::iterator类型的变量iter，然后判断iter是否到达了s的末尾，
只要还没有到达末尾就执行循环体的内容。但是该式把变量的定义和关系
判断混合在一起，如果要使用iter与其他值比较，必须首先为iter赋初值。
修改后的程序应该是：
	string::iterator iter = s.begin();
	while(iter != s.end())
	{
		++iter;
		/*...*/
	}
	(b)是非法的，变量status定义在while循环结构的内部，其作用域仅限
于while循环。if语句已经位于while循环的作用域之外，status在if语句内
是一个未命名的无效变量。要想在if语句中继续使用status，需要把它定义
在while循环之前。修改后的程序是：
	bool status;
	while(status = find(word)){/*...*/}
	if(!status){/*...*/}
	
//练习5.5
#include <iostream>
#incldue <string>
using namespace std;

int main()
{
	int grade;
	cout<<"请输入您的成绩："；
	cin>>grade;
	if(grade<0 || grade >100)
	{
		cout<<"该成绩不合法"<<endl;
		return -1；
	}
	
	if(grade == 100)
	{
		cout<<"等级成绩是： "<<"A++"<<endl;
		return -1;
	}
	
	if(grade<60)
	{
		cout<<"等级成绩是："<<"F"<<endl;
		return -1;
	}
	int iU = grade/10;
	int iT = grade%10;
	string score,level,lettergrade;
	//根据成绩的十位数字确定score
	if(iU == 9)
		score = "A";
	else if(iU == 8)
		score = "B";
	else if(iU ==7)
		score = "C";
	else
		score = "D";
	
	//根据成绩的个位数字确定level
	if(iT<3)
		level = "-";
	else if(iT>7)
		level = "+";
	else
		level = "";
	//累加求得等级成绩
	lettergrade =score +level;
	cout<<"等级成绩是："<<lettergrade<<endl;
	
	return 0;
}


//练习5.6
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int grade;
	cout<<"请输入您的成绩："；
	cin>>grade;
	if(grade<0 || grade >100)
	{
		cout<<"该成绩不合法"<<endl;
		return -1；
	}
	
	if(grade == 100)
	{
		cout<<"等级成绩是： "<<"A++"<<endl;
		return -1;
	}
	
	if(grade<60)
	{
		cout<<"等级成绩是："<<"F"<<endl;
		return -1;
	}
	int iU = grade/10;
	int iT = grade%10;
	string score,level,lettergrade;
	//根据成绩的十位数字确定score
	socre =(iU == 9)?"A":
						(iU == 8)?"B":
										(iU ==7)? "C":"D";
	
	//根据成绩的个位数字确定level
	level =(iT<3)?"-":
						(iT>7)?"+":"";
	//累加求得等级成绩
	lettergrade =score +level;
	cout<<"等级成绩是："<<lettergrade<<endl;
	
	return 0;
}

//练习5.7
	(a)加 ;
	(b)加{}
	(c)将ival在if条件以外定义
	(d)将 if(ival = 0)
		改为if(ival == 0)

//练习5.8
	悬垂else是指当程序中的if分支多于else分支时，如何为else寻找与之
匹配的if分支的问题。
	C++规定，else与离它最近的尚未匹配的if匹配，从而消除了二义性。
	
//练习5.9
#include <iostream>
using namespace std;
int main()
{
	unsigned int vowelCnt = 0;
	char ch;
	cout<<"请输入一段文本： "<<endl;
	while(cin>>ch)
	{
		if(ch == 'a')
			++vowelCnt;
		if(ch == 'e')
			++vowelCnt;
		if(ch == 'i')
			++vowelCnt;
		if(ch == 'o')
			++vowelCnt;
		if(ch == 'u')
			++vowelCnt;
	}
	cout<<"您输入的文本中共有"<<vowelCnt<<"个元音字母"<<endl;
	
	return 0;
}

//练习5.10
#include <iostream>
using namespace std;
int main()
{
	unsigned int aCnt =0,eCnt =0,iCnt =0,oCnt =0,uCnt =0;
	char ch;
	cout<<"请输入一段文本："<<endl;
	while(cin>>ch)
	{
		switch(ch)
		{
			case 'a';
			case 'A';
			++aCnt;
			break;
			case 'e';
			case 'E';
			++eCnt;
			break;
			case 'i';
			case 'I';
			++iCnt;
			break;
			case 'o';
			case 'O';
			++oCnt;
			break;
			case 'u';
			case 'U';
			++uCnt;
			break;
		}
	}
	cout<<"元音字母a的数量是："<<aCnt<<endl;
	cout<<"元音字母e的数量是："<<eCnt<<endl;
	cout<<"元音字母i的数量是："<<iCnt<<endl;
	cout<<"元音字母o的数量是："<<oCnt<<endl;
	cout<<"元音字母u的数量是："<<uCnt<<endl;
	return 0;
}


//练习5.11
#include <iostream>
using namespace std;
int main()
{
	unsigned int aCnt =0,eCnt =0,iCnt =0,oCnt =0,uCnt =0;
	unsigned int spaceCnt =0,tabCnt =0,newLineCnt =0;
	char ch;
	cout<<"请输入一段文本："<<endl;
	while(cin.get(ch))
	{
		switch(ch)
		{
			case 'a';
			case 'A';
			++aCnt;
			break;
			case 'e';
			case 'E';
			++eCnt;
			break;
			case 'i';
			case 'I';
			++iCnt;
			break;
			case 'o';
			case 'O';
			++oCnt;
			break;
			case 'u';
			case 'U';
			++uCnt;
			break;
			case ' ';
			++spaceCnt;
			break;
			case '\t';
			++tabCnt;
			break;
			case '\n';
			++newLineCnt;
			break;
		}
	}
	cout<<"元音字母a的数量是："<<aCnt<<endl;
	cout<<"元音字母e的数量是："<<eCnt<<endl;
	cout<<"元音字母i的数量是："<<iCnt<<endl;
	cout<<"元音字母o的数量是："<<oCnt<<endl;
	cout<<"元音字母u的数量是："<<uCnt<<endl;
	
	cout<<"空格的数量是："<<spaceCnt<<endl;
	cout<<"制表符的数量是："<<tabCnt<<endl;
	cout<<"换行符的数量是："<<newLineCnt<<endl;
	return 0;
}

//练习5.12
#include <iostream>
using namespace std;
int main()
{
	unsigned int ffCnt =0,flCnt =0,fiCnt =0;
	char ch,prech = '\0';
	cout<<"请输入一段文本："<<endl;
	while(cin>>ch)
	{
		bool bl = true;
		if(prech == 'f')
		{
			switch(ch)
			{
				case 'f';
				++ffCnt;
				bl = false;
				break;
				case 'l'
				++flCnt;
				break;
				case 'i'
				++fiCnt;
				break;
			}
		}
		if(!bl)
			prech = '\0';
		else
			prech = ch;
	}
	
	cout<<"ff的数量是："<<ffCnt<<endl;
	cout<<"fl的数量是："<<flCnt<<endl;
	cout<<"fi的数量是："<<fiCnt<<endl;
	return 0;
}

//练习5.13
	(a) 缺少 break;
	(b) 的错误是在case分支中定义并初始化了变量ix，同时在default分支中
使用了该变量，此时如果控制流跳过case分支而直接到达default分支，则会试
图使用未经初始化的变量，因而该程序无法通过编译。
	(c)的错误是同一个case标签中放置了多个值，而在C++规定一个case标签只
能对应一个值。
	(d)的错误是使用变量作为case标签的内容，c++规定，case标签的内容是整
型常量表达式。

//练习5.14
#include <iostream>
#include <string>
using namespace std;
int main()
{
	//当前、前一个、次数最多的字符串
	string currString,preString = "",maxString;
	//当前字符串的次数，历史次数最多的字符串的次数
	int currtCnt  = 1,maxCnt =0;
	while(cin>>currString)
	{
		//
		if(currString == preString)
		{
			++currtCnt;
			if(currtCnt>maxCnt)
			{
				maxCnt = currCnt;
				maxString = currString;
			}
		}
		//如果当前字符串与前一个字符串不一致，重复currCnt
		else
		{
			currCnt = 1;
		}
		preString = currString;
	}
	if(maxCnt>1)
		cout<<"出现最多的符号是："<<maxString<<",次数是"<<maxCnt<<endl;
	else
		cout<<"每个字符串都只出现一次"<<endl;
	return 0;
}

//练习5.15
	(a)的错误是在for语句中定义了变量ix,然后试图在for语句之外继续使用ix。因
为ix定义在for语句的内部，所以其作用域仅限于for语句。在if语句中ix已经失效，
因此程序无法编译通过。
	修改：将ix的定义提到for循环外面
	
	(b)两处错误。一是未初始化ix，二是for语句的控制结构缺少一句话
	改为：
		int ix;
		for(ix =0;ix!=sz;++ix){/*...*/}
		
	(c)的错误是一旦进入循环，程序就会一直进行下去
	修改：删除++sz

//练习5.16
	读取：
		char ch;
		while(cin>>ch)
		{/*...*/}
	
		for(;cin>>ch;)
		{/*...*/}
	整数累加：
	int iCount = 0;
	for(int i =0;i<10;++i)
	{
		iCount += 1;
	}
	
	int iCount = 0,i = 0;
	while(i<10)
	{
		iCount += i;
		++i;
	}

//练习5.17
#include <iostram>
#include <vector>

using namespace std;

int main()
{
	vector<int> v1 = {0,1,1,2};
	vector<int> v2 = {0,1,1,2,3,5,8};
	vector<int> v3 = {3,5,8};
	vector<int> v4 = {3,5,0,9,2,7];
	
	auto it1 = v1.cbegin();
	auto it2 = v2.cbegin();
	auto it3 = v3.cbegin();
	auto it4 = v4.cbegin();
	
	while(it1 != v1.cend() && it2 != v2.cend())
	{
		//
		if(*it != *it2)
		{
			cout<<"v1和v2之间不存在前缀关系"<<endl;
			break;
		}
		++it1;
		++it2;
	}
	if(it1 == v1.cend())
	{
		cout<<"v1是v2的前缀"<<endl;
	}
	if(it2 == v2.cend())
	{
		cout<<"v2是v1的前缀"<<endl;
	}
	return 0;
}

//练习5.18

(a)的含义是每次循环读入两个整数并输出它们的和。因为do-while语句的循环体
必须是一条语句或者一个语句块，所以在本题中应该把循环体的内容用花括号括起
来。修改后的程序是：
	do{
		int v1,v2;
		cout<<"Please enter two number to sum:";
		if(cin>>v1>>v2)
			cout<<"Sum is:"<<v1+v2<<endl;
	}while(cin)

(b)的含义是当get_response 的返回值不为0时执行循环体。因为do-while语句
不允许在循环体条件内定义变量，所以该程序是错误的。修改后的程序是：
	int ival;
	do{
		ival = get_response();
	}while(iavl);
	

(c)的含义是当get_response 的返回值不为0时执行循环体。因为出现在
do-while语句条件部分的变量必须定义循环体之外，所以该程序是错误的。
修改后的程序是：
	int ival;
	do{
		ival = get_response();
	}while(ival);


//练习5.19
#include <iostream>
#include <string>
using namespace std;

int main()
{
	do{
		cout<<"请输入两个字符串："<<endl;
		string str1,str2;
		cin>>str1>>str2;
		if(str1.size()<str2.size())
			cout<<"长度较小的字符串是："<<str1<<endl;
		else if(str1.size()>str2.size())
			cout<<"两个字符串等长"<<str2<<endl;
	}while(cin);
	
	return 0;
}

//练习5.20
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string currString,preString;
	bool b1 = true;
	cout<<"请输入一组字符串："<<endl;
	while(cin>>currString)
	{
		if(currString == preString)
		{
			b1 = false;
			cout<<"连续出现的字符串是："<<currString<<endl;
			break;
		}
		preString = currString;
	}
	if(b1)
		cout<<"没有连续出现的字符串"<<endl;
	return 0;
} 

//连续5.21
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string currString,preString;
	bool b1 = true;
	cout<<"请输入一组字符串："<<endl;
	while(cin>>currString)
	{
		if(!isupper(currString[0]))
			continue;
		if(currString == preString)
		{
			b1 = false;
			cout<<"连续出现的字符串是："<<currString<<endl;
			break;
		}
		preString = currString;
	}
	if(b1)
		cout<<"没有连续出现的字符串"<<endl;
	return 0;
}


//连续5.22
int sz;
do{
	sz = get_size();
}while(sz<=0);

//连续5.23
#include <iostream>
using namespace std;
int main()
{
	cout<<"请依次输入被除数和除数： "<<endl;
	int ival1,ival2;
	if(ival2 == 0)
	{
		cout<<"除数不能为0"<<endl;
		return -1;
	}
	cout<<"两数相除的结果是： "<<ival1/ival2<<endl;
	return 0;
}


//连续5.24
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
	cout<<"请依次输入被除数和除数："<<endl;
	int ival1,ival2;
	cin>>ival>>ival2;
	if(ival2 == 0)
	{
		throw runtime_error("除数不能为0");
	}
	cout<<"两数相除的结果是："<<ival1/ival2<<endl;
	return 0;
}

//连续5.25
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
	cout<<"请依次输入被除数和除数："<<endl;
	int  ival1,ival2;
	while(cin>>ival1>>ival2)
	{
		try
		{
			if(ival2 == 0)
			{
				throw runtime_error("除数不能为0");
			}
			cout<<"两数相除的结果是："<<ival1/ival2<<endl;
		}catch(runtime_error)
		{
			cout<<err.what()<<endl;
			cout<<"需要继续吗(y or n)?";
			char ch;
			cin>>ch;
			if(ch != 'y' && ch != 'Y')
				break;
		}
	}
	return 0;
}




























