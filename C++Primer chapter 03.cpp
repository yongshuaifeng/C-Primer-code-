//第三章
//字符串、向量和数组


//using
//练习3.1
		#include <iostream>
		using  std::cout;
		using  std::endl;
		
		int main()
		{
			int sun =0;
			int i =50;
			while(i<=100){
				sum+=i;
				i++;
			}
			cout<<"50到100之间的整数之和为"<<sum<<endl;
			return 0;
		}
		.....
		
//标准库类型string
//练习3.2	
	#include <iostream>
	#incldue <cstring>
	using namespace std;
	int main()
	{
		string line;
		cout<<"请输入一行内容: "<<endl;
		while(getline(cin,line))
			cout<<line<<endl;
		return 0;
	}

	#include <iostream>
	using namespace std;
	int main()
	{
		string word;
		cout<<"请输入一行内容: "<<endl;
		while(cin>>word)
			cout<<word<<endl;
		return 0;
	}

//练习3.3
		string 的输入运算符自动忽略字符串开头的
	空白（包括空格符、换行符、制表符等），从第一
	个真正的字符开始读起，直到遇到下一次空白为止。
		getline从给定的输入流中读取数据，直到遇到换行
	符为止，此时换行符也被读取出来，但是并不存储在最
	后的字符串中。

//练习3.4
  #include <iostream>
  #include <string>
  using namespace std;
  int main()
  {
	  string str1,str2;
	  cout<<"请输入一个字符串str1："<<endl;
	  cin>>str1;
	  cout<<"请输入另一个字符串str2："<<endl;
	  cin>>str1;
	  if(str1=str2)
		  cout<<"两个字符串相等"<<endl;
	  else if(str1>str2)
		  cout<<str1<<endl;
	  else
		  cout<<str2<<endl;
	  return 0;
  }

  #include <iostream>
  #include <string>
  using namespace std;
  int main()
  {
	  string str1,str2;
	  cout<<"请输入一个字符串str1："<<endl;
	  cin>>str1;
	  cout<<"请输入另一个字符串str2："<<endl;
	  cin>>str1;
	  if(str1.size()=str2.size())
		  cout<<"两个字符串等长"<<endl;
	  else if(str1.size()>str2.size())
		  cout<<str1<<endl;
	  else
		  cout<<str2<<endl;
	  return 0;
  }

//练习3.5
  #include <iostream>
  #include <string>
  using namespace std;
  int main()
  {
	  string str,curr_str;
	  cout<<"请输入要连接的字符串： "<<endl; 
	  while(cin>>curr_str)
		  str += curr_str;
	  cout<<"链接成的字符串为："<<str<<endl;
	  return 0;
  }

  #include <iostream>
  #include <string>
  using namespace std;
  int main()
  {
	  string str,curr_str;
	  cout<<"请输入要连接的字符串： "<<endl; 
	  while(cin>>curr_str)
		  str = str+curr_str+" ";
	  cout<<"链接成的字符串为："<<str<<endl;
	  return 0;
  }


//练习3.6
#include <iostream>
#include <string>
using namespace std;
int main()
  {
	  string str;
	  cout<<"请输入一串字符："<<endl;
	  getline(cin,str);
	  for(auto &c:str)
		  if(isalpha(c))		//是否将非字母改为x，若需要，注释本行
			  c = 'x';
		  
		cout<<str<<endl;
	  return 0;
  }

//练习3.7
	没有影响
	
//练习3.8
#include <iostream>
#include <string>
using namespace std;
int main()
  {
	  string str;
	  cout<<"请输入一串字符："<<endl;
	  getline(cin,str);
	  int i = 0;
	  while(str[i]!='\n')
	  {
		  if(isalpha(str[i]))		//是否将非字母改为x，若需要，注释本行
			  str[i] = 'x';
			  i++;
	  }  
		cout<<str<<endl;
	  return 0;
  }



#include <iostream>
#include <string>
using namespace std;
int main()
  {
	  string str;
	  cout<<"请输入一串字符："<<endl;
	  getline(cin,str);
	  for(unsigned i = 0;i<str.size();i++)
		  if(isalpha(str[i]))		//是否将非字母改为x，若需要，注释本行
			  str[i] = 'x';
		  
		cout<<str<<endl;
	  return 0;
  }

//练习3.9
	不合法
	初始状态下没有给s赋任何值，字符串s为空，下标0是非法的。

//练习3.10
#include <iostream>
#include <string>
using namespace std;
int main()
  {
	  string str;
	  cout<<"请输入一串字符,包含标点符号："<<endl;
	  getline(cin,str);
	  for(auto &c:str)
		  if(！ispunct(c))		//是否将非字母改为x，若需要，注释本行
			 cout<<c;
		  
		cout<<str<<endl;
	  return 0;
  }

