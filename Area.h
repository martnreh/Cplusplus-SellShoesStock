
#ifndef Area_h
#define Area_h
#include <string>
using namespace std;
//Programado por Francisco Guerra

// Clase Area
class Area
{

public:
    // constructores
    Area();
    Area(string nuevoNombre, int nuevoID);
    // metodos de modificacion
    void setArea(string nuevoNombre);

    // metodos de acceso
    string getArea(); //nombre del Area
    int getID(); //ID personal del Area

    // otros metodos

private:
    // atributos
    string area;
    int id;
};

//constructor
Area::Area()
{
    area = "-";
}
//constructor con parámetros
Area::Area(string nuevoNombre, int nuevoID)
{
    area = nuevoNombre;
    id = nuevoID;
}
//función para establecer el nombre del Area de la tienda
void Area::setArea(string nuevoNombre)
{
    area = nuevoNombre;
}

//función para recbir el string del nombre del Area de la tienda
string Area::getArea()
{
    return area;
}
//función para obtener el entero del ID que identifica cada Area de la tienda
int Area::getID()
{
    return id;
}

#endif /* Area_h */