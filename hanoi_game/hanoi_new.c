#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define MAX_LEVEL 99
 
typedef struct HANOI {
	int tower[MAX_LEVEL+1];
	int length;
	int *top;
} Hanoi;



Hanoi *init_hanoi(int max)
{
	int i;
	int *temp;
	Hanoi *new;

	new = (Hanoi *)malloc(sizeof(Hanoi));
	assert(new != NULL);
	temp = new->tower;
	for(i = max; i > 0; i--)
		*(++temp) = i;
	new->length = max;
	new->top = temp;
	
	return new;
}


void printf_hanoi(Hanoi *p)
{
	int i;
	int *temp;
	
	temp = p->tower;
	for(i = p->length; i > 0; i--)
		printf("%d ", *(++temp));
	printf("\n");
}


void destroy_hanoi(Hanoi *p)
{
	free(p);
}


void push_hanoi(Hanoi *p, int num)
{
	(p->length)++;
	(p->top)++;
	*(p->top) = num;
}


int pop_hanoi(Hanoi *p)
{
	int num = *(p->top);

	(p->top)--;
	(p->length)--;

	return num;
}

void move_hanoi(Hanoi *from, Hanoi *to)
{
	if ((from->length <= 0) 
		|| (to->length >= MAX_LEVEL))
		return;
	else if ((to->top != to->tower) 
		&& (*(to->top) < *(from->top)))
		return;

	push_hanoi(to, pop_hanoi(from));
}

int main()
{
	Hanoi *hanoi_a;
	Hanoi *hanoi_b;
	Hanoi *hanoi_c;

	hanoi_a = init_hanoi(5);
	hanoi_b = init_hanoi(0);
	hanoi_c = init_hanoi(0);

	printf_hanoi(hanoi_a);
	printf_hanoi(hanoi_b);
	printf_hanoi(hanoi_c);
	printf("\n");

	move_hanoi(hanoi_a, hanoi_b);
	move_hanoi(hanoi_c, hanoi_a);
	move_hanoi(hanoi_a, hanoi_c);
	printf_hanoi(hanoi_a);
	printf_hanoi(hanoi_b);
	printf_hanoi(hanoi_c);
	printf("\n");

	move_hanoi(hanoi_a, hanoi_c);
	move_hanoi(hanoi_a, hanoi_b);
	move_hanoi(hanoi_b, hanoi_c);
	printf_hanoi(hanoi_a);
	printf_hanoi(hanoi_b);
	printf_hanoi(hanoi_c);
	printf("\n");

	return 0;
}