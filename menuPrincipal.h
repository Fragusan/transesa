#ifndef menuPrincipal.h
#define menuPrincipal.h
#include "menuVenta.h"

void principal(){
		int opc;
	do{
		membrete();
		cartelLogoEmpresa();
		textoCentro("MENU PRINCIPAL",11);
		textoCentro("*********************",12);
		alternarLocale();
		hiddenCur();
		textoCentro("Usa el teclado númerico para seleccionar una de las opciones", 14);
		gotoxy(20, 16);printf("1. REALIZAR NUEVA VENTA");
		gotoxy(20, 17);printf("2. CONSULTAR VENTAS"); //mostrar tabla 
		gotoxy(20, 18);printf("3. MODIFICAR VENTA/TICKET"); // cambiar datos de cliente
		gotoxy(20, 19);printf("4. CANCELACIÓN PARCIAL DE VENTA/TICKET"); // cambiar pago a en espera
		gotoxy(20, 20);printf("5. CANCELACIÓN TOTAL DE VENTA/TICKET"); // liberacion de asiento asignado
		gotoxy(20, 21);
		gotoxy(20, 22);printf("0. SALIR");
		gotoxy(20, 24);printf("OPCIÓN SELECCIONADA: -> ");
		showCur();
		alternarLocale();
		scanf("%i", &opc);
	
	
		switch(opc){
		case 0:
			
			break;
		case 1:
			nuevaVenta();
			break;
		case 2:
			
			break;
		case 3:
			modificarVenta();
			break;
		case 4:
			
			break;
			
		case 5:
			
			break;
			
		default :
			cout << WINE;
			textoCentro("OPCION INGRESADA NO VÁLIDA", 7);
			cout << BLACK;
			Sleep(600);
			principal();
			break;
		}
	}while (opc<0 || opc > 4);
}

void otro(){
	textoCentro("MENU CONSULTAR VENTAS",11);
    textoCentro("*********************",12);
	cuadrito(4,13,9,15,201,153,188,200);//4 ID
	cuadrito(9,13,19,15,203,202,188,202);//10 DNI
	cuadrito(19,13,33,15,203,202,188,202);//apellido
	cuadrito(33,13,42,15,203,202,188,202);//f compra
	cuadrito(42,13,54,15,203,202,188,202);//f de viaje
	cuadrito(54,13,64,15,203,202,188,202);//hora
	cuadrito(64,13,74,15,203,202,188,202);//tipo
	cuadrito(74,13,85,15,203,202,188,202);//estado
	cuadrito(85,13,96,15,203,187,188,202);
	
	gotoxy(6,14);cout << "ID";
	gotoxy(13,14);cout << "DNI";
	gotoxy(23,14);cout << "Apellido";
	gotoxy(36,14);cout << "Tipo";
	gotoxy(46,14);cout << "Hora";
	gotoxy(56,14);cout << "F.Viaje";
	gotoxy(66,14);cout << "F.Compra";
	gotoxy(77,14);cout << "Estado";
	gotoxy(88,14);cout << "Asiento";
	gotoxy(65,26);
}

void otre(){
	int opc;
	do{
	cout << GREEN;
	cuadrito(41,1,59,3);
	//textoCentro("###################",1);
	textoCentro(" T R A N S E S A ",2);
	//textoCentro("###################",3);
	cout << BLACK;
	textoCentro("MENU CONSULTAR VENTAS",4);
    textoCentro("*********************",5);
    
    //encabezado de tabla
	vector<string> titulos = {" ID", "DNI", "Apellido", "F.Compra", "F.Viaje", "Hora", "Tipo", "Estado", "Asiento"};
    vector<int> anchosColumnas = {5, 10, 12, 12, 12, 10, 8, 12, 10};
    
    //carga de datos tablas (hacerlo con db)
    vector<string> titulos1 = {" 58", "45123456", "Campisi", "01/11/2024", "04/11/2024", "Tarde", "Ida", "En espera", "18"};
    vector<string> titulos2 = {" 57", "33654789", "Diaz", "01/11/2024", "04/11/2024", "Noche", "Ida", "En espera", "12"};
    vector<string> titulos3 = {" 56", "27364482", "Moyano", "17/11/2024", "19/11/2024", "Noche", "Vuelta", "En espera", "08"};
    vector<string> titulos4 = {" 55", "27854196", "Paz", "24/10/2024", "04/11/2024", "Noche", "Ida", "Cancelado", "24"};
    vector<string> titulos5 = {" 54", "24365478", "Flores", "22/10/2024", "04/11/2024", "Noche", "Vuelta", "En espera", "16"};
    
    //generarTablaConInterior(4, 9, anchosColumnas, titulos1);//58
    
    //columnas inicial hasta penultima
    generarInteriorSimple(4, 9, anchosColumnas, titulos1);
    generarInteriorSimple(4, 11, anchosColumnas, titulos2);
    generarInteriorSimple(4, 13, anchosColumnas, titulos3);
    generarInteriorSimple(4, 15, anchosColumnas, titulos4);
    //generarInteriorSimple(4, 17, anchosColumnas, titulos5);//5
    
    //encabezado de tabla (luego de cuerpo)
    generarTabla(4, 7, anchosColumnas, titulos); // encabezado
    
    //ultima fila porque es diferente
    generarSimpleFinal(4, 17, anchosColumnas, titulos5, true);//ultima fila
    alternarLocale();
    textoCentro("Use el teclado númerico para seleccionar una de las opciones", 20);
    gotoxy(42,22);cout << "1 VOLVER AL MENU PRINCIPAL"<< endl;
    gotoxy(42,24);cout << "0 SALIR"<< endl;
    gotoxy(42,27);cout << "OPCION SELECCIONADA: -> ";
    showCur();
    scanf("%i", &opc);
    
    switch (opc){
    	case 0:
    		break;
    		
    	case 1:
    		alternarLocale();
    		principal();
    		break;
    		
    	default :
    		cout << WINE;
			textoCentro("OPCION INGRESADA NO VÁLIDA", 7);
			cout << BLACK;
			Sleep(600);
    		break;
	}
	}while (opc<0 || opc > 1);
	
	gotoxy(70,29);
	
}


#endif 
