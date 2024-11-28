#include <iostream>
#include "utils.h"
#include "menuPrincipal.h"
#include "menuVenta.h"
#include "Mysql.h"
using namespace std;

int main() {
	splash();
	principal();
	membrete(); 
	cartelLogoEmpresa();
	principal();
	//otro();
	//otre();  ---->
	//mirando(); prueba la conexion con la base de datos
	return 0;
}
