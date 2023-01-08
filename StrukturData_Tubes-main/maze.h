#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED
#include <iostream>
#define top(S) S.top
#define info(P) P->info
#define next(P) P->next

using namespace std;


// stack akan menyimpan koordinat x dan y dan nanti di prosedur print akan 'dirapikan' (dipisahkan dengan ( ) )
struct infotype_stack
{
    int dimensi_1, dimensi_2;
};

typedef struct element_stack *address;

struct element_stack
{
    infotype_stack info;
    address next;
};

struct Stack
{
    address top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
void push(Stack &S, int dimensi1, int dimensi2);
void pop(Stack &S);
Stack reverseStack(Stack S);
void printStack(Stack S);

void searchPath(int maze[19][21][2], Stack &S, int dimensi1, int dimensi2);
void printMaze(int maze[19][21][2]);
void printPath(int maze[19][21][2], Stack S);
void chooseMenu(int input);

int chooseMenu();
void programUtama1();
#endif // MAZE_H_INCLUDED
