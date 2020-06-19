/*
PUC - Minas
Ciencia da Computacao
AED 1
Aluno: Pedro Henrique Lima Carvalho
Matricula: 651230
Recuperacao 01a
*/

//definicoes
#include "io.h"

/**
Method00 - Nao faz nada
*/
void method00 ()
{
    //nao faza nada
}//fim method00 ()

/**
Method01 - Le um valor inteiro n do teclado para indicar uma quantidade
le a quantidade em valores inteiros do teclado testando:
se valor 'e negativo, zero, positivo, par ou impar 
*/
void method01 ()
{
    //definir dados
    int n = 0;
    int inteiro = 0;
    char c =' ';

    //identificar
    IO_id ("Recuperacao01a - Exercicio 01");

    //ler teclado para quantidade testando
    do
    {
        n = IO_readint ("Entre com a quantidade a ser lida:");
        if (n<1)
        {
            IO_pause ("Numero Invalido");
        }
    } while (n<1);
    
    //repetir n vezes
    for (int x = 0; x <n; x++)
    {
        //ler valor a ser testado
        inteiro = IO_readint ("Entre com inteiro a ser testado:");
        
        //testa se igual a zero
        if (inteiro == 0)
        {
            printf ("%s\n", "valor igual a zero");
        }//fim if
        //demais testes
        else
        {
            //testa se impar
            if (inteiro%2!=0)
            {
                //testa se postivo
                if (inteiro > 0)
                {
                    printf ("%s\n", "Valor positivo impar");
                }//fim if
                //else negativo
                else
                {
                    printf ("%s\n", "Valor negativo impar");
                }//fim else    
            }//fim if
            //else par
            else
            {
                //testa se postivo
                if (inteiro > 0)
                {
                    printf ("%s\n", "Valor positivo par");
                }//fim if
                //else negativo
                else
                {
                    printf ("%s\n", "Valor negativo par");
                }//fim else      
            }//fim else
        }//fim else
    }//fim for

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method01 ()

/**
Method02 - Le um valor inteiro n do teclado para indicar uma quantidade
Le a quantidade de valores inteiros do teclado
conta quantos sao negativos, positivos, pares impares ou iguais a zero
*/
void method02 ()
{
    //definir dados
    int n = 0;
    int inteiro = 0;
    int positivos = 0;
    int negativos = 0;
    int pares = 0;
    int impares = 0;
    int zeros = 0;
    int controle = 0;

    //identificar
    IO_id ("- Recuperacao01a - Exercicio 02");

    //ler teclado para quantidade testandi
    do
    {
        n = IO_readint ("Entre com a quantidade a ser lida:");
        if (n <1)
        {
            IO_pause ("Numero Invalido");
        }
    }while (n<1);

    //repetir n vezes
    for (int x = 0; x <n; x++)
    {
        //ler valor a ser testado
        inteiro = IO_readint ("Entre com inteiro a ser testado:");
        
        //testa se igual a zero
        if (inteiro == 0)
        {
            zeros = zeros + 1;
        }//fim if
        //demais testes
        else
        {
            //testa se impar atualizando contador
            if (inteiro%2!=0)
            {
                impares = impares + 1;
                
                //testa se postivo atualizando contador
                if (inteiro > 0)
                {
                    positivos = positivos + 1;
                }//fim if
                //else negativo atualiza contador
                else
                {
                    negativos = negativos + 1;
                }//fim else    
            }//fim if
            //else par atualiza contador
            else
            {
                pares = pares + 1;

                //testa se postivo atualizando contador
                if (inteiro > 0)
                {
                    positivos = positivos + 1;
                }//fim if
                //else negativo atualiza contador
                else
                {
                    negativos = negativos + 1;
                }//fim else      
            }//fim else
        }//fim else
    }//fim for

    //mostrar quantidade de cada tipo
    printf ("Zeros: %d, Pares: %d, Impares: %d, Negativos: %d, Positivos: %d\n",
                    zeros, pares, impares, negativos, positivos);
    
    //verificar qual e'a maior quantidade
    //repertir ate controle mudar
    while (controle == 0)
    {
        //compara quantidade em cada tipo com quantidade total
        if(zeros == n)
        {
            printf ("%s ", "zeros");
            controle = 1;
        }
        if (pares == n)
        {
            printf ("%s ", "pares");
            controle = 1;
        }
        if (impares == n)
        {
            printf ("%s ", "impares");
            controle = 1;
        }
        if (negativos == n)
        {
            printf ("%s ", "negativos");
            controle = 1;
        }
        if (positivos == n)
        {
            printf ("%s ", "positivos");
            controle = 1;
        }
        //se controle == 1 , finaliza
        if (controle == 1)
        {
            printf ("%s%d\n", "tem a maior quantidade: ", n);
        }
        //reduz n para tentar menores quantidades
        n = n - 1;    
    }//fim while

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method02 ()

/**
logico - Verifica se caractere 'e logico (& | !)
@param caractere
@return verdadeiro ou falso
*/
bool logico (char c)
{
    //definir dados
    bool teste = 0;

    // testar
    if (c=='&' || c=='|' || c=='!')
    {
        teste = 1;
    }
    //encerra
    return (teste);
}//fim logico

/**
aritmetico - Verifica se caractere 'e aritmetico (+ - * / %)
@param caractere
@return verdadeiro ou falso
*/
bool aritmetico (char c)
{
    //definir dados
    bool teste = 0;

    /// testar
    if (c=='+' || c=='-' || c=='*' || c=='/' || c=='%')
    {
        teste = 1;
    }
    //encerra
    return (teste);
}//fim aritmetico

/**
relacional - Verifica se caractere 'e relacional (> < =)
@param caractere
@return verdadeiro ou falso
*/
bool relacional (char c)
{
    //definir dados
    bool teste = 0;

    // testar
    if (c=='>' || c=='<' || c=='=')
    {
            teste = 1;
    }
    //encerra
    return (teste);
}//fim relacional

/**
separador - Verifica se caractere 'e separador (espaco . , ; : _)
@param caractere
@return verdadeiro ou falso
*/
bool separador (char c)
{
    //definir dados
    bool teste = 0;

    // testar
    if (c==' ' || c=='.' || c==',' || c==';' || c==':' || c=='_')
    {
        teste = 1;
    }
    //encerra
    return (teste);
}//fim separador

/**
Method03 - Le uma cadeia de caracteres e verifica cada um
dizendo se 'e operador logico (& | !), aritimetico (+ - * / %)
realcional (> < =), separadores(espaco ponto virgula ponto-e-vigula
dois-pontos, sublinha) ou outro caracter
*/
void method03 ()
{
    //definir dados
    char *cadeia = NULL;
    cadeia = (char*) malloc (sizeof(char) * STR_SIZE+1);

    //identificar
    IO_id ("Recuperacao01a - Exercicio 3");
    
    //vefirificar cadeia
    if (cadeia != NULL)
    {
        //fechar cadeia
        cadeia[0] = '\0';
        
        //ler teclado usando fgets para pegar espacos
        getchar (); //limpar stdin
        printf ("%s\n", "Entre com uma cadeia de caracteres:");
        fgets (cadeia, 80, stdin); //OS nao aceitou gets
        cadeia[strlen(cadeia)-1] = '\0'; //consertar fgets esta inserindo '\n' na cadeia

        //passar por cada caractere da cadeia testando
        for (int x = 0; x < strlen(cadeia); x++)
        {
            if (logico(cadeia[x]))
            {
                //se logico mostrar
                printf ("%c%s\n", cadeia[x], " 'e um operador logico");
            }//fim if
            else
            {
                if (aritmetico(cadeia[x]))
                {
                    //se aritmetico mostrar
                    printf ("%c%s\n", cadeia[x], " 'e um operador aritmetico");
                }//fim if
                else
                {
                    if (relacional(cadeia[x]))
                    {
                        //se relacional mostrar
                        printf ("%c%s\n", cadeia[x], " 'e um operador relacional");
                    }//fim if
                    else
                    {
                        if (separador(cadeia[x]))
                        {
                            //se separador mostrar
                            printf ("%c%s\n", cadeia[x], " 'e um operador separador");
                        }//fim if
                        else
                        {
                            //demais mostrar
                            printf ( "%c%s\n", cadeia[x], " 'e outro simbolo qualquer");
                        }//fim else
                    }//fim else
                }//fim else
            }//fim else
        }//fim for
    }//fim if 
    
    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method03 ()

/**
maiusculas - Verifica se caractere 'e letra maiuscula
@param caractere
@return verdadeiro ou falso
*/
bool maiuscula (char c)
{
    //definir dados
    bool teste = 0;

    // testar
    if ('A'<=c && c<='Z')
    {
        teste = 1;
    }
    //encerra
    return (teste);
}//fim maiuscula

/**
minuscula - Verifica se caractere 'e letra minuscula
@param caractere
@return verdadeiro ou falso
*/
bool minuscula (char c)
{
    //definir dados
    bool teste = 0;

    // testar
    if ('a'<=c && c<='z')
    {
        teste = 1;
    }
    //encerra
    return (teste);
}//fim minuscula

/**
digito - Verifica se caractere 'e digito
@param caractere
@return verdadeiro ou falso
*/
bool digito (char c)
{
    //definir dados
    bool teste = 0;

    // testar
    if ('0'<=c && c<='9')
    {
        teste = 1;
    }
    //encerra
    return (teste);
}//fim digito

/**
Method04 - Le uma cadeia de caracteres do teclado e verifica da um
contando separadamente se 'e letra maiuscula, minuscula, digitos, 
operadores ou separadores
*/
void method04 ()
{
    //definir dados
    char *cadeia = NULL;
    cadeia = (char*) malloc (sizeof(char) * STR_SIZE+1);
    int logicos = 0;
    int aritmeticos = 0;
    int relacionais = 0;
    int separadores = 0;
    int digitos = 0;
    int maiusculas = 0;
    int minusculas = 0;

    //identificar
    IO_id ("Recuperacao01a - Exercicio 4");
    
    //vefirificar cadeia
    if (cadeia != NULL)
    {
        //fechar cadeia
        cadeia[0] = '\0';
        
        //ler teclado usando fgets para pegar espacos
        getchar (); //limpar stdin
        printf ("%s\n", "Entre com uma cadeia de caracteres:");
        fgets (cadeia, 80, stdin); //OS nao aceitou gets
        cadeia[strlen(cadeia)-1] = '\0'; //consertar fgets esta inserindo '\n' na cadeia

        //testar cada caractere da cadeia
        for (int x = 0; x < strlen(cadeia); x++)
        {
            //somar se logico
            if (logico(cadeia[x]))
            {
                logicos = logicos + 1;
            }//fim if
            else
            {
                //somar se aritmetico
                if (aritmetico(cadeia[x]))
                {
                    aritmeticos = aritmeticos + 1;        
                }//fim if
                else
                {
                    //somar se relacional
                    if (relacional(cadeia[x]))
                    {
                        relacionais = relacionais + 1;
                    }//fim if
                    else
                    {
                        //somar se separador
                        if (separador(cadeia[x]))
                        {
                            separadores = separadores + 1;
                        }//fim if
                        else
                        {
                            //somar se maiuscula
                            if (maiuscula(cadeia[x]))
                            {
                                maiusculas = maiusculas + 1;
                            }//fim if
                            else
                            {
                                if (minuscula(cadeia[x]))
                                {
                                    minusculas = minusculas + 1;
                                }//fim if
                                else
                                {
                                    if (digito(cadeia[x]))
                                    {
                                        digitos = digitos + 1;
                                    }//fim if
                                }//fim else   
                            }//fim else 
                        }//fim else
                    }//fim else
                }//fim else
            }//fim else
        }//fim for
    }//fim if 
    
    //mostrar total
    printf ("A cadeia tem:\n%d maiusculas\n%d minusculas\n%d digitos\n%d logicos\n%d aritmeticos\n%d relacionais\n%d separadores",
            maiusculas, minusculas, digitos, logicos, aritmeticos, relacionais, separadores);
    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method04 ()

/**
Method05 - Le uma quantidade do teclado, le a quantidade
de valores reais do teclado, calcula e mostra media dos valores
<-32.75, [-32.75: 54.25], >54.35. Dizer a menor media
*/
void method05 ()
{
    //definir dados
    int n = 0;
    double valor = 0.0;
    double m_menores = 0.0;
    int menores = 0;
    double m_intervalo = 0.0;
    int intervalo = 0;
    double m_maiores = 0.0;
    int maiores = 0;

    //identificar
    IO_id ("Recuperacao01a - Exercicio 5");

    //ler teclado conferindo
    do
    {
        n = IO_readint ("Entre com a quantidade:");
        if (n <1)
        {
            IO_pause ("Numero Invalido");
        }
    } while (n<1);

    //repetir n vezes
    for (int x = 0; x<n; x++)
    {
        //ler teclado
        valor = IO_readdouble ("Entre com um valor real:");

        //testar valor
        if (valor < -32.75)
        {
            //atualiza total
            m_menores = (m_menores + valor);
            //atualiza numero de menores
            menores = menores + 1;
        }//fim if
        else
        {
            if (valor > 54.25)
            {
                //atualiza total
                m_maiores = (m_maiores + valor);
                //atualiza numero de maiores
                maiores = maiores + 1;
            }//fim if
            //valor [-32.25:54.25]
            else
            {
                //atualiza total
                m_intervalo = (m_intervalo + valor);
                //atualiza numero de intervalos
                intervalo = intervalo + 1;
            }//fim else
        }//fim else
    }//fim for

    //calcula medias conferindo se ha pelo menos 1 numero no intervalo
    if (menores == 0)
    {
        m_menores=0.0;
        printf ("%s\n", "Nao ha valores <-32.75");
    }//fim if
    else
    {
        m_menores = m_menores/menores;
        printf ("%s%lf\n", "Media <-32.75: ", m_menores);
    }//fim else
    if (intervalo == 0)
    {
        m_intervalo=100.0; //numero fora do intervalo para controle
        printf ("%s\n", "Nao ha valores [-32.75:54.25]");

    }//fim if
    else
    {
        m_intervalo = m_intervalo/intervalo;
        printf ("%s%lf\n", "Media [-32.75:54.25]: ", m_intervalo);
    }//fim else
    if (maiores == 0)
    {
        m_maiores=0.0;
        printf ("%s\n", "Nao ha valores >54.25");
    }//fim if    
    else
    {
        m_maiores = m_maiores/maiores;
        printf ("%s%lf\n", "Media >54.25: ", m_maiores);
    }//fim else

    //mostrar medias
    //se ha pelo menos um valor real em cada intervalo
    if (m_menores != 0.0 && m_maiores != 0.0 && m_intervalo != 100.0)
    {
        //nao ha como outra media ser menor
        printf ("%s\n", "Menor media: valores < -32.75");
    }//fim if
    else
    {
        //verifica se ha apenas uma media
        if ((m_menores == 0.0 && m_maiores == 0.0) || 
            (m_menores == 0.0 && m_intervalo == 100.0) ||
            (m_intervalo == 100.0 && m_maiores == 0.0))
        {
            //apenas uma media
            printf ("%s\n", "Apenas uma media - Impossivel comparar");
        }//fim if
        else
        {
            //apenas medias de intervalo e maiores
            if (m_menores == 0.0)
            {
                printf ("%s\n", "Menor media: valores [-32.75:54.25]");
            }//fim if
            //apenas medias de intervalo e menores
            if (m_maiores == 0.0)
            {
                printf ("%s\n", "Menor media: valores <-32.75");
            }//fim if
            //apenas medias de menores e maiores
            if (m_intervalo == 100.0)
            {
                printf ("%s\n", "Menor media: valores <-32.75");
            }//fim if
        }//fim else
    }//fim else

    //encerrar
    IO_pause ("Aperte ENTER para continuar");

}//fim method05 ()

/**
Method06 - Le dois inteiros (a,b) para formar o intervalo ]a:a[
le outros valores inteiros do teclado até q o ultimo valor seja -1
calcular e mostrar a soma dos cubos (1/x3)dos valores dentro do intervalo
Obs: Usuário deve inserir apenas valores inteiros!!!
*/
void method06 ()
{
    //definir dados
    int a = 0;
    int b = 0;
    int valor = 0;
    double soma = 0.0;

    //identificar
    IO_id ("Recuperacao01a - Exercicio 06");

    //ler teclado
    a = IO_readint ("Entre com o primeiro valor inteiro do intervalo: ");

    //assegurar intervalo valido
    do
    {
        b = IO_readint ("Entre com o segundo valor inteiro do intervalo maior que primeiro: ");
    }while(b<=a);

    //ler teclado ate usuario inserir -1
    while (valor != -1)
    {
        valor = IO_readint ("Entre com valor inteiro para somar (-1 para encerrar): ");

        //verificar se valor igual a zero e dentro do intervalo
        if (valor != 0 && a<valor && valor<b)
        {
            soma = soma + 1.0/pow((double)valor, 3.0);
        }//fim if     
    }//fim while

    //mostrar soma
    printf ("%s%lf\n", "soma dos cubos inversos: ", soma);

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method06 ()

/**
Method07 - Le dois valores reais (a, b) para formar o intervalo ]a:b[
le valores reais do teclado ate o usuario inserir 0 (descarta)
contar quantos valores estao dentro, quantos estao fora do intervalo
Calcular as porcentagens dos valores acima, dentro e abaixo do intervalo
Obs: Usuário deve inserir apenas valores reais!!!
*/
void method07 ()
{
    //definir dados
    double a = 0.0;
    double b = 0.0;
    double valor = 1.0;
    double acima = 0;
    double dentro = 0;
    double abaixo = 0;
    double total = 0;

    //identificar
    IO_id ("Recuperacao01a - Exercicio 07");

    //ler teclado
    a = IO_readdouble ("Entre com o primeiro valor real do intervalo: ");

    //assegurar intervalo valido
    do
    {
        b = IO_readdouble ("Entre com o segundo valor real do intervalo maior que primeiro: ");
    }while(b<=a);

    //ler teclado ate usuario inserir -1
    while (valor != 0.0)
    {
        valor = IO_readdouble ("Entre com valor real (0.0 para encerrar): ");

        //verificar se valor igual a zero
        if (valor != 0.0)
        {
            //verificar se valor esta acima do intervalo
            if (valor >= b)
            {
                //contar
                acima = acima + 1.0;
            }//fim if
            else
            {
                //verificar se valor dentro do intervalo
                if (a < valor && valor < b)
                {
                    //contar
                    dentro = dentro + 1.0;
                }//fim if
                //valor abaixo do interval
                else
                {
                    //contar
                    abaixo = abaixo + 1.0;
                }//fim else
            }//fim else
        }//fim if     
    }//fim while

    //calcular porcentagens
    total = acima + dentro + abaixo;

    //porcentagem de valores acima
    if (total != 0)
    {
        acima = acima/total*100;
        dentro = dentro/total*100;
        abaixo = abaixo/total*100;
        //mostrar porcentagens
        printf ("As porcentagens dos valores que estao:\nAcima: %lf%%\nDentro: %lf%%\nAbaixo: %lf%%\n",
                    acima, dentro, abaixo);
    }
    else
    {
        printf ("%s\n", "Nao foram inserido valores validos.");
    }

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method07 ()

/**
Method08 - Le tres valores reais (x, y, z), um por vez
diz se estao em ordem crescente, decrescente ou nenhuma,
nesse caso diz maior e o menor
*/
void method08 ()
{
    //definir dados
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
    double maior = 0.0;
    double menor = 0.0;
    
    //identificar
    IO_id ("Recuperacao01a - Exercicio 8");

    //ler teclado
    x = IO_readdouble ("Entre com valor real para x:");
    y = IO_readdouble ("Entre com valor real para y:");
    z = IO_readdouble ("Entre com valor real para z:");

    //verificar se estao em ordem crescente
    if (x<y && y<z)
    {
        printf ("%s %lf %lf %lf\n", "Valores em ordem crescente:", x, y, z);
    }//fim if
    else
    {
        //verificar se estao em ordem decrescente
        if (z<y && y<x)
        {
            printf ("%s %lf %lf %lf\n", "Valores em ordem decrescente:", x, y, z);
        }//fim if
        else
        {
            //verificar se sao todos iguais
            if (x==y && y==z)
            {
            printf ("%s %lf %lf %lf\n", "Todos os valores sao iguais:", x, y, z);
            }//fim if
            else
            {
                //igualar menor ao menor numero
                if (x<=y && x<=z)
                {
                    menor = x;
                }
                if (y<=x && y<=z)
                {
                    menor = y;
                }
                if (z<=x && z<=y)
                {
                    menor = z;
                }
                //igualar maior ao mario numero
                if (x>=y && x>=z)
                {
                    maior = x;
                }
                if (y>=x && y>=z)
                {
                    maior = y;
                }
                if (z>=x && z>=y)
                {
                    maior = z;
                }
                //mostrar maior e menor
                printf ("Entre %lf, %lf, %lf\nO maior: %lf\nO menor:%lf\n", x, y, z, maior, menor);
            }//fim else    
        }//fim else
    }//fim else
    
    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method08 ()

/**
Method09 - Le tres caracteres do teclado, um por vez
diz se estao em ordem crescente decrescente ou em nenhuma
Obs: caracteres iguais nao sao considerados em ordem crescente ou decrescente
Obs: Como os inputs nao estao limitados a letras, para classificacao crescente e decrescente 
foi considerada a posicao na tabela ASCII, ou seja, letras maiusculas menores que minusculas.
*/
void method09 ()
{
    //definir dados
    char x = 0;
    char y = 0;
    char z = 0;
    
    //identificar
    IO_id ("Recuperacao01a - Exercicio 9");

    //ler teclado
    x = IO_readchar ("Entre com um caractere para x:");
    y = IO_readchar ("Entre com um caractere para y:");
    z = IO_readchar ("Entre com um caractere para z:");

    //verificar se estao em ordem crescente
    if (x<y && y<z)
    {
        printf ("%s %c %c %c\n", "Caracteres em ordem crescente:", x, y, z);
    }//fim if
    else
    {
        //verificar se estao em ordem decrescente
        if (z<y && y<x)
        {
            printf ("%s %c %c %c\n", "Caracteres em ordem decrescente:", x, y, z);
        }//fim if
        else
        {
            printf ("%s %c %c %c\n", "Caracteres nao estao em qualquer ordem:", x, y, z);
        }//fim else
    }//fim else 

    //encerrar
    IO_pause ("Aperte ENTER para continuar");   
}//fim method09 ()

/**
Method10 - Le tres cadeias de caracteres (x, y, z), uma por vez
diz se estao em ordem alfabetica crescente, decrescente ou nenhuma ordem
nesse caso, diz quel a menor e qual a maior
*/
void method10 ()
{
    //definir dados
    char *x = NULL;
    char *y = NULL;
    char *z = NULL;
    char *menor = NULL;
    char *maior = NULL;
    int xy = 0;
    int xz = 0;
    int yz = 0;
    
    //identificar
    IO_id ("Recuperacao01a - Exercicio 10");

    //ler teclado
    x = IO_readstring ("Entre com uma cadeia de caracteres para x:");
    y = IO_readstring ("Entre com uma cadeia de caracteres para y:");
    z = IO_readstring ("Entre com uma cadeia de caracteres para z:");

    //verificar
    if (x != NULL && y != NULL && z != NULL)
    {
        //comparar strings
        xy = strcmp (x, y);
        xz = strcmp (x, z);
        yz = strcmp (y, z);

        if (xy<0 && yz<0)
        {
            printf ("%s\n%s\n%s\n%s\n", x, y, z, "Cadeias em ordem crescente");
        }//fim if
        else
        {
            if (xy>0 && yz>0)
            {
                printf ("%s\n%s\n%s\n%s\n", x, y, z, "Cadeias em ordem decrescente");
            }//fim if
           else
            {
               if (xy==0 && yz==0)
                {
                    printf ("%s\n%s\n%s\n%s\n", x, y, z, "Todas as cadeias sao iguais");
                }//fim if
                else
                {
                    //nao estao em qualquer ordem
                    printf ("%s\n%s\n%s\n%s\n", x, y, z, "Cadeias nao estao em qualquer ordem");

                    //verificar se x 'e menor
                    if (xy <= 0 && xz <= 0)
                    {
                        menor = x;
                    }//fim if
                    //verifica se y 'e menor
                    if (xy >=0 && yz <= 0)
                    {
                        menor = y;
                    }//fim if
                    //verifica se z 'e menor
                    if (xz >= 0 && yz >=0)
                    {
                        menor = z;
                    }//fim if

                    //verificar verifica se x 'e maior
                    if (xy >= 0 && xz >= 0)
                    {
                        maior = x;
                    }//fim if
                    if (xy <= 0 && yz >= 0)
                    {
                        maior = y;
                    }//fim if
                    if (xz <= 0 && yz<= 0)
                    {
                        maior = z;
                    }//fim if

                    //mostrar
                    printf ("A maior:%s\nA menor:%s\n", maior, menor);
                }//fim else 
            }//fim else
        }//fim else
    }//fim if

    //encerrar
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
        IO_id ("Recuperacao 01a");

        //opcoes
        IO_println ("Opcoes:");
        IO_println ("0- Sair");
        IO_println ("1- Verifica se inteiros sao negativos, positivos, zeros, pares ou impares");
        IO_println ("2- Conta quantos inteiros sao negativos, positivos, pares ou impares");
        IO_println ("3- Verifica o tipo dos simbolos de uma cadeia de caracteres");
        IO_println ("4- Conta quantos caracteres de cada tipo existem em uma cadeia");
        IO_println ("5- Calcula  e compara a media dos valores entre os intervalos <-32.75, [-32.75:54.25], >54.25");
        IO_println ("6- Calcula e mostra a soma dos cubos dos inversos dos inteiros dentro do intervalo ]a:b[");
        IO_println ("7- Conta e mostra porcentagem de quantos valores reais estao dentro e fora do intervalo ]a:b[");
        IO_println ("8- Verifica a ordem de tres valores reais");
        IO_println ("9- Verifica a ordem de tres caracteres pela tabela ASCII");
        IO_println ("10- Verifica a ordem de tres cadeias de caracteres");

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
    v1-primeira compilacao acusou methods unused
    () esquecidos apos methodxx dentro de switch
    consertado com a adicao dos parenteses methodxx ();
    v2-funcionou como esperado

method01:
    v1-funcionou como esperado

method02:
    v1- contou mas nao mostrou nao havia comando para mostrar
    consertado com adicao de printfs;
    v2- nao previu a possibilidade de as duas ou tres ou quatro 
    quantidades serem iguais, apenas se todas fosse iguais (tinha 6 ifs);
    v3- esqueceu de reduzir n na linha 202, programa nao chegou ao fim;
    v4- funcionou como esperado;

method03:
    v1- OS nao aceitou rodar programa com gets, 
    consertado utilizando fgets;
    v2- fgets incluindo \n na cadeia,
    consertado antecipando a posicao do \0 em 1.
    v3- funcionou como esperado

method04:
    v1- nao contou maiusculas e minusculas
    consertado funcoes tinham utilizado 'a'<c e nao <=;
    v2- funcionou como esperado

method05:
    Obs: enunciado diz intervalo [-32.75:54.25] 
    e media dos maiores que 54.20 - erro de digitacao??
    method criado considerando maiores que 54.25;
    v1- media dividindo por dois mesmo q so tenha um valor
    calculo: media = (media + valor)/2
    consertado com contador;
    v2- problema de v1 resolvido, mas aparece media indeterminada
    quando nao ha nenhum valor no intervalo (divide por 0)
    consertado com if
    v3- nao foi contemplada a possibilidade de so ter valor em um ou dois intervalos
    consertado com comparacao de intervalos com ou sem valores a menor media sera 
    sempre a do menor intervalo com valores
    v4- funcionou com esperado

method06:
    v1- nao foi testado se valor pertence ao intervalo
    v2- funcionou como esperado
    Obs: -1 para sair, entrando na conta

method07:
    v1- compilador acusou invalid specifier
    consertado dobrando o % para escapa-lo
    v2- funcionou como esperado

method08:
    v1- nao considerou a possbilidade de dois ou mais serem iguais
    consertado retira das condicoes de < ou > para apurar o menor maior
    v2- muitos ifs tentando ver qual era menor e qual maior
    consertado criando duas variaveis maior e menor independente de quem lhe 
    atribui valor x y ou z
    v3- funcionou como esperado

method09:
    v1- funcionou como esperado

method10:
    v1- funcionou como esperado



------------------------------------Testes
method01:   5: -11, -10, 0, 1, 2   

method02:   1: -11, -10, 0, 1, 2; 
            3: -11 -13 0, 10 12 1, 0 0 -10, -10 -12 4 

method03:   aA@&|!+-*\/%<>= .,;:_2 

method04:   Aaz091&&||+-%/+<>==><;:., _.

method05:   1: -32.76, -30.1, 55.5, 
            2: um teste com cada par acima
            4: -32.76 -32.75 54.25 54.26

method06:   -3 3, -4 1 1 4 -1
            4 9, 3 5 10 -1
            3 -3,

method07:   -3.2 3.2, -3.2 -3.1 3.1 -3.2 0
            3.2 -3.2, 
            -1.1 1.1, 0
            -1.1 1.1, -0.5, 0.5 0

method08:   -1.1 1.2 1.3
            1.3 1.2 1.1
            1.1 1.3 1.2
            1.1 1.1 1.1
            1.1 1.1 1.2
            1.1 1.2 1.1
            1.2 1.1 1.1

method09:   a b c
            Z X C
            Z a c
            ! B m

method10:
            abc abd aca em diferentes ordens
            aaa aaa abc em diferentes ordens
            aaa aaa aaa
*/