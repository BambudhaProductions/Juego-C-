#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>//se usa para generar un numero aleatorio.
using namespace std;

//globales
int numero,numeroU,numeroD,numeroC,numeroA;
int numeroAU,numeroAD,numeroAC;
int numeroIntentos = 0;
int sw;
bool victoria = false;
void buscandoSimilitudes();
int validarNumero(char numero[3]);

int main(){
    	char numero[3];
//generando numero aleatorio de 3 cifras
	srand(time(NULL));
	numeroA = 1 + rand ()%(1000);
	
// partiendo el numero aleatorio en unidad, decena y centena
	numeroAC = numeroA%10, numeroA/=10;
	numeroAD = numeroA%10, numeroA/=10;
	numeroAU = numeroA%10, numeroA/=10;

//cout<<"\nEl numero aleatorio es: "<<numeroAU<<numeroAD<<numeroAC<<endl;
do{   
        cout<<endl;
	cout<<"\t\t\t\t::[INSTRUCCIONES]::\n"<<endl;
	cout<<"Usted debera encontrar un numero de 3 cifras, si acierta la unidad, decena o centena del numero aleatorio se le marcara con un 'BIEN',de lo contrario se le marcara con un 'MAL'."<<endl;
	cout<<"Recuerde que tendra una cantidad limitada de intentos [20], sino perdere el juego."<<endl;
        cout<<"\nDigite un numero de 3 cifras: ";
    	gets(numero);
    	
    	sw = validarNumero(numero);
    	
    	if (sw==0){
	// partiendo el numero del usuario en unidad, decena y centena
		numeroC = numero[2]%10, numero[2]/=10;
		numeroD = numero[1]%10, numero[1]/=10;
		numeroU = numero[0]%10, numero[0]/=10;

		buscandoSimilitudes();	
		
	// condicional para ganar el juego							    
		if((numeroAU==numeroU)&&(numeroAD==numeroD)&&(numeroAC==numeroC)){
		cout<<"\n--[FELICIDADES USTED HA ENCONTRADO EL NUMERO]--"<<endl;
		cout<<"\nEl numero de intentos ha sido de: "<<numeroIntentos<<endl;
		victoria = true;
		break;
		}
	}
	else{// cuando digita un numero o caracter invalido
		cout<<"\nComando Invalido\n"<<endl;
		system("pause");
		system("cls");
	}
   
 }while(numeroIntentos<20);
    
      cout<<endl;
      cout<<"\t--[GAME OVER]--"<<endl;
      cout<<endl;
      system("pause");
      return 0;
}

void buscandoSimilitudes(){
	
if((numeroAU!=numeroU)&&(numeroAD!=numeroD)&&(numeroAC!=numeroC)){
	cout<<"3 mal"<<endl;
	numeroIntentos++;
	} 
		    
	 else if((numeroAU!=numeroU)&&(numeroAD!=numeroD)&&(numeroAC==numeroC)){
	 cout<<"2 mal 1 bien"<<endl;
	 numeroIntentos++;
	 } 
		    
	 else if((numeroAU!=numeroU)&&(numeroAD==numeroD)&&(numeroAC!=numeroC)){
	 cout<<"2 mal 1 bien"<<endl;
	 numeroIntentos++;
         } 
		    
	else if((numeroAU==numeroU)&&(numeroAD!=numeroD)&&(numeroAC!=numeroC)){
	cout<<"2 mal 1 bien"<<endl;
	numeroIntentos++;
	} 
		    
	else if((numeroAU==numeroU)&&(numeroAD==numeroD)&&(numeroAC!=numeroC)){
	cout<<"2 bien 1 mal"<<endl;
	numeroIntentos++;
	} 
		    
	else if((numeroAU==numeroU)&&(numeroAD!=numeroD)&&(numeroAC==numeroC)){
	cout<<"2 bien 1 mal"<<endl;
	numeroIntentos++;
        } 
		    
	else if((numeroAU!=numeroU)&&(numeroAD==numeroD)&&(numeroAC==numeroC)){
	cout<<"2 bien 1 mal"<<endl;
	numeroIntentos++;
	} 
		    
	system("pause");
	system("cls");
}

int validarNumero(char numero[3]){
	int i=0, sw=0, j;
	j = strlen(numero); 
	
	while(i<j && sw==0){
		if(isdigit(numero[i])!=0 && j==3){
		    i++;
		}
		else{
		    sw = 1;
		}
	}
	return sw;		
}


	        
		



