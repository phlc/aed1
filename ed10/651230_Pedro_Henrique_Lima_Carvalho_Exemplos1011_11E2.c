/*
PUC - Minas
Ciencia da Computacao
AED 1
Estudo Dirigido 10
Aluno: Pedro Henrique Lima Carvalho
Matricula: 651230
*/

//dependencias
#include "io.h"

//definicoes
typedef 
    struct arranjo {
        int tamanho;
        int* dados;
        int posicao;
    }arranjo;

typedef
    struct matriz {
        int linhas;
        int colunas;
        int** dados;
    }matriz;

// ----------------------------------------- Funcoes e Metodos Globais

    // ------------------------------------- Arranjos
/**
new_array - Cria um arrajo criado por struct de forma dinamica
@param tamanho do arranjo
@return ponteiro para o arranjo
*/
arranjo* new_array (int n)
{
    //definir dados
    arranjo* p_arranjo = (arranjo*) malloc (sizeof(arranjo));

    //testar valores validos
    if (p_arranjo == NULL || n < 1)
    {
        printf ("\n%s\n", "ERROR: new_array()");
    }//fim if
    else
    {
        //definir elementos do arranjo
        p_arranjo->tamanho = n;
        p_arranjo->dados = (int*) malloc (sizeof(int)*n);
        p_arranjo->posicao = 0;

        //testar dados do arranjo
        if (p_arranjo->dados == NULL)
        {
            p_arranjo->posicao = -1;
            p_arranjo->tamanho = 0;
            printf ("\n%s\n", "ERROR: new_array ()");
        }//fim if
    }//fim else

    //retorno
    return (p_arranjo);
}//fim new_array ()

/**
free_new_array - Liberar a memoria de um arranjo criado 
por struct de forma dinamica
@param ponteiro para o arranjo
*/
void free_new_array (arranjo* p_arranjo)
{
    //testar input
    if (p_arranjo != NULL)
    {
        free (p_arranjo->dados);
        free (p_arranjo);
    }// fim if
}//fim free_new_array ()

/**
fprint_array - grava em arquivo arranjo criado
por struct de forma dinamica
@param ponteiro para o arranjo e nome do arquivo
*/
void fprint_array (arranjo* p_arranjo, char* file)
{
    //definir dados
    FILE* arquivo = fopen (file, "wt");

    //testar input e arquivo
    if (arquivo == NULL || p_arranjo == NULL || p_arranjo->tamanho<1)
    {
        printf ("\n%s\n", "ERROR: fprint_array ()");
    }//fim if
    else
    {
        //gravar em arquivo o tamanho
        fprintf (arquivo, "%d\n", p_arranjo->tamanho);

        //gravar em arquivo elementos do arranjo
        for (int x=0; x<p_arranjo->tamanho; x++)
        {
            fprintf (arquivo, "%d\n", p_arranjo->dados[x]);
        }//fim for
    }//fim else

    //encerrar
    fclose (arquivo);
}//fim fprint_array

/**
random_int - gera uma numero inteiro aleatorio
@param limites inferior e superior
@return numero inteiro aleatorio
*/

int random_int (int inferior, int superior)
{
    //definir dados
    int resposta = 0;

    //gerar numero aleatorio entre intervalos abertos
    resposta = inferior + 1 + (rand() % (superior - inferior - 1));

    //retorno
    return (resposta);
}//fim random_int ()

/**
fread_array_size - Le o tamanho de um arranjo em um arquivo
@param nome do arquivo
@return tamanho do arranjo
*/
int fread_array_size (char* file)
{
    //definir dados
    int tamanho = 0;
    FILE *arquivo = fopen (file, "rt");

    //ler tamanho
    if (arquivo != NULL)
    {
        fscanf (arquivo, "%d", &tamanho);
    }//fim if

    //retorno
    return (tamanho);
}//fim fread_array_size ()

/**
fread_array - Le um arranjo de um arquivo
@param nome do arquivo e tamanho do arranjo
@return ponteiro para o arranho
*/
arranjo* fread_array (char* file, int size)
{
    //definir dados
    FILE *arquivo = fopen (file, "rt");
    int tamanho = 0;
    arranjo* p_arranjo = NULL;

    //testar dados
    if (arquivo != NULL && size > 0)
    {
        //ler tamanho do arranjo
        fscanf (arquivo, "%d", &tamanho);

        //testar de tamanhos sao igual
        if (tamanho != size)
        {
            printf ("\n%s\n", "ERROR: fread_array ()");
        }//fim if
        else
        {
            //criar arranjo
            p_arranjo = new_array (tamanho);

            //testar arranjo
            if (p_arranjo != NULL)
            {
                //preencher tamanho do arranjo
                p_arranjo->tamanho = tamanho;

                //preencher elementos do arranjo
                while (!feof(arquivo) && p_arranjo->posicao < tamanho)
                {
                    //ler elemento do arquivo e armazenar em arranjo
                    fscanf (arquivo, "%d", &p_arranjo->dados[p_arranjo->posicao]);

                    //mudar posicao
                    p_arranjo->posicao=p_arranjo->posicao+1;
                }//fim while

                //retornar posicao para 0
                p_arranjo->posicao = 0;
            }//fim if
        }//fim else
    }//fim if

    //retorno
    return (p_arranjo);
}//fim fread_array()

