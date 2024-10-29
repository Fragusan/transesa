#include <fstream>
#include <string>
#include <cctype>
#include "venta.h"
//#include "estampaTemporal.h"

using namespace std;

void nuevaVenta(){
    		int opc=-1;
    	do{
    		membrete();
    		cartelLogoEmpresa();
    		textoCentro("MENU NUEVA VENTA",11);
    		textoCentro("*********************",12);
    		alternarLocale();
    		hiddenCur();
    		textoCentro("Usa el teclado n�merico para seleccionar una de las opciones", 14);
    		gotoxy(20, 16);printf("1. REALIZAR NUEVA VENTA");
    		gotoxy(20, 17);printf("2. VOLVER AL MENU PRINCIPAL");//
    		gotoxy(20, 18);
    		gotoxy(20, 19);cout << WINE << "0. SALIR" << BLACK;
    		gotoxy(20, 24);printf("OPCI�N SELECCIONADA: -> ");
    		showCur();
    		alternarLocale();
    		string entrada;
    		getline(cin, entrada);

    		if (entrada.size() == 1 && isdigit(entrada[0])) {
                        opc = stoi(entrada);
                    } else {
                        gotoxy(20, 21); cout << WINE << "Entrada no v�lida. Intente nuevamente." << BLACK;
                        continue;
                    }

                    switch (opc) {
                                case 1: {
                                    string nombre, apellido, fechaCompra, fechaViaje;
                                    int id, dni, telefono, asiento;
                                    bool pago;
                                    int horaViaje, estadoVenta;
                                    
                                    cin.ignore(); 
                                    cout << "Ingrese el nombre del cliente: ";
                                    getline(cin, nombre);
                                    cout << "Ingrese el apellido del cliente: ";
                                    getline(cin, apellido);
                                    cout << "Ingrese el DNI del cliente: ";
                                    cin >> dni;
                                    cout << "Ingrese el tel�fono del cliente: ";
                                    cin >> telefono;
                                    cin.ignore(); 
                                    // Resto de la captura de datos

                                    // Crear instancia y guardar en JSON
                                    venta actual(nombre, apellido, 01, dni, telefono, 32);


                                    //venta ventaActual(nombre, apellido, id, dni, telefono, asiento, fechaCompra, fechaViaje, pago,);
                                    
                                    //venta.setHorario(static_cast<venta::horario>(horaViaje));
									//venta.setEstado(static_cast<venta::estado>(estadoVenta));
                                    //venta.guardarEnArchivo("ventas.json");

                                    cout << "Venta registrada exitosamente.\n";
                                    cout << actual.getInfo();
                                    Sleep(12000);
                                    break;
                                }
                                case 0:
                                    cout << "Saliendo del programa...\n";
                                    break;
                                
                                case 2:
                                	opc=0;
                                	break;
                                default:
                                    cout << "Opción inválida, por favor intente de nuevo.\n";
                            }

    	}while (opc != 0);
    
}
