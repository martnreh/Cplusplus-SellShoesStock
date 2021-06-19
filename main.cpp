// Francisco Javier Guerra Quintanilla | A00829919
// Adrián Martin Hernández Barrientos | A01570656

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
#include <fstream>
#include "Producto.h"
#include "Cliente.h"
#include "Administrador.h"
#include "Proveedor.h"
#include "Area.h"
#include "Fecha.h"

//Programado por Francisco Guerra
// Funcion que registra el nombre y direccion del cliente nuevo
void registrarCliente(string &nom, string &dire)
{   //Pedir los datos del cliente
    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nom); //Se lee toda la linea por si acaso se ingresa nombre y apellido o si ingresa espacio
    cout << "Dirección: ";
    getline(cin, dire);//Se lee toda la linea por si acaso se ingresa nombre y apellido o si ingresa espacio
    //constructor de tipo cliente el cual recibe nombre y dirección para poder confirmar su compra al final
    Cliente cliente1(nom, dire);
    cout << " "
         << endl;
}

//Programado por Francisco Guerra
// Funcion que muestra todos los productos al cliente
void mostrarInventarioCliente(Proveedor listaProveedores[], Producto listaProductos[], int &size)
{
    cout << " " << endl;
    //for que mostrará el invnetario al cliente desde la lista interna del progama, solo mostrando los nombres de los productos, el precio y el proveedor.
    for (int cont = 0; cont < size; cont++)
    {
        cout << cont + 1 << ". " << listaProductos[cont].getNombreProducto() << " a $" << listaProductos[cont].getPrecioProducto() << ", de " << listaProveedores[cont].getProveedor() << endl;
    }
    cout << endl;
}
//Programado por Francisco Guerra
// Funcion que agrega productos elegidos por el cliente a su carrito de compras
void carritoCliente(int listaCarritoCliente[],Producto listaProductos[],int &sizeCarrito,int size,string nom, string dire){
  int eleccion; //elección de funciones para el cliente
  int total = 0; // suma de los precios 
  int cont = 0; // contador local para índice de listas
  sizeCarrito = 0;  //contador inicial del carrito para la lista del carrito.
  do{
    // Pedir elección del producto al cliente 
    cout<< "Teclea el número del producto que deseas comprar o un 0 para finalizar tu compra: ";
    cin>> eleccion;
    if (eleccion > 0){
      //Verificar que su elección este en el rango de la lista en el inventario y que sea mayor a 0 para no continuar eligiendo
      if (eleccion <= size) {
        //la lista del cliente empieza en 0. Se agrega el índice del producto que eligió a su lista.
        listaCarritoCliente[cont] = eleccion-1;
        // Se acumula una suma de los precios de producto.
        total += listaProductos[eleccion-1].getPrecioProducto();
        //aumentan los contadores del carrito del cliente y el contador local para posicionar los productos.
        cont++;
        sizeCarrito++;
        //Se confirma al usuario que se agregó su porducto a su carrito.
        cout << "¡Agregado!" << endl;
      } else {
        //Se informa que no se ingresó un numero válido.
        cout << "- Escribe un numero valido" << endl;
      }
    }
  } while(eleccion != 0);

  // Mostrar el carrito al usuario
  cout << "\nARTICULOS DEL CARRITO" << endl;
  //Se despliega el nombre del usuario y su dirección 
  cout<< "Cliente: " << nom <<"\nDirrección de envío: "<<dire<<endl;

  //Uso de for para desplegar la lista de los productos del carrito del usuario.
  for(int i = 0;i<sizeCarrito;i++){
    cout << i+1 << ". " << listaProductos[listaCarritoCliente[i]].getNombreProducto() << "....." << "$" << listaProductos[listaCarritoCliente[i]].getPrecioProducto() << endl;
  }
  //Desplegar el total la cual es suma de los precios. 
  cout << "Su total es: $" << total << endl;

  int eleccionFinal;//elección final del cliente para confirmar o no su compra y regresar al inicio de usuario cliente. 
  cout<< "\n¿Confirmar compra?\n1) Si\n2) No\nOpcion: ";
  cin >> eleccionFinal;
  if (eleccionFinal == 1){
    //Si el cliente confirma su compra se despliega una comnfirmación.
    cout << "¡Gracias por tu compra! Recibirás pronto tu pedido" << endl;
    exit(0);
  }
  cout << " " << endl;
}
//Programado por Adrián Martin
// Funcion que verifica si el ID ingresado es de un administrador
bool iniciarSesionAdmin()
{ 
    ifstream archivo;//llamada al archivo en variable
    string idAdmin; //nombre del admin
    string idPrueba; //id que será verificado si es de un admin o no
    string NombreAdmin;// nombre del admin recibido desde el archivo
    bool resp = false; //respuesta incial 

    //abrir el archivo de texto conteniendo los ID y nombres de los administradores
    cout << "Ingrese ID de administrador: " << endl;
    cin >> idPrueba;
    archivo.open("Administradores.txt");
    //Leer primero ID y nombres.
    while (archivo >> idAdmin >> NombreAdmin)
    {   //verificar que el ID que ingresó el usuario existe.
        if (idPrueba == idAdmin)
        {   //confirmación
            cout << "Bienvenido Administrador: " << NombreAdmin << "\n"
                 << endl;
            resp = true;
            //Se crea un administrador actual y se coloca en los constructores de la clase Administardor
            Administrador adminActual;
            adminActual.setIDAdmin(idAdmin);
            adminActual.setNombreAdmin(NombreAdmin);
        }
    }
    //se cierra el archivo
    archivo.close();
    //se regresa true o false para saber si el administrador si pudo acceder o no
    return resp;
}

