#include <stdlib.h>
#include <stdio.h>
char x1 = 1;//全局区 DATA段
char x2 = 2;

int y1;//全局区 BSS段
int y2;

static int x3 = 3; //全局区 Data段
static int x4 = 4;

static int y3;//全局区 BSS段
static int y4;

void f() {

}

int main() {
	printf("================栈区========================\n");
	int a;
	char b = 'a';
	char c[10] = "asdf";
	int *p = &a;
	printf("a在栈区：%p\n", &a);
	printf("b在栈区：%p\n", &b);
	printf("c在栈区：%p\n", &c);
	printf("p在栈区：%p\n", &p);

	printf("================堆区========================\n");
	int *q1 = (int*)malloc(sizeof(int));
	int *q2 = (int*)malloc(sizeof(int));
	printf("q1在堆区：%p\n", q1);
	printf("q2在堆区：%p\n", q2);
	free(q1), free(q2);

	printf("================全局区========================\n");
	printf("x1在全局区 DATA段：%p\n", &x1);
	printf("x2在全局区 DATA段：%p\n", &x2);
	printf("y1在全局区 BSS段：%p\n", &y1);
	printf("y2在全局区 BSS段：%p\n", &y2);
	printf("用static修饰之后\n");
	printf("x3在全局区 DATA段：%p\n", &x3);
	printf("x4在全局区 DATA段：%p\n", &x4);
	printf("y3在全局区 BSS段：%p\n", &y3);
	printf("y4在全局区 BSS段：%p\n", &y4);
	
	printf("================文字常量区========================\n");
	const char *s1 = "asdfsfsda";
	const char *s2 = "fsd";
	printf("s1在文字常量区：%p\n", s1);
	printf("s2在文字常量区：%p\n", s2);

	printf("================程序区========================\n");
	printf("main函数放在程序区:%p\n", &main);
	printf("f函数放在程序区:%p\n", &f);
	return 0;
}
