#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>   //le time.h nous permettras d'utiliser le d�placemement automatique
//COnstant
const int MAX=20;   //taille du plateau
//prototype
int menu();         //Proc�dure du menu
int creamur();      //Procedure cr�ant les murs
int creasnaker (int* nbrandom, int* nbrandom2); //Procdure placent le snake
int initsouris(int* sourisrandom, int* sourisrandom2); //Procedure cr�ant la souris
/*int Plusgrand(); //Proc�dure pour grandir le serpent
int Score();       //Procdure du score
int findepartie();*/ //Procddure affichant les r�sultars en fin de partie
int Deplaceserpent(int* nbrandom, int* nbrandom2, int* sourisrandom, int* sourisrandom2);  //Procdure d�placent le serpent

void gotoxy( int column, int line ); //Procdure gotoxy (pour d�placer le curseur sur l'ecrant
int wherex();
int wherey();


int main()
{
    menu();
    gotoxy(0,30);
}

int menu(){

    int choix;
    int point;
    int pointe;

    printf("Snake\n");


        system("@cls||clear");      //nettoyage de l'ecrant
        printf("Veuiller choisir un numero\n");
        printf("1-Jouer\nAutre choix-Quitter\n"); //affichage des choix
        scanf("/d",choix);

        if(choix=1){        //si le choix est  alors on lance une partie
            creamur();      //Appelle des proc�dures
            creasnaker(point, pointe);
            deplaceserpent(point, pointe);
        }
    system("Pause");
}

int creamur()
{
    int Compteur;
    int Compteure;

    system("@cls||clear");
    for (Compteur=1; Compteur<=MAX; Compteur++){
       for (Compteure=1; Compteure<=MAX; Compteure++){


           if(Compteure==1 || Compteure==MAX ||Compteur==1 || Compteur==MAX){
            printf("X");
           }

           else{
            printf(" ");
           }

           if(Compteure==MAX){
            printf("\n");
           }

       }
    }

}

int creasnaker(int* nbrandom1, int* nbrandom2) //Ceci permettras de placer le serpent al�atoirement sur la carte
{
    srand(time(NULL));  //Permet de mettre une valeur au hasard sur les coordon�e de la t�te et du corp
    int BordureMax;     //Permet de planifier les valeurs possible des coordon�e du serpent

    BordureMax=MAX-2;

    nbrandom1 = rand() % BordureMax+1;
    nbrandom2 = rand() % BordureMax+1;  //Pour assigner les valeurs au hasard on prend la valeur max des cases puis on edxclus les bordure, on ajoute 1 pour �vite qu'il se g�n�re sur la 1er bodure placer en valeur 1

    gotoxy(nbrandom1, nbrandom2);        //On va au coordon�e et on place les points (la t^te et )
    printf("D");
}

int initsouris(int* sourisrandom1, int* sourisrandom2){   //Procedure pour initialiser la souris

    srand(time(NULL));
    int BordureMax2;

    BordureMax2=MAX-2;

    sourisrandom1 = rand() % BordureMax2+1;
    sourisrandom2 = rand() % BordureMax2+1;

    gotoxy(sourisrandom1, sourisrandom2);
    printf(".");
}

int deplaceserpent(int* nbrandom, int* nbrandom2, int* sourisrandom1, int* sourisrandom2){  //Pour d�placer le serpent

    int test=1;            //Verifie si oon peu encore jouer
    int valx=*nbrandom;     //On r�cup�re les valeurs des coordonn�e de la t�te pour d�placer le serpent
    int valy=*nbrandom2;
    int verifsouris=1;      //Permet de v�rifier si il reste une souris en jeux
    int score=-1;
    int lastpos=0;

    valx=2; //valeur de test
    valy=2; //valeur de test

    do{
        Sleep(250);   //le sleep permet de faire les actions automatiquement
       /* if(verifsouris==1)  //permet de verifier si il reste une souris sur le terrain
        {
            score=score+1;
            gotoxy(MAX+4,15);
            printf("Score: %d\n",score);
            gotoxy(valx,valy);
            initsouris(*nbrandom,*nbrandom2);   //si il en a plus on g�n�re une nouvell
            verifsouris=0;
        }*/

        if(GetAsyncKeyState(VK_UP)) //Si on apuis sur la fl�che du haut
        {
            gotoxy(valx,valy);      //On revient a notre position
            printf(" ");            //on efface l'affichage l'ecrant de l'ancienne position du serpent
            valy=valy-1;            //on met a jours les coordon�e
        }

        if(GetAsyncKeyState(VK_DOWN))
        {
            gotoxy(valx,valy);
            printf(" ");
            valy=valy+1;
        }

        if(GetAsyncKeyState(VK_RIGHT))
        {
            gotoxy(valx,valy);
            printf(" ");
            valx=valx+1;
        }

        if(GetAsyncKeyState(VK_LEFT))
        {
            gotoxy(valx,valy);
            printf(" ");
            valx=valx-1;
        }

        gotoxy(valx, valy);     //On va au nouvelle coordonn�e puis on place la nouvelle position de la t�te
        printf("D");

        if(valx==0 || valy==0 || valx==MAX-1 || valy==MAX-1)    //Permet de v�rifier si le serpent est dans un mur
        {
            test=0;     //On change la vakeur de sortie de la boucle
            gotoxy(1,MAX+3);
            printf("GAME OVER !!!");
        }

    }while(test==1);

}


/*
int Plusgrand(){

    int grille[MAX][MAX];
    int posx;
    int posy;
    int cptx;
    int cpty;
    int longserp=2;

    for(cptx=1; cptx=MAX; cptx++){
        for(cpty=1; cpty=MAX; cpty++){
            if(grille[cptx][cpty]="."){
                posx=cptx;
                posy=cpty;
            }
        }
    }
    if("O"=grille[posx][posy])){
        longserp=longserp+1;
    }
}


int Score(){

    int serpentete;
    int score=0;

    do{
        score=score+1;
    }while(serpentete==".")
}


int findepartie(){

    int serpentete;

    if(serpentete=="o" || serpentete=="X"){
        findepartie()=1;
    }

}


int Affichagefinal(){

    int score;

    printf("Fin de partie\n");
    printf("Votre score est de &d\n", score);
}
*/

void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }

int wherex()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD                      result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.X;
  }

int wherey()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD                      result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.Y;
  }
