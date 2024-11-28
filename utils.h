#include "colors.h" //libreria de github para colorear fondos y textos
#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include "estampaTemporal.h"


using namespace std;


void alternarLocale() {
    // Obtener la configuraciï¿½n regional actual
    const char* localeActual = setlocale(LC_CTYPE, NULL);

    // Verificar la configuraciï¿½n regional actual y alternar
    if (localeActual && strcmp(localeActual, "Spanish_Spain.1252") == 0) {
        setlocale(LC_CTYPE, "C");
    } else {
        setlocale(LC_CTYPE, "Spanish_Spain.1252");
    }
}

void gotoxy(int x, int y){
	HANDLE hcon;
	hcon= GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void cuadrito(int xs, int ys, int xe, int ye){ // genera marcos decorativos
	int i;
	//control horizontal
	for (i= xs; i<= xe; i++){
		gotoxy(i,ys); printf("%c\n", 205);
		gotoxy(i,ye); printf("%c\n", 205);
	}
	//control vertical
	for (i= ys; i<= ye; i++){
		gotoxy(xs,i); printf("%c\n", 186);
		gotoxy(xe,i); printf("%c\n", 186);
	}
	//primera esquina
	gotoxy(xs,ys); printf("%c\n", 201);
	//segunda esquina
	gotoxy(xe,ys); printf("%c\n", 187);
	//tercera esquina
	gotoxy(xe,ye); printf("%c\n", 188);
	//cuarta esquina
	gotoxy(xs,ye); printf("%c\n", 200);
}

void cuadrito(int xs, int ys, int xe, int ye, int esquina1, int esquina2, int esquina3, int esquina4){ //hacer sobrecarga de metodo para cuadro anidado
	int i;
	//control horizontal
	for (i= xs; i<= xe; i++){
		gotoxy(i,ys); printf("%c\n", 205);
		gotoxy(i,ye); printf("%c\n", 205);
	}
	//control vertical
	for (i= ys; i<= ye; i++){
		gotoxy(xs,i); printf("%c\n", 186);
		gotoxy(xe,i); printf("%c\n", 186);
	}
	//primera esquina
	gotoxy(xs,ys); printf("%c\n", esquina1);
	//segunda esquina
	gotoxy(xe,ys); printf("%c\n", esquina2);
	//tercera esquina
	gotoxy(xe,ye); printf("%c\n", esquina3);
	//cuarta esquina
	gotoxy(xs,ye); printf("%c\n", esquina4);
}

void cuadritoLineaEfecto(int xs, int ys, int xe, int ye){ // genera marcos decorativos con relieve simulado
	int i;
	//control horizontal
	for (i= xs; i<= xe; i++){
		gotoxy(i,ys); printf("%c", 196);
		gotoxy(i,ye); printf("%c", 205);
	}
	//control vertical
	for (i= ys; i<= ye; i++){
		gotoxy(xs,i); printf("%c", 179);
		gotoxy(xe,i); printf("%c", 186);
	}
	//primera esquina
	gotoxy(xs,ys); printf("%c", 218);
	//segunda esquina
	gotoxy(xe,ys); printf("%c", 191);
	//tercera esquina
	gotoxy(xe,ye); printf("%c", 188);
	//cuarta esquina
	gotoxy(xs,ye); printf("%c", 192);
}

void margen(){
	cuadrito(1,0,98,28); // recuadro de pantalla
}

void textoCentro (char *texto, int y){//centra el texto en pantalla a la altura de y que se le indique (usa gotoxy())
	int longitud = strlen(texto);
	gotoxy(50-(longitud/2), y); printf(texto);
}

void hiddenCur(){
	printf("\e[?25l");
}

//muestra el cursor
void showCur(){
	printf("\e[?25h");
}

void sinMaximVentana(){//funciona en windows con permisos elevados
	HWND consoleWindow; 
	consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE,GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

}

void charger(string txt){
	int i;
	char* charArray = new char[txt.length() + 1]; // +1 para el carÃ¡cter nulo
    strcpy(charArray, txt.c_str());

	alternarLocale();
	textoCentro(charArray, 23);
	alternarLocale();
	for(i=4; i<= 95; i++){
		gotoxy(i, 25); printf("%c\n", 176);
	}

	for(i=4; i<= 95; i++){
		cout << YELLOW;
	gotoxy(i, 25); printf("%c\n", 178);
	Sleep(12);//retardo para apariencia de carga
	}
	cout << BLACK;
}

void parpadeo(const char* txt, int y, char modo) {
    bool show = true;
    int longitud = strlen(txt);
    char* espacio = new char[longitud + 1]; // +1 para el carï¿½cter nulo
    // Rellena el array con espacios y aï¿½ade el carï¿½cter nulo al final
	memset(espacio, ' ', longitud);
    espacio[longitud] = '\0';

    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            if ((modo == 'e' && ch == 13) || // Enter
                (modo == 'a') || // Cualquier tecla
                (modo == 'n' && ch >= '0' && ch <= '9')) { // Tecla numï¿½rica
                textoCentro(espacio, y);
                break;
            }
        }
        if (show) {
            textoCentro(const_cast<char*>(txt), y);
        } else {
            textoCentro(espacio, y);
        }
        show = !show;

        Sleep(500); // retardo
        gotoxy(0, y);
    }
    delete[] espacio; // Libera la memoria
}

