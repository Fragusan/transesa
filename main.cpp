#include <iostream>

#include "utils.h"
#include "menuPrincipal.h"
using namespace std;


int main() {
	system("mode con: cols=100 lines=30");
	system("color 70");
	splash();
	principal();
	
	return 0;
}
