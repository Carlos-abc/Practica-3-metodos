#include<stdio.h>

void GenerarMatriz(int tamano, float matriz[][tamano],float inversa[][tamano]){

	int i, j;

	for(i=0; i<tamano; i++)
		for(j=0; j<tamano; j++){

			printf("Ingrese el elemento [ %d ][ %d ] de la matriz: ",i,j); // Llenado de la matriz
            scanf("%f",&matriz[i][j]);
            
            if(i == j){
				
				inversa[i][j] = 1.00; // Llenado de la matriz identidad
			
			}else inversa[i][j] = 0.00;

		}	
}
void PintaMatrizAumentada(int tamano, float matriz[][tamano]){
	
	int i, j;

	for(i=0; i<tamano; i++){
		for(j=0; j<tamano*2; j++){  // tamano * 2 para poder imprimir la matriz identidad

			if(i<tamano && j<tamano){
				
				printf("[ %.2f ]",matriz[i][j]);
				
			}else if(j-i == tamano){ // condicion para poder imprimir 1 en la diagonal principal
				
				printf("[ %.2f ]",1.00);
			
			} else printf("[ %.2f ]",0.00);
			
			
		
			
		}
		
		printf("\n");
	}
	
}

void Inversa(int tamano, float matriz[][tamano],float inversa[][tamano]){
	
	//reduccion por renglones
	int i,j,k;
	float aux, pivote;
	
	for(i=0; i<tamano; i++){
		
		pivote = matriz[i][i]; // Se utiliza el pivote para poder reducir los elemtnos que se encuentren por debajo o encima del pivote a 0
		
			//Convertir el pivote a 1 y aplicar la operacion sobre toda la fila
		for(k=0; k<tamano; k++){
					
					matriz[i][k] = matriz[i][k] / pivote;
					inversa[i][k] = inversa[i][k] / pivote;
			
			
		}
		
		//Ciclo para convertir a 0 todo lo que esta por debajo y encima del pivote
		for(j=0; j<tamano; j++){
			
			
			if(i!=j){    //No esta haciendo las operaciones en la diagonal
			
			
			aux = matriz[j][i];
			
				for(k =0; k<tamano; k++){
							
							matriz[j][k] = matriz[j][k] - aux*matriz[i][k];
							inversa[j][k] = inversa[j][k] - aux*inversa[i][k];
						
						
				
				}
			
			}
		
		}
		
	}
	
	printf("\n\n");
	
	//Impresion de la matriz identidad
	printf("MATRIZ IDENTIDAD\n");
	for(i=0; i<tamano; i++){
		
		for(j=0; j<tamano; j++){
	
			
			printf("[ %.7f ]",matriz[i][j]);
		
		}
	
		printf("\n");
	}
	
	//Impresion de la matriz inversa
	printf("\n");
	printf("MATRIZ INVERSA\n");
	for(i=0; i<tamano; i++){
		
		for(j=0; j<tamano; j++){
	
			
			printf("[ %.7f ]",inversa[i][j]);
		
	}
	printf("\n");

	}

}

void Multiplicacion(int tamano, float inversa[][tamano], float resultantes[tamano]){
	
	int i, j;
	float resultado[tamano];
	
	for(i=0; i<tamano; i++){
		
		resultado[i] = 0.0;
		
		for(j=0; j<tamano; j++){
			
			
			resultado[i] += inversa[i][j] * resultantes[j];
			
			
		}
		
		printf("\nResultado [ %d ]:  %.5f ",i,resultado[i]);
	}
	
}

int main(){
	
	int i,tamano;
	float valores;
	
	printf("Ingrese el tamano: ");
	scanf("%d",&tamano);
		
	printf("\n\n");

	float matriz[tamano][tamano]; // Creacion de la matriz
	float inversa[tamano][tamano]; // Creacion de la matriz identidad
	
	GenerarMatriz(tamano,matriz,inversa);
	printf("\n");
	printf("MATRIZ AUMENTADA");
	printf("\n");
	 PintaMatrizAumentada(tamano,matriz); // Imprime matriz aumentada
	 printf("\n");
	 Inversa(tamano,matriz,inversa); // Imprime la matriz inversa junto con la identidad de la original
	 
	 
	 printf("\nINGRESE LOS VALORES RESULTANTES:\n");
	 
	 float resultantes[tamano]; // Valores que van en el lado derecho de la igualdad
	 
	 for(i=0; i<tamano; i++){
	 	
		 printf("Ingrese el valor resultante [ %d ]: ",i);
		 scanf("%f",&resultantes[i]);
	 	
	 }
	 
	 printf("\n");
	 Multiplicacion(tamano,inversa,resultantes); // Se imprimen los resultados finales
		
		
		
	 
	return 0;	 
}
	 	