/**
search_array - procura certo valor em arranjo
@param ponteiro para arranjo e valor a ser procurado
@return verdadeiro se encontrar ou falso se nao
*/
bool search_array (arranjo* p_arranjo, int valor)
{
    //definir dados
    int counter = 0;

    //testar input 
    if (p_arranjo != NULL)
    {
        //procurar valor em arranjo
        for (int x=0; x<p_arranjo->tamanho && counter == 0; x++)
        {
            if (valor == p_arranjo->dados[x])
            {
                counter = 1;
            }//fim if
        }//fim for
    }//fim if

    //retorno
    return (counter == 1);
}//fim search_array

/**
compare_arrays - compara dois arranjos
@param ponteiros para os arranjos a serem comparados
@return verdadeiro se iguais, falso se nao
*/
bool compare_arrays (arranjo* p_arranjo1, arranjo* p_arranjo2)
{
    //definir dados
    int counter = 0;
    
    //testar inputs
    if (p_arranjo1 == NULL || p_arranjo2 == NULL)
    {
        printf ("\n%s\n", "ERROR: compare_arrays ()");
    }//fim if
    else
    {
        //comparar tamanho dos arranjos
        if (p_arranjo1->tamanho != p_arranjo2->tamanho)
        {
            counter = 1;
        }//fim if
        else
        {
            //comparar elemento a elementos do arranjo
            for (int x=0; x<p_arranjo1->tamanho && counter == 0; x++)
            {
                if (p_arranjo1->dados[x] != p_arranjo2->dados[x])
                {
                    counter = 1;
                }//fim if
            }//fim for
        }//fim else
    }//fim else

    //retorno
    return(counter == 0);
}//fim compare_arrays

/**
print_array - mostra arranjo na tela
@param ponteiro do arranjo
*/
void print_array (arranjo* p_arranjo)
{
    //testar input
    if (p_arranjo == NULL || p_arranjo->tamanho<1)
    {
        printf ("\n%s\n", "ERROR: print_array ()");
    }//fim if
    else
    {
        //mostrar arranjo
        printf ("\n%s", "[ ");
        for (int x=0; x<p_arranjo->tamanho; x++)
        {
            printf ("%d ", p_arranjo->dados[x]);
        }//fim for
        printf ("%s\n", "]");
    }//fim else

}//fim print_array ()

/** 
sum_arrays - soma arranjos com segundo escalonado por constante
@param ponteiros para os arranjos a serem somados e constante
@return ponteiro para o arranjo com o resultado
*/
arranjo* sum_arrays (arranjo* p_arranjo1, arranjo* p_arranjo2, int constante)
{
    //definir dados
    arranjo* p_arranjo_soma = NULL;

    //testar inputs
    if (p_arranjo1 == NULL || p_arranjo2 == NULL || p_arranjo1->tamanho != p_arranjo2->tamanho)
    {
        printf ("\n%s\n", "ERROR: sum_arrays ()");
    }//fim if
    else
    {
        //criar arranjos para soma
        p_arranjo_soma = new_array (p_arranjo2->tamanho);

        //testar p_arranjo_soma
        if (p_arranjo_soma == NULL)
        {
            printf ("\n%s\n", "ERROR: sum_arrays ()");
        }//fim if
        else
        {
            //somar arranjos
            for (int x=0; x<p_arranjo1->tamanho; x++)
            {
                p_arranjo_soma->dados[x] = p_arranjo1->dados[x] + constante*p_arranjo2->dados[x];
            }//fim for
        }//fim else
    }//fim else

    //retorno
    return (p_arranjo_soma);
}// fim sum_arrays ()

/**
sorted_array - Verifica se arranjo esta em ordem crescente
@param ponteiro para arranjo a ser verificado
@return verdadeiro se em ordem crescente, falso se nao
*/
bool sorted_array (arranjo* p_arranjo)
{
    //definir dados
    int counter = 0;

    //testar input
    if (p_arranjo == NULL || p_arranjo->tamanho<1)
    {
        printf ("\n%s\n", "ERROR: sorted_array()");
    }//fim if
    else
    {
        //verificar se arranjo esta em ordem crescente
        for (int x=1; x<p_arranjo->tamanho && counter==0; x++)
        {
            if (p_arranjo->dados[x-1] > p_arranjo->dados[x])
            {
                counter = 1;
            }//fim if
        }//fim for
    }//fim else
    
    return (counter == 0);
}//fim sort_array ()

/**
sort_array - Organiza arranjo em ordem crescente
@param ponteiro para arranjo a ser verificado
*/
void sort_array (arranjo* p_arranjo)
{
    //definir dados
    int counter = 0;
    int buffer = 0;

    //testar input
    if (p_arranjo == NULL || p_arranjo->tamanho<1)
    {
        printf ("\n%s\n", "ERROR: sorted_array()");
    }//fim if
    else
    {
        //repetir ate arranjo em ordem
        do
        {
            //resetar contador
            counter = 0;

            //verificar se arranjo esta em ordem crescente
            for (int x=1; x<p_arranjo->tamanho; x++)
            {
                //se nao estiver trocar
                if (p_arranjo->dados[x-1] > p_arranjo->dados[x])
                {
                    //trocar
                    buffer = p_arranjo->dados[x-1];
                    p_arranjo->dados[x-1] = p_arranjo->dados[x];
                    p_arranjo->dados[x] = buffer;

                    //alterar contador
                    counter = 1;
                }//fim if
            }//fim for
        } while (counter != 0);//fim while
    }//fim else
}//fim sort_array ()

    // ------------------------------------- Matrizes