//练习3.11
	程序语法上合法，但不能改变c绑定的字符串的值

//练习3.12
	a、c正确，b不正确
	b中svec的元素类型是string，而ivec的元素类型是int，
	因此不能使用ivec初始化svec。

//练习3.13
	(a)一个0
	(b)10 个0
	(c)10 个42
	(d)一个10
	(e)10 和 42
	(f)10 个空串
	(g)10 个 hi
	
//练习3.14
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> vec_num;
	int num;
	cout<<"请输入一串数字"<<endl;
	while(cin>>num)
		vec_num.push_back(num);
	for(auto c:vec_num)
		cout<<c<<" ";
	cout<<endl;
	return 0;
}

//练习3.15
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<string> vec_str;
	string str;
	cout<<"请输入一串字符串："<<endl;
	while(cin>>str)
		vec_str.push_back(str);
	for(auto c:vec_str)
		cout<<c<<" ";
	cout<<endl;
	return 0;
}

//练习3.16
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10,42);
	vector<int> v4{10};
	vector<int> v5{10,42};
	vector<string> v6{10};
	vector<string> v7{10,"hi"};
	
	cout<<"v1的元素个数是： "<<v1.size()<<endl;
	if(v1.size()>0)
	{
		cout<<"v1的元素分别是："<<endl;
		for(auto e:v1)
			cout<<e<<" ";
		cout<<endl;
	}
	
	cout<<"v2的元素个数是： "<<v2.size()<<endl;
	if(v2.size()>0)
	{
		cout<<"v2的元素分别是："<<endl;
		for(auto e:v2)
			cout<<e<<" ";
		cout<<endl;
	}
	
	cout<<"v3的元素个数是： "<<v3.size()<<endl;
	if(v3.size()>0)
	{
		cout<<"v3的元素分别是："<<endl;
		for(auto e:v3)
			cout<<e<<" ";
		cout<<endl;
	}
	
	cout<<"v4的元素个数是： "<<v4.size()<<endl;
	if(v4.size()>0)
	{
		cout<<"v4的元素分别是："<<endl;
		for(auto e:v4)
			cout<<e<<" ";
		cout<<endl;
	}
	
	cout<<"v5的元素个数是： "<<v5.size()<<endl;
	if(v5.size()>0)
	{
		cout<<"v5的元素分别是："<<endl;
		for(auto e:v5)
			cout<<e<<" ";
		cout<<endl;
	}
	
	cout<<"v6的元素个数是： "<<v6.size()<<endl;
	if(v6.size()>0)
	{
		cout<<"v6的元素分别是："<<endl;
		for(auto e:v6)
			cout<<e<<" ";
		cout<<endl;
	}
	
	cout<<"v7的元素个数是： "<<v7.size()<<endl;
	if(v7.size()>0)
	{
		cout<<"v7的元素分别是："<<endl;
		for(auto e:v7)
			cout<<e<<" ";
		cout<<endl;
	}
	
	
	
	return 0;
}

//练习3.17
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<string> vec_str;
	string str;
	cout<<"	请输入一组词："<<endl;
	while(cin>>str)
		vec_str.push_back(str);
	for(int i = 0;i<vec_str.size();i++)
		for(auto &c:vec_str[i])
			c = toupper(c);
	for(int i = 0;i<vec_str.size();i++)
			cout<<vec_str[i]<<endl;
	
	return 0;
}  

//练习3.18
	不合法
	修改为：
	vector<int> ivec;
	ivec.push_back(42);

//练习3.19
	第一种 vector<int> vet(10,42);
	第二种 vector<int> vet{42,42,42,42,42,42,42,42,42,42}
	第三种 
	vector<int> vet;
	for(int i =0;i<10;i++)
		vet.push_back(42);

//练习3.20
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<int> vec_num;
	int num;
	cout<<"请输入一组整数："<<endl;
	while(cin>>num)
		vec_num.push_back(num);
	cout<<"相邻整数的和为："<<endl;
	for(int i = 0;i<vec_num.size()-1;i++)
			cout<<vec_num[i]+vec_num[i+1]<<endl;
	
	return 0;
}  



#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<int> vec_num;
	int num;
	cout<<"请输入一组整数："<<endl;
	while(cin>>num)
		vec_num.push_back(num);
	cout<<"对应整数的和为："<<endl;
	for(int i = 0;i<vec_num.size()/2;i++)
			cout<<vec_num[i]+vec_num[vec_num.size()-1-i]<<endl;
	
	return 0;
}  

