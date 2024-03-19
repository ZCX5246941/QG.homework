#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct Node
{
	ElemType data;//������
	struct Node *next;//ָ����
}Node;
typedef struct Node* LinkList;

void CreatList(LinkList* L, int n);//��������
void GetElem(LinkList L, int i);//ͨ��Ԫ��λ�ò���Ԫ��ֵ
void ListInsert(LinkList L, int i, ElemType e);//��������
void ListDelete(LinkList L, int i);//ɾ������
void ClearList(LinkList L);//��ձ�
void PrintList(LinkList L);//��ӡ����Ԫ��

int main()
{
	int choice = 0;
	LinkList L;
	L = (LinkList)malloc(sizeof(Node)); //��ʼ�����������
	L->next = NULL; 
	int n,i,j;
	printf("********************������*********************\n");
	printf("��ִ�����²�����\n");
	printf("1.����������\n");
	printf("2.����Ԫ�أ�\n");
	printf("3.ɾ��Ԫ�أ�\n");
	printf("4.ͨ��λ�ò���Ԫ�أ�\n");
	printf("5.��յ�����\n");
	printf("0.��������");

	while (choice == 0)
	{
		printf("����������ִ�еĲ�����");
		scanf("%d", &n);
		switch (n) 
		{
		case 1:
			printf("�������봴������ĳ���:");
			scanf("%d", &i);
			CreatList(&L, i);
			PrintList(L);
			break;
		case 2:
			printf("��������������λ�ü�Ԫ�أ�");
			scanf("%d %d", &i, &j);
			ListInsert(L, i, j);
			PrintList(L);
			break;
		case 3:
			printf("����������ɾ����Ԫ�ص�λ�ã�");
			scanf("%d", &i);
			ListDelete(L, i);
			PrintList(L);
			break;
		case 4:
			printf("������������ҵ�λ�ã�");
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
	printf("********************���н���********************");
}

void CreatList(LinkList* L, int n)//β�巨��������
{
	LinkList p, r;//pָ������ָ��ÿ���µĽ�㣬rָ������ָ��β���
	int i;
	*L = (LinkList)malloc(sizeof(Node));//����ͷ���
	r = *L;//�ձ�rָ��ͷ���
	r->next = NULL;
	printf("���������������Ԫ�أ�");
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		
		scanf("%d", &p->data);
		r->next = p;
		r = p;//ÿ���½�㶼��β��㣬�����½���rָ��β���
	}
	r->next = NULL;
	return;
}

void GetElem(LinkList L, int i)
{
	int j,e;//j��������Ѱ��iλ�ã�e���iλ�õ�����
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
		printf("����ʧ�ܣ������ҵ�%dλ�ò����ڣ������²�����\n", i);
		return;
	}
	e = p->data;
	printf("�������ҵ�Ԫ��Ϊ��%d\n", e);
	return;
}

void ListInsert(LinkList L,int i,ElemType e)
{
	int j;
	LinkList p ,s;//pָ����������Ѱ��iλ�ã�sΪҪ����Ľ��
	p = L;
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
	{
		printf("����ʧ�ܣ���Ҫ�����%dλ�ò����ڣ������²�����\n",i);
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
	LinkList p,q;//p��������Ѱ��iλ�ã�qΪҪɾ���Ľ��
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
		printf("����ʧ�ܣ���Ҫɾ����%dλ�ò����ڣ������²�����\n");
		return;
	}
	p->next = p->next->next;
	free(q);
	return;
}


void ClearList(LinkList L)
{
	LinkList p, q;//pΪɾ���Ľ�㣬qΪp������һ�����
	p = L->next;
	while (p)//�ӱ�ͷ���ɾ�����
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
	printf("��ʱ������Ϊ��");
	if (!p)//�ձ�ֱ�ӽ�������
	{
		printf("�ձ�");
		return;
	}
	while (p)
	{
		printf("%4d", p->data);
		p = p->next;
	}
	return;
}
