#include <iostream>
#include <cstdio>
#include <stdlib.h>


using namespace std;



char tablero[3][3];
char jugadorActual = 'X';

void inicializar()
{
    for( int i = 0; i < 3; i++ )
        {
            for( int j = 0; j < 3; j++ )
                {
                    tablero[i][j] = ' ';
                }
        }
}

void desplegarTablero()
{
    for( int i = 0; i < 3; i++ )
    {
        printf("\t|----------------------|\n");
        for( int j = 0; j < 3; j++ )
        {
            printf( "\t|  %c  ",tablero[i][j] );
        }
        printf(" |\n");
    }
    printf("\t|----------------------|\n\n");
}

void registrarJugada(int fila, int columna)
{

  tablero [--fila][--columna] = jugadorActual;
}


bool hayGanador()
{
    //horizontal
    char jugadorEncontrado = tablero[0][0];

    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if (tablero[i][j] == ' ')
            {
                break; break;
            }
            if ( jugadorEncontrado != tablero[i][j] )
            {
                break;break;
            }
            jugadorEncontrado = tablero[i][j];
            if( j == 2 )
            {
                printf("Haz ganado %c: \n",jugadorEncontrado);
                return true;
            }
        }
    }

    //vertical
    jugadorEncontrado = tablero[0][0];

    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if (tablero[j][i] == ' ')
            {
                break; break;
            }
            if ( jugadorEncontrado != tablero[j][i] )
            {
                break;break;
           }
           jugadorEncontrado = tablero[j][i];

            if( j == 2 )
            {
                printf("Haz  ganado %c: \n",jugadorEncontrado);
                return true;
            }
        }
    }

    //diagonal izquieda a derecha
    jugadorEncontrado = tablero[0][0];

    for (int i = 0; i < 3; i++)
    {

        if (tablero[i][i] == ' ')
        {
            break;
        }
        if ( jugadorEncontrado != tablero[i][i] )
        {
            break;
        }
            jugadorEncontrado = tablero[i][i];

        if( i == 2 )
        {
            printf("Haz ganado %c: \n",jugadorEncontrado);
            return true;
        }
    }

    // //diagonal derecha a izquieda
    jugadorEncontrado = tablero[0][2];
    for (int i = 2; i >= 0; i--)
    {

        if (tablero[2-i][i] == ' ')
        {
            break;
        }
        if ( jugadorEncontrado != tablero[2-i][i] )
        {
            break;
        }
            jugadorEncontrado = tablero[2-i][i];
        if( i == 0 )
        {
            printf("Haz ganado %c: \n",jugadorEncontrado);
            return true;
        }
    }

    return false;
}

bool hayEmpate()
{
    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if (tablero[i][j] == ' ')
            {
                return false;
            }

        }
    }
    printf("Hay un empate\n");
    return true;

}


void jugar()
{
    while ( !hayGanador() && !hayEmpate())
    {
        int fila = 0;
        int columna = 0;

        desplegarTablero();
        printf( "En que fila deseas jugar %c: ",jugadorActual );
        scanf( "%d", &fila );
        if( fila < 1 || fila > 3 )
        {
            cout << "fila no valida" << endl;
            system("pause");
            system("cls");
            jugar();
        }
        printf( "En que columna deseas jugar %c: ",jugadorActual );
        scanf( "%d", &columna );
        if( columna < 1 || columna > 3 )
        {
            cout << "columna no valida" << endl;
            system("pause");
            system("cls");
            jugar();
        }

        if (tablero[fila-1][columna-1] == ' ')
        {
            registrarJugada( fila, columna );
            system("cls");
        }else
        {
            printf("Esta fila ya esta ocupada intente otra\n");
        }




        if ( jugadorActual == 'X')
        {
            jugadorActual = 'O';
        }else
            {
                jugadorActual = 'X';
            }
    }
}

int main()
{
    cout << "\Bienvenino al juego Tic Tac Toe \n" << endl;
    inicializar();
    try
    {
        jugar();
        printf("\n");
        desplegarTablero();
        system("pause");
    }catch( char error)
    {
        cout << error << "no valido " <<endl;
        jugar();

    }

    return 0;
}
