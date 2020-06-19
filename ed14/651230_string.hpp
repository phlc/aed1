/**
Autor: Pedro Henrique Lima Carvalho
651230_string.hpp
*/

// dependencias
#include <string>

//definicoes
#ifndef _MYSTRING_HPP_
#define _MYSTRING_HPP_

//definicao de estrutura
typedef
    struct node
    {
        node* previous;
        char c;
        node* next;
    }node;

// ----------------------------------------------- classes
#include "651230_erro.hpp" // classe para tratar erros
class MyString : public Erro
{
    /**
     * Definicoes Privadas
     */
    private:
        node* inicio;
        int size;

    /**
     * Definicoes Publicas
     */
    public:
        /**
         * Constructor MyString
         */
        MyString ( const char string[] )
        {
            //definir dados
            char a = '_';
            int length = -1;
            
            //verificar tamanho da string
            while (a != '\0' && length < 81)
            {
                length++;
                a = string[length];
            }//fim while

            //limitacao do loop e aviso de erro
            if (length == 81 || length<1)
            {
                setErro(1);
            }//fim if
            else
            {
                //inicializar MyString
                this->inicio = new node;
                this->size = length;

                //criar buffer
                node* buffer_anterior = nullptr;
                node* buffer = this->inicio;

                //Inicializar Nodes
                for (int x=0; x<length; x++)
                {
                    buffer->previous = buffer_anterior;
                    buffer->c = string[x];
                    buffer->next = nullptr;

                    //encerrar aqui no ultimo
                    if (x<length-1)
                    {
                        buffer->next = new node;
                        buffer_anterior = buffer;
                        buffer = buffer->next;
                    }//fim if
                }//fim for
                    
                //no erro
                setErro(0);
            }//fim else
        }//fim constructor

        /**
         * Constructor MyString Alternativo Vazio
         */
        MyString ()
        {
            //inicializar MyString
            this->inicio = nullptr;
            this->size = 0;
            
            //no erro
            setErro(0);
        }//fim constructor

        /**
         * Constructor MyString Alternativo por copia
         */
        MyString ( const MyString& other )
        {
            //definir dados
            this->size = other.size;
            node* this_buffer = nullptr;
            node* this_buffer_anterior = nullptr;
            node* other_buffer = nullptr;
            node* other_buffer_anterior = nullptr;

            //limitacao do loop e aviso de erro
            if (this->size < 1)
            {
                setErro(1);
            }//fim if
            else
            {
                //andar para primeiro node em other
                other_buffer = other.inicio;
                
                //inicializar primeiro node em this
                this->inicio = new node;

                //andar para primeiro node em this
                this_buffer = this->inicio;

                //Inicializar Nodes
                for (int x=0; x<this->size; x++)
                {
                    //preencher node de this
                    this_buffer->previous = this_buffer_anterior;
                    this_buffer->c = other_buffer->c;
                    this_buffer->next = nullptr;

                    //encerrar aqui no ultimo
                    if (x<this->size-1)
                    {
                        //criar novo node em this
                        this_buffer->next = new node;

                        //andar node em this e other
                        this_buffer_anterior = this_buffer;
                        this_buffer = this_buffer->next;
                        other_buffer_anterior = other_buffer;
                        other_buffer = other_buffer->next;
                    }//fim if
                }//fim for
                    
                //no erro
                setErro(0);
            }//fim else
        }//fim constructor alternativo

        /**
         * Destructor MyString
         */
        ~MyString ()
        {
            //definir dados
            node* buffer = this->inicio;
            node* buffer_anterior = nullptr;

            //ir ate o ultimo node
            while (buffer->next != nullptr)
            {
                buffer_anterior = buffer;
                buffer = buffer->next;
            }//fim for

            while (buffer_anterior != nullptr)
            {
                buffer = buffer_anterior;
                buffer_anterior = buffer->previous;
                delete buffer;
            }//fim while

            //fechar o objeto
            this->inicio = nullptr;
        }//fim destrutor