/**
new_matrix - cria uma matriz criada por struct por alocacao dinamica
@param numero de linhas e colunas
@return ponteiro para matriz
*/
matriz* new_matrix (int lines, int columns)
{
    //definir dados
    matriz *p_matrix = NULL;

    //alocar espaco para matrix
    p_matrix = (matriz*) malloc (sizeof(matriz));

    //testar dados
    if (p_matrix == NULL || lines < 1 || columns < 1)
    {
        printf ("\n%s\n", "ERROR: new_matrix ()");
    }//fim if
    else
    {
        //preencher dados matriz
        p_matrix->linhas = lines;
        p_matrix->colunas = columns;

        //alocar memoria para linhas
        p_matrix->dados = (int**) malloc (sizeof(int*) * lines);

        //testar alocacao
        if (p_matrix->dados == NULL)
        {
            printf ("\n%s\n", "ERROR: new_matrix ()");
            p_matrix->linhas = 0;
            p_matrix->colunas = 0;
        }//fim if
        else
        {
            //alocar memoria para colunas
            for (int x=0; x<lines; x++)
            {
                p_matrix->dados[x] = (int*) malloc (sizeof(int) * columns);
                
                //testar alocacao 
                if (p_matrix->dados[x] == NULL)
                {
                    printf ("\n%s\n", "ERROR: new_matrix ()");
                    p_matrix->linhas = 0;
                    p_matrix->colunas = 0;
                    x = lines;
                }//fim if
            }//fim for
        }//fim else

    }//fim else
    
    //retorno
    return (p_matrix);
}//fim new_matrix ()

/**
free_matrix - Libera a memoria de uma matriz criada por struct
@param ponteiro da matriz
*/
void free_matrix (matriz* p_matrix)
{
    //testar se matriz existe
    if (p_matrix != NULL)
    {
        //testar se matriz.dados existe
        if (p_matrix->dados != NULL)
        {
            //testar se matriz.dados[x] existe
            for (int x=0; x<p_matrix->linhas; x++)
            {
                if (p_matrix->dados[x] != NULL)
                {
                    free (p_matrix->dados[x]);
                }//fim if
            }//fim for
            //liberar matriz.dados
            free (p_matrix->dados);
        }//fim if
        //liberar matriz
        free (p_matrix);
    }//fim if
}//fim free_matrix ()

/**
fread_matrix_dimensions - Le as dimensoes de uma matriz de um arquivo
@param nome do arquivo, ponteiros para numero de linhas e de colunas
*/
void fread_matrix_dimensions (char* file, int* p_lines, int* p_columns)
{
    //definir dados
    FILE *arquivo = fopen (file, "rt");
    *p_lines = 0;
    *p_columns = 0;

    //testar dado
    if (arquivo != NULL)
    {
        //ler dimensoes
        fscanf (arquivo, "%d", p_lines);
        fscanf (arquivo, "%d", p_columns);
    }//fim if

    //testar leitura de dados validos
    if (*p_lines < 1 || *p_columns < 1)
    {
        printf ("\n%s\n", "ERROR: fread_matrix_dimensions ()");
    }//fim if
}// fim fread_matrix_dimensions ()

/**
fread_matrix - Le matriz de arquivo
@param nome do arquivo, dimensoes da matrix
@return ponteiro para a matriz
*/
matriz* fread_matrix (char* file, int lines, int columns)
{
    //definir dados
    FILE *arquivo = fopen (file, "rt");
    int linhas = 0;
    int colunas = 0;
    matriz* p_matrix = NULL;

    //testar dados
    if (arquivo == NULL || lines < 1 || columns < 1)
    {
        printf ("\n%s\n", "ERROR: fread_matrix ()");
    }
    else
    {
        //ler dimensoes
        fscanf (arquivo, "%d", &linhas);
        fscanf (arquivo, "%d", &colunas);

        //verificar dimensoes
        if (linhas != lines || colunas != columns)
        {
            printf ("\n%s\n", "ERROR: fread_matrix ()");
        }//fim if
        else
        {
            //alocar matriz
            p_matrix = new_matrix(lines, columns);

            //preencher matriz
            for (int x=0; x<lines && !feof(arquivo); x++)
            {
                for (int y=0; y<columns && !feof(arquivo); y++)
                {
                    fscanf (arquivo, "%d", &p_matrix->dados[x][y]);
                }//fim for
            }//fim for
        }//fim else
    }//fim else

    //retorno
    return (p_matrix);
}//fim fread_matrix

/**
print_matrix - Mostra uma matriz criada por struct na tela
@param ponteiro para a matriz
*/
void print_matrix (matriz* p_matrix)
{
    //testar dados
    if (p_matrix == NULL || p_matrix->linhas < 1 || p_matrix->colunas < 1)
    {
        printf ("\n%s\n", "ERROR: print_matrix ()");
    }//fim if
    else
    {
        //mostrar matriz
        printf ("\n");
        for (int x=0; x<p_matrix->linhas; x++)
        {
            for (int y=0; y<p_matrix->colunas; y++)
            {
                printf ("\t%d", p_matrix->dados[x][y]);
            }//fim for
            printf ("\n");
        }//fim for
    }//fim else
}//fim print_matrix

