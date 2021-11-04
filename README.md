# Three-Jug-Problem

**Puzzle statement:** Find all the solutions to A-B-C jug problem.

You are given 3 jugs A, B, C of capacities a, b, c litres respectively.
The initial state/initial volumes of water in the jugs are X, Y, Z.
Your goal is to get to a final state of P, Q, R litres.

There are no markings on the jugs (you can’t just measure off litres directly).
You may pour from a jug to any other jug (you have to transfer from one jug to another until either one jug becomes empty or the other full). You cannot waste water. The total amount of water in the entire system must be the same as the initial.

1)How To Compile:
    Use gcc client.c code.c

2)four data structures were used:

      i) state:
            it represents the state of the jugs currently
            -has quantity of a,b,c 
            -also has a variable called pour which specifies what is the next pour action that can be taken on this state 
     
     ii)node:
            it just encapsulates a state so that we can add it to the list
            -it has variable st which is nothing but the state it holds
            -it also has next and prev which points to the next and previous node to the current node in the list

    iii)list:
            It is the list itself which stores the path followed to reach the solution
            its a doubly linked list.
            -it has head and tail pointers to access the first and last node of the list
     
     iv)callback array:
            it has pointer to all the pour functions that can be applied on a state.
            it holds 6 functions


3) Logic:
        The state space search is used to solve this 3 jug problem. 
        We use a list to keep track of all the states we have passed while doing transitions.
        This is needed so that we can print the solution when we reach the destination state.
        So initially we begin at start state by inserting it into a list.
        then we try to perform a pour action on this to get a another state
        We insert the new state in the list as long as its not already present in the list.
        if it is indeed present in the list already then this state is not again to avoid having loops as this wont reach the final solution now if it hasnt already.
        We keep repeating this and every time we check for a pour action on the last inserted node.
        Incase there is no pour action possible anymore we discard the current node from the list as it no longer has a path leading to the solution.

        In case we find the destination node we print the transition with the help of pour variable of state.
        Then since this path gave solution already we move onto the next path by just removing this node. This will make the parent search for the next pour action it can take.

        The entire problem is done iteratively. It keeps checking for solution in apath and when its not found ,it backtracks so as to try the next possible path.
