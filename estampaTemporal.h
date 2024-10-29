#include <ctime> // para el tiempo
#include <sstream> //para archivo donde se guarda la hora
#include <iomanip> //para manipular los textos de la hora
#include <string> //para manipular string

using namespace std;

string fecha(){
	time_t t = time(nullptr);
	tm* now = localtime(&t);
	stringstream ss;
	ss  << now->tm_mday 
	<< '/' << (now->tm_mon + 1)
	<< '/' <<(now->tm_year + 1900);
	string fecha = ss.str();
	return fecha;
}

string hora(){
	time_t t = time(nullptr);
	tm* now = localtime(&t);
	stringstream ss;
	ss << setfill('0') << setw(2) << now->tm_hour << ':'
	<< setfill('0') << setw(2) << now->tm_min << ':'
	<< setfill('0') << setw(2) << now->tm_sec;
	string hora = ss.str();
	return hora;
}
