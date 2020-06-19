/*
PUC - Minas
Ciencia da Computacao
AED 1
Refacao 02
Aluno: Pedro Henrique Lima Carvalho
Matricula: 651230
*/

//dependencias
#include "io.hpp"


//definicoes
#define ARRAY_SIZE 80
#define ROWS_SIZE 20
#define COLUMNS_SIZE 20

struct s_Array
{
    int length;
    int data[ ARRAY_SIZE ];
};

struct s_Matrix
{
    int rows, columns;
    int data[ ROWS_SIZE ][ COLUMNS_SIZE ];
};

// using namespace
using namespace std;


/**
Method00 - nao faz nada.
*/
void method00 ( )
{
    // nao faz nada
} // fim method00 ( )

/**
 * questao1 - Metodo da questao 1
 * @param ponteiro das structs
*/
void questao1 (struct s_Array *arr, struct s_Matrix *mtx)
{
    //testar dimensoes da matriz
    if(mtx->rows != mtx->columns || mtx->rows<1 || mtx->columns<1)
    {
        printf("%s\n", "Matriz nao tem dimensoes validas");
    }//fim if
    else
    {
        if (((((mtx->rows * mtx->columns) - mtx->rows) / 2) + mtx->rows) > ARRAY_SIZE)
        {
            printf("%s\n", "Tamanho do arranjo insuficiente");
        }//fim if
        else
        {
            //atribuir tamanho de length
            arr->length = ((((mtx->rows * mtx->columns) - mtx->rows) / 2) + mtx->rows);
            
            //criar contador
            int cont = 0;

            //preencher arranjo com os elementos abaixo da diagonal
            for (int x=0; x<mtx->rows; x++)
            {
                for (int y=0; y<mtx->columns; y++)
                {
                    if (x>y)
                    {
                        arr->data[cont] = mtx->data[x][y];
                        cont = cont + 1;
                    }//fim if
                }//fim for
            }//fim for

            //preencher arranjo com os elementos da diagonal
            for (int x=0; x<mtx->rows; x++)
            {
                for (int y=0; y<mtx->columns; y++)
                {
                    if (x==y)
                    {
                        arr->data[cont] = mtx->data[x][y];
                        cont = cont + 1;
                    }//fim if
                }//fim for
            }//fim for
        }//
        
    }//fim else
}//fim questao1 ()