//Transesa: Transporte Seguro y Eficiente S.A.

void cartelLogoEmpresa() {
	cout << GREEN;
    gotoxy(13, 3);
    printf("######## ########     ###    ##    ##  ######  ########  ######     ###    ");
    gotoxy(13, 4);
    printf("   ##    ##     ##   ## ##   ###   ## ##    ## ##       ##    ##   ## ##   ");
    gotoxy(13, 5);
    printf("   ##    ##     ##  ##   ##  ####  ## ##       ##       ##        ##   ##  ");
    gotoxy(13, 6);
    printf("   ##    ########  ##     ## ## ## ##  ######  ######    ######  ##     ## ");
    gotoxy(13, 7);
    printf("   ##    ##   ##   ######### ##  ####       ## ##             ## ######### ");
    gotoxy(13, 8);
    printf("   ##    ##    ##  ##     ## ##   ### ##    ## ##       ##    ## ##     ## ");
    gotoxy(13, 9);
    printf("   ##    ##     ## ##     ## ##    ##  ######  ########  ######  ##     ## ");
    cout << BLACK;
}

void membrete (){
	system("cls");
	system("mode con: cols=100 lines=30");
	system("color 70");
	sinMaximVentana();
	margen();
	cout << BLUE;
	gotoxy(5,1); cout << hora() << BLACK;
	cout << WINE;
	gotoxy(85,1); cout << fecha() << BLACK;
}


void splash(){
	membrete();
	cartelLogoEmpresa();
	cout << BG_MAGENTA << WHITE ;
	textoCentro("Transesa: Transporte Seguro y Eficiente S.A.",12);
	cout << BG_COW ;
	alternarLocale();
	textoCentro("Sistema de gestión de ventas",14);
	alternarLocale();
	cout << BG_YELLOW;
	textoCentro("Creado por Fragusan. Todos los derechos reservados 2024",27);
	cout << BG_COW << BLACK;
	hiddenCur();
	parpadeo("PRESIONA ENTER PARA INICIAR", 24, 'e');
	charger("Cargando base de datos...");
}

