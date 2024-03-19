#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct Node
{
	ElemType data;//数据域
	struct Node *next;//指针域
}Node;
typedef struct Node* LinkList;

void CreatList(LinkList* L, int n);//创建链表
void GetElem(LinkList L, int i);//通过元素位置查找元素值
void ListInsert(LinkList L, int i, ElemType e);//插入数据
void ListDelete(LinkList L, int i);//删除数据
void ClearList(LinkList L);//清空表
void PrintList(LinkList L);//打印链表元素

int main()
{
	int choice = 0;
	LinkList L;
	L = (LinkList)malloc(sizeof(Node)); //初始化定义的链表
	L->next = NULL; 
	int n,i,j;
	printf("********************单链表*********************\n");
	printf("可执行以下操作：\n");
	printf("1.创建单链表；\n");
	printf("2.插入元素；\n");
	printf("3.删除元素；\n");
	printf("4.通过位置查找元素；\n");
	printf("5.清空单链表；\n");
	printf("0.结束程序；");

	while (choice == 0)
	{
		printf("请输入您想执行的操作：");
		scanf("%d", &n);
		switch (n) 
		{
		case 1:
			printf("请输入想创建链表的长度:");
			scanf("%d", &i);
			CreatList(&L, i);
			PrintList(L);
			break;
		case 2:
			printf("请输入您想插入的位置及元素：");
			scanf("%d %d", &i, &j);
			ListInsert(L, i, j);
			PrintList(L);
			break;
		case 3:
			printf("请输入您想删除的元素的位置：");
			scanf("%d", &i);
			ListDelete(L, i);
			PrintList(L);
			break;
		case 4:
			printf("请输入您想查找的位置：");
			scanf("%d", &i);
			GetElem(L, i);
			PrintList(L);
			break;
		case 5:
			ClearList(L);
			PrintList(L);
			break;
		case 0:
			choice = -1;
			break;
		}
		printf("\n");
	}
	printf("********************运行结束********************");
}

void CreatList(LinkList* L, int n)//尾插法创建链表
{
	LinkList p, r;//p指针用来指向每个新的结点，r指针用来指向尾结点
	int i;
	*L = (LinkList)malloc(sizeof(Node));//创建头结点
	r = *L;//空表r指向头结点
	r->next = NULL;
	printf("请输入您想输入的元素：");
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		
		scanf("%d", &p->data);
		r->next = p;
		r = p;//每个新结点都是尾结点，存入新结点后r指向尾结点
	}
	r->next = NULL;
	return;
}

void GetElem(LinkList L, int i)
{
	int j,e;//j用来遍历寻找i位置，e存放i位置的数据
	LinkList p;
	p = L->next;
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
	{
		printf("操作失败，您查找的%d位置不存在，请重新操作。\n", i);
		return;
	}
	e = p->data;
	printf("您所查找的元素为：%d\n", e);
	return;
}

void ListInsert(LinkList L,int i,ElemType e)
{
	int j;
	LinkList p ,s;//p指针用来遍历寻找i位置，s为要插入的结点
	p = L;
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
	{
		printf("操作失败，您要插入的%d位置不存在，请重新操作。\n",i);
		return;
	}
		
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return;
}

void ListDelete(LinkList L, int i)
{
	int j;
	LinkList p,q;//p用来遍历寻找i位置，q为要删除的结点
	j = 1;
	p = L;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	q = p->next;
	if (!q)
	{
		printf("操作失败，您要删除的%d位置不存在，请重新操作。\n");
		return;
	}
	p->next = p->next->next;
	free(q);
	return;
}


void ClearList(LinkList L)
{
	LinkList p, q;//p为删除的结点，q为p结点的下一个结点
	p = L->next;
	while (p)//从表头逐个删除结点
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	return;
}
void PrintList(LinkList L)
{
	LinkList p;
	p = L->next;
	printf("此时的链表为：");
	if (!p)//空表，直接结束函数
	{
		printf("空表！");
		return;
	}
	while (p)
	{
		printf("%4d", p->data);
		p = p->next;
	}
	return;
}