/**
 transp_matrix - gera uma matriz transposta
 @param ponteiro da matriz a ser transposta
 @return ponteiro da matriz transposta 
*/
matriz* transp_matrix (matriz* p_matrix)
{
    //definir dados
    matriz* p_transp = NULL;
    
    //verificar dados
    if (p_matrix == NULL || p_matrix->linhas < 1 || p_matrix->colunas < 1)
    {
        printf ("\n%s\n", "ERROR: transp_matrix ()");
    }//fim if
    else
    {
        //alocar matriz transposta
        p_transp = new_matrix (p_matrix->colunas, p_matrix->linhas);

        //preencher matriz transposta
        for (int x=0; x<p_matrix->linhas; x++)
        {
            for (int y=0; y<p_matrix->colunas; y++)       
            {
                p_transp->dados[y][x] = p_matrix->dados[x][y];
            }//fim for
        }//fim for
    }//fim else

    //retorno
    return (p_transp);
}//fim transp_matrix

/**
test_matrix_zero - testa se todos valores da matriz sao zero
@param ponteiro da matriz
@return verdadeiro se todos sao zero, falso se nao
*/
bool test_matrix_zero (matriz* p_matrix)
{
    //definir dados 
    int counter = 0;

    //testar input
    if (p_matrix == NULL)
    {
        printf ("\n%s\n", "ERROR: test_matrix_zero ()");
    }//fim if
    else
    {
        //passar por elementos da matriz
        for (int x=0; x<p_matrix->linhas && counter==0; x++)
        {
            for (int y=0; y<p_matrix->colunas && counter==0; y++)
            {
                //testar elemento da matriz
                if (p_matrix->dados[x][y] != 0)
                {
                    //altera contador
                    counter = 1;
                }//fim if
            }//fim for
        }//fim for
    }//fim else

    //retorno
    return (counter == 0);
}//fim test_matriz_zero

/**
test_matrix_equal - testa se duas matrizes sao iguais
@param ponteiro das matrizes
@return verdadeiro se iguais, falso se nao
*/
bool test_matrix_equal (matriz* p_matrix1, matriz* p_matrix2)
{
    //definir dados 
    int counter = 0;

    //testar input
    if (p_matrix1 == NULL || p_matrix2 == NULL)
    {
        printf ("\n%s\n", "ERROR: test_matrix_equal ()");
    }//fim if
    else
    {
        //testar se linhas e colunas sao iguais
        if (p_matrix1->linhas != p_matrix2->linhas || 
            p_matrix1->colunas != p_matrix2->colunas)
        {
            //altera contador
            counter = 1;
        }//fim if
        else
        {
            //passar por elementos da matriz
            for (int x=0; x<p_matrix1->linhas && counter==0; x++)
            {
                for (int y=0; y<p_matrix1->colunas && counter==0; y++)
                {
                    //testar elemento da matriz
                    if (p_matrix1->dados[x][y] != p_matrix2->dados[x][y])
                    {
                        //altera contador
                        counter = 1;
                    }//fim if
                }//fim for
            }//fim for
        }//fim else
    }//fim else
    //retorno
    return (counter == 0);
}//fim test_matriz_equal

/**
sum_matrix - soma duas matrizes com a segunda escalonada por uma constante
@param ponteiro das matrizes e constante
@return ponteiro para matriz somada
*/
matriz* sum_matrix (matriz* p_matrix1, matriz* p_matrix2, int constante)
{    
    //definir dados
    matriz* p_matrix_soma = NULL;
    
    //testar input
    if (p_matrix1 == NULL || p_matrix2 == NULL)
    {
        printf ("\n%s\n", "ERROR: sum_matrix ()");
    }//fim if
    else
    {
        //testar se linhas e colunas sao iguais
        if (p_matrix1->linhas != p_matrix2->linhas || 
            p_matrix1->colunas != p_matrix2->colunas)
        {
            printf ("\n%s\n", "Matrizes nao tem a mesma dimensao");
        }//fim if
        else
        {
            //alocar matriz somada
            p_matrix_soma = new_matrix (p_matrix1->linhas, p_matrix1->colunas);

            //passar por elementos da matriz
            for (int x=0; x<p_matrix_soma->linhas; x++)
            {
                for (int y=0; y<p_matrix_soma->colunas; y++)
                {
                    //somar matrizes
                    p_matrix_soma->dados[x][y] = p_matrix1->dados[x][y] + constante * p_matrix2->dados[x][y];
                }//fim for
            }//fim for
        }//fim else
    }//fim else
    //retorno
    return (p_matrix_soma);
}//fim sum_matrix

/**
mult_matrix - multiplica duas matrizes
@param ponteiro das matrizes
@return ponteiro para matriz multiplicada
*/
matriz* mult_matrix (matriz* p_matrix1, matriz* p_matrix2)
{    
    //definir dados
    matriz* p_matrix_mult = NULL;
    int produto = 0;
    
    //testar input
    if (p_matrix1 == NULL || p_matrix2 == NULL)
    {
        printf ("\n%s\n", "ERROR: mult_matrix ()");
    }//fim if
    else
    {
        //testar se linhas e colunas sao iguais
        if (p_matrix1->colunas != p_matrix2->linhas)
        {
            printf ("\n%s\n", "Matrizes nao tem dimensoes compatives");
        }//fim if
        else
        {
            //alocar matriz multiplicada
            p_matrix_mult = new_matrix (p_matrix1->linhas, p_matrix2->colunas);

            //testar alocacao
            if (p_matrix_mult == NULL)
            {
                printf ("\n%s\n", "ERROR: mult_matrix ()");
            }//fim if
            else
            {      
                //preencher elementos da matriz multiplicada
                for (int x=0; x<p_matrix_mult->linhas; x++)
                {
                    for (int y=0; y<p_matrix_mult->colunas; y++)
                    {
                        //multiplica matrizes
                        for (int z=0; z<p_matrix1->colunas; z++)
                        {
                            produto = produto + p_matrix1->dados[x][z] * p_matrix2->dados[z][y];
                        }//fim for

                        //armazena em matriz multiplicada valor produto
                        p_matrix_mult->dados[x][y] = produto;
                        
                        //zerar produto
                        produto = 0;
                    }//fim for
                }//fim for
            }//fim else
        }//fim else
    }//fim else
    //retorno
    return (p_matrix_mult);
}//fim mult_matriz

