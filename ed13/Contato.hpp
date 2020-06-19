/*
Contato.hpp 
*/

// ----------------------------------------------- definicoes globais
#ifndef _CONTATO_H_
#define _CONTATO_H_

// dependencias
#include <iostream>
using std::cin ; // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha
#include <iomanip>
using std::setw; // para definir espacamento
#include <string>
using std::string; // para cadeia de caracteres
#include <fstream>
using std::ofstream; // para gravar arquivo
using std::ifstream; // para ler arquivo

// outras dependencias
void pause ( std::string text )
{
    std::string dummy;
    std::cin.clear ( );
    std::cout << std::endl << text;
    std::cin.ignore( );
    std::getline(std::cin, dummy);
    std::cout << std::endl << std::endl;
} // end pause ( )

#include "Erro.hpp"

// ---------------------------------------------- definicao de classe
/**
* Classe para tratar contatos, derivada da classe Erro.
*/
class Contato : public Erro
{
    /**
    * atributos privados.
    */
    private:
        string nome;
        string fone;
        string fone2;
        int n_fones;

    /**
    * metodos privados.
    */
    
    /**
    * testa se valor do telefone e' valido
    */
    bool foneValid ()
    {
        // definir dados
        bool result = false;

        //testar length de fone
        if (this->fone.length() == 10)
        {
            result = true;
            
            //verificar digitos
            for (int x=0; x<10 && result; x++)
            {
                if (x==5 && this->fone[x] != '-')
                {
                    result = false;
                }//fim if
                if (x!=5 && !('0' <= this->fone[x] && this->fone[x] <= '9'))
                {
                    result = false;
                }//fim if
            }//fim for
        }//fim if
        
        //retorno
        return (result);
    } //fim foneValid ()

    /**
    * testa se valor do telefone e' valido
    */
    bool fone2Valid ()
    {
        // definir dados
        bool result = false;

        //testar length de fone
        if (this->fone2.length() == 10)
        {
            result = true;
            
            //verificar digitos
            for (int x=0; x<10 && result; x++)
            {
                if (x==5 && this->fone2[x] != '-')
                {
                    result = false;
                }//fim if
                if (x!=5 && !('0' <= this->fone2[x] && this->fone2[x] <= '9'))
                {
                    result = false;
                }//fim if
            }//fim for
        }//fim if
        
        //retorno
        return (result);
    } //fim fone2Valid ()
    
    /**
    * definicoes publicas.
    */
    public:
        /**
        * Destrutor.
        */
        ~Contato ( )
        { }

        /**
        * Construtor padrao.
        */
        Contato ( )
        {
            setErro ( 0 ); // nenhum erro, ainda
            // atribuir valores iniciais vazios
            nome = "";
            fone = "";
            fone2 = "";
            n_fones = 0;
        } // fim construtor padrao

        /**
        * Construtor alternativo.
        * @param nome_inicial a ser atribuido
        * @param fone_inicial a ser atribuido
        */
        Contato ( std::string nome_inicial, std::string fone_inicial, std::string fone_secundario )
        {
            setErro ( 0 ); // nenhum erro, ainda
            n_fones = 0; // nenhum telefone, ainda
            // atribuir valores iniciais
            setNome ( nome_inicial ); // nome = nome_inicial;
            setFone ( fone_inicial ); // fone = fone_inicial;
            setFone2 ( fone_secundario); // fone2 = fone_secundario;
        } // fim construtor alternativo

        /**
        * Construtor alternativo baseado em copia.
        */
        Contato ( Contato const & another )
        {
            // atribuir valores iniciais por copia
            setErro ( 0 ); // copiar erro
            setNome ( another.nome ); // copiar nome
            setFone ( another.fone ); // copiar fone
            setFone2 ( another.fone2 ); // copiar fone2
        } // fim construtor alternativo
        

// ----------------------------------- metodos para acesso

    /**
    * Metodo para atribuir nome.
    * @param nome a ser atribuido
    */
    void setNome ( std::string nome )
    {
        if ( nome.empty ( ) )
            setErro ( 1 ); // nome invalido
        else
            this->nome = nome;
    } // fim setNome ( )

    /**
    * Metodo alternativo para atribuir nome lido do teclado
    */
    void setNome ()
    {
        string nome;
        std:: cout << "Entre com o nome do contado: ";
        std:: cin >> nome;
        std:: cout << endl;

        if (nome.empty())
            setErro (1);
        else
            this->nome=nome;
    }// fim setNome()

    /**
    * Metodo para atribuir telefone.
    * @param fone a ser atribuido
    */
    void setFone ( std::string fone )
    {
        if ( fone.empty ( ))
            setErro ( 2 ); // fone invalido
        else
            this->fone = fone;
            if ( !this->foneValid())
            {
                setErro (2); //fone invalido
                this->fone = "";
            }
            else
            {
                //verificar ha outro telefone
                if (this->fone2Valid())
                {
                    //dois telefones validos
                    this->n_fones=2;
                }//fim if
                else
                {
                    //apenas um telefone valido
                    this->n_fones=1;
                }//fim else
            }//fim else
    } // fim setFone ( )

    /**
    * Metodo para atribuir telefone secudario.
    * @param fone a ser atribuido
    */
    void setFone2 ( std::string fone )
    {
        if ( fone.empty ( ))
            setErro ( 2 ); // fone invalido
        else
            this->fone2 = fone;
            if ( !this->fone2Valid())
            {
                setErro (2); //fone invalido
                this->fone2 = "";
            }
            else
            {
                //verificar ha outro telefone
                if (this->foneValid())
                {
                    //dois telefones validos
                    this->n_fones=2;
                }//fim if
                else
                {
                    //apenas um telefone valido
                    this->n_fones=1;
                }//fim else
            }//fim else
    } // fim setFone ( )