        /**
         * print - mostra a cadeia de caracteres
         */
        void print ()
        {
            //definir dados
            node* buffer = this->inicio;
            node* buffer_anterior = nullptr;
            std::cout << buffer->c;

            //ir ate o ultimo node
            while (buffer->next != nullptr)
            {
                buffer_anterior = buffer;
                buffer = buffer->next;
                std::cout << buffer->c;
            }//fim for
        }//fim print

        /**
         * getSize - retorna o size da MyString
         * @return size
         */
        int getSize ()
        {
            return(this->size);
        }//fim getSize

        /**
         * toInteger - transforma a string para inteiro
         * @return valor inteiro ou -1 se nao foi possivel converter
         */
        int toInteger ()
        {
            //definir dados
            node* buffer = this->inicio;
            node* buffer_anterior = nullptr;
            int controle = 0;
            int resposta = -1;

            //verificar numero negativo
            if (buffer->c == '-')
            {
                //andar um node
                buffer_anterior = buffer;
                buffer = buffer->next;
            }//fim if

            //ir ate o ultimo node testando se caracteres == algarismos
            while (buffer->next != nullptr && controle==0)
            {
                if (!('0'<=buffer->c && buffer->c<='9'))
                {
                    controle = 1;
                    setErro(2);
                }//fim if
                else
                {
                    buffer_anterior = buffer;
                    buffer = buffer->next;
                }//fim else
            }//fim for

            if(controle==0)
            {
                //realizar conversao do caractere
                resposta = 0;
                resposta = resposta + (int(buffer->c)-48)*(int)pow(10, controle);

                //converter de tras para frente
                while (buffer_anterior != nullptr)
                {
                    //andar entre os nodes
                    buffer = buffer_anterior;
                    buffer_anterior = buffer->previous;
                    
                    //atualizar controle
                    controle++;

                    //realizar conversao do caractere
                    if(buffer->c == '-')
                        resposta = resposta * -1;
                    else
                        resposta = resposta + (int(buffer->c)-48)*(int)pow(10, controle);
                }//fim while
            }//fim if

            //retorno
            return (resposta);

        }//fim toInteger

        /**
         * toDouble - transforma a string para double
         * @return valor inteiro ou 0.0 se nao foi possivel converter
         */
        double toDouble ()
        {
            //definir dados
            node* buffer = this->inicio;
            node* buffer_anterior = nullptr;
            int controle = -1;
            int contador = 1;
            double resposta = 0.0;

            //verificar numero negativo
            if (buffer->c == '-')
            {
                //andar um node
                buffer_anterior = buffer;
                buffer = buffer->next;
            }//fim if

            //ir ate o ultimo node testando se caracteres == algarismos
            while (buffer->next != nullptr && controle!=1)
            {
                if (!('0'<=buffer->c && buffer->c<='9') && !(buffer->c=='.'))
                {
                    controle = 1;
                    setErro(2);
                }//fim if
                else
                {
                    //contar o numero de '.''
                    if (buffer->c=='.')
                        controle++;
                    
                    //andar um node    
                    buffer_anterior = buffer;
                    buffer = buffer->next;

                    //fazer conta decimal (aproveitar o sentido da movimentacao entre nodes)
                    if (controle==0)
                    {
                        resposta = resposta + (double(buffer->c)-48)*pow(10, -1*contador);
                        contador++;
                    }//fim if
                    else if (controle == 1)
                    {
                        //mais de um '.'
                        setErro(2);
                        resposta = 0.0;
                    }//fim else
                }//fim else
            }//fim for

            //verificar validade
            if(controle==0)
            {
                //voltar ate o '.'
                while (buffer->c!='.')
                {
                    buffer = buffer_anterior;
                    buffer_anterior = buffer->previous;
                };

                //testar se o node com '.' nao e' o primeiro
                if (buffer_anterior==nullptr)
                    controle=1;
            }//fim if

            //verificar validade
            if(controle==0)
            {
                //andar mais um
                buffer = buffer_anterior;
                buffer_anterior = buffer->previous;

                //realizar conversao do caractere decimal
                resposta = resposta + (double(buffer->c)-48.0)*pow(10, controle);

                //converter de tras para frente
                while (buffer_anterior != nullptr)
                {
                    //andar entre os nodes
                    buffer = buffer_anterior;
                    buffer_anterior = buffer->previous;
                    
                    //atualizar controle
                    controle++;

                    //realizar conversao do caractere
                    if(buffer->c == '-')
                        resposta = resposta * -1;
                    else
                        resposta = resposta + (int(buffer->c)-48)*(int)pow(10, controle);
                }//fim while
            }//fim if

            //retorno
            return (resposta);
        }//fim toDouble

