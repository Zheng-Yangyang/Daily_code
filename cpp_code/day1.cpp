/*
 * @Author: yangyang zheng 
 * @Date: 2023-04-10 22:22:34
 * @LastEditors: yangyang zheng ‘1332616027@qq.com’
 * @LastEditTime: 2023-04-10 22:46:45
 * @FilePath: \cpp_code\day1.cpp
 * @Description: C++实现一个不可以被继承的类
 */
#include<iostream>
using namespace std;
class A
{	
private:
	A(int data = 0):a(data)
	{
		cout<<"A()"<<endl;
	}
	~A()
	{
		cout<<"~A()"<<endl;
	}
	int a ;
	friend class B;
};
 
class B :virtual public A
{
public:
	B(int val = 0):b(val)
	{
		cout<<"B()"<<endl;
	}
	~B()
	{
		cout<<"~B()"<<endl;
	}
private:
	int b ;
};
 
/*
由于虚基类的构造要依靠最终子类，那么C要先构造A，但是A的构造函数在私有下，外部不可访问，并且A与C之间不存在友元关系，所以C无法构造A，所以B是一个不可被继承的类，但是可以和普通类一样实例化。

B虚继承A，并且B是A的友元，B可以访问A的私有成员，所以B可以正常构造
*/
//class C:public B
// {
// public:
// 	C(int val = 0):c(val)
// 	{
// 		cout<<"C()"<<endl;
// 	}
// 	~C()
// 	{
// 		cout<<"~C()"<<endl;
// 	}
// private:
// 	int c ;
// };

int main()
{
    
    return 0;
}