/**
test_matrix_ident - testa se matriz identidade
@param ponteiro da matriz
@return verdadeiro se matriz identidade, falso se nao
*/
bool test_matrix_ident (matriz* p_matrix)
{
    //definir dados 
    int counter = 0;

    //testar input
    if (p_matrix == NULL)
    {
        printf ("\n%s\n", "ERROR: test_matrix_ident ()");
    }//fim if
    else
    {
        //passar por elementos da matriz
        for (int x=0; x<p_matrix->linhas && counter==0; x++)
        {
            for (int y=0; y<p_matrix->colunas && counter==0; y++)
            {
                //verificar se elemento da diagonal principal
                if ( x == y)
                {
                    //testar elemento da matriz
                    if (p_matrix->dados[x][y] != 1)
                    {
                        //altera contador
                        counter = 1;
                    }//fim if
                }//fim if
                else
                {
                    //testar elemento da matriz
                    if (p_matrix->dados[x][y] != 0)
                    {
                        //altera contador
                        counter = 1;
                    }//fim if
                }//fim if
            }//fim for
        }//fim for
    }//fim else

    //retorno
    return (counter == 0);
}//fim test_matriz_ident

// ----------------------------------------- Metodos Principais

/**
Method00 - Nao faz nada
*/
void method00 ()
{
    //nao faza nada
}//fim method00 ()

/**
Method01 - Cria arranjo a com numeros aleatorios
*/
void method01 ()
{
    //definir dados
    int inferior = 0;
    int superior = 0;
    int quantidade = 0;
    arranjo* p_arranjo = NULL;

    //identificar
    IO_id ("ED10 - Exemplo 1011");

    //ler teclado
    inferior = IO_readint ("Entre com o limite inferior do intervalo: ");
    do
    {
        superior = IO_readint ("Entre com o limite superior do intervalo: ");
    }while (inferior >= superior);
    quantidade = IO_readint ("Entre com a quantidad de valores a serem gerados: ");

    //criar arranjo
    if (quantidade < 1 )
    {
        printf ("\n%s\n", "ERROR: quantidade invalida");
    }//fim if
    else
    {
        p_arranjo = new_array (quantidade);
    }//fim else

    //testar  p_arranjo
    if (p_arranjo != NULL || p_arranjo->posicao != -1)
    {
        //seed rand
        srand (time(NULL));
        
        //preencher arranjo
        for (int x=0;  x<quantidade; x++)
        {
            p_arranjo->dados[x] = random_int (inferior, superior);
        }//fim for

        //gravar arranjo em arquivo
        fprint_array (p_arranjo, "dados.txt");
    }//fim if

    //encerrar
    free_new_array (p_arranjo);
    IO_pause ("Aperte ENTER para continuar");   
}//fim method01 ()

/**
Method02 - Verifica se determinado valor se encontra em arranjo
*/
void method02 ()
{
    //definir dados
    int valor = 0;
    int tamanho = 0;
    arranjo* p_arranjo = NULL;

    //identificar
    IO_id ("ED09 - Exemplo 1012");

    //ler valor do teclado
    valor = IO_readint ("Entre com valor a ser procurado: ");

    //carregar arranjo de arquivo
    tamanho = fread_array_size ("dados.txt");
    p_arranjo = fread_array ("dados.txt", tamanho);

    //verificar se valor esta no arranjo
    if (search_array(p_arranjo, valor))
    {
        printf ("\n%d%s\n", valor, " esta entre os elementos do arranjo.");
    }//fim if
    else
    {
        printf ("\n%d%s\n", valor, " NAO esta entre os elementos do arranjo.");
    }//fim else

    //encerrar
    free_new_array (p_arranjo);
    IO_pause ("Aperte ENTER para continuar");

}//fim method02 ()

/**
Method03 - Compara dois arranjos
*/
void method03 ()
{
    //definir dados
    arranjo* p_arranjo1 = NULL;
    arranjo* p_arranjo2 = NULL;
    int tamanho1 = 0;
    int tamanho2 = 0;
    //identificar
    IO_id ("ED09 - Exemplo 1013");

    //carregar arranjos
    tamanho1 = fread_array_size ("dados1.txt");
    p_arranjo1 = fread_array ("dados1.txt", tamanho1);
    tamanho2 = fread_array_size ("dados2.txt");
    p_arranjo2 = fread_array ("dados2.txt", tamanho2);

    //comparar arranjos
    if (compare_arrays(p_arranjo1, p_arranjo2))
    {
        printf ("\n%s\n", "Arranjos sao iguais");
    }//fim if
    else
    {
        printf ("\n%s\n", "Arranjos sao diferentes");
    }//fim else
    
    //encerar
    free_new_array (p_arranjo1);
    free_new_array (p_arranjo2);
    IO_pause ("Aperte ENTER para continuar");

}//fim method03 ()

