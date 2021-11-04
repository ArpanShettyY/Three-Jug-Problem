#include <stdio.h>
#include <stdlib.h>
#include "A3_header_PES1UG19CS086.h"

//function explaination comments is there in header
void set_state(state *newstate, int a,int b, int c)
{
    newstate->a=a;
    newstate->b=b;
    newstate->c=c;
    newstate->pour=-1;                                      //initially no pour has taken place from this state
}


int same(const state *st1, const state *st2)
{
    return ((st1->a ==st2->a) &&
            (st1->b ==st2->b) &&
            (st1->c ==st2->c));
}


void pour_ab(const state *st1, state *st2, int max_a,int max_b, int max_c)
{
    int a,b,c;
    int rem= max_b - st1->b;                                //return how much quantity of the jug is empty
    if(st1->a <=rem)                                        //if the water in 1st jug can be completely transferred to second jug
    {
        b=st1->b + st1->a;
        a=0; 
    } 
    else                                                    //if the water in 1st jug can not be completely transferred to second jug due to overflow
    {
        b=max_b;
        a=st1->a - rem;
    }
    c=st1->c;                                               //no change in remaining jug
    set_state(st2,a,b,c);
}


//the above comments apply to rest of the pour function except different source and destination jugs are used
void pour_ac(const state *st1, state *st2, int max_a,int max_b, int max_c)
{
    int a,b,c;
    int rem= max_c - st1->c;
    if(st1->a <=rem)
    {
        c=st1->c + st1->a;
        a=0; 
    } 
    else
    {
        c=max_c;
        a=st1->a - rem;
    }
    b=st1->b;
    set_state(st2,a,b,c);
}


void pour_ba(const state *st1, state *st2, int max_a,int max_b, int max_c)
{
    int a,b,c;
    int rem= max_a - st1->a;
    if(st1->b <=rem)
    {
        a=st1->a + st1->b;
        b=0; 
    } 
    else
    {
        a=max_a;
        b=st1->b - rem;
    }
    c=st1->c;
    set_state(st2,a,b,c);
}


void pour_bc(const state *st1, state *st2, int max_a,int max_b, int max_c)
{
    int a,b,c;
    int rem= max_c - st1->c;
    if(st1->b <=rem)
    {
        c=st1->c + st1->b;
        b=0; 
    } 
    else
    {
        c=max_c;
        b=st1->b - rem;
    }
    a=st1->a;
    set_state(st2,a,b,c);
}


void pour_ca(const state *st1, state *st2, int max_a,int max_b, int max_c)
{
    int a,b,c;
    int rem= max_a - st1->a;
    if(st1->c <=rem)
    {
        a=st1->a + st1->c;
        c=0; 
    } 
    else
    {
        a=max_a;
        c=st1->c - rem;
    }
    b=st1->b;
    set_state(st2,a,b,c);
}


void pour_cb(const state *st1, state *st2, int max_a,int max_b, int max_c)
{
    int a,b,c;
    int rem= max_b - st1->b;
    if(st1->c <=rem)
    {
        b=st1->b + st1->c;
        c=0; 
    } 
    else
    {
        b=max_b;
        c=st1->c - rem;
    }
    a=st1->a;
    set_state(st2,a,b,c);
}


void (*pour[])(const state *st1, state *st2, int max_a,int max_b, int max_c)={pour_ab,pour_ac,pour_ba,pour_bc,pour_ca,pour_cb}; //array of pointers to function


void initialize(list *ls)
{
    ls->head=NULL;          //initially list is empty
    ls->tail=NULL;
}


void display(const list *ls)
{
    node *t=ls->head;                   //begin at first node
    while(t!=ls->tail)                  //till the end
    {
        switch(t->st.pour)              //check pour value to find out which transition it is
        {
            case 0:printf("A B\n");
                   break;
            case 1:printf("A C\n");
                   break;
            case 2:printf("B A\n");
                   break;
            case 3:printf("B C\n");
                   break;
            case 4:printf("C A\n");
                   break;
            case 5:printf("C B\n");
                   break;
        }
        t=t->next;
    }
    printf("\n");
}


void insert_node(list *ls, const state *st)
{
    node* temp = (node*)malloc(sizeof(node));       //the newly created node
	temp->st = *st;
	temp->next = NULL;
	if(ls->head == NULL)                            //if the list is empty
	{
		temp->prev =NULL;
		ls->head = ls->tail = temp;
	}
	else                                            //if the list already has some nodes
	{
		temp->prev = ls->tail;
		ls->tail->next = temp;
        ls->tail=temp;
	}
}

void remove_node(list *ls)
{
    //it is made sure that remove is never called on empty list so that condition is not taken care here
    node *temp=ls->tail;
    if(ls->head == ls->tail )           //if the list just has one node
	{
		ls->head = ls->tail = NULL;
	}
	else                                //if the list has more than one node
	{
		ls->tail = ls->tail->prev;
		ls->tail->next = NULL;
	}
    free(temp);
}


int repeated(const list *ls, const state *st)
{
    node *t =ls->head;              //traverse from start to end of list ,for each node check if its state is the same as given sate
	while(t!= NULL)
	{
		if(same(st, &(t->st)))
		{
			return 1;
		}
		t = t->next;
	}
	return 0;
}