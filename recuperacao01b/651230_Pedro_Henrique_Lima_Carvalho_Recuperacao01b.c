/*
PUC - Minas
Ciencia da Computacao
AED 1
Recuperacao 2
Aluno: Pedro Henrique Lima Carvalho
Matricula: 651230
*/

//dependencias
#include "io.h"

/**
Method00 - Nao faz nada
*/
void method00 ()
{
    //nao faza nada
}//fim method00 ()

/**
f_divisores - calcula quantos sao os divisores de um numero inteiro
@param numero
@return quantidade de divisores
*/
int f_divisores (int n)
{
    //definir dados
    int resultado = 0;

    //verificar divisores
    for (int x = 1; x <= n; x++)
    {
        //testar se x divisor de n
        if (n%x == 0)
        {
            //atualizar resultado
            resultado = resultado + 1;
        }//fim if
    }//fim for

    //retorno
    return (resultado);
}//fim f_divisores()

/**
Method01 -
*/
void method01 ()
{
    //definir dados
    int quant_menor = 2147483647;
    int quant_maior = 0;
    int divisores;
    int numero = 0;
    FILE* dados = fopen ("DADOS.TXT", "rt");
    FILE* resultados = fopen ("RESULTADO.TXT", "wt");

    //identificar
    IO_id ("Recuperacao 2 - Exercicio 1");

    //testar arquivo
    if (dados == NULL)
    {
        printf ("\n%s\n", "Erro ao abrir arquivo");
    }//fim if
    else
    {
        //ler primeiro numero
        fscanf (dados, "%d", &numero);

        //repetir ate 0
        while (numero != 0)
        {
            //verificar quantidade de divisores
            divisores = f_divisores (numero);

            //testar quantidade
            if (quant_menor >= divisores)
            {
                quant_menor = divisores;
            }//fim if
            if (quant_maior <= divisores)
            {
                quant_maior = divisores;
            }//fim if

            //ler proximo numero
            fscanf (dados, "%d", &numero);
        }//fim while

        //mover cursor para comeco
        fseek (dados, 0, SEEK_SET);

        //ler primeiro numero
        fscanf (dados, "%d", &numero);

        //repetir ate 0
        while (numero != 0)
        {
            //verificar quantidade de divisores
            divisores = f_divisores (numero);

            //testar se quantidade igual maior ou menor
            if (quant_menor == divisores || quant_maior == divisores)
            {
                //escrever numero em arquivo
                fprintf (resultados, "%d\n", numero);
            }//fim if

            //ler proximo numero
            fscanf (dados, "%d", &numero);
        }//fim while
    }//fim else
    
    //encerrar
    fclose (dados);
    fclose (resultados);
    IO_pause ("Aperte ENTER para continuar");

}//fim method01 ()

/**
soma_divisores - soma todos os divisores de um numero excluido ele mesmo
@param numero
@return soma dos divisores excluido ele mesmo
*/
int soma_divisores (int n)
{
    //definir dados
    int soma = 0;

    //passar por todos numeros ate n
    for (int x = 1; x < n; x++)
    {
        //testar se x divisor de n
        if (n%x == 0)
        {
            //somar x
            soma = soma + x;
        }//fim if
    }//fim for

    //retorno
    return (soma);
}//fim soma_divisores

/**
perfeito - verifica se um numero e' perfeito
@param n
@return verdadeiro se perfeito, caso contrario falso
*/
bool perfeito (int n)
{
    //retorno
    return (n == soma_divisores(n));
}//fim perfeito


/**
Method02 - 
*/
void method02 ()
{
    //definir dados
    int quantidade = 0;
    int numero = 0;
    FILE* arquivo = fopen ("PERFEITOS.TXT", "wt");

    //identificar 
    IO_id ("Recuperacao 2 - Exercicio 2");

    //gravar 0 na quantidade (placeholder)
    fprintf (arquivo, "%d\n", quantidade);

    //passar pelo intervalo
    for (int x = 1000; x<10000; x++)
    {
        //verificar se numero e' perfeito
        if (perfeito(x))
        {
            //atualizar quantidade
            quantidade = quantidade + 1;

            //gravar numero perfeito
            fprintf (arquivo, "%d\n", x);
        }//fim if
    }//fim for

    //voltar cursor para inicio
    fseek (arquivo, 0, SEEK_SET);

    //gravar quantidade
    fprintf (arquivo, "%d", quantidade);

    //encerrar
    fclose (arquivo);
    IO_pause ("Aperte ENTER para continuar");
}//fim method02 ()