//练习3.21

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10,42);
	vector<int> v4{10};
	vector<int> v5{10,42};
	vector<string> v6{10};
	vector<string> v7{10,"hi"};
	
	cout<<"v1的元素个数是： "<<v1.size()<<endl;
	if(v1.cbegin() != v1.cend())
	{
		cout<<"v1的元素分别是："<<endl;
		for(auto it = v1.cbegin();it<v1.cend();it++)
		    cout<<*it<<" ";
			cout<<endl;
		
	}
	
	cout<<"v2的元素个数是： "<<v2.size()<<endl;
	if(v2.cbegin() != v2.cend())
	{
		cout<<"v2的元素分别是："<<endl;
		for(auto it = v2.cbegin();it<v2.cend();it++)
			cout<<*it<<" ";
			cout<<endl;
		
	}
	
	cout<<"v3的元素个数是： "<<v3.size()<<endl;
	if(v3.cbegin() != v3.cend())
	{
		cout<<"v3的元素分别是："<<endl;
		for(auto it = v3.cbegin();it<v3.cend();it++)
			cout<<*it<<" ";
			cout<<endl;
		
	}
	
	cout<<"v4的元素个数是： "<<v4.size()<<endl;
	if(v4.cbegin() != v4.cend())
	{
		cout<<"v4的元素分别是："<<endl;
		for(auto it = v4.cbegin();it<v4.cend();it++)
			cout<<*it<<" ";
			cout<<endl;
		
	}
	
	cout<<"v5的元素个数是： "<<v5.size()<<endl;
	if(v5.cbegin() != v5.cend())
	{
		cout<<"v5的元素分别是："<<endl;
		for(auto it = v5.cbegin();it<v5.cend();it++)
			cout<<*it<<" ";
			cout<<endl;
		
	}
	
	cout<<"v6的元素个数是： "<<v6.size()<<endl;
	if(v6.cbegin() != v6.cend())
	{
		cout<<"v6的元素分别是："<<endl;
		for(auto it = v6.cbegin();it<v6.cend();it++)
			cout<<*it<<" ";
			cout<<endl;
		
	}
	
	cout<<"v7的元素个数是： "<<v7.size()<<endl;
	if(v7.cbegin() != v7.cend())
	{
		cout<<"v7的元素分别是："<<endl;
		for(auto it = v7.cbegin();it<v7.cend();it++)
			cout<<*it<<" ";
			cout<<endl;
		
	}
	return 0;
}

//练习3.22
#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int main()
{
	vector<string> text;
	string s;
	
	while(getline(cin,s))
		text.push_back(s);
	
	for(auto it = text.begin();it != text.end()&& !it->empty();it++)
	{
		for(auto it2 = it->begin();it2 != it->end();it2++)
			*it2 = toupper(*it2);
		cout<<*it<<endl;
	}
	
	return 0;
}

//练习3.23
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
	vector<int> vInt;
	srand((unsigned)time(NULL));//生成随机种子
	for(int i = 0;i<10;i++) //循环10次
		vInt.push_back(rand()%100); //将随机生成的100以内的整数添加其中
	cout<<"随机生成的10个数字是： "<<endl;
	for(auto it = vInt.cbegin();it!= vInt.cend();it++)
		cout<<*it<<" ";
	cout<<endl;
	
	cout<<"翻倍后的10个数字是："<<endl;
	
	for(auto it = vInt.begin();it!= vInt.end();it++)
	{
		*it *= 2;
		cout<<*it<<" ";
	}
	cout<<endl;
	
	
	return 0;
}

//练习3.24
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<int> vec_num;
	int num;
	cout<<"请输入一组整数："<<endl;
	while(cin>>num)
		vec_num.push_back(num);
	
	if(vec_num.begin() == vec_num.end())
	{
		cout<<"没有输入值"<<endl;
		return 0;
	}
	
	cout<<"相邻整数的和为："<<endl;
	
	for(auto it = vec_num.begin();it != vec_num.end()-1;it++)
			cout<<*it+*(it+1)<<endl;
	return 0;
}  



#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<int> vec_num;
	int num;
	cout<<"请输入一组整数："<<endl;
	while(cin>>num)
		vec_num.push_back(num);
	
	if(vec_num.begin() == vec_num.end())
	{
		cout<<"没有输入值"<<endl;
		return 0;
	}
	
	cout<<"对应整数的和为："<<endl;
	for(auto beg = vec_num.begin(), end =vec_num.end();beg != vec_num.begin()+(vec_num.end()-vec_num.begin())/2;beg++,end--)
			cout<<*beg+*(end-1)<<endl;
	
	return 0;
}  