//Programado por Francisco Guerra
//Programado por Adrián Martin
// Funcion que checa si area ya existe para su registro
void registroArea(Area listaAreas[], string area, int &size, int &sizeArea)
{
    if (sizeArea == 0)
    { //Si el tamaño de la lista es 0, se agrega a la lista de Areas un Area nueva con constructor con parámetros
        listaAreas[size] = Area(area, sizeArea);
        sizeArea++;
    }
    else
    {   //Si el area de la lista si no es 0, se hará un chqueo de si existe o no el Area ya.
        bool check = false;
        //For para analizar toda la lista.
        for (int i = 0; i < size; i++)
        {   //Si el nombre del area es el mismo que el Area de la lista de Areas se entra a la condición.
            if (area == listaAreas[i].getArea())
            {
              //Agregar a la lista de Areas la nueva area con constructor con parametros de clase Area
                //Se obtiene el ID de la Area existente ya que es la misma la nueva Area a la existente. 
                listaAreas[size] = Area(area, listaAreas[i].getID());
                check = true; //cambiar el check a verdadero
            }
        }
        //Si el check no se realizó se entra a una condición.
        if (check == false)
        {
          //A LA lista de areas se le agrega un Area con constructor con parámetros como una nueva Area que no existe actualmente.
            listaAreas[size] = Area(area, sizeArea);
            sizeArea++;
        }
    }
    size++; //incrementar el tamaño de la lista
}
//Programado por Adrián Martin
// Funcion que permite al administrador agregar nuevos productos
void agregarInventario(Proveedor listaProveedores[], Producto listaProductos[], Area listaAreas[], int &size, int &sizeArea)
{
    //Definicón de variables internas locales para recibir los inputs del administrador
    string producto;
    double precio;
    string prov;
    string area;
    int dia;
    int mes;
    int ano;
    Fecha FechaInv;//Variable tipo Fecha
    //Recbir los inputs del nuevo producto del administrador
    
    cout << "Producto:" << endl;
    cin.ignore();
    getline(cin, producto);
    cout << "Precio:" << endl;
    cin >> precio;
    cout << "Proveedor:" << endl;
    cin.ignore();
    getline(cin, prov);
    cout << "Area:" << endl;
    cin>>area;
    cout << "Dia Mes Año (ej. 07 11 2020):" << endl;
    cin >> dia >> mes >> ano;
    cout << "\n"
         << endl;
    //Constructor con parámetros de Fecha para recibir día,mes y año y asignarlo a FechaInv
    FechaInv = Fecha(dia, mes, ano);
    //Constructor con parametros de un producto con composición de la Fecha, para agregar a la lista de productos
    listaProductos[size] = Producto(producto, precio, FechaInv);
    //Agregar el Proveedor con constructor con parámetros y agregarlo a la lista de proveedores.
    listaProveedores[size] = Proveedor(prov);
    //Llamar función para registrar el Area de la tienda
    registroArea(listaAreas, area, size, sizeArea);
    
}
//Programado por Adrián Martin
// Funcion que imprime al administrador los productos
void mostrarInventario(Proveedor listaProveedores[], Producto listaProductos[], Area listaAreas[], int &size)
{
    //Mostrar inventario completo al administrador usando la posicón desde 0 hasta el final de la lista.
    for (int cont = 0; cont < size; cont++)
    {   //Obtener el Proveedor
        cout << "Proveedor: " << listaProveedores[cont].getProveedor() << endl;
        //Obtener el Nombre del Producto
        cout << "Producto: " << listaProductos[cont].getNombreProducto() << endl;
        //Obtener el recio del Producto
        cout << "Precio: " << listaProductos[cont].getPrecioProducto() << endl;
        //Obtener la Fecha del Producto
        cout << "Fecha: " << listaProductos[cont].getProductoFecha().getFecha() << endl;
        //Obtener el Area 
        cout << "Area: " << listaAreas[cont].getArea() << endl;
        cout << " " << endl;
    }
}

