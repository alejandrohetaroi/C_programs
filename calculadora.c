//Programa que ejecutara una calculadora


//directivas de preprocesador
#include <stdio.h>
#include <math.h>

int dividirbinarios();
int restabinario(int num1, int num2);
int sumabinario(int x, int y);
char * decimaltobinario(int numero);
int printbinario(char *ptr);

//Muestra el menu de opcciones
int menu() {
	
	static int seleccion;
	/*Menu de la calculadora*/
	printf("LAS OPERACIONES SERÁN SÓLO PARA NÚMEROS NO MAYORES A 1 BYTE\n");
	printf("Seleccione una opcion ingresando el numero que la precede\n");
	printf(" 1. Sumar Binarios \n 2. Restar Binarios\n 3. Multiplicar Binarios \n 4. Dividir Binarios \n 5. Convertir decimal a binario \n\n");
 	scanf("%d",&seleccion);
 	return seleccion;

}




int main() {


	int option = menu();
	int num;
	int x,y;
	int resultado;
	static char *pointer; //Permite mostrar los numeros de formato decimal en binario

	//SUMAR 
 	if(option == 1){
 		printf("USTED SELECCIONÓ LA SUMADORA DE NÚMEROS BINARIOS\n");
 		printf("EL RESULTADO LO OBTENDRÁ POR PANTALLA EN BINARIO\n");
 		printf("NÚMERO 1: \n");
 		scanf("%d",&x);
 		printf("NÚMERO 2: \n");
 		scanf("%d",&y);
 		resultado = sumabinario(x,y);
 		pointer = decimaltobinario(x);
 		printbinario(pointer);
 		pointer = decimaltobinario(y);
 		printbinario(pointer);
 		printf("\t\t--------\n");
 		pointer = decimaltobinario(resultado);
 		printbinario(pointer);
 		


 	  //RESTAR
 	} else if(option == 2){
 		printf("USTED SELECCIONÓ RESTAR NÚMEROS BINARIOS\n");
 		printf("EL RESULTADO LO OBTENDRÁ POR PANTALLA EN BINARIO\n");
 		printf("NÚMERO 1: \n");
 		scanf("%d",&x);
 		printf("NÚMERO 2: \n");
 		scanf("%d",&y);
 		resultado = restabinario(x,y);
 		printf("El resultado de la resta es %d\n", resultado);


 	} else if(option == 3){
		printf("Usted ha seleccionado Multiplicar binarios\n");
		printf("NÚMERO 1: \n");
 		scanf("%d",&x);
 		printf("NÚMERO 2: \n");
 		scanf("%d",&y);
 		resultado = x*y;
 		pointer = decimaltobinario(x);
 		printbinario(pointer);
 		pointer = decimaltobinario(y);
 		printbinario(pointer);
 		printf("\t\t--------\n");
 		pointer = decimaltobinario(resultado);
 		printbinario(pointer);


 	} else if(option == 4){
 		printf("USTED HA SELECCIONADO DIVIDIR BINARIOS\n");
 		printf("INGRESE EL DIVIDENDO: \n");
 		scanf("%d",&x);
 		printf("INGRESE EL DIVISOR: \n");
 		scanf("%d",&y);
 		resultado = x/y;
 		pointer = decimaltobinario(x);
 		printbinario(pointer);
 		pointer = decimaltobinario(y);
 		printbinario(pointer);
 		printf("\t\t--------\n");
 		pointer = decimaltobinario(resultado);
 		printbinario(pointer);


 	} else if(option == 5){
 		printf("Usted a seleccionado convertir de decimal a binario\n");
 		scanf("%d",&num); //se ingresa valor a convertir
 		pointer = decimaltobinario(num);
 		printbinario(pointer);


 	} else {
 		printf("Debe Ingresar una opcion valida\n");

 	}

 	return 0;
}


int sumabinario(int x, int y)
{
	int carry; //acarreo
	//El ciclo se detiene cuando no hay mas acarreo
    while (y != 0) {
        //Encontramos donde existe acarreo con AND y desplazamos y bit el resultado
        carry = (x & y) << 1;
        //sumamos
        x=x^y;
        /*actualizamos el valor de y con el acarreo para encontrar nuevamente donde hay acarreo
        en la siguiente iteracion. */
        y=carry;
      }
    return x; 
}


//Esta funcion realiza resta binaria
int restabinario(int num1, int num2) 
{
    int carry;

    //se  obtiene complemento a dos
    num2 = sumabinario(~num2, 1);

    while (num2 != 0) {
		//Encuentro el acarreo                
        carry = (num1 & num2) << 1;
              
        //realizo la suma
		num1 = num1 ^ num2;
		//sumo el acarreo en la siguiente iteración
        num2 = carry;  
    }
    
    return num1;
}


// Esta funcion convierte un numero decimal a binario
char * decimaltobinario(int numero){	
	/*
		NOTA LOS OPERADORES BINARIOS SOLO FUNCIONAN CON ENTEROS
		char 1 byte (8 bits)
		int 2 bytes (16 bits)
	*/
	static char bin[8];
	char *ptr;
	ptr = bin;
	unsigned int contador = 128; 			// 2 (n-1) n = 8 ; 2*2*2*2*2*2*2*2

	for(contador; contador > 0 ; contador >>= 1){
		if (contador & numero){
			//printf("1");			
			*ptr = 1;	//Asigno el valor uno a la direccion de memoria que apunta ptr
			ptr++;   	//incremento el apuntador

		}else {
			*ptr = 0;
			ptr++;
		}
	}
	return bin; //paso 

	}


//Imprime vector
int printbinario(char *ptr){
	for (int j = 0; j < 8; j++ ){
		
		if(j == 0){
			printf("\t\t");
		}
		printf("%d",*ptr++);

		if(j == 7){
			printf("\n");
		}
	}
}




/*
    regla para restar numero binarios

    0 - 0 = 0
    0 - 1 = 1 (genera un acarreo negativo)
    1 - 0 = 1
    1 - 1 = 0

*/

/*
    regla para restar numero binarios

    0 + 0 = 0
    0 + 1 = 1
    1 + 0 = 1
    1 + 1 = 0 (genera un acarreo de 1 el cual se suma a la siguiente etapa)


*/



