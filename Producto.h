
#ifndef Producto_h
#define Producto_h
#include <string>
#include <fstream>
#include "Fecha.h"
#include "Proveedor.h"
#include "Producto.h"
#include "Area.h"

using namespace std;
//Programado por Adrián Martin
class Producto
{
public:
    // constructores
    Producto();
    Producto(string nom, double p, Fecha fecha1);
    // metodos de modificacion
    void setNombre(string nuevoNombre);
    void setCantidad(int nuevaCantidad);
    void setPrecio(int nuevoPrecio);
    // metodos de acceso
    string getNombreProducto();
    int getCantidadProducto();
    double getPrecioProducto();
    Fecha getProductoFecha();
    // otros metodos

private:
    // atributos
    string nombre;
    double precio;
    Fecha fecha;
};

// constructores
Producto::Producto()
{
    nombre = "-";
    precio = 0;
    fecha = Fecha(0, 0, 0);
}

//constructor con parámetros
Producto::Producto(string nom, double p, Fecha fecha1)
{
    nombre = nom;
    precio = p;
    fecha = fecha1;
}

// metodos de modificacion
void Producto::setNombre(string nuevoNombre)
{
    nombre = nuevoNombre;
}

void Producto::setPrecio(int nuevoPrecio)
{
    precio = nuevoPrecio;
}

//métodos de acceso

string Producto::getNombreProducto()
{
    return nombre;
}

double Producto::getPrecioProducto()
{

    return precio;
}

Fecha Producto::getProductoFecha()
{
    return fecha;
}

#endif /* Producto_h */