//Programado por Adrián Martin
// Funcion que lee los productos de Inventario.txt y los guarda para su uso
void crearInventarioInicial(Proveedor listaProveedores[], Producto listaProductos[], Area listaAreas[], int &size, int &sizeArea)
{
    ifstream inventario; //archivo inventario
    //strings para asignar nombres para proveedores,areas y productos
    string prov, area, producto;
    //variable double para asignar el precio
    double precio;
    // variable int para dia mes y año
    int dia, mes, ano;
    //Variable tipo Fecha 
    Fecha FechaInv;

    //Leer el archvio de Inventario y recibir todos los datos de el y asignarlos a las variables establecidas 
    inventario.open("Inventario.txt");
    while (inventario >> prov >> precio >> producto >> dia >> mes >> ano >> area)
    {   //Constructor Fecha que creará un objeto y      asignará a una varible.
        FechaInv = Fecha(dia, mes, ano);
        //Relación composición la cual la lista de Productos recibirá el producto, el precio y de tipo Fecha una fecha para su constructor.
        listaProductos[size] = Producto(producto, precio, FechaInv);
        //Agregar proveedores a la lista
        listaProveedores[size] = Proveedor(prov);
        //LLamar función para registrar el Area
        registroArea(listaAreas, area, size, sizeArea);
    }
    //cerrar el archivo 
    inventario.close();
}

//Programado por Francisco Guerra
// Funcion que muestra los productos de dicha area
void muestraProductosArea(Area listaAreas[], Producto listaProductos[], Proveedor listaProveedores[], int size, int eleccion)
{
    cout << " " << endl;
    int cont = 0;
    //for para leer de principio a fin una lista
    for (int ii = 0; ii < size; ii++)
    {     
        if (listaAreas[ii].getID() == eleccion)
        {   //Si el ID del Area en la posición actual es la misma que la elección del cliente se mostrará ese producto, el precio y el proveedor.
            cout << cont + 1 << ". " << listaProductos[ii].getNombreProducto() << " a $" << listaProductos[ii].getPrecioProducto() << ", de " << listaProveedores[ii].getProveedor() << endl;
            cont++;
        }
    }
    cout << " " << endl;
}
//Programado por Francisco Guerra
// Funcion que muestra las areas
void mostrarAreas(Area listaAreas[], Producto listaProductos[], Proveedor listaProveedores[], int size, int sizeArea)
{   
    cout << "\nAREAS" << endl;
    int cont = 0;
    //While para repetir la condición que se repita de 0 hasta el tamaño de la lista de Areas
    while (cont < sizeArea)
    {
        //for para repetir el tamaño de la lista de inventario
        for (int j = 0; j < size; j++)
        {     //se obtiene el ID de las Areas 
            if (listaAreas[j].getID() == cont)
            { //Si el ID es igual al del contador, se imprime de 1 hacia adelante seguido de las Areas.
                cout << cont + 1 << ". " << listaAreas[j].getArea() << endl;
                break;
            }
        }
        cont++; //Contador aumenta 1
    }
    int opcionArea; //opción al Cliente de ver Areas
    cout << "Teclea el numero del area para ver sus productos:" << endl;
    cin >> opcionArea;
    //Se verifica que su opción este dentro del rango de Areas existentes.
    if (opcionArea > 0 && opcionArea <= sizeArea)
    {
        //Se llama la función que muestra los Prodcutos dentro del Area elegida, sol que una posición anterior ya que se empieza por posición siguiente. 
        muestraProductosArea(listaAreas, listaProductos, listaProveedores, size, opcionArea - 1);
    }
}