void generarTabla(int xInicial, int yInicial, const vector<int>& anchosColumnas, const vector<string>& titulos) {
    int numColumnas = anchosColumnas.size();
    int xActual = xInicial;
    int ySuperior = yInicial;
    int yInferior = yInicial + 2;

    // Dibujar cada celda de la tabla con el ancho especificado para cada columna
    for (int i = 0; i < numColumnas; ++i) {
        int xFinal = xActual + anchosColumnas[i];

        // Usa `cuadrito` para dibujar el borde de cada columna
        int esquinaIzqSup = (i == 0) ? 201 : 203;
        int esquinaDerSup = (i == numColumnas - 1) ? 187 : 202;
        int esquinaIzqInf = (i == 0) ? 200 : 202;
        int esquinaDerInf = (i == numColumnas - 1) ? 188 : 202;

        cuadrito(xActual, ySuperior, xFinal, yInferior, esquinaIzqSup, esquinaDerSup, esquinaDerInf, esquinaIzqInf);

        // Imprimir título en el centro de la celda
        int xTexto = xActual + (anchosColumnas[i] / 2) - (titulos[i].length() / 2);
        gotoxy(xTexto, ySuperior + 1);
        cout  << ORANGE<< titulos[i];

        // Mover la posición xActual para la siguiente celda
        xActual += anchosColumnas[i];
    }
    cout  << BLACK;
}

void generarTablaConInterior(int xInicial, int yInicial, const vector<int>& anchosColumnas, const vector<string>& titulos) {
    int numColumnas = anchosColumnas.size();
    int xActual = xInicial;
    int ySuperior = yInicial;
    int yInferior = yInicial + 2;

    // Dibujar cada celda de la tabla con el ancho especificado para cada columna
    for (int i = 0; i < numColumnas; ++i) {
        int xFinal = xActual + anchosColumnas[i];

        // Configurar caracteres de esquina para dar sensación de continuidad
        int esquinaIzqSup = (i == 0) ? 204 : 206;       // 204 para el borde izquierdo
        int esquinaDerSup = (i == numColumnas - 1) ? 185 : 206; // 185 para el borde derecho
        int esquinaIzqInf = (i == 0) ? 204 : 202;
        int esquinaDerInf = (i == numColumnas - 1) ? 185 : 202;

        cuadrito(xActual, ySuperior, xFinal, yInferior, esquinaIzqSup, esquinaDerSup, esquinaDerInf, esquinaIzqInf);

        // Imprimir título en el centro de la celda
        int xTexto = xActual + (anchosColumnas[i] / 2) - (titulos[i].length() / 2);
        gotoxy(xTexto, ySuperior + 1);
        cout << titulos[i];

        // Mover la posición xActual para la siguiente celda
        xActual += anchosColumnas[i];
    }
}

void cuadritoSimple(int xs, int ys, int xe, int ye, int esquina1, int esquina2, int esquina3, int esquina4){ //hacer sobrecarga de metodo para cuadro anidado
	int i;
	//control horizontal
	for (i= xs; i<= xe; i++){
		gotoxy(i,ys); printf("%c\n", 196);
		gotoxy(i,ye); printf("%c\n", 196);
	}
	//control vertical
	for (i= ys; i<= ye; i++){
		gotoxy(xs,i); printf("%c\n", 179);
		gotoxy(xe,i); printf("%c\n", 179);
	}
	//primera esquina
	gotoxy(xs,ys); printf("%c\n", esquina1);
	//segunda esquina
	gotoxy(xe,ys); printf("%c\n", esquina2);
	//tercera esquina
	gotoxy(xe,ye); printf("%c\n", esquina3);
	//cuarta esquina
	gotoxy(xs,ye); printf("%c\n", esquina4);
}

