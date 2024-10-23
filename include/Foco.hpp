#include <stdexcept>
class Foco
{
private:
    int numero;
    bool encendido;

public:
    Foco()
    {
        this->numero = 0;
        this->encendido = false;
    }
    Foco(int numero)
    {
        this->encendido = false;
        if (numero > 100 || numero < 0)
        {
            throw new std::runtime_error("Numero fuera de rango.");
        }
        else
        {
            this->numero = numero;
        }
    }
    ~Foco()
    {
    }
    void Encender(int numero)
    {

        this->numero += numero;
    }
    void Disminuir(int numero)
    {
        this->numero -= numero;
    }
    char Imprimir()
    {
        if (this->encendido)
        {
            return '*';
        }else
        {
            return 'o';
        }
    }

    void Encender()
    {
        this->encendido = true;
    }
    void Apagar()
    {
        this->encendido = false;
    }
};