//Programado por Francisco Guerra
//Programado por Adrián Martin
// MAIN
int main()
{
    //Creación de listas iniciales.
    Proveedor listaProveedores[10]; //Proveedores
    Producto listaProductos[10]; //Productos
    Area listaAreas[10]; //Areas de la tienda
    int listaCarritoCliente[10]; //Carrito del cliente que contiene el índice de lista productos que elige el cliente
    string nom, dire; //nombre y dirección del cliente
    int sizeCarrito = 0; //tamaño del carrito del cliente
    int size = 0; // tamaño de los productos en inventario
    int sizeArea = 0; //tamaño de la cantidad de Areas que hay en la tienda
    //Función que leerá el archivo de Inventario y creará el inventario inicial
    crearInventarioInicial(listaProveedores, listaProductos, listaAreas, size, sizeArea);
    

    int opcion;//opción del usuario inicial
    //Do while para poder repetir y regresar al usuario a la pagina inicial de la tienda. 
    do
    {
        cout << endl
             << "¡Bienvenido a SuperMark!\n1 Registrarse como nuevo cliente\n2 Ingresar como administrador\n3 Salir del programa\n"
             << endl;
        cout << "Opción: ";
        cin >> opcion;
        cout << " " << endl;
        //switch para mandar al usuario como cliente, como usuario o salir del programa.
        switch (opcion)
        {
          //Caso 1 Entrar como cliente
        case 1:
        {
            //Función para registrar un nuevo cliente
            registrarCliente(nom,dire);
            //Pedirle la opción de lo que quiere hacer después
            int opcionCliente;
            //Do while para repetir y regresar al cliente a este menú
            do
            {
                cout << "Teclea:\n1 Ver todos los productos\n2 Ver areas\n3 Cerrar sesión"
                     << endl;
                cout << "\nOpción: ";
                cin >> opcionCliente; //recibir la opción del cliente
                //Switch para mandar al cliente a diferentes métodos dependiendo de su elección.
                switch (opcionCliente)
                {
                  //Caso 1 Se le muestra el inventario
                case 1:
                {   //Mostar el inventario general de la tienda al cliente
                    mostrarInventarioCliente(listaProveedores, listaProductos, size);
                    //Preguntarle si quiere comprar o quiere seguir viendo.
                    cout<<"Teclea:\n1 Para agregar a tu carrito de compras\n2 Para salir"<<endl;
                    cout << "Opción: "; 
                    int opcionCompra;
                    cin>>opcionCompra;//Se le pide su elección
                    cout << " " << endl;
                    //Si elige comprar, se llama la función carritoCliente la cual creará su lista de carrito. 
                    if (opcionCompra == 1){
                      carritoCliente(listaCarritoCliente,listaProductos,sizeCarrito,size,nom,dire);
                    }
                    else {
                      //Si no decide comprar, se sale del switch al menú del cliente.
                      break;
                    }
        
                    break;
                }
                //Caso 2 se le muestra las Areas de la tienda al cliente y los productos que están solo en esa área.
                case 2:
                {
                    mostrarAreas(listaAreas, listaProductos, listaProveedores, size, sizeArea);
                    break;
                }
                }

            } while (opcionCliente != 3); //Termina Do while del cliente.
            break;
        }
        //Caso 2 el usuario desea ingresar como administrador.
        case 2:
        {   //Llamada a función la cual verifica que el Administrador si existe y puede ingresar. 
            
            if (iniciarSesionAdmin() == true)
            {   
                int opcionAdmin; //opción al administrador 
                //Si si logró ingresar el administrador se usa do while para el menú de sus opciones.
                do 
                {
                    cout << "Teclea:\n1 Agregar Inventario\n2 Ver inventario\n3 Cerrar sesión\n"
                         << endl;
                    cout << "Opción: ";
                    cin >> opcionAdmin;
                    cout<<endl;
                    //pedir opción al administrador de qué hacer

                    switch (opcionAdmin)
                    {
                      //Caso 1 el administrador quiere agregar nuevos productos al inventario
                    case 1:
                    {   //Función que pide datos al administrador sobre el producto y los agrega a sus respectivas listas.
                        agregarInventario(listaProveedores, listaProductos, listaAreas, size, sizeArea);
                        break;
                    }
                    //Caso 2 El administrador desea ver el inventario.
                    case 2:
                    {   //Función que muestra el inventario actual al administrador
                        mostrarInventario(listaProveedores, listaProductos, listaAreas, size);
                        break;
                    }
                    
                    break;
                    }
                    //Si elige la opción 3 sale de menú de administrador
                    if (opcionAdmin == 3)
                    {
                        break;
                    }
                    //Confirmación para salir o mantenerse en el menú
                } while (opcion != 3);
            }
            else
            {
                break;
            }
        }
        }

    // Si en el menú principal de la tienda el usuario ingresa un 3, se sale del do while principal y termina el programa.
    } while (opcion != 3);
}