void generarInteriorSimple(int xInicial, int yInicial, const vector<int>& anchosColumnas, const vector<string>& titulos) {
    int numColumnas = anchosColumnas.size();
    int xActual = xInicial;
    int ySuperior = yInicial;
    int yInferior = yInicial + 2;

    // Dibujar cada celda de la tabla con el ancho especificado para cada columna
    for (int i = 0; i < numColumnas; ++i) {
        int xFinal = xActual + anchosColumnas[i];

        // Configurar caracteres de esquina para dar sensación de continuidad
        int esquinaIzqSup = (i == 0) ? 195 : 197;       // 204 para el borde izquierdo
        int esquinaDerSup = (i == numColumnas - 1) ? 180 : 197; // 185 para el borde derecho
        int esquinaIzqInf = (i == 0) ? 195 : 193;
        int esquinaDerInf = (i == numColumnas - 1) ? 180 : 193;

        cuadritoSimple(xActual, ySuperior, xFinal, yInferior, esquinaIzqSup, esquinaDerSup, esquinaDerInf, esquinaIzqInf);

        // Imprimir título en el centro de la celda
        int xTexto = xActual + (anchosColumnas[i] / 2) - (titulos[i].length() / 2);
        gotoxy(xTexto, ySuperior + 1);
        cout << titulos[i];

        // Mover la posición xActual para la siguiente celda
        xActual += anchosColumnas[i];
    }
}

void cuadritoSimpleFinal(int xs, int ys, int xe, int ye, int esquina1, int esquina2, int esquina3, int esquina4) {
    int i;
    // Control horizontal
    for (i = xs; i <= xe; i++) {
        gotoxy(i, ys);
        printf("%c\n", 196); // Línea horizontal
        gotoxy(i, ye);
        printf("%c\n", 196); // Línea horizontal
    }
    // Control vertical
    for (i = ys; i <= ye; i++) {
        gotoxy(xs, i);
        printf("%c\n", 179); // Línea vertical
        gotoxy(xe, i);
        printf("%c\n", 179); // Línea vertical
    }
    // Esquinas
    gotoxy(xs, ys);
    printf("%c\n", esquina1); // Esquina superior izquierda
    gotoxy(xe, ys);
    printf("%c\n", esquina2); // Esquina superior derecha
    gotoxy(xe, ye);
    printf("%c\n", esquina3); // Esquina inferior derecha
    gotoxy(xs, ye);
    printf("%c\n", esquina4); // Esquina inferior izquierda
}

void generarSimpleFinal(int xInicial, int yInicial, const vector<int>& anchosColumnas, const vector<string>& titulos, bool esUltimaFila) {
    int numColumnas = anchosColumnas.size();
    int xActual = xInicial;
    int ySuperior = yInicial;
    int yInferior = yInicial + 2;

    for (int i = 0; i < numColumnas; ++i) {
        int xFinal = xActual + anchosColumnas[i];

        // Configurar caracteres de esquina según sea la última fila
        int esquinaIzqSup = (i == 0) ? 195 : 197; // Código 195 para la primera columna
        int esquinaDerSup = (i == numColumnas - 1) ? 180 : 197;
        int esquinaIzqInf = (i == 0 && esUltimaFila) ? 192 : 193; // Código 192 para última fila
        int esquinaDerInf = (i == numColumnas - 1 && esUltimaFila) ? 217 : 180; // Código 217 para última fila

        cuadritoSimpleFinal(xActual, ySuperior, xFinal, yInferior, esquinaIzqSup, esquinaDerSup, esquinaDerInf, esquinaIzqInf);

        // Imprimir título centrado
        int xTexto = xActual + (anchosColumnas[i] / 2) - (titulos[i].length() / 2);
        gotoxy(xTexto, ySuperior + 1);
        cout << titulos[i];

        // Avanzar posición
        xActual += anchosColumnas[i];
    }
}

int errorMsj (int a, int b, int c, int d,char *msj, bool bandera){
		hiddenCur();
    	cuadritoLineaEfecto(a,b,c,d);
    	alternarLocale();
    	cout << WINE;
    	textoCentro(msj,21);
        cout  << BLACK;
        Sleep(1500);
        alternarLocale();
        cin.ignore();
        //if(bandera){ principal();}
        return 0;
}


// inicio (){
//	membrete ();
//	cartelLogoEmpresa()
//	hiddenCur();
//	parpadeo("PRESIONA ENTER PARA INICIAR", 24, 'e');
//}
