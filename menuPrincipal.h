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
		gotoxy(20, 16);printf("1. REALIZAR NUEVA VENTA");//en menu 1 y 2 deberia tambien dejarme modificar el nivel de dificultad
		gotoxy(20, 17);printf("2. CONSULTAR VENTAS");//
		gotoxy(20, 18);printf("3. MODIFICAR VENTA/TICKET"); // MUSICA, CAMBIAR COLOR, SONIDOS, NIVEL
		gotoxy(20, 19);printf("4. CANCELACIÓN PARCIAL DE VENTA/TICKET");
		gotoxy(20, 20);printf("5. CANCELACIÓN TOTAL DE VENTA/TICKET");
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
#endif 