/**
Method04 - 
*/
void method04 ()
{
    //definir dados
    arranjo* p_arranjo1 = NULL;
    arranjo* p_arranjo2 = NULL;
    arranjo* p_arranjo_soma = NULL;
    int tamanho1 = 0;
    int tamanho2 = 0;
    int constante = -1;
    //identificar
    IO_id ("ED09 - Exemplo 1014");

    //carregar arranjos
    tamanho1 = fread_array_size ("dados4.txt");
    p_arranjo1 = fread_array ("dados4.txt", tamanho1);
    tamanho2 = fread_array_size ("dados5.txt");
    p_arranjo2 = fread_array ("dados5.txt", tamanho2);

    //somar arranjos
    p_arranjo_soma = sum_arrays(p_arranjo1, p_arranjo2, constante);
    
    //mostrar arranjos
    print_array (p_arranjo1);
    print_array (p_arranjo2);
    print_array (p_arranjo_soma);

    //encerar
    free_new_array (p_arranjo1);
    free_new_array (p_arranjo2);
    free_new_array (p_arranjo_soma);
    IO_pause ("Aperte ENTER para continuar");
}//fim method04 ()

/**
Method05 - Verifica se arranjo esta em ordem crescente
*/
void method05 ()
{
    //definir dados
    int tamanho = 0;
    arranjo* p_arranjo = NULL;

    //identificar
    IO_id ("ED09 - Exemplo 1015");

    //carregar arranjo de arquivo
    tamanho = fread_array_size ("dados5.txt");
    p_arranjo = fread_array ("dados5.txt", tamanho);

    //verificar se arranjo esta ordenado
    if (sorted_array(p_arranjo))
    {
        printf ("\n%s\n", "Arranjo esta em ordem crescente.");
    }//fim if
    else
    {
        printf ("\n%s\n", " Arranjo NAO esta em ordem crescente.");
    }//fim else

    //encerrar
    free_new_array (p_arranjo);
    IO_pause ("Aperte ENTER para continuar");

}//fim method05 ()

/**
Method06 - Le matriz de arquivo e mostra matriz transposta
*/
void method06 ()
{
    //definir dados
    matriz* p_matrix = NULL;
    matriz* p_transposta = NULL;
    int linhas = 0;
    int colunas = 0;

    //identificar
    IO_id ("ED10 - Exemplo 1016");

    //ler dimensoes da matriz de arquivo
    fread_matrix_dimensions("matriz1.txt", &linhas, &colunas);

    //testar dimensoes validas
    if (linhas < 1 || colunas < 1)
    {
        printf ("\n%s\n", "ERROR: method06 ()");
    }//fim if
    else
    {
        //ler matriz de arquivo
        p_matrix = fread_matrix("matriz1.txt", linhas, colunas);

        //transpor matriz
        p_transposta = transp_matrix(p_matrix);

        //testar p_transposta
        if (p_transposta == NULL)
        {
            printf ("\n%s\n", "ERROR: method06 ()");
        }//fim fi
        else
        {
            //mostrar matrizes
            print_matrix(p_matrix);
            print_matrix(p_transposta);
        }//fim else
    }//fim else   

    //encerrar
    free_matrix (p_matrix);
    free_matrix (p_transposta);
    IO_pause ("Aperte ENTER para continuar");
}//fim method06 ()

/**
Method07 - Testa se todos elementos da matriz iguais a zero
*/
void method07 ()
{
    //definir dados
    matriz* p_matrix = NULL;
    int linhas = 0;
    int colunas = 0;

    //identificar
    IO_id ("ED10 - Exemplo 1017");

    //ler dimensoes da matriz de arquivo
    fread_matrix_dimensions("matriz2.txt", &linhas, &colunas);

    //testar dimensoes validas
    if (linhas < 1 || colunas < 1)
    {
        printf ("\n%s\n", "ERROR: method07 ()");
    }//fim if
    else
    {
        //ler matriz de arquivo
        p_matrix = fread_matrix("matriz2.txt", linhas, colunas);

        //mostrar matriz
        print_matrix(p_matrix);

        //testar matriz
        if (test_matrix_zero(p_matrix))
        {
            printf ("\n%s\n", "Todos valores da matriz IGUAIS a zero");        
        }//fim if
        else
        {
            printf ("\n%s\n", "Matriz tem valores DIFERENTES de zero");        

        }//fim else
    }//fim else   

    //encerrar
    free_matrix (p_matrix);
    IO_pause ("Aperte ENTER para continuar");
}//fim method07 ()

/**
Method08 - Testa se duas matrizes sao iguais
*/
void method08 ()
{
    //definir dados
    matriz* p_matrix1 = NULL;
    matriz* p_matrix2 = NULL;
    int linhas1 = 0;
    int colunas1 = 0;
    int linhas2 = 0;
    int colunas2 = 0;

    //identificar
    IO_id ("ED10 - Exemplo 1018");

    //ler dimensoes das matrizes de arquivo
    fread_matrix_dimensions("matriz2.txt", &linhas1, &colunas1);
    fread_matrix_dimensions("matriz3.txt", &linhas2, &colunas2);

    //testar dimensoes validas
    if (linhas1 < 1 || colunas1 < 1 || linhas2 < 1 || colunas2 < 1)
    {
        printf ("\n%s\n", "ERROR: method08 ()");
    }//fim if
    else
    {
        //ler matrizes de arquivo
        p_matrix1 = fread_matrix("matriz2.txt", linhas1, colunas1);
        p_matrix2 = fread_matrix("matriz3.txt", linhas2, colunas2);

        //mostrar matrizes
        print_matrix(p_matrix1);
        print_matrix(p_matrix2);

        //testar matrizes
        if (test_matrix_equal(p_matrix1, p_matrix2))
        {
            printf ("\n%s\n", "Matrizes sao IGUAIS");        
        }//fim if
        else
        {
            printf ("\n%s\n", "Matrizes DIFERENTES");        

        }//fim else
    }//fim else   

    //encerrar
    free_matrix (p_matrix1);
    free_matrix (p_matrix2);
    IO_pause ("Aperte ENTER para continuar");
}//fim method08 ()

