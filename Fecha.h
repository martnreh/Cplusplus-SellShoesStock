
#ifndef Fecha_h
#define Fecha_h
#include <sstream>
#include <iostream>
//Programado por Adrián Martin
class Fecha
{
    // publico
public:
    // constructor default  
    Fecha();
    // constructor con parámetros 
    Fecha(int dd, int mm, int aa);
    // métodos de acceso para todos los atributos
    int getDia();
    int getMes();
    int getAno();
    // métodos de modificación para todos los atributos
    void setDia(int dd);
    void setMes(int mm);
    void setAno(int aa);

    //método para obtener en formato fecha
    string getFecha();

    // privado
private:
    // atributos dia mes y año
    int dia;
    int mes;
    int ano;
};

// implementa los métodos

//constructor default
Fecha::Fecha()
{
    dia = 0;
    mes = 0;
    ano = 0;
}
//constructor con parámetros
Fecha::Fecha(int dd, int mm, int aa)
{
    dia = dd;
    mes = mm;
    ano = aa;
}

//métodos de acceso
int Fecha::getDia()
{
    return dia;
}

int Fecha::getMes()
{
    return mes;
}

int Fecha::getAno()
{
    return ano;
}

string Fecha::getFecha()
{
    stringstream fechaI;
    fechaI << dia << "/" << mes << "/" << ano;
    string fechaF = fechaI.str();
    return fechaF;
}

//métodos de modificación
void Fecha::setDia(int dd)
{
    dia = dd;
}

void Fecha::setMes(int mm)
{
    mes = mm;
}

void Fecha::setAno(int aa)
{
    ano = aa;
}


#endif /* Fraccion_h_h */
