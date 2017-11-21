#include <iostream>

using namespace std;

int getAnio(int date);
int  getMonth(int date);
int  getDay(int date);
bool  isValidDate(int date);
bool  isValidYear(int a);
bool  isValidMonth(int d,int m, int a);
bool isValidDay(int d, int maxDias);
bool isYearBiciesto(int a);


int  main() {
	
	int  date = 20171115;

	if(isValidDate(date)){
		
		cout<<"Fecha correcta: "<<endl;
		cout<<"Fecha anio: "<< getAnio(date)<<endl;
		cout<<"Fecha mes: "<< getMonth(date)<<endl;
		cout<<"Fecha dia: "<< getDay(date)<<endl;

	}else{
		cout<<"Invalid date"<<endl;;
	}


}





int getAnio(int date){

	return date/10000;
}
int  getMonth(int date){

	return (date%10000)/100;
}
int  getDay(int date){

	return (date%10000)%100;
}
	
	bool  isValidDate(int date){
		int  anio = getAnio(date);
		int  mes = getMonth(date);
		int  dia = getDay(date);


		//si tenemos un ano correcto y un mes correcto segun a sus dias
		if(isValidYear(anio) && isValidMonth(dia,mes, anio)){
			return true;
		}else{
			return false;
		}
	}


	bool  isValidYear(int a){
		//si es multiplo de 4 el anio entonces el mes de febrero tien un
		//dia mas 
		if(a>1900 && a < 2018){
			return true;
		}else {
			return false;
		}

	}

	bool  isValidMonth(int d,int m, int a){
		//si es un mes valido
		if(m > 0 && m < 12){
			//si es un mes de 31 dias
			if(m == 1 || m == 3 || m == 5 ||m == 7 ||m == 8 ||m == 10 ||m == 12 ){
					return isValidDay(d,31);
				
				//si son los restantes meses exepto mes 2 solo 30 dias
			}else if(m != 2){
					return isValidDay(d,30);
				//si es el mes dos comprobamos si no es anio biciesto
			}else{
				//si es anio biciesto mes dos entre 0 a 29
				if(isYearBiciesto(a)){

					return isValidDay(d,29);
					
				//si no es biciesto mes dos entre 0 y 28 dias
				}else{
					
					return isValidDay(d,28);
				}
			}

			//si no es un mes valido
		}else{
			return false;
		}
	}

	bool isValidDay(int d, int maxDias){
		/*Dia valido si esta etre 0 y 31 exepto si es mes dos el anio no tiene q ser biciesto
		si el anio es biciesto el mes dos tiene q tener 29 dias*/
		if(d > 0 && d <= maxDias ){
				return true;
		}else{
				return false;
		}

	}

	bool isYearBiciesto(int a){
		/*si es multiplo de cuatro es anio biciesto*/
		/*cada 4 anios es biciesto execto si ese anio es multiplo de 100*/
		//primero si es un anio valido
		if(isValidYear(a)){
			//si es biciesto o no
			if(a % 4 == 0 && a % 100 != 0 ){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	}







