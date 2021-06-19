
#ifndef Administrador_h
#define Administrador_h
#include <string>
#include "Fecha.h"
#include "Proveedor.h"
#include "Area.h"
#include "Producto.h"
using namespace std;
//Programado por Adrián Martin

class Administrador
{

public:
    // constructores
    Administrador();
    Administrador(string idAdmin, string nombreAdmin);
    // metodos de acceso
    string getNombreAdmin();
    string getIDAdmin();
    // metodos de modificacion
    void setIDAdmin(string idAdmin);
    void setNombreAdmin(string nombreAdmin);

private:
    // atributos
    string ID;
    string nombre;
};

// constructores
Administrador::Administrador()
{
    ID = "-";
    nombre = "-";
}
//constructor con parámetros
Administrador::Administrador(string idAdmin, string nombreAdmin)
{
    nombre = nombreAdmin;
    ID = idAdmin;
}
// metodos de modificacion
void Administrador::setIDAdmin(string idAdmin)
{
    ID = idAdmin;
}
void Administrador::setNombreAdmin(string nombreAdmin)
{
    nombre = nombreAdmin;
}

// metodos de acceso
string Administrador::getNombreAdmin()
{
    return nombre;
}
string Administrador::getIDAdmin()
{
    return ID;
}

#endif /* Administrador_h */