/**
mdc - calcula o maximo divisor comum de dois numeros
@param dois numeros
@return maximo divisor comum
*/
int mdc (int x, int y)
{
    //definir dados
    int divisor = 0;

    //passar por todos os numeros ate x
    for (int z=1; z<x; z++)
    {
        //testar se z divisor de x e y
        if (x%z==0 && y%z==0)
        {
            //atualizar divisor maximo
            divisor = z;
        }//fim if
    }//fim for

    //retorno 
    return (divisor);
}//fim mdc

/**
Method03 - 
*/
void method03 ()
{
    //definir dados
    FILE* arquivo = fopen("NUMEROS.TXT", "rt");
    int divisor = 0;
    int n1 = 0;
    int n2 = 0;

    //identificar 
    IO_id ("Recuperacao 2 - Exercicio 3");

    //testar arquivo 
    if (arquivo == NULL)
    {
        printf ("%s\n", "Erro ao abrir arquivo");
    }//fim if
    else
    {
        //ler numeros
        fscanf (arquivo, "%d", &n1);
        fscanf (arquivo, "%d", &n2);

        //verificar mdc
        divisor = mdc (n1, n2);

        //mostrar resultado
        printf ("n1 %d\nn2: %d\nmdc: %d\n", n1, n2, divisor);
    }//fim else

    //encerrar
    fclose (arquivo);
    IO_pause ("Aperte ENTER para continuar");

}//fim method03 ()

/**
mmc - calcula o minimo multiplo comum de dois numeros
@param dois numeros
@return minimo multiplo comum
*/
int mmc (int x, int y)
{
    //definir dados
    int multiplo = 0;
    int teste = 0;

    //atribuir x a teste
    teste = x;

    //testar ate achar mmc
    while (multiplo == 0)
    {
        //testar se z divisor de x e y
        if (teste%x==0 && teste%y==0)
        {
            //estabelecer mmc
            multiplo = teste;
        }//fim if

        //aumentar teste
        teste = teste + 1;
    }//fim for

    //retorno 
    return (multiplo);
}//fim mmc

/**
Method04 - 
*/
void method04 ()
{
    //definir dados
    FILE* arquivo = fopen("NUMEROS.TXT", "rt");
    int multiplo = 0;
    int n1 = 0;
    int n2 = 0;

    //identificar 
    IO_id ("Recuperacao 2 - Exercicio 4");

    //testar arquivo 
    if (arquivo == NULL)
    {
        printf ("%s\n", "Erro ao abrir arquivo");
    }//fim if
    else
    {
        //ler numeros
        fscanf (arquivo, "%d", &n1);
        fscanf (arquivo, "%d", &n2);

        //verificar mdc
        multiplo = mmc (n1, n2);

        //mostrar resultado
        printf ("n1 %d\nn2: %d\nmmc: %d\n", n1, n2, multiplo);
    }//fim else

    //encerrar
    fclose (arquivo);
    IO_pause ("Aperte ENTER para continuar");
}//fim method04 ()

/**
f_substring - retorna uma substring com os n primeros
caracteres de uma string
@param string e n
@return substring
*/
char* f_substring (char* string, int n)
{
    //definir dados
    char* substring = NULL;
    int size = 0;

    //testar dados
    if (string == NULL)
    {
        printf ("%s\n", "Erro: String NULL");
    }//fim if
    else
    {
        //verificar tamanho string
        size = strlen (string);

        //retirar quebra de pagina
        if (string[size-1] == '\n')
        {
            string[size-1] ='\0';
            size = strlen (string);
        }//fim if

        //aloca memoria para substring
        substring = (char*) malloc (sizeof(char) * (n+1));

        //testar substring
        if (substring == NULL)
        {
            printf ("%s\n", "Erro: Substring NULL");
        }//fim if
        else
        {
            //copia os n primeiros digitos para substring
            for (int x=0; x<n && x<size; x++)
            {
                substring[x] = string[x];
                substring[x+1] = '\0';
            }//fim for
        }//fim else
    }//fim if
    
    //retorno
    return (substring);
}//fim f_substring

/**
print_string - mostra string na tela
@param string
*/
void print_string (char* string)
{
    //testar string
    if (string == NULL)
    {
        printf( "%s", "Erro: String NULL");
    }//fim if
    else
    {
        //mostrar string
        printf ("\n");
        for (int x=0; x<strlen(string); x++)
        {
            printf ("%c", string[x]);
        }//fim for
        printf ("\n");
    }//fim else
}//fim print_string

