#include<stdio.h>
#include<malloc.h>
typedef int ElemType;

typedef struct Lnode /* 单链表的结点类型 */
{
	ElemType data;
	Lnode* next;
} LNode, * LinkedList;

LinkedList setnull()    /* 置空队的函数 */
{
    LinkedList rear;
    rear=(LinkedList)malloc(sizeof(LNode));
    rear->next=rear;
    return rear;
}

LinkedList enqueue1(LinkedList rear,int x)    /* 第一个函数入队列进行特殊处理 */
{
    LinkedList s;
	s = (LinkedList)malloc(sizeof(LNode));
	s->data = x;
	s->next = rear;
	rear->next = s;
	return s;
}
void enqueue(LinkedList rear,int x)   /* 入队列的函数 */
{
    LinkedList p, s;
	p = rear->next;
	s = (LinkedList)malloc(sizeof(LNode));
	s->data = x;
	s->next = p->next;
	p->next = s;
}
LinkedList outqueue(LinkedList rear)  /*出队列的函数*/
{
    LinkedList p,s;
    s=rear;
    p=rear->next;
    while(p->next!=rear)
        p=p->next;
    p->next=rear->next;
    free(s);
    return p;
} 
void showqueue(LinkedList rear)    /* 遍历输出当前列表*/
{
    LinkedList p;
	p = rear->next->next;
	printf("队列中的元素为:");
	while (p != rear->next)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void freeLinkList(LinkedList rear)   /*释放循环链表*/
{
	LinkedList p, q;
	q = p = rear->next;
	while (p != rear)
	{
		p = p->next;
		free(q);
		q = p;
	}
}
int main()
{
	LinkedList rear;
	rear=setnull();  /*调用置空函数*/
	rear=enqueue1(rear,0);
	for (int i = 1; i <= 5; i++)
	{
		enqueue(rear, i);/*调用入队列函数*/
	}
	showqueue(rear);
	rear=outqueue(rear);  /*调用出队列的函数，删除最先进的元素0;*/
	showqueue(rear);
	freeLinkList(rear);
	return 0;
}
