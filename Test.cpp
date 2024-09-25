//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	// 编译报错：“ra”: 必须初始化引⽤
//	//int& ra;
//	int& b = a;
//	int c = 20;
//	// 这⾥并⾮让b引⽤c，因为C++引⽤不能改变指向，
//	// 这⾥是⼀个赋值
//	b = c;
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	return 0;
//}
//#include<iostream>
//#include<stdio.h>
//#include<assert.h>
//using namespace std;
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//void STInit(ST& rs, int n = 4)
//{
//	rs.a = (STDataType*)malloc(n * sizeof(STDataType));
//	rs.top = 0;
//	rs.capacity = n;
//}
//// 栈顶
//void STPush(ST& rs, STDataType x)
//{
//	//assert(rs);
//	// 满了， 扩容
//	if (rs.top == rs.capacity)
//	{
//		printf("扩容\n");
//		int newcapacity = rs.capacity == 0 ? 4 : rs.capacity * 2;
//		STDataType* tmp = (STDataType*)realloc(rs.a, newcapacity *
//			sizeof(STDataType));
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			return;
//		}
//		rs.a = tmp;
//		rs.capacity = newcapacity;
//	}
//	rs.a[rs.top] = x;
//	rs.top++;
//}
//// int STTop(ST& rs)
//int& STTop(ST& rs)
//{
//	assert(rs.top > 0);
//	return rs.a[rs.top - 1];
//}
//int* STTopp(ST& rs)
//{
//	assert(rs.top > 0);
//	return &(rs.a[rs.top - 1]);
//}
//int main()
//{
//	// 调⽤全局的
//	ST st1;
//	STInit(st1);
//	STPush(st1, 1);
//	STPush(st1, 2);
//	cout << STTop(st1) << endl;
//	//STTop(st1) += 10;
//	*(STTopp(st1)) += 10;
//	/*cout << STTop(st1) << endl;*/
//	cout << *STTopp(st1) << endl;
//	return 0;
//}
//#include<iostream>
//#include<stdio.h>
//#include<assert.h>
//using namespace std;
//int main()
//{
//	const int a = 10;
//	//权限不能放大
//	//int& ra = a;
//	const int& ra = 1;
//	//权限可以缩小
//	/*int b = 1;
//	const int& rb = b;*/
//	int b = 20;
//	int* p3 = &b;
//	const int* p4 = p3;
//	//不存在权限放大，因为const修饰的是p4本身而不是指向的内容
//	int* const p5 = &b;
//	int* p6 = p5;
//
//	return 0;
//}
//#include<iostream>
//#include<stdio.h>
//#include<assert.h>
//using namespace std;
//void f1(const int& rx)
//{
//
//}
//int main()
//{
//	int a = 10;
//	//int& b = a;
//	int b = 20;
//	const int& rb = a * 3;
//	int* aa = &a;
//	const int*& bb = aa;
//	bb = &b;
//
//	double d = 12.34;
//	const int& rd = d;
//
//	f1(a);
//	f1(a * 3);
//	return 0;
//}

//#include<iostream>
//using namespace std;
// 没有宏函数的坑，也不用建立函数栈帧，提效
//inline int Add(int x, int y)
//{
//	int ret = x + y;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	return ret;
//}
//int main()
//{
//	// 可以通过汇编观察程序是否展开
//    // 有call Add语句就是没有展开，没有就是展开了
//	int ret = Add(1, 2);
//	cout << Add(1, 2) * 5 << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//// 实现⼀个ADD宏函数的常⻅问题
////#define ADD(int a, int b) return a + b;
////#define ADD(a, b) a + b;
////#define ADD(a, b) (a + b)
//// 正确的宏实现
//#define ADD(a, b) ((a) + (b))
//// 1.为什么不能加分号?
//// 2.为什么要加外⾯的括号?
//// 3.为什么要加⾥⾯的括号?
//int main()
//{
//	int ret = ADD(1, 2);
//	//问题1
//	cout << ADD(1, 2) << endl;
//	//问题2
//	cout << ADD(1, 2) * 5 << endl;
//	//问题3
//	int x = 1, y = 2;
//	ADD(x & y, x | y); //->(x&y+x|y)
//	cout << ADD(x & y, x | y) << endl;
//	return 0;
//}

//#include "Func.h"
//int main()
//{
//	// 链接错误：⽆法解析的外部符号 "void __cdecl f(int)" (?f@@YAXH@Z)
//	f(10);
//	return 0;
//}

#include<iostream>
using namespace std;
void f(int x)
{
	cout << "f(int x)" << endl;
}
void f(int* ptr)
{
	cout << "f(int* ptr)" << endl;
}
int main()
{
	f(0);
	// 本想通过f(NULL)调⽤指针版本的f(int*)函数，但是由于NULL被定义成0，调⽤了f(int x)，因此与程序的初衷相悖。
	f(NULL);
	f((int*)NULL);
	// 编译报错：error C2665: “f”: 2 个重载中没有⼀个可以转换所有参数类型
	// f((void*)NULL);
	f(nullptr);

	return 0;
}