        /**
         * toBoolean - transforma a string para bool
         * @return valor booleano 0 para false e 1 para true
         */
        bool toBoolean ()
        {
            //definir dados
            node* buffer = this->inicio;
            node* buffer_anterior = nullptr;
            int controle = 0;
            bool resposta = false;

            //verificar se o objeto so tem um node
            if (this->size == 1)
            {
                //verificar verdadeiro (T ou 1)
                if (buffer->c == 'T' || buffer->c == '1')
                {
                    resposta = true;
                }//fim if
                else if (buffer->c != 'F' && buffer->c != '0')
                {
                    //nao foi possivel conversao
                    setErro(2);
                }//fim else
            }//fim if
            //verificar "true"
            else if (this->size == 4)
            {
                if (buffer->c=='t')
                {
                    //andar um node
                    buffer_anterior = buffer;
                    buffer = buffer->next;
                    if (buffer->c=='r')
                    {
                        //andar um node
                        buffer_anterior = buffer;
                        buffer = buffer->next;
                        if (buffer->c=='u')
                        {
                            //andar um node
                            buffer_anterior = buffer;
                            buffer = buffer->next;
                            if (buffer->c=='e')
                            {
                                resposta = true;
                                controle=1;
                            }//fim if
                        }//fim if
                    }//fim if
                }//fim if
                if (controle==0)
                    setErro(2);
            }//fim else if

            //verificar "false"
            else if (this->size == 5)
            {
                if (buffer->c=='f')
                {
                    //andar um node
                    buffer_anterior = buffer;
                    buffer = buffer->next;
                    if (buffer->c=='a')
                    {
                        //andar um node
                        buffer_anterior = buffer;
                        buffer = buffer->next;
                        if (buffer->c=='l')
                        {
                            //andar um node
                            buffer_anterior = buffer;
                            buffer = buffer->next;
                            if (buffer->c=='s')
                            {
                                //andar um node
                                buffer_anterior = buffer;
                                buffer = buffer->next;
                                if (buffer->c=='e')
                                {
                                    controle=1;
                                }//fim if
                            }//fim if
                        }//fim if
                    }//fim if
                }//fim if
                if (controle==0)
                    setErro(2);
            }//fim else if
            else
                setErro(2);

            //retorno
            return (resposta);
        }//fim toBoolean()

        /**
         * contains - verifica se a string contem substring
         * @param substring
         * @return verdadeiro ou falso
         */
        bool contains ( const char string[] )
        {
            //definir dados
            int length = 0;
            char a = string[length];
            int controle = 0;
            

            //verificar tamanho da string
            while (a != '\0' && length < 81)
            {
                length++;
                a = string[length];
            }//fim while

            //limitacao do loop e aviso de erro
            if (length == 81)
            {
                setErro(3);
            }//fim if
            else
            {
                //criar buffer
                node* buffer_anterior = nullptr;
                node* buffer = this->inicio;

                //ir ate o ultimo node
                do
                {
                    for (int x=0; x<length && controle == 0; x++)
                    { 
                        if (buffer != nullptr && buffer->c == string[x])
                        {
                            //andar um node
                            buffer_anterior = buffer;
                            buffer = buffer->next;
                        }//fim if
                        else
                        {
                            controle = 1;
                            //andar um node
                            buffer_anterior = buffer;
                            buffer = buffer->next;
                        }//fim else
                    }//fim for

                    //vefirificar se o for foi ate o final
                    if (controle == 0)
                    {
                        //mudar controle para final positivo
                        controle = 2;
                    }//fim if
                    else
                    {
                        //voltar controle para 0
                        controle = 0;
                    }//fim else
                }while (buffer != nullptr && controle!=2);//fim do while
            }//fim else

            //retorno
            return (controle==2);
        }//fim contains ()