/**
Method01 - Mostrar certa quantidade de valores.
*/
void method01 ( )
{
    // identificar
    IO_id ("Questao 1");

    //definir dados
    struct s_Array arranjo;
    arranjo.length = 0;

    int controle = 1;

    struct s_Matrix matriz;

    //inicializar matriz
    matriz.rows = 5;
    matriz.columns = 5;
    for (int x=0; x<matriz.rows; x++)
    {
        for (int y=0; y<matriz.columns; y++)
        {
            matriz.data[x][y] = controle;
            controle++;
        }//fim for
    }//fim for

    //mostrar matriz
    for (int x=0; x<matriz.rows; x++)
    {
        for (int y=0; y<matriz.columns; y++)
        {
            printf ("\t%d", matriz.data[x][y]);
        }//fim for
        printf("\n");
    }//fim for

    questao1(&arranjo, &matriz);

    //mostrar arranjo    
    for (int x=0; x<arranjo.length; x++)
    {
        printf (" %d", arranjo.data[x]);
    }//fim for

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
 * test - funcao da questao 2
 */
bool teste(int linhas, int colunas, int** matriz)
{
    //definir dados
    int control = 0;

    //testar se matriz quadrada
    if (linhas != colunas)
    {
        control = 1;
        printf("%s\n", "Matriz nao e' quadrada");
    }//fim if
    else
    {
        //testar se matriz obedece ao padrao de transposicao
        for (int x=0; x<linhas && control==0; x++)
        {
            for (int y=0; y<colunas && control==0; y++)
            {
                if (matriz[x][y] != matriz[y][x])
                {
                    control = 1;
                }//fim if
            }//fim for
        }//fim for

        //testar se a matriz obedece ao padrao da diagonal
        for (int x=1; x<linhas && control==0; x++)
        {
            if (matriz[x-1][x-1] != matriz[x][x])
            {
                control = 1;
            }//fim if
        }//fim for
    }//fim else
    
    //retorn
    return(control==0);
}//fim teste ()

/**
Method02.
*/
void method02 ( )
{
    // identificar
    IO_id ("Questao 2");

    //definir dados
    char string [ ARRAY_SIZE ];
    int linhas = 0;
    int colunas = 0;

    //ler nome do arquivo
    printf("%s", "Entre com o nome do arquivo: ");
    scanf("%s", string);

    //abrir arquivo
    FILE *arq = fopen(string, "rt");

    //verificar abertura
    if (arq == NULL)
    {
        printf("%s\n", "Falha ao abrir arquivo");
    }//fim if
    else
    {
        //ler linhas e colunas
        fscanf(arq, "%d", &linhas);
        fscanf(arq, "%d", &colunas);

        //testar linhas e colunas
        if (linhas != colunas || linhas<1 || colunas<1)
        {
            printf("%s\n", "Dimensoes da matriz invalidas");
        }// fim if
        else
        {
            //criar matriz
            int** matriz = (int**) malloc (sizeof(int*)*linhas);
            for (int x=0; x<linhas; x++)
            {
                matriz[x] = (int*) malloc (sizeof(int)*colunas);
            }//fim for

            //preencher matriz com dados do arquivo
            for (int x=0; x<linhas; x++)
            {
                for (int y=0; !feof(arq) && y<colunas; y++)
                {
                    fscanf(arq, "%d", &matriz[x][y]);
                }//fim for
            }//fim for

            //mostrar matriz
            printf("\n");
            for (int x=0; x<linhas; x++)
            {
                for (int y=0; y<colunas; y++)
                {
                    printf ("\t%d", matriz[x][y]);
                }//fim for
                printf("\n");
            }//fim for

            //testar padrao
            if ( teste(linhas, colunas, matriz) )
            {
                printf("%s\n", "Matriz obedece aos padroes");
            }//fim if
            else
            {
                printf("%s\n", "Matriz NAO obedece aos padroes");
            }//fim else

            //liberar memoria
            for (int x=0; x<linhas; x++)
            {
                free(matriz[x]);
            }//fim for
            free(matriz);

        }//fim else
    }//fim else

    //fechar arquivo
    fclose(arq);

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
Method03.
*/
void method03 ( )
{
    // identificar
    IO_id ("Questao 3");

    //definir dados
    string str;
    string resp = "";

    //ler cadeia de caracteres
    cout << "Entre com a cadeia de caracteres" << endl;
    cin >> str;

    //copiar dados para resp alterando
    for (int x=0; x<str.length(); x++)
    {
        if (x != 0 && ('A' <= str[x] && str[x] <= 'Z'))
        {
            resp = resp + "_" + (char)(str[x] - 'A' + 'a');
        }//fim if
        else
        {
            resp = resp + str[x];
        }//fim else
    }//fim for

    //mostrar resp
    cout << resp << endl;

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )


// ----------------------------------------------- acao principal
/*
Funcao principal.
@return codigo de encerramento
*/
int main ( int argc, char** argv )
{
    // definir dado
    int x = 0; // definir variavel com valor inicial

    // repetir até desejar parar
    do
    {
        // identificar
        IO_id ("Refacao 02");
    
        // mostrar opcoes
        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - Questao 1" << endl;
        cout << " 2 - Questao 2" << endl;
        cout << " 3 - Questao 3" << endl;

        // ler do teclado
        cout << endl << "Entrar com uma opcao: ";
        cin >> x;

        // escolher acao
        switch ( x )
        {
            case 0:
            method00 ( );
            break;

            case 1:
            method01 ( );
            break;
            
            case 2:
            method02 ( );
            break;
            
            case 3:
            method03 ( );
            break;
            
            default:
            cout << endl << "ERRO: Valor invalido." << endl;
        } // fim escolher
    }while ( x != 0 );
    
    // encerrar
    IO_pause ( "Apertar ENTER para terminar" );
    return ( 0 );
} // fim main( )

/*
------------------------------------Comentarios
Main:   
    v1- teste sem ponteiro.  
    v2- funcionou como esperado

method01:
    v1- Nao compilava passando int matriz [][colunas] como parametro
    v2- funcionou como esperado

method02:
    v1- funcionou com esperado

method03:
    v1- funcionou como esperado

------------------------------------Testes
method01:   teste sem utilizar pointer: nao funcionou
            com pointer: funcinou

method02:   tentando passar como parametro int matriz[][colunas];
            criacao da matriz de forma dinamica
            matriz1.txt, matriz2.txt, matriz3.txt

method03:   

*/
