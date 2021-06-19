
#ifndef Proveedor_h
#define Proveedor_h
#include <string>
using namespace std;
//Programado por Francisco Guerra
class Proveedor
{

public:
    // constructores
    Proveedor();
    Proveedor(string nuevoNombre);
    // metodos de modificacion
    void setProveedor(string nuevoNombre);

    // metodos de acceso
    string getProveedor();

    // otros metodos

private:
    // atributos
    string provedoor;
};

//constructor default
Proveedor::Proveedor()
{
    provedoor = "-";
}
//constructor con parámetros
Proveedor::Proveedor(string nuevoNombre)
{
    provedoor = nuevoNombre;
}

//métodos de modificación
void Proveedor::setProveedor(string nuevoNombre)
{
    provedoor = nuevoNombre;
}

//métodos de  acceso

string Proveedor::getProveedor()
{
    return provedoor;
}

#endif /* Proveedor_h */
