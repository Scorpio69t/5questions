#include <stdio.h>

int menu(void); //菜单显示函数

void countGreatestCommonDivisor(void); //解决求两个数的最大公约数问题

void getAbc(void); //计算满足条件的三位数
int factorial(int n); //递归实现阶乘


void countEatPeach(void); //解决猴子吃桃问题
long peach(int n); //计算第一天的桃子数

void printMultiplicationTable(void); //打印99乘法表

void fishermanFishing(void); //解决渔夫打渔问题
int leap(int year); //判断是否为闰年
int countDays(int year, int month, int day); //计算输入的日期距离2015-1-1过了多少天

int main()
{
	int select = menu();
	while (select != 0)
	{
		switch (select)
		{
		case 1:
			countGreatestCommonDivisor();
			break;
		case 2:
			getAbc();
			break;
		case 3:
			countEatPeach();
			break;
		case 4:
			printMultiplicationTable();
			break;
		case 5:
			fishermanFishing();
			break;
		case 0:
			break;
		default:
			printf("请输入0-5之间的数字！\n");
			system("pause");
			break;
		}
		if (select != 0)
		{
			select = menu();
		}
	}

	printf("感谢使用！\n");
	system("pause");
	return 0;
}

int menu(void)
{
	int select = 0;
	system("cls");
	printf("========================================\n");
	printf("******欢迎使用求解经典算法题程序******* \n");
	printf("========================================\n");
	printf("       1.求两个数的最大公约数.          \n");
	printf("       2.求出满足条件的三位数.          \n");
	printf("       3.求解猴子吃桃问题.              \n");
	printf("       4.打印9*9 乘法表.               \n");
	printf("       5.求解渔夫打渔问题.             \n");
	printf("       0.退出.                        \n");
	printf("========================================\n");
	scanf_s("%d", &select);

	return select;
}

void countGreatestCommonDivisor(void)
{
	int a, b, m, n, r;
	printf("计算最大公约数:\n");
	printf("请输入要计算的两个数(a b)：_____\b\b\b\b\b");
	scanf_s("%d %d", &a, &b);
	if (a > b)
	{
		m = a;
		n = b;
	}
	else
	{
		m = b;
		n = a;
	}
	r = m % n;
	while (r != 0)
	{
		m = n;
		n = r;
		r = m % n;
	}

	printf("%d %d 的最大公约数是：%d\n", a, b, n);
	system("pause");
	return;
}

void getAbc(void)
{
	int i = 0;
	printf("输出满足abc=a!+b!+c!条件的三位数:\n");
	for (i = 100; i < 1000; i++)
	{
		//分别将三位bai数的百位、十位、各位du赋给a,b,c
		int a, b, c;
		a = i / 100;
		b = (i - a * 100) / 10;
		c = i - a * 100 - b * 10;
		//如果满足条件则输出
		if (i == (factorial(a) + factorial(b) + factorial(c)))
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	system("pause");
	return;
}

int factorial(int n)
{
	int fac = 1;
	if (n <= 1)
	{
		return 1;
	}
	fac = factorial(n - 1) * n;
	return fac;
}

void countEatPeach(void)
{
	int n;
	long peachnum;

	printf("猴子吃桃问题求解：\n");
	printf("输入天数: ___\b\b\b");
	scanf_s("%d", &n);
	peachnum = peach(n);
	printf("最初的桃子数为：%ld个.\n", peachnum);
	system("pause");
	return;
}

long peach(int n)
{
	long pe;
	if (n == 1)
	{
		return 1;
	}
	else
	{
		pe = (peach(n - 1) + 1) * 2;
	}
	return pe;
}

void printMultiplicationTable(void)
{
	int i, j, n;
	printf("9*9 乘法表:\n");
	for (i = 1; i <= 9; i++)
	{
		// 将下面的for循环注释掉，就输出左下三角形
		/*for (n = 1; n <= 9 - i; n++)
		{
			printf("        ");
		}*/
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%2d  ", j, i, i * j);
		}
		printf("\n");
	}
	system("pause");
	return;
}

void fishermanFishing(void)
{
	int year, month, day, n;
	printf("渔夫打渔问题：\n");
	printf("请输入年-月-日(2020-7-17): ___________\b\b\b\b\b\b\b\b\b\b\b");
	scanf_s("%d-%d-%d", &year, &month, &day);    /*输入年月日*/
	n = countDays(year, month, day);    /*调用函数 countDays()*/
	if ((n % 5) < 4 && (n % 5) > 0)    /*余数是1或2或3时说明在打渔，否则在晒网*/
	{
		printf("%d-%d-%d: 这一天渔夫在打渔\n", year, month, day);
	}
	else
	{
		printf("%d-%d-%d: 这一天渔夫在晒网\n", year, month, day);
	}
	system("pause");
	return;
}

int leap(int year) //判断输入的年份是否为闰年
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)/* 闰年判定条件 */
	{
		return 1;    /*是闰年返回1*/
	}
	else
	{
		return 0;    /*不是闰年返回O*/
	}
}

int countDays(int year, int month, int day)    //计算输入日期距2015年1月1日共有多少天
{
	int sum = 0, i, j, k;
	int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };    /*数组a存放平年每月的天数*/
	int b[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };    /*数组b存放闰年每月的天数*/

	if (leap(year) == 1)    /*判断是否为闰年*/
	{
		for (i = 0; i < month - 1; i++)
		{
			sum += b[i];    /*是闰年，累加数组b前m-1个月份的天数*/
		}
	}
	else
	{
		for (i = 0; i < month - 1; i++)
			sum += a[i];    /*不是闰年，累加数组a前m-1个月份的天数*/
	}
	for (j = 2015; j < year; j++)
	{
		if (leap(j) == i)
		{
			sum += 366;    /*2015年到输入的年份是闰年的加366*/
		}
		else
		{
			sum += 365;    /*2015年到输入的年份不是闰年的加365*/
		}
	}

	sum += day;    /*将前面累加的结果加上日期，求出总天数*/
	return sum;    /*返回计算的天数*/
}