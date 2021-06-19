
#ifndef Cliente_h
#define Cliente_h
#include <string>
using namespace std;
//Programado por Francisco Guerra
class Cliente
{

public:
    // constructores
    Cliente();
    Cliente(string nuevoNombre, string nuevaDireccion);
    // metodos de modificacion
    void setNombre(string nuevoNombre);
    void setDireccion(string nuevaDireccion);
    // metodos de acceso
    string getNombre();
    string getDireccion();
    // otros metodos

private:
    // atributos
    string nombre;
    string direccion;
};

// constructores
Cliente::Cliente()
{
    nombre = "-";
    direccion = "-";
}
//constructor con parámetros
Cliente::Cliente(string nuevoNombre, string nuevaDireccion)
{
    nombre = nuevoNombre;
    direccion = nuevaDireccion;
}

// metodos de modificacion
void Cliente::setNombre(string nuevoNombre)
{
    nombre = nuevoNombre;
}

void Cliente::setDireccion(string nuevaDireccion)
{
    direccion = nuevaDireccion;
}

// metodos de acceso
string Cliente::getNombre()
{
    return nombre;
}

string Cliente::getDireccion()
{
    return direccion;
}

#endif /* Cliente_h */
