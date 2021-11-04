#include<stdio.h>
#include<stdlib.h>
#include "A3_header_PES1UG19CS086.h"

int main()
{
    state start, end, temp;                         //the initial state, final sate of jugs. temp used to store new state 
    list ls;
    int a ,b ,c ,max_a, max_b, max_c, pour_in;      //max a,b,c is used to hold the maximum quantity the jugs can hold
    int solns=0;                                    //used to store the number of solutions

    scanf("%d %d %d",&max_a,&max_b,&max_c);
    scanf("%d %d %d",&a,&b,&c);
    set_state(&start, a, b, c);
    scanf("%d %d %d",&a,&b,&c);
    set_state(&end, a, b, c);

    initialize(&ls);
    insert_node(&ls,&start);                        //the start state is added into the list

    while(ls.head!=NULL)                            //while the list is not empty
    {
        pour_in= ++ls.tail->st.pour;                //update to the next pour to do
        if(pour_in<6)                               //if its a valid pour
        {
            pour[pour_in](&(ls.tail->st), &temp, max_a, max_b, max_c);      //temp will be the sate after the pour
            if(!repeated(&ls, &temp))                                       //if this state is not there in list already
            {
                insert_node(&ls,&temp);                                     //insert it into the list
                if(same(&temp, &end))                                       //if that is indeed our destination state
                {
                    solns++;                                    
                    display(&ls);                                           //display the transitions we did to find the solution
                    remove_node(&ls);
                }
            }
        }
        else
        {
            remove_node(&ls);                                               //if no more pours can be done from that node then remove this node from the list
        }
    }

    printf("%d\n",solns);                                                   //finally print the number of solutions we get

    return 0;
}
