/*
PUC - Minas
Ciencia da Computacao
AED 1
Refacao01a
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
    //nao faz nada
}//fim method00


/**
Method01 - Exercicio 1
*/

void method01 ()
{
    //definir dados
    int z = 0,
        y = 0,
        p = 0,
        x = 0;
    
    //ler teclado
    x = IO_readint ("Matricula: ");

    p=x;

    while (p>0)
    {
        if (p%10%2 != 0)
        {
            y = y + p%10/2;
        }
        else
        {
            z=z+ p%10;
        }
        p=p/10;
    }
    if (z-y>0)
    {
        printf("%s%d\n","a. resposta=", (z-y));
    }
    else
    {
        printf("%s%d\n", "b. resposta=", (10+y-z));
    }

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method01

/**
Method02a - Recebe uma quantidade n de termos como parametro
calcula e mostra a sequencia
1 2 5 6 10 11 15 16 20 21 25 26 35 36 40 41 45 46 50 51 55 65...
@param quantidade de termos
*/
void method02a (int n)
{
    //definir dados
    int termo = 0;
    int tentativa = 1;
    int contador_global = 1;   
    int contador_impares = 1;
    int contador_pares = 1;

    //repetir n vezes
    while (contador_global <= n)
    {
        //dois primeiros termos
        if (tentativa<3)
        {
            termo = tentativa;
            printf ("%d ", termo);
            //termo encontrado e mostrado atualiza contador_global
            contador_global = contador_global + 1;
        }

        //acima do segundo termo
        else
        {
            //tentativa impar
            if (tentativa%2 !=0)
            {
                //termo multiplo de 5
                termo = contador_impares * 5;
                contador_impares = contador_impares + 1; //atualiza contador_impar em cada tentativa impar
                
                //verifica se nao e' multiplo de 30
                if (termo%30 != 0)
                {
                    printf ("%d ", termo);
                    //termo encontrado e mostrado, atualiza contador_global
                    contador_global = contador_global + 1;
                }//fim if
            }//fim else

            //tentativa par
            else
            {
                //termo (multiplo de 5) + 1
                termo = (contador_pares * 5) + 1;
                contador_pares = contador_pares + 1; //atualiza contador_par em cada tentativa par
                
                //verifica se tentativa impar anterior nao era multiplo de 30
                //verifica se tentiva impar anterior  nao era multiplo de 55
                if ((termo-1)%30 !=0 && (termo-1)%55 !=0)
                {
                    printf ("%d ", termo);
                    //termo encontrado e mostrado, atualiza contador_global
                    contador_global = contador_global + 1;
                }
            }
        }
        //atualizar tentiva
        tentativa = tentativa + 1;
    }//fim while
}//fim method02a ()

/**
Method02b - Recebe uma quantidade n de termos como parametro
calcula e mostra a sequencia - Desenvolvendo a ideia comecada
na prova. Fazer atraves de modulos
1 2 5 6 10 11 15 16 20 21 25 26 35 36 40 41 45 46 50 51 55 65...
@param quantidade de termos
*/

void method02b (int n)
{
    //definir dados
    int termo = 0;
    int contador = 1;

    //dois primeiros termos fogem da regra
    if (n > 0)
    {
        termo = 1;
        printf ("%d ", termo);
        
        //diminui n em 1 pois ja mostrou um termo
        n = n - 1;
    }
    if (n > 0) // significa que n 'e maior que 1
    {
        termo = 2;
        printf ("%d ", termo);
        
        // diminui n em 1 pois ja mostrou outro termo
        n = n - 1;
    }
    //repeticao padrao
    while (n > 0) //significa que n 'e maior que 2 
    {
       // iguala termo a contador
       termo = contador;

       // condicoes da sequencia usando modulo
       if (((termo%10==5) || (termo%10==0)) && (termo%30!=0)) //exclui multiplos de 30
       {
           //mostra multiplos de 5
           printf ("%d ", termo);
           //diminui n em 1 pois ja mostrou outro termo
           n = n - 1;

           //para excluir os multiplos de 55 + 1 e caso n termine antes
           if (termo%55!=0 && n>0)
           {
               //mostra multiplos de 5 +1
               printf("%d ", termo + 1);
               //diminui n em 1 pois ja mostrou outro termo
               n = n - 1;
           }//fim if
       }//fim if
       
       //atualiza contador
       contador = contador + 1;
    }//fim while
}//method2b()

/**
Method02 - Exercicio 2
*/
void method02 ()
{
    //definir dados
    int n = 0;

    //identificar
    IO_id ("Refacao01a - Exercicio 2");

    //ler teclado confirmando
    do
    {
        n = IO_readint ("Entrar com valor inteiro:");
    } while (n<1);

    //chamar method02a e b
    printf ("%s\n", "Method02a:");
    method02a (n);
    printf ("\n%s\n", "Method02b:");
    method02b (n);

    //encerar
    IO_pause ("Aperte ENTER para continuar");
    
}//fim method02

/**separar - Trabalha uma cadeia de caracteres para separar
letras de digitos, primeiro as letras. Se nao houver letras
ou digitos, cadeia devera conter a mesma quantidade de simbolos
iguais a '-'
*/

char *separar (char* string)
{
    //definir dados
    char *letras = (char*) malloc (sizeof(char) * strlen (string));
    char *digitos = (char*) malloc (sizeof(char) * strlen(string));
    char *resposta = (char*) malloc (sizeof(char) * strlen(string));
    resposta [0] = '\0';
    int contadorletras = 0;
    int contadordigitos = 0;

    //testar parametro
    if (string != NULL)
    {
        for (int x = 0; x < strlen(string); x++)
        {
            //verificar letras e separa-las em outra string
            if (('a' <= string[x] && string[x] <= 'z') 
                || ('A' <= string [x] && string[x] <= 'Z'))
                {
                    letras[contadorletras] = string[x];
                    letras[contadorletras +1] = '\0'; //fechar string
                    contadorletras = contadorletras + 1;
                }//fim if
        
            //verificar digitos e separa-los em outras string
            if ('0' <= string[x] && string[x] <= '9')
            {
                digitos[contadordigitos] = string[x];
                digitos[contadordigitos+1] = '\0'; //fechar string
                contadordigitos = contadordigitos + 1;
            }//fim if
        }
        //se nao houver digitos nem letras, preenchar com '-'
        if (contadorletras == 0 && contadordigitos == 0)
        {
            for (int y = 0; y < strlen(string); y++)
            {   
                resposta[y] = '-';
                resposta[y+1]='\0';
            }//fim for
        }//fim if
        //se houver digitos ou letras, copiar e concatenar
        else
        {
            strcpy (resposta, letras);
            strcat (resposta, digitos);
        }//fim else
    }
    //encerrar
    free (letras);
    free (digitos);
    return (resposta);
}//fim separar

/** 
method3 - Exercicio 3
*/
void method03 ()
{
    //definir dados
    char *string = NULL;
    char *resposta = NULL;

    //identificar
    IO_id ("Refacao01a - Exercicio 3");

    //ler teclado
    string = IO_readstring ("Entre com uma cadeia de caracteres:");

    //chamar funcao
    resposta = separar (string);

    //mostrar resposta
    printf ("%s\n", resposta);

    //encerrar
    free(string);
    free(resposta);
    IO_pause ("Aperte ENTER para continuar");
}

int main ()
{
    //definir dados
    int x = 0;

    //identificar
    IO_id ("Refacao01a - Exercicios 01 - 03");

    //opcoes
    do
    {
        //mostrar opcoes
        IO_println ("Opcoes");
        IO_println ("0- Sair");
        IO_println ("1- Exercicio 1");
        IO_println ("2- Exercicio 2");
        IO_println ("3- Exercicio 3");

        //ler teclado
        x = IO_readint ("Escolha uma das opcoes:");

        //selecionar
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

            default:
            IO_pause ("Numero invalido");
        }

    } while (x!=0);//fim dowhile

    //encerrar
    IO_pause ("Aperte ENTER para encerrar");
    
}//fim main