        /**
         * toUpperCase - cria string com letras maiusculas
         * @return referencia para nova string
         */
        MyString& toUpperCase ()
        {   
            //criar nova MyString por copia
            MyString* p_nova = new MyString(*this);

            //definir dados
            node* buffer = p_nova->inicio;
            node* buffer_anterior = nullptr;

            //ir ate o ultimo node procurando por
            while (buffer != nullptr)
            {
                if ('a'<=buffer->c && buffer->c<='z')
                {
                    buffer->c = (char) (buffer->c - 'a' + 'A');
                }//fim if

                buffer_anterior = buffer;
                buffer = buffer->next;
            }//fim for

            //retorno
            return (*p_nova);

        }//fim toUpperCase

        /**
         * toLowerCase - cria string com letras minusculas
         * @return referencia para nova string
         */
        MyString& toLowerCase ()
        {   
            //criar nova MyString por copia
            MyString* p_nova = new MyString(*this);

            //definir dados
            node* buffer = p_nova->inicio;
            node* buffer_anterior = nullptr;

            //ir ate o ultimo node procurando por
            while (buffer != nullptr)
            {
                if ('A'<=buffer->c && buffer->c<='Z')
                {
                    buffer->c = (char) (buffer->c - 'A' + 'a');
                }//fim if

                buffer_anterior = buffer;
                buffer = buffer->next;
            }//fim for

            //retorno
            return (*p_nova);

        }//fim toLowerCase

        /**
         * replace - cria string com caracteres substituidos
         * @param - caractere a ser substituido e caractere substituto
         * @return referencia para nova string
         */
        MyString& replace (char original, char novo)
        {   
            //criar nova MyString por copia
            MyString* p_nova = new MyString(*this);

            //definir dados
            node* buffer = p_nova->inicio;
            node* buffer_anterior = nullptr;

            //ir ate o ultimo node procurando por
            while (buffer != nullptr)
            {
                if (buffer->c<=original)
                {
                    buffer->c = novo;
                }//fim if

                buffer_anterior = buffer;
                buffer = buffer->next;
            }//fim for

            //retorno
            return (*p_nova);

        }//fim replace

        void append ( char c )
        {
            //definir dados
            node* buffer_anterior = nullptr;
            node *buffer = nullptr;
            
            //cria primeiro node se nao existe e inicializa
            if (this->inicio == nullptr)
            {
                this->inicio = new node;
                this->size = 1;
                buffer = this->inicio;
                buffer->previous = buffer_anterior;
                buffer->next = nullptr;
                buffer->c = c;
            }//fim if
            else
            {
                //mover ate ultimo node
                buffer = this->inicio;

                while (buffer->next != nullptr)
                {
                    buffer_anterior = buffer;
                    buffer = buffer->next;
                }//fim while

                //criar novo node
                buffer->next = new node;
                
                //andar para novo node
                buffer_anterior = buffer;
                buffer = buffer->next;

                //inicializar novo node
                buffer->previous = buffer_anterior;
                buffer->c = c;
                buffer->next = nullptr;

            }//fim else
        }//fim append

