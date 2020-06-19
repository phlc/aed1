/*
Extras.hpp 
*/

// ----------------------------------------------- definicoes globais
#ifndef _EXTRAS_H_
#define _EXTRAS_H_

// dependencias
#include "Contato.hpp"

// ---------------------------------------------- definicao de classe
/**
* Classe para tratar contatos, derivada da classe Erro.
*/
class Extras : public Contato
{
    /**
    * atributos privados.
    */
    private:
        string fones[10];
        int controle;
        string end_prof;
        string end_resid;
    
    /**
    * metodos privados.
    */
    
    /**
    * testa se valor do telefone e' valido
    */
    bool arr_foneValid (std::string fone)
    {
        // definir dados
        bool result = false;

        //testar length de fone
        if (fone.length() == 10)
        {
            result = true;
            
            //verificar digitos
            for (int x=0; x<10 && result; x++)
            {
                if (x==5 && fone[x] != '-')
                {
                    result = false;
                }//fim if
                if (x!=5 && !('0' <= fone[x] && fone[x] <= '9'))
                {
                    result = false;
                }//fim if
            }//fim for
        }//fim if
        
        //retorno
        return (result);
    } //fim foneValid ()

    /**
    * definicoes publicas.
    */
    public:
        /**
        * Destrutor.
        */
        ~Extras ( )
        { }

        /**
        * Construtor padrao.
        */
        Extras ( )
        {
            setErro ( 0 ); // nenhum erro, ainda
            // atribuir valores iniciais vazios
            for (int x=0; x<10; x++)
            {
                fones[x] = "";
            }
            controle = 0;
            end_prof = "";
            end_resid = "";            
        } // fim construtor padrao
        

// ----------------------------------- metodos para acesso

    /**
    * Metodo para atribuir endereco profissional.
    * @param endereco a ser atribuido
    */
    void setEnd_prof ( std::string endereco )
    {
        if ( endereco.empty ( ) )
            setErro ( 1 ); // nome invalido
        else
            this->end_prof = endereco;
    } // fim setEnd_prof ( )

    /**
    * Metodo para atribuir endereco residencial.
    * @param endereco a ser atribuido
    */
    void setEnd_resid ( std::string endereco )
    {
        if ( endereco.empty ( ) )
            setErro ( 1 ); // nome invalido
        else
            this->end_resid = endereco;
    } // fim setEnd_resid ( )

    /**
    * Metodo para remover endereco profissional.
    */
    void removeEnd_prof ( )
    {
        this->end_prof = "";
    } // fim removeEnd_prof ( )

    /**
    * Metodo para remover endereco residencial.
    */
    void removeEnd_resid ( )
    {
        this->end_resid = "";
    } // fim setEnd_resid ( )

    /**
    * Metodo para gravar novo telefone.
    * @param fone a ser atribuido
    */
    void newFone ( std::string fone )
    {
        if ( fone.empty ( ))
            setErro ( 2 ); // fone invalido
        else
            if ( !arr_foneValid(fone))
            {
                setErro (2); //fone invalido
            }
            else
            {
                //verificar lista esta cheia
                if (this->controle > 9)
                {
                    setErro (2); //lista cheia
                    std::cout << "Lista de telefones cheia" << endl;
                }//fim if
                else
                {
                    //armazenar novo telefone
                    this->fones[controle] = fone;
                    this->controle = this->controle + 1;
                }//fim else
            }//fim else
    } // fim newFone ( )

    /**
    * Metodo para sobrescrever telefone.
    * @param fone a ser atribuido
    */
    void overwriteFone ( std::string fone, int pos )
    {
        if ( fone.empty ( ))
            setErro ( 2 ); // fone invalido
        else
            if ( !arr_foneValid(fone))
            {
                setErro (2); //fone invalido
            }
            else
            {
                //verificar pos ja tem numero
                if (this->controle <= pos)
                {
                    setErro (2); //posicao vazia
                    std::cout << "Posicao vazia" << endl;
                }//fim if
                else
                {
                    //armazenar novo telefone
                    this->fones[pos] = fone;
                }//fim else
            }//fim else
    } // fim overwriteFone ( )

    /**
    * Metodo para remover telefone.
    * @param fone a ser atribuido
    */
    void removeFone ( int pos )
    {
        
        //verificar pos tem numero
        if (pos >= this->controle)
        {
            setErro (2); //posicao vazia
            std::cout << "Posicao vazia" << endl;
        }//fim if
        else
        {
            //se pos igual ultimo numero
            if (pos == this->controle - 1)
            {
                this->fones[pos] = "";
            }//fim if
            //se pos nao for ultimo numero, reorganizar arranjo
            else
            {
                for (int x=pos+1; x<this->controle; x++)
                {
                    this->fones[x-1] = this->fones[x];
                    this->fones[x] = "";
                }
            }//fim else
            this->controle = this->controle - 1;
        }//fim else
    } // fim removeFone ( )

    /**
    * Funcao para obter endereco profisional.
    * @return nome armazenado
    */
    std::string getEnd_prof ( )
    {
        return ( this->end_prof );
    } // fim getEnd_prof ( )

    /**
    * Funcao para obter endereco residencial.
    * @return nome armazenado
    */
    std::string getEnd_resid ( )
    {
        return ( this->end_resid );
    } // fim getEnd_resid ( )

    /**
    * Funcao para obter fone.
    * @return fone armazenado
    */
    std::string getListFone (int pos)
    {
        if (pos >= this->controle)
            std::cout << "Numero inexistente" << endl;
        return ( this->fones[pos] );
    } // fim getListFone ( )

    
    /**
    * Funcao para obter dados de uma pessoa.
    * @return dados de uma pessoa
    */
    std::string toString ( )
    {
        std:: string str = "{ "+getNome( )+", "+getFone( )+", "+getFone2( );
        for (int x=0; x<this->controle; x++)
        {
            str = str+", "+this->getListFone(x); 
        }
        if (getEnd_prof()!="")
            str = str+", "+getEnd_prof();
        if (getEnd_resid()!="")    
            str = str+", "+getEnd_resid();

        str = str+" }";
        return (str);
    } // fim toString ( )


}; // fim da classe Extras
#endif