/**
Method09 - Somas duas matrizes a segunda escalonada por constante
*/
void method09 ()
{
    //definir dados
    matriz* p_matrix1 = NULL;
    matriz* p_matrix2 = NULL;
    matriz* p_matrix_soma = NULL;
    int linhas1 = 0;
    int colunas1 = 0;
    int linhas2 = 0;
    int colunas2 = 0;
    int constante = -2;

    //identificar
    IO_id ("ED10 - Exemplo 1019");

    //ler dimensoes das matrizes de arquivo
    fread_matrix_dimensions("matriz.txt", &linhas1, &colunas1);
    fread_matrix_dimensions("matriz.txt", &linhas2, &colunas2);

    //testar dimensoes validas
    if (linhas1 < 1 || colunas1 < 1 || linhas2 < 1 || colunas2 < 1)
    {
        printf ("\n%s\n", "ERROR: method09 ()");
    }//fim if
    else
    {
        //ler matrizes de arquivo
        p_matrix1 = fread_matrix("matriz.txt", linhas1, colunas1);
        p_matrix2 = fread_matrix("matriz.txt", linhas2, colunas2);

        //mostrar matrizes
        print_matrix(p_matrix1);
        print_matrix(p_matrix2);

        //somar matrizes
        p_matrix_soma = sum_matrix (p_matrix1, p_matrix2, constante);
        
        //testar matriz somada
        if (p_matrix_soma != NULL)
        {
            //mostrar matriz
            printf ("\n%s%d:\n", "Matriz somada com a segunda escalonada por ", constante);
            print_matrix(p_matrix_soma);
        }//fim if
    }//fim else   

    //encerrar
    free_matrix (p_matrix1);
    free_matrix (p_matrix2);
    free_matrix (p_matrix_soma);
    IO_pause ("Aperte ENTER para continuar");
}//fim method09 ()

/**
Method10 - Multiplica duas matrizes
*/
void method10 ()
{
    //definir dados
    matriz* p_matrix1 = NULL;
    matriz* p_matrix2 = NULL;
    matriz* p_matrix_mult = NULL;
    int linhas1 = 0;
    int colunas1 = 0;
    int linhas2 = 0;
    int colunas2 = 0;

    //identificar
    IO_id ("ED10 - Exemplo 1020");

    //ler dimensoes das matrizes de arquivo
    fread_matrix_dimensions("matriz4.txt", &linhas1, &colunas1);
    fread_matrix_dimensions("matriz5.txt", &linhas2, &colunas2);

    //testar dimensoes validas
    if (linhas1 < 1 || colunas1 < 1 || linhas2 < 1 || colunas2 < 1)
    {
        printf ("\n%s\n", "ERROR: method10 ()");
    }//fim if
    else
    {
        //ler matrizes de arquivo
        p_matrix1 = fread_matrix("matriz4.txt", linhas1, colunas1);
        p_matrix2 = fread_matrix("matriz5.txt", linhas2, colunas2);

        //mostrar matrizes
        print_matrix(p_matrix1);
        print_matrix(p_matrix2);

        //multiplicar matrizes
        p_matrix_mult = mult_matrix (p_matrix1, p_matrix2);
        
        //testar matriz multiplicada
        if (p_matrix_mult != NULL)
        {
            //mostrar matriz
            printf ("\n%s\n", "Matriz multiplicada:");
            print_matrix(p_matrix_mult);
        }//fim if
    }//fim else   

    //encerrar
    free_matrix (p_matrix1);
    free_matrix (p_matrix2);
    free_matrix (p_matrix_mult);
    IO_pause ("Aperte ENTER para continuar");
}//fim method10 ()

/**
Method11 -
*/
void method11 ()
{
    //definir dados
    int tamanho = 0;
    arranjo* p_arranjo = NULL;

    //identificar
    IO_id ("ED09 - Exemplo 10E1");

    //carregar arranjo de arquivo
    tamanho = fread_array_size ("dados1.txt");
    p_arranjo = fread_array ("dados1.txt", tamanho);

    //verificar p_arranjo
    if (p_arranjo == NULL)
    {
        printf ("\n%s\n", "ERROR: method11 ()");
    }//fim if
    else
    {
        //mostrar arranjo
        printf ("\n%s\n", "Arranjo original:");        
        print_array (p_arranjo);

        //ordenar arranjo
        sort_array (p_arranjo);

        //mostrar arranjo ordenado
        printf ("\n%s\n", "Arranjo ordenado:");
        print_array (p_arranjo);
    }//fim else

    //encerrar
    free_new_array (p_arranjo);
    IO_pause ("Aperte ENTER para continuar");
}//fim method11 ()

