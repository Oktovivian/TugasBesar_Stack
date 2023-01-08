#include "maze.h"

void createStack(Stack &S)
{
    top(S) = NULL;
}

bool isEmpty(Stack S)
{
    return top(S) == NULL;
}

void push(Stack &S, int dimensi1, int dimensi2)
{
    address P;
    P = new element_stack;
    infotype_stack Dimensi;
    Dimensi.dimensi_1 = dimensi1;
    Dimensi.dimensi_2 = dimensi2;
    info(P) = Dimensi;
    next(P) = NULL;
    if (isEmpty(S))
    {
        top(S) = P;
    }
    else
    {
        next(P) = top(S);
        top(S) = P;
    }
}

void pop(Stack &S)
{
    if (isEmpty(S))
    {
        cout << "STACK KOSONG" << endl;
    }
    else if (next(top(S)) == NULL)
    // kasus 1 element
    {
        top(S) = NULL;
    }
    else
    {
        top(S) = next(top(S));
    }
}

Stack reverseStack(Stack S)
{
    Stack reverse_S;
    createStack(reverse_S);
    address pointer_P = top(S);
    while (pointer_P != NULL)
    {
        push(reverse_S, info(pointer_P).dimensi_1, info(pointer_P).dimensi_2);
        pointer_P = next(pointer_P);
    }
    return reverse_S;
}

void printStack(Stack S)
{
    address pointer_P = top(S);
    while (pointer_P != NULL)
    {
        cout << "(" << info(pointer_P).dimensi_1 << "," << info(pointer_P).dimensi_2 << ") ";
        pointer_P = next(pointer_P);
    }
    cout << endl;
    cout << endl;
}

void searchPath(int maze[19][21][2], Stack &S, int dimensi1, int dimensi2)
{
    // Kondisi untuk berhentinya adalah koordinat titik akhir (20,1)
    if (!(dimensi1 == 1 && dimensi2 == 20))
    {
         if ((maze[dimensi1][dimensi2 + 1][0] == 1) && (maze[dimensi1][dimensi2 + 1][1] == 0))
        // bergerak ke kanan
        {
            dimensi2++;
            push(S, dimensi1, dimensi2);
            maze[dimensi1][dimensi2][1] = 1;
            searchPath(maze, S, dimensi1, dimensi2);
        }

        else if ((maze[dimensi1 + 1][dimensi2][0] == 1) && (maze[dimensi1 + 1][dimensi2][1] == 0))
        // bergerak ke bawah
        {
            dimensi1++;
            push(S, dimensi1, dimensi2);
            maze[dimensi1][dimensi2][1] = 1; // Menandai bahwa sudah dilewati
            searchPath(maze, S, dimensi1, dimensi2); // Rekursif
        }

        else if ((maze[dimensi1][dimensi2 - 1][0] == 1) && (maze[dimensi1][dimensi2 - 1][1] == 0))
        // bergerak ke kiri
        {
            dimensi2--;
            push(S, dimensi1, dimensi2);
            maze[dimensi1][dimensi2][1] = 1;
            searchPath(maze, S, dimensi1, dimensi2);
        }
       
        else if ((maze[dimensi1 - 1][dimensi2][0] == 1) && (maze[dimensi1 - 1][dimensi2][1] == 0))
        // bergerak ke atas
        {
            dimensi1--;
            push(S, dimensi1, dimensi2);
            maze[dimensi1][dimensi2][1] = 1;
            searchPath(maze, S, dimensi1, dimensi2);
        }
            
        else
        // Kasus buntu
        {
            pop(S);
            searchPath(maze, S, info(top(S)).dimensi_1, info(top(S)).dimensi_2);
        }
    }
}

void printMaze(int maze[19][21][2])
{
    int dimensi1, dimensi2;
    for (dimensi1 = 0; dimensi1 < 19; dimensi1++)
    {
        for (dimensi2 = 0; dimensi2 < 21; dimensi2++)
        {
            cout << maze[dimensi1][dimensi2][0] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printPath(int maze[19][21][2], Stack S)
{
    int dimensi1, dimensi2;
    address pointer_P;
    bool found;
    for (dimensi1 = 0; dimensi1 < 19; dimensi1++)
    {
        for (dimensi2 = 0; dimensi2 < 21; dimensi2++)
        {
            pointer_P = top(S);
            found = false;
            while (pointer_P != NULL && !found)
            {
                if ((info(pointer_P).dimensi_1 == dimensi1) && (info(pointer_P).dimensi_2 == dimensi2))
                {
                    cout << "  ";
                    found = true;
                }
                else
                {
                    pointer_P = next(pointer_P);
                }
            }
            if (!found)
            {
                cout << maze[dimensi1][dimensi2][0] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int chooseMenu()
{
    cout<<"Selamat datang di program maze"<<endl;
    cout << "============================== MENU ==============================\n";
    cout << "1. Menampilkan labirin yang belum di-solve\n";
    cout << "2. Menampilkan koordinat jalur setelah di-solve\n";
    cout << "3. Menampilkan labirin yang sudah di-solve\n";
    cout << "0. Exit\n\n";
    cout << "Masukkan menu: ";
    int pilihan;
    cin>>pilihan;
    return pilihan;
}

void programUtama1(){
    int maze[19][21][2] = {
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {1, 0}, {0, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 0}, {1, 0}, {1, 0}},
        {{0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}},
        {{0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}},
        {{0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}},
        {{0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}},
        {{0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}},
        {{0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}},
        {{0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}},
        {{0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}},
        {{0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}},
        {{0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}},
        {{0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}},
        {{0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}},
        {{0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}},
        {{0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}},
        {{1, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}};

    // Pengguna memasukkan inputan dengan panggil prosedur chooseMenu
    int userChoice = chooseMenu();

    // Koordinat titik awalnya adalah (17,0)
    int dimensi1, dimensi2;
    dimensi1 = 17;
    dimensi2 = 0;


    // Stack untuk menyimpan jalur yang telah dilalui
    Stack S;
    createStack(S);

    // push titik awal ke stack
    push(S, dimensi1, dimensi2);
    maze[dimensi1][dimensi2][1]=1;

    while(userChoice != 0){
        switch(userChoice){
            case 1:
                // Print maze
                printMaze(maze);
                break;     
            case 2:
                // Mencari jalan keluar maze
                searchPath(maze, S, dimensi1, dimensi2);
                 // Print stack
                Stack reverse_S;
                reverse_S = reverseStack(S);
                printStack(reverse_S);
                break;    
            case 3:
                // Print maze yang sudah disolve
                printPath(maze, reverse_S);
                break;     
        }
        userChoice = chooseMenu();
    }
    cout<<"anda keluar dari program"<<endl;
};