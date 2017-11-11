#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	char buffer [80], *ptr;
	int kilos, suma = 0, sumalinea;
	cout << " Introduzca el texto linea a linea. \n";
	for (; ; )
		{ sumalinea = 0;
			cin.getline(buffer, 80);
		if (strlen(buffer) == 0)
			break; // salida del bucle
	ptr = strtok(buffer, " ");
while (ptr)
{
	if ((kilos = atoi (ptr)) != 0)
		sumalinea += kilos;
	ptr = strtok(NULL, " ");
}
cout << " La suma de kg en linea es: " << sumalinea << endl;
suma += sumalinea;
}
cout << " La suma de kg de todas las lineas es: " << suma << endl; system("PAUSE");
}