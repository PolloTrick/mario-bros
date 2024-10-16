#include <Porcentaje.hpp>
#include <iostream>

int main(){
    Porcentaje porcentaje1;
    Porcentaje porcentaje2;
    Porcentaje porcentaje3;
   

    porcentaje1.Incrementar(10);
    porcentaje1.Incrementar(10);
    porcentaje1.Disminuir(4);

    std::cout
    <<"porcentaje 1: "
    <<porcentaje1.Imprimir()
    <<std::endl;


};