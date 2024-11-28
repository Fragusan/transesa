#ifndef menuVenta.h
#define menuVenta.h

#include <fstream>
#include <string>
#include <cctype>
#include "menuPrincipal.h"
#include "venta.h"
#include "Mysql.h"


//#include "estampaTemporal.h"

using namespace std;

void nuevaVenta(){
			cin.ignore();
    		int opc=-1;
    	do{
    		//instancia generica
    		venta res("none", "none", 01, 0, "0", 32);
			membrete();
    		cartelLogoEmpresa();
    		textoCentro("MENU NUEVA VENTA",11);
    		textoCentro("*********************",12);
    		alternarLocale();
    		hiddenCur();
    		textoCentro("Usa el teclado númerico para seleccionar una de las opciones", 14);
    		gotoxy(20, 16);printf("1. REALIZAR NUEVA VENTA");
    		gotoxy(20, 17);printf("2. VOLVER AL MENU PRINCIPAL");//
    		gotoxy(20, 18);
    		gotoxy(20, 19);cout << WINE << "0. SALIR" << BLACK;
    		gotoxy(20, 24);printf("OPCIÓN SELECCIONADA: -> ");
    		showCur();
    		alternarLocale();
    		string entrada;
    		getline(cin, entrada);
			
			//validador de entrada
    		if (entrada.size() == 1 && isdigit(entrada[0])) {
                        opc = stoi(entrada);
                    } else {
                    	/*
                    	hiddenCur();
                    	cuadritoLineaEfecto(28,20,70,22);
                    	alternarLocale();
                    	cout << WINE;
                    	textoCentro("Entrada no válida. Intente nuevamente.",21);
                        cout  << BLACK;
                        Sleep(2500);
                        alternarLocale();
                        cin.ignore();*/
                        errorMsj(28,20,70,22, "Entrada no válida. Intente nuevamente.", false );
                        continue;
                    }

                    switch (opc) {
                    			
                    			case 0:
                    				errorMsj(15,20,84,22, "Está operación finaliza el programa. Presione enter para proseguir.", false );
                                    //cout << "Saliendo del programa...\n";
                                    exit(0);
                                    break;
                    			
                                case 1: {
                                    string nombre, apellido, fechaCompra, fechaViaje;
                                    int id, dni, telefono, asiento;
                                    bool pago;
                                    int horaViaje, estadoVenta;
                                    
                                    system("cls");
									system("mode con: cols=100 lines=30");
									system("color 70");
                                    membrete();
									cartelLogoEmpresa();
									textoCentro("MENU NUEVA VENTA",11);
									textoCentro("*********************",12);
									alternarLocale();
									//hiddenCur();
                                    //cin.ignore(); 
                                    gotoxy(20, 14);
                                    cout << "Ingrese el DNI del cliente: ";
                                    cin >> dni;
                                    //comprobar dni --> si dni existe, 
                                    res = existeCliente(dni);
                                    if(res.getNombre() == "Default"){
                                    	gotoxy(20, 15);
                                    	cout << "Ingrese el apellido del cliente: ";
                                    	cin >> apellido;
                                    	gotoxy(20, 16);
                                    	cout << "Ingrese el nombre del cliente: ";
                                    	cin >> nombre;
                                    	gotoxy(20, 17);
                                    	cout << "Ingrese el teléfono del cliente: ";
                                    	cin >> telefono;
                                    	cin.ignore(); 
                                    	
                                    	// Crear instancia y guardar en JSON
                                    	res.setNombre(nombre);
                                    	res.setApellido(apellido);
                                    	res.setTelefono(to_string(telefono));
                                    	res.setDni(dni);
                                    	res.setId(01);
                                    	res.setAsiento(32);
                                    	
									}
									
									//si no es default, significa que se encontro
									gotoxy(20, 15); cout << "Apellido: " << res.getApellido();
                                    gotoxy(20, 16); cout << "Nombre: " << res.getNombre();
                                    
                                    // Resto de la captura de datos



                                    //venta ventaActual(nombre, apellido, id, dni, telefono, asiento, fechaCompra, fechaViaje, pago,);
                                    
                                    //venta.setHorario(static_cast<venta::horario>(horaViaje));
									//venta.setEstado(static_cast<venta::estado>(estadoVenta));
                                    //venta.guardarEnArchivo("ventas.json");
									gotoxy(20, 19);
                                    cout << "Venta registrada exitosamente.\n";
                                    cout << res.getInfo();
                                    alternarLocale();
                                    Sleep(12000);
                                    opc=0;
                                    break;
                                }
                                
                                case 2:
		                         	//principal();
		                         	errorMsj(28,20,70,22, "Presione ENTER para confirmar.", true );
		                         	opc=0;
									continue;
                                	break;
                            
                                default:
                                    cout << "Opción inválida, por favor intente de nuevo.\n";
                                    Sleep(6000);
                                    
                            }

    	}while (opc != 0 );
    
    cin.ignore();
}

#endif 