/**
Method05 - 
*/
void method05 ()
{
    //definir dados
    FILE* arquivo = fopen ("FRASES.TXT", "rt");
    char* string = NULL;
    char* substring = NULL;
    int n = 0;

    //identificar
    IO_id ("Recuperacao 2 - Exercicio 5");

    //alocar memoria para string
    string = (char*) malloc (sizeof(char) * (STR_SIZE+1));
    
    //ler n do teclado
    n = IO_readint ("Entre com valor de N: ");

    //testar dados
    if (string == NULL || n < 1)
    {
        printf ("%s", "ERROR: String NULL ou N invalido");
    }//fim if
    else
    {
        //ler primeira frase do arquivo
        fgets (string, STR_SIZE - 1, arquivo);

        //repetir ate fim do arquivo
        while (!feof(arquivo)) 
        {
            //chamar f_substring
            substring = f_substring (string, n);

            //mostrar substring
            print_string (substring);

            //ler proxima frase do arquivo
            fgets (string, STR_SIZE - 1, arquivo);

        }//fim while
    }//fim else

    //encerrar
    free (string);
    free (substring);
    IO_pause ("Aperte ENTER para continuar");
    
}//fim method05 ()

/**
f_substring2 - retorna uma substring com os n ultimos
caracteres de uma string
@param string e n
@return substring
*/
char* f_substring2 (char* string, int n)
{
    //definir dados
    char* substring = NULL;
    int size = 0;

    //testar dados
    if (string == NULL)
    {
        printf ("%s\n", "Erro: String NULL");
    }//fim if
    else
    {
        //verificar tamanho string
        size = strlen (string);

        //retirar quebra de pagina
        if (string[size-1] == '\n')
        {
            string[size-1] = '\0';
            size = strlen(string);
        }//fim if

        //aloca memoria para substring
        substring = (char*) malloc (sizeof(char) * (size));

        //testar substring
        if (substring == NULL)
        {
            printf ("%s\n", "Erro: Substring NULL");
        }//fim if
        else
        {
            //fechar substring caso n >= size
            substring[0] = '\0';
            
            //copia os n primeiros digitos para substring
            for (int x=n, y=0; x < size && y<size-n; x++, y++)
            {
                substring[y] = string[x];
                substring[y+1] = '\0';
            }//fim for    
        }//fim else
    }//fim if
    
    //retorno
    return (substring);
}//fim f_substring2

/**
Method06 - 
*/
void method06 ()
{
    //definir dados
    FILE* arquivo = fopen ("FRASES.TXT", "rt");
    char* string = NULL;
    char* substring = NULL;
    int n = 0;

    //identificar
    IO_id ("Recuperacao 2 - Exercicio 6");

    //alocar memoria para string
    string = (char*) malloc (sizeof(char) * (STR_SIZE+1));
    
    //ler n do teclado
    n = IO_readint ("Entre com valor de N: ");

    //testar dados
    if (string == NULL || n < 0)
    {
        printf ("%s", "ERROR: String NULL ou N invalido");
    }//fim if
    else
    {
        //ler primeira frase do arquivo
        fgets (string, STR_SIZE - 1, arquivo);
        
        //repetir ate fim do arquivo
        while (!feof(arquivo)) 
        {
            //chamar f_substring
            substring = f_substring2 (string, n);

            //mostrar substring    
            print_string (substring);

            //ler proxima frase do arquivo
            fgets (string, STR_SIZE - 1, arquivo);
        }//fim while
    }//fim else

    //encerrar
    free (string);
    free (substring);
    IO_pause ("Aperte ENTER para continuar");
}//fim method06 ()

/**
lastchar - retorna o ultimo caractere de uma string
@param string
@return char
*/
char lastchar (char* string)
{
    //definir dados
    char last = '-';
    int size = 0;

    //testar dados
    if (string == NULL)
    {
        printf ("%s\n", "Erro: String NULL");
    }//fim if
    else
    {
        //verificar tamanho string
        size = strlen (string);

        //retirar quebra de pagina
        if (string[size-1] == '\n')
        {
            string[size-1] = '\0';
            size = strlen(string);
        }//fim if

        //copiar ultimo caractere
        last = string[size-1];
    }//fim if
    
    //retorno
    return (last);
}//fim lastchar