    /**
     * Metodo alternativo para atribuir telefone do teclado
     */
    void setFone ( )
    {
        string fone;
        std:: cout << "Entre com o telefone do contado (ex: 99999-9999): ";
        std:: cin >> fone;
        std:: cout << endl;

        if (fone.empty())
            setErro (1);
        else
            this->fone = fone;
            if ( !this->foneValid())
            {
                setErro (2); //fone invalido
                this->fone = "";
            }
            else
            {
                //verificar ha outro telefone
                if (this->fone2Valid())
                {
                    //dois telefones validos
                    this->n_fones=2;
                }//fim if
                else
                {
                    //apenas um telefone valido
                    this->n_fones=1;
                }//fim else
            }//fim else
    }// fim setFone()

    /**
     * Metodo alternativo para atribuir telefone secundario do teclado
     */
    void setFone2 ( )
    {
        string fone;
        std:: cout << "Entre com o telefone secundario do contado (ex: 99999-9999): ";
        std:: cin >> fone;
        std:: cout << endl;

        if (fone2.empty())
            setErro (1);
        else
            this->fone2 = fone;
            if ( !this->fone2Valid())
            {
                setErro (2); //fone invalido
                this->fone2 = "";
            }
            else
            {
                //verificar ha outro telefone
                if (this->foneValid())
                {
                    //dois telefones validos
                    this->n_fones=2;
                }//fim if
                else
                {
                    //apenas um telefone valido
                    this->n_fones=1;
                }//fim else
            }//fim else
    }// fim setFone2()

    /**
     * Metodo  para alterar telefone secundario do teclado
     * Se o contato nao tiver o segundo telefone informa erro
     */
    void changeFone2 ( std::string fone)
    {
        if (fone.empty())
            setErro (1);
        else
            if ( !this->fone2Valid())
            {
                setErro (2); //nao ha fone a ser alterado
                this->fone2 = "";
                std::cout << "Nao ha telefone secundario para ser alterado" << endl;
            }
            else
            {
                //altera telefone
                this->fone2 = fone;

                //verifica se novo telefone e valido
                if (!this->fone2Valid())
                {
                    setErro (2); //fone invalido
                    this->fone2 = "";
                }
                else
                {
                    //verificar ha outro telefone
                    if (this->foneValid())
                    {
                        //dois telefones validos
                        this->n_fones=2;
                    }//fim if
                    else
                    {
                        //apenas um telefone valido
                        this->n_fones=1;
                    }//fim else
                }//fim else
            }//fim else
    }// fim changeFone2()

    /**
     * Metodo  para remover telefone secundario do teclado
     * Se o contato nao tiver o segundo telefone informa erro
     */
    void removeFone2 ( )
    {
        if ( !this->fone2Valid())
        {
            setErro (2); //nao ha fone a ser removido
            this->fone2 = "";
            std::cout << "Nao ha telefone secundario para ser removido" << endl;
        }
        else
        {
            //remove telefone secundario
            this->fone2 = "";
            
            //verificar ha outro telefone
            if (this->foneValid())
            {
                //um telefone valido
                this->n_fones=1;
            }//fim if
            else
            {
                //nenhum telefone valido
                this->n_fones=0;
            }//fim else
        }//fim else
    }// fim removeFone2()

    /**
    * Funcao para obter nome.
    * @return nome armazenado
    */
    std::string getNome ( )
    {
        return ( this->nome );
    } // fim getNome ( )

    /**
    * Funcao para obter fone.
    * @return fone armazenado
    */
    std::string getFone ( )
    {
        return ( this->fone );
    } // fim getFone ( )

    /**
    * Funcao para obter fone secundario.
    * @return fone armazenado
    */
    std::string getFone2 ( )
    {
        return ( this->fone2 );
    } // fim getFone ( )

    /**
    * Funcao para obter quantidade de telefones validos.
    * @return quantidade
    */
    int getNValidFones ( )
    {
        return ( this->n_fones );
    } // fim getFone ( )

    /**
    * Funcao para obter dados de uma pessoa.
    * @return dados de uma pessoa
    */
    virtual std::string toString ( )
    {
        return ( "{ "+getNome( )+", "+getFone( )+", "+getFone2( )+" }" );
    } // fim toString ( )

    /**
    * Metodo para ler dados de contado do arquivo
    * @param nome do arquivo
    */
    void fromFile (std:: string file)
    {
        std:: ifstream arquivo;
        arquivo.open(file);

        if (!arquivo.is_open())
        {
            std:: cout << "Erro ao abrir arquivo" << endl;
            setErro(1);
        }// fim if
        else
        {
            arquivo >> this->nome;
            arquivo >> this->fone; 
            if ( !this->foneValid())
            {
                setErro (2); //fone invalido
                this->fone = "";
            }// fim if
            arquivo >> this->fone2; 
            if ( !this->fone2Valid())
            {
                setErro (2); //fone invalido
                this->fone2 = "";
            }// fim if
            arquivo.close();
        }// fim else
    }// fim fromFile()

    /**
    * Metodo para gravar contato em arquivo
    * @param nome do arquivo
    */
   void toFile (std:: string file)
   {
        std:: ofstream arquivo;
        arquivo.open (file);
        arquivo << this->nome << endl;
        arquivo << this->fone << endl;
        arquivo << this->fone2 << endl;
        arquivo.close();
   }// fim toFiel()     

}; // fim da classe Contato

using ref_Contato = Contato*; // similar a typedef Contato* ref_Contato;
#endif