//练习3.25
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<unsigned> vUS(11);
	auto it = vUS.begin();
	int iVal;
	cout<<"请输入一组成绩(0~100): "<<endl;
	while(cin>>iVal)
		if(iVal<101)
			++*(it+iVal/10);
		
	cout<<"您总计输入了 "<<vUS.size()<<" 个成绩"<<endl;
	cout<<"各分数段的人数分布是（成绩从低到高）："<<endl;
	for(;it != vUS.end();it++ )
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	return 0;
}

//练习3.26
	C++没有定义两个迭代器的加法运算符，实际上
	把两个迭代器加起来是没有意义的。

//练习3.27
	(a)非法
	(b)合法
	(c)非法
	(d)非法

//练习3.28
     sa为空
     ia为0
     a2为空
     ia2为随机数
//练习3.29
		数组与vector的相同之处是都能存放类型相同的对象，且这些对象没有名字，
	需要通过其所在位置访问。
		数组与vector的最大不同是，数组的大小固定不变，不能随意
	向数组中增加额外的元素，虽然在某些情况下运行时性能较好，但是
	与vector相比损失了灵活性。
		
//练习3.30
		循环越界
		将 ix <= array_size 改为 ix < array_size
		
//练习3.31
		#include <iostream>
		
		using namespace std;
		
		int main()
		{
			const int sz = 10;
			int a[sz];
			
			for(int i = 0;i<sz;i++)
				a[i] = i;
			for(auto val:a)
				cout<<val<<" ";
			cout<<endl;
			
			return 0;
		}

//练习3.32

		#include <iostream>
		
		using namespace std;
		
		int main()
		{
			const int sz = 10;
			int a[sz],b[sz];
			
			for(int i = 0;i<sz;i++)
				a[i] = i;
			for(int j = 0;j<sz;j++)
				b[i] = a[j];
			for(auto val:b)
				cout<<val<<" ";
			cout<<endl;
			
			return 0;
		}


		#include <iostream>
		#include <vector>
		
		using namespace std;
		
		int main()
		{
			const int sz = 10;
			vector<int> vInt,vInt2;
			
			for(int i = 0;i<sz;i++)
				vInt.push_back(i);
			for(int j =0;j<sz;j++)
				vInt2.push_back(vInt[j]);
			for(auto val:vInt2)
				cout<<val<<" ";
			cout<<endl;
			
			return 0;
		}

//练习3.33

//练习3.34
	如果p1和p2指向同一个数组中的元素，则该条语句令p1指向p2原来所指向的元素。
	从语法上来说，即使p1和p2指向的元素不属于同一个数组，但只要p1和p2的类
	型相同，该语句也是合法的。
	如果p1和p2的类型不同，则编译时报错。
	
//练习3.35
#include <iostream>

using namespace std;

int main()
{
	int num[10] = {1,2,3,4,5,6,7,8,9,10};
	int* p = num;
	cout<<"数组的原内容是："<<endl;
	for(auto c:num)
		cout<<c<<" ";
	cout<<endl;
	
	for(int i = 0;i<10;i++,p++)
		*p = 0;
		
	cout<<"数组的修改后的内容是："<<endl;
	for(auto c:num)
		cout<<c<<" ";
	cout<<endl;
	
	return 0;
} 

//练习3.36
#include <iostream>
using namespace std;
int main()
{
	int a[10],b[10];
	cout<<"请输入第一个数组的内容(10个整数)："<<endl;
	for(int i =0;i<10;i++)
		cin>>a[i];
	cout<<"请输入第二个数组的内容(10个整数)："<<endl;
	for(int i =0;i<10;i++)
		cin>>b[i];
	for(int i = 0;i<10;i++)
	{
		if(a[i]!=b[i])
		{
			
			cout<<"两个数组不相等"<<endl;
			return 0;
		}
	}
	cout<<"两个数组相等"<<endl;
	return 0;
}



#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<int> v_a,v_b;
	int num;
	cout<<"请输入第一个数组的内容(10个整数)："<<endl;
	for(int i =0;i<10;i++)
	{
		cin>>num;
		v_a.push_back(num);
	}
		
	cout<<"请输入第二个数组的内容(10个整数)："<<endl;
	for(int i =0;i<10;i++)
	{
		cin>>num;
		v_b.push_back(num);
	}
	
	for(int i = 0;i<v_a.size();i++)
	{
		if(v_a[i]!=v_b[i])
		{
			
			cout<<"两个数组不相等"<<endl;
			return 0;
		}
	}
	cout<<"两个数组相等"<<endl;
	return 0;
}

//练习3.37
//练习3.38
//练习3.39
//练习3.40
//练习3.41
//练习3.42
//练习3.43
//练习3.44
//练习3.45
















	