/**
Method07 - 
*/
void method07 ()
{
    //definir dados
    FILE* arquivo = fopen ("FRASES.TXT", "rt");
    char* string = NULL;
    char last = '-';
    int n = 0;

    //identificar
    IO_id ("Recuperacao 2 - Exercicio 7");

    //alocar memoria para string
    string = (char*) malloc (sizeof(char) * (STR_SIZE+1));
    
    //ler n do teclado
    n = IO_readint ("Entre com valor de N: ");

    //testar dados
    if (string == NULL || n < 1)
    {
        printf ("%s", "ERROR: String NULL ou N invalido");
    }//fim if
    else
    {
        //ler primeira frase do arquivo
        fgets (string, STR_SIZE - 1, arquivo);
        
        //repetir ate fim do arquivo
        while (!feof(arquivo) && n>0) 
        {
            //diminuir n
            n = n - 1;

            //chamar f_substring
            last = lastchar (string);

            //mostrar lastchar    
            printf("%c\n", last);

            //ler proxima frase do arquivo
            fgets (string, STR_SIZE - 1, arquivo);
        }//fim while
    }//fim else

    //encerrar
    free (string);
    IO_pause ("Aperte ENTER para continuar");
}//fim method07 ()

/**
minuslast - retorna uma substring com todos os caracteres
menos o ultimo
@param string
@return substring
*/
char* minuslast (char* string)
{
    //definir dados
    char* substring = NULL;
    int size = 0;

    //testar dados
    if (string == NULL)
    {
        printf ("%s\n", "Erro: String NULL");
    }//fim if
    else
    {
        //verificar tamanho string
        size = strlen (string);

        //retirar quebra de pagina
        if (string[size-1] == '\n')
        {
            string[size-1] ='\0';
            size = strlen (string);
        }//fim if

        //aloca memoria para substring
        substring = (char*) malloc (sizeof(char) * (size));

        //testar substring
        if (substring == NULL)
        {
            printf ("%s\n", "Erro: Substring NULL");
        }//fim if
        else
        {
            //copia os n primeiros digitos para substring
            for (int x=0; x<size-1; x++)
            {
                substring[x] = string[x];
                substring[x+1] = '\0';
            }//fim for
        }//fim else
    }//fim if
    
    //retorno
    return (substring);
}//fim minuslast

/**
Method08 - 
*/
void method08 ()
{
    //definir dados
    FILE* arquivo = fopen ("FRASES.TXT", "rt");
    char* string = NULL;
    char* substring = NULL;
    int n = 0;

    //identificar
    IO_id ("Recuperacao 2 - Exercicio 8");

    //alocar memoria para string
    string = (char*) malloc (sizeof(char) * (STR_SIZE+1));
    
    //ler n do teclado
    n = IO_readint ("Entre com valor de N: ");

    //testar dados
    if (string == NULL || n < 1)
    {
        printf ("%s", "ERROR: String NULL ou N invalido");
    }//fim if
    else
    {
        //ler primeira frase do arquivo
        fgets (string, STR_SIZE - 1, arquivo);
        
        //repetir ate fim do arquivo
        while (!feof(arquivo) && n>0) 
        {
            //diminuir n
            n = n - 1;

            //chamar f_substring
            substring = minuslast (string);

            //mostrar substring    
            print_string (substring);

            //ler proxima frase do arquivo
            fgets (string, STR_SIZE - 1, arquivo);
        }//fim while
    }//fim else

    //encerrar
    free (string);
    free (substring);
    IO_pause ("Aperte ENTER para continuar");
}//fim method08 ()

/**
paradecimal - converte um arranjo binario em numero decimal
@param arranjo e tamanho do arranjo
@return numero decimal
*/
int paradecimal (int arr[], int n)
{
    //decimal
    int decimal = 0;

    //repetir por todos itens do arranjo
    for (int x=0; x<n; x++)
    {
        decimal = decimal + arr[x]*( (int) pow(2.0, (x)) );
    }//fim for

    //retorno
    return (decimal);
}//fim paradecimal

/**
Method09 - 
*/
void method09 ()
{
    //definir dados
    int n = 0;
    int decimal = 0;

    //identificar
    IO_id ("Recuperacao 2 - Exercicio 9");

    //ler numero do teclado
    n = IO_readint ("Entre com a quantidade de numeros a serem lidos: ");

    //criar arranjo tamanho n
    int arr[n];

    //preencher arranjo
    for (int x=0; x<n; x++)
    {
        do
        {
            //ler valor binario do teclado
            printf ("%s%d: ", "Posicao do arranjo ", x);
            scanf ("%d", &arr[x]);
        } while (arr[x] != 0 && arr[x] != 1);//fim while      
    }//fim for

    //obter decimal
    decimal = paradecimal (arr, n);

    //mostrar decimal
    printf ("%s%d", "Valor decimal: ", decimal);

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method09 ()

/**
inverte - inverte a ordem dos elementos de um arranjo
@param arranjo a ser invertido, arranjo destino e tamanho dos arranjos
*/
void inverte (int arr1[], int arr2[], int n)
{
    //copiar invertido
    for (int x=0; x<n; x++)
    {
        arr2[n-1-x] = arr1[x];
    }//fim for
}//fim inverte

/**
inverte_recursiva - inverte a ordem dos elementos de um arranjo
de forma recursiva
@param arranjo a ser invertido, arranjo destino, posicao de inicio e tamanho
*/
void inverte_recursiva (int arr1[], int arr2[], int p, int n)
{    
    //motor
    if (p < n)
    {
        //trocar elementos
        arr2[p] = arr1[n-1];
        arr2[n-1] = arr1[p];
        
        //chamada recursiva
        inverte_recursiva (arr1, arr2, p+1, n-1);
    }//fim if
}//fim inverte recursiva

/**
Method10 - 
*/
void method10 ()
{
    //definir dados
    int n = 0;
    FILE* entrada = fopen ("CRESCENTE.TXT", "rt");
    FILE* saida = fopen ("INVERTIDOS.TXT", "wt");

    //identificar
    IO_id ("Recuperacao 2 - Exercicio 10");

    //testar abertura do arquivo
    if (entrada == NULL)
    {
        printf ("%s\n", "Erro ao abrir arquivo");
    }//fim if
    else
    {
        //ler tamanho do arranjo do arquivo
        fscanf (entrada, "%d", &n);

        //testar tamanho
        if (n < 1)
        {
            printf ("%s", "Erro tamanho do arranjo no arquivo");
        }//fim if
        else
        {
            //criar arranjo
            int crescente[n];
            int invertido[n];

            //preencher arranjo
            for (int x=0; x<n && !feof(entrada); x++)
            {
                fscanf (entrada, "%d", &crescente[x]);
            }//fim for

            //chamar inverte
//            inverte (arr1, arr2, n);
            inverte_recursiva (crescente, invertido, 0, n);

            //gravar em arquivo invertido
            //gravar tamanho do arranjo
            fprintf (saida, "%d\n", n);

            //gravar elementos do arrajo
            for (int x=0; x<n; x++)
            {
                fprintf (saida, "%d\n", invertido[x]);
            }//fim for
        }//fim else
    }//fim else

    //encerrar
    fclose (entrada);
    fclose (saida);
    IO_pause ("Aperte ENTER para continuar");
}//fim method10 ()

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
        IO_id ("Recuperacao 2");

        //opcoes
        IO_println ("Opcoes:");
        IO_println ("0- Sair");
        IO_println ("1- Exercicio 1");
        IO_println ("2- Exercicio 2");
        IO_println ("3- Exercicio 3");
        IO_println ("4- Exercicio 4");
        IO_println ("5- Exercicio 5");
        IO_println ("6- Exercicio 6");
        IO_println ("7- Exercicio 7");
        IO_println ("8- Exercicio 8");
        IO_println ("9- Exercicio 9");
        IO_println ("10- Exercicio 10");

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
    v1- quant_menor nao pode comecar em 0. alterado para 2147483647.
    v2- funcionou como esperado

method02:
    v1- funcionou como esperado

method03:
    v1- funcinou como esperado

method04:
    v1- funcinou como esperado

method05:
    v1- loop infinito. faltou dentro do loop ler proxima frase;
    v2- funcionou como esperado

method06:
    v1- N maior que string = Substring NULL. Alterada a forma de alocacao da substring
    v2- funcinou como esperado

method07:
    v1- funcinou como esperado

method08:
    v1- funcinou como esperado

method09:
    v1- decimal retornando numero errado. for de leitura do teclado com lixo
    v2- funcinou como esperado

method10:
    v1- funcionou como esperado

------------------------------------Testes
method01:   DADOS.TXT

method02:   defaut

method03:   NUMEROS.TXT

method04:   NUMEROS.TXT

method05:   5, 15, 19

method06:   5, 15, 19

method07:   0, 1, 2, 3, 4, 5

method08:   0, 1, 2, 3, 4, 5

method09:   1, 0, 1, 1

method10:   CRESCENTE.TXT
*/