        /**
         * split - separa um string em diversas substrings de acordo com o parametro
         * @param ponteiro para arranjo de string e caractere referencia
         * @return quantidade de substrings
         */
        int split (MyString* arr[], char ref)
        {   
            //definir dados
            node* buffer = this->inicio;
            node* buffer_anterior = nullptr;
            int contador = 0;

            //controle de sucesso
            if (buffer == nullptr)
                contador = -1;

            //verificar se primeiros nodes sao caracteres referencia
            while (buffer->c==ref && contador!=-1)
            {
                //mover para proximo node
                buffer_anterior = buffer;
                buffer = buffer->next;

                //controle de sucesso
                if (buffer == nullptr)
                    contador = -1;
            }//fim while

            //verificar erro
            if (contador != -1)
            {
                //ir ate o ultimo node
                while (buffer != nullptr && contador<80)
                {
                    //criar uma MyString dentro do array se atual caractere !referencia
                    if (buffer->c != ref)
                    {   
                        arr[contador] = new MyString();

                        //atualizar contador
                        contador++;
                    }//fim if

                    //ir ate o proximo caractere referencia
                    while (buffer->c !=ref && buffer != nullptr)
                    {
                        //append em MyString caractere
                        arr[contador-1]->append(buffer->c);
                    
                        //mover para proximo node
                        buffer_anterior = buffer;
                        buffer = buffer->next;
                    }//fim if

                    //proximo node se diferente de nullptr
                    if (buffer != nullptr)
                    {
                        buffer_anterior = buffer;
                        buffer = buffer->next;
                    }//fim if
                }//fim while
            }//fim if

            //retorno
            return (contador);
        }//fim split

        /**
         * encrypt - cria string com cifrada
         * @param chave de cifragem
         * @return referencia para nova string
         */
        MyString& encrypt (int x)
        {   
            //criar nova MyString por copia
            MyString* p_nova = new MyString(*this);

            //definir dados
            node* buffer = p_nova->inicio;
            node* buffer_anterior = nullptr;

            //ir ate o ultimo node procurando por letras
            while (buffer != nullptr)
            {
                //cifrar maiusculas
                if ('A'<=buffer->c && buffer->c<='Z')
                {
                    buffer->c = (char) (((((buffer->c - 'A') + x))%26)+'A');
                }//fim if

                //cifrar minusculas
                if ('a'<=buffer->c && buffer->c<='z')
                {
                    buffer->c = (char) (((((buffer->c - 'a') + x))%26)+'a');
                }//fim if

                buffer_anterior = buffer;
                buffer = buffer->next;
            }//fim for

            //retorno
            return (*p_nova);

        }//fim encrypt

        /**
         * decrypt - cria string com decifrada
         * @param chave de decifragem
         * @return referencia para nova string
         */
        MyString& decrypt (int x)
        {   
            if(x>26)
                x=x%26;
            //retorno
            return (this->encrypt(26-x));

        }//fim decrypt

        /**
         * invert - cria string com os caracteres em ordem invertida
         * @return referencia para nova string
         */
        MyString& invert ()
        {   
            //criar nova MyString por copia
            MyString* p_nova = new MyString(*this);

            //definir dados
            node* buffer = p_nova->inicio;
            node* buffer_anterior = nullptr;
            node* buffer_proximo = nullptr;

            //ir ate o ultimo node 
            while (buffer->next != nullptr)
            {
                buffer_anterior = buffer;
                buffer = buffer->next;
            }//fim for

            //ligar this ao ultimo
            p_nova->inicio = buffer;
            
            //resetar buffers
            buffer_anterior = nullptr;
            buffer_proximo = nullptr;

            //voltar invertendo a ordem dos nodes
            while (buffer->previous != nullptr)
            {
                buffer_proximo = buffer->previous;
                buffer_anterior = buffer->next;
                buffer->next = buffer_proximo;
                buffer->previous = buffer_anterior;
                buffer = buffer->next;

            }//fim while
            
            //retorno
            return (*p_nova);

        }//fim invert

}; // fim classe MyString

#endif