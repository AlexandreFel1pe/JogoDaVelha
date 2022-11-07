#include <stdio.h>
#include <stdlib.h>

char matrix[3] [3];

char done = 'a';

void init(void);
void display(void);
void playMoveX(void);
void playMoveY(void);
char result(void);

void main(void){
    int sair;
    init();

    for(;;)
    {
    system("cls");
    display();
    playMoveX();
    done = result();
    if(done == 'x') break;
    system("cls");
    display();
    playMoveY();
    done = result();
    if(done == 'y') break;
    }
    system("cls");
    if(done=='x') printf("\nJogador X venceu\n");
    else printf ("\nJogador Y venceu\n");
    printf("\n");
    display();

    printf("\nDigite: 1 para jogar novamente e\nDigite: 2 para sair\n");
    scanf("%d", &sair);
    if(sair == 1){
        main();
    }
    else;
}

/*Incializa matrix*/

void init(void)
{
    int i, j, k;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            matrix[i][j] = ' ';
        }
    }
}

/*Exibe a tela*/

void display(void)
{
    printf(" 0 1 2");
    printf("\n0%c|%c|%c",matrix[0][0], matrix[0][1], matrix[0][2]);
    printf("\n1%c|%c|%c",matrix[1][0], matrix[1][1], matrix[1][2]);
    printf("\n2%c|%c|%c\n",matrix[2][0], matrix[2][1], matrix[2][2]);
}

/*Move Jogador X*/

void playMoveX(void)
{
    int x, y;

    printf("\nJogador X faca uma jogada digitando as coordenadas:\n");
    printf("X: ");
    scanf("%d", &x);
    printf("Y: ");
    scanf("%d", &y);


    if((x==0 || x==1 || x==2) && (y==0 || y==1 || y==2))
    {
        if(matrix[x][y]==' '){
            matrix[x][y] = 'x';
        }
        else 
        {
            printf("Local escolhido ja esta prenchido");
            playMoveX();
        }
    }
    else
    {
        printf("Coodernadas invalidas. Tente novamentes");
        playMoveX();
    }
}

/*Move Jogador Y*/

void playMoveY(void)
{
    int x, y;

    printf("\nJogador Y faca uma jogada digitando as coordenadas:\n");
    printf("X: ");
    scanf("%d", &x);
    printf("Y: ");
    scanf("%d", &y);

    if((x==0 || x==1 || x==2) && (y==0 || y==1 || y==2))
    {
        if(matrix[x][y]==' '){
            matrix[x][y] = 'y';
        }
        else 
        {
            printf("Local escolhido ja esta prenchido");
            playMoveY();
        }
    }
    else
    {
        printf("Coodernadas invalidas. Tente novamentes");
        playMoveY();
    }
}

char result(void){
    for(int i = 0; i < 3; i++){
    if(matrix[i][0]=='x' && matrix[i][1]=='x' && matrix[i][2]=='x') return('x');
    }

    for(int i = 0; i < 3; i++){
    if(matrix[0][i]=='x' && matrix[1][i]=='x' && matrix[2][i]=='x') return('x');
    }

    if(matrix[0][0]=='x' && matrix[1][1]=='x' && matrix[2][2]=='x') return('x');

    if(matrix[0][2]=='x' && matrix[1][1]=='x' && matrix[2][0]=='x') return('x');

    for(int i = 0; i < 3; i++){
    if(matrix[i][0]=='y' && matrix[i][1]=='y' && matrix[i][2]=='y') return('y');
    }

    for(int i = 0; i < 3; i++){
    if(matrix[0][i]=='y' && matrix[1][i]=='y' && matrix[2][i]=='y') return('y');
    }

    if(matrix[0][0]=='y' && matrix[1][1]=='y' && matrix[2][2]=='y') return('y');

    if(matrix[0][2]=='y' && matrix[1][1]=='y' && matrix[2][0]=='y') return('y');
    else return('a');
}