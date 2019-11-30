#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	int num;
	int score;
	struct student *next;
}stu;

stu *creat(int num)
{
	int i;
	stu *p, *head = NULL, *tail = head;
	for (i = 0; i < num; i++)
	{
		p = (stu *)malloc(sizeof(stu));
		scanf("%d%d", &p->num, &p->score);
		p->next = NULL;
		if (p->num <= 0)
		{
			free(p);
			break;
		}
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
	}
	return head;
}

void print(stu *p)
{
	while (p != NULL)
	{
		printf("%d\t%d\n", p->num, p->score);
		p = p->next;
	}
}

stu *link(stu *p1, stu *p2)
{
	stu *p, *head;
	if (p1->num < p2->num)
	{
		head = p = p1;
		p1 = p1->next;
	}
	else
	{
		head = p = p2;
		p2 = p2->next;
	}
	while ((p1 != NULL) && (p2 != NULL))
	{
		if (p1->num < p2->num)
		{
			p->next = p1;
			p = p1;
			p1 = p1->next;
		}
		else
		{
			p->next = p2;
			p = p2;
			p2 = p2->next;
		}
	}
	if (p1 != NULL)
		p->next = p1;
	else
		p->next = p2;

	return head;
}

stu* merge(stu* n1, stu* n2);
stu *sort(stu *c)
{
	stu *l = c, *m = c, *r = c;
	if (!c || !c->next) return c;
	
	while (r && r->next) {
		r = r->next->next;
		m = l;
		l = l->next;
	}
	m->next = NULL;
	return merge(sortList(c), sortList(l));
}

stu* merge(stu* n1, stu* n2) {
	if (!n1) return n2;
	if (!n2) return n1;
	if (n1->num <= n2->num) {
		n1->next = merge(n1->next, n2);
		return n1;
	}
	else {
		n2->next = merge(n2->next, n1);
		return n2;
	}
}

int main()
{
	stu *a, *b, *c ,*d;
	int n = 0;
	int m = 0;
	scanf("%d %d", &n,& m);
	a = creat(n);
	b = creat(m);
	
	c = link(a, b);

	d = sort(c);
	print(d);
	system("pause");
	return 0;
}
