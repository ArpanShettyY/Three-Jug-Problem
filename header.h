#ifndef PROJ
#define PROJ

struct state        //used to store the current status of the jugs
{
    int a;          //quantity of water in jug A
    int b;          //quantity of water in jug B
    int c;          //quantity of water in jug C
    int pour;       //tells what pour action is done currently
};
typedef struct state state;

void set_state(state *newstate, int a,int b, int c);                    //used for setting values into a new state
int same(const state *st1, const state *st2);                           //used for checking if the state of st1 and st2 are one and the same

void pour_ab(const state *st1, state *st2, int max_a,int max_b, int max_c);     //Performs a pour from Jug A to Jug B
void pour_ac(const state *st1, state *st2, int max_a,int max_b, int max_c);     //Performs a pour from Jug A to Jug C
void pour_ba(const state *st1, state *st2, int max_a,int max_b, int max_c);     //Performs a pour from Jug B to Jug A
void pour_bc(const state *st1, state *st2, int max_a,int max_b, int max_c);     //Performs a pour from Jug B to Jug C
void pour_ca(const state *st1, state *st2, int max_a,int max_b, int max_c);     //Performs a pour from Jug C to Jug A
void pour_cb(const state *st1, state *st2, int max_a,int max_b, int max_c);     //Performs a pour from Jug C to Jug B


extern void (*pour[])(const state *st1, state *st2, int max_a,int max_b, int max_c);        //callback array

struct node                     //acts as an unit of the list 
{
    state st;                   //the state of the jugs it resembles
    struct node *prev;          //the previous node pointer
    struct node *next;          //the next node pointer
};
typedef struct node node;

struct list                     //a list to store the sequence of transition from start to final state
{
    node *head;                 //pointer to the first node
    node *tail;                 //pointer to the last node
};
typedef struct list list;

void initialize(list *ls);                      //initializes the list mentioned above
void display(const list *ls);                   //displays the transitions taken from start of the list to reach the last state
void insert_node(list *ls, const state *st);    //inserts a new node at the tail of the list
void remove_node(list *ls);                     //deletes a node from the list
int repeated(const list *ls, const state *st);  //to check if a state is already present in the current list

#endif