/**
 * Method12 - 
*/
void method12 ()
{
    //definir dados
    matriz* p_matrix1 = NULL;
    matriz* p_matrix2 = NULL;
    matriz* p_matrix_mult = NULL;
    int linhas1 = 0;
    int colunas1 = 0;
    int linhas2 = 0;
    int colunas2 = 0;

    //identificar
    IO_id ("ED10 - Exemplo 10E2");

    //ler dimensoes das matrizes de arquivo
    fread_matrix_dimensions("matriz4.txt", &linhas1, &colunas1);
    fread_matrix_dimensions("matriz6.txt", &linhas2, &colunas2);

    //testar dimensoes validas
    if (linhas1 < 1 || colunas1 < 1 || linhas2 < 1 || colunas2 < 1)
    {
        printf ("\n%s\n", "ERROR: method12 ()");
    }//fim if
    else
    {
        //ler matrizes de arquivo
        p_matrix1 = fread_matrix("matriz4.txt", linhas1, colunas1);
        p_matrix2 = fread_matrix("matriz6.txt", linhas2, colunas2);

        //mostrar matrizes
        print_matrix(p_matrix1);
        print_matrix(p_matrix2);

        //multiplicar matrizes
        p_matrix_mult = mult_matrix (p_matrix1, p_matrix2);
        
        //testar matriz multiplicada
        if (p_matrix_mult != NULL)
        {
            //mostrar matriz
            printf ("\n%s\n", "Matriz multiplicada:");
            print_matrix(p_matrix_mult);
        }//fim if

        //testar se produto igual a matriz identidade
        if (test_matrix_ident (p_matrix_mult))
        {
            printf ("\n%s\n", "Matriz multiplicada IGUAL matriz identidade");
        }//fim if
        else
        {
            printf ("\n%s\n", "Matriz multiplicada DIFERENTE de matriz identidade");

        }//fim else
    }//fim else   

    //encerrar
    free_matrix (p_matrix1);
    free_matrix (p_matrix2);
    free_matrix (p_matrix_mult);
    IO_pause ("Aperte ENTER para continuar");
}//fim method12 ()

/**
Funcao Principal - Apresenta menu de escolhas de metodos
*/

int main ()
{
    //definir dados
    int x = 0;

    //apresentar menu
    do
    {
        //identidicar
        printf ("\n");
        IO_id ("ED10 - Exemplos 1011 - 10E2");

        //opcoes
        IO_println ("Opcoes:");
        IO_println ("0- Sair");
        IO_println ("1- Gerar N numeros aleatorios e armazena-los em arranjo e arquivo");
        IO_println ("2- Verifica se valor esta entre elementos do arranjo");
        IO_println ("3- Compara dois arranjos");
        IO_println ("4- Soma dois arranjos com segundo escalada por constante");
        IO_println ("5- Verifica se arranjo esta em ordem crescente");
        IO_println ("6- Le matriz de arquivo e mostra sua transposta");
        IO_println ("7- Testa se matriz so contem valores iguais a zero");
        IO_println ("8- Testa se duas matrizes sao iguais");
        IO_println ("9- Soma duas matrizes");
        IO_println ("10- Multiplica duas matrizes");
        IO_println ("11- Organiza um arranjo em ordem crescente");
        IO_println ("12- Testa se o produto de duas matrizes igual identidade");


        //ler teclado
        x = IO_readint ("Escolha uma das opcoes:");

        //chamar metodo de acordo com opcao
        switch (x)
        {
            case 0:
            method00 ();
            break;

            case 1:
            method01 ();
            break;

            case 2:
            method02 ();
            break;

            case 3:
            method03 ();
            break;

            case 4:
            method04 ();
            break;

            case 5:
            method05 ();
            break;            

            case 6:
            method06 ();
            break;

            case 7:
            method07 ();
            break;

            case 8:
            method08 ();
            break;

            case 9:
            method09 ();
            break;            

            case 10:
            method10 ();
            break;

            case 11:
            method11 ();
            break;

            case 12:
            method12 ();
            break;

            default:
            IO_pause ("Numero Invalido");
        }
                
    } while (x!=0); //fim while
    
    //encerrar
    IO_pause ("Aperte ENTER para terminar");

    //retorno
    return (0);

}//fim main

/*
------------------------------------Comentarios
Main:   
    v1- funcionou como esperado

method01:
    v1- numeros gerados todos iguais a zero ou completamente errados
        loop for de preencher arranjo usando variavel errada [quantidade]
        ao inves de [x];
    v2- funcionou como esperado

method02:
    v1- nao encontrou qualque valor
        teste do for dentro de search_array errado, nem entreva no loop.
    v2- funcinou como esperado

method03:
    v1- funcionou como esperado

method04:
    v1- funcionou como esperado

method05:
    v1- funcionou com esperado

method06:
    v1- erro ao guardar valores lidos do arquivo
        condicao do loop for de fread_matrix () errada || -> certa &&
    v2- funcionou como esperado

method07:
    v1- funcionou como esperado

method08:
    v1- funcionou como esperado

method09:
    v1- funcionou como esperado

method10:
    v1- funcionou como esperado

method11:
    v1- funcionou como esperado

method12:
    v1- funcinou como esperado

------------------------------------Testes
method01:   10 100 10;
            -10 20 10;

method02:   51 92 100

method03:   dados1.txt dados2.txt
            dados1.txt dados.txt
            dados2.txt dados3.txt

method04:   dados.txt dados2.txt
            dados4.txt dados5.txt

method05:   dados.txt
            dados4.txt

method06:   matriz.txt
            matriz1.txt

method07:   matriz2.txt

method08:   matriz1.txt matriz1.txt
            matriz.txt matriz2.txt

method09:   matriz1.txt matriz2.txt
            matriz.txt matriz3.txt

method10:   matriz4.txt matriz5.txt
            matriz5.txt matriz4.txt

method11:   dados1.txt

method12:   matriz4.txt matriz5.txt
            matriz4.txt matriz6.txt
*/
