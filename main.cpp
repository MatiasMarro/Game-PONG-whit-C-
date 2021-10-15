#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "libgame.h"


class JUGADOR {
    int x,y;
public:
    JUGADOR(int _x, int _y);
    void pintar() const ;
    void borrar() const;
    void Y(int _y) {y += _y;}
};

JUGADOR::JUGADOR(int _x, int _y): x(_x), y(_y){}

void JUGADOR::pintar() const{

    gotoxy(x,y-1); printf("%c",219);
    gotoxy(x,y);   printf("%c",219);
    gotoxy(x,y+1); printf("%c",219);

}
void JUGADOR::borrar() const{
    gotoxy(x,y-1); printf(" ");
    gotoxy(x,y);   printf(" ");
    gotoxy(x,y+1); printf(" ");
}


int main(){
    OcultaCursor();
    pintar_marco();

    JUGADOR A(6,15);  A.pintar();
    JUGADOR B(74,15); B.pintar();

    char tecla;

    while(1){
        A.borrar();     B.borrar();

        if(kbhit()){
            A.borrar(); B.borrar();
            tecla = getch();
            if(tecla == 'q') A.Y(-1); else if(tecla == 'a') A.Y(1);
            if(tecla == 'o') B.Y(-1); else if(tecla == 'l') B.Y(1);
            A.pintar(); B.pintar();
        }

        A.pintar(); B.pintar();


        pausa(10);

    }


    return 0;
}
