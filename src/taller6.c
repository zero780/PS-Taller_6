
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define T_LINEA 100

void reemplazar(char *texto, int n){
	for(int i=0; i<n; i++){
		if(texto[i]=='\n'){
			texto[i]=0;
		}
	}
}
int cuadrado(int numero){
      int  cuadrado=numero*numero;
       return cuadrado;
}

int main(int argc, char **argv){
	int max, min;
        int *arreglo=NULL;
        int capacidad_arr=5;
        arreglo=malloc(capacidad_arr*sizeof(int));
	float suma =0;
	int contPromedio=1;
	float resultado = 0;
	int limite =1;
	int contLimite =0;
	char entrada[T_LINEA];
	if(argc==3 && strcmp(argv[1],"-n")==0){
		limite = atoi(argv[2]);
	}
	fgets(entrada, T_LINEA, stdin);
	reemplazar(entrada, T_LINEA);

	while(strcmp(entrada,"x")!=0 && contLimite < limite){	
		suma+=atof(entrada);
		contPromedio++;
		//maximo y minimo
		arreglo[contPromedio-1]=atoi(entrada);
                //duplicado, solo que no se inicializa con 0 la otra porciòn, no sabìa como y decidì hacerlo con realloc nomàs
                if(contPromedio-1==capacidad_arr){
                 arreglo=realloc(arreglo,(contPromedio*2)*sizeof(int));
                }
		max=arreglo[0];
		min =arreglo[1];
		for(int i=0; i<contPromedio; i++){   	
			if(arreglo[i]<min && arreglo[i]!=0){
				min= arreglo[i];
			}
			if(arreglo[i]>max){
				max=arreglo[i];
			}			
		}
		if (argc==3 && strcmp(argv[1],"-n")==0){
			contLimite++;
		}
		if(contLimite< limite){
			fgets(entrada, T_LINEA, stdin);
			reemplazar(entrada, T_LINEA);
		}
	}
	if(contPromedio>1){
		resultado =suma/(contPromedio-1);		
		
	}
	 //desviaciòn estandar
	float sumador=0;
	//el tamaño del arreglo lo calculè con esta formula:
        //int tama=sizeof(arreglo)/sizeof(int);
	int i=1;
	while(i<contPromedio){
		sumador=sumador+ ((arreglo[i]-resultado))*((arreglo[i]-resultado));
		//printf("%.3f\n", sumador);
		i++;
	}        
	//printf("N ES %d", contPromedio);
	float dividir= (sumador/(contPromedio-1));
	//printf("LA DIVISION ES %g\n", dividir);
	double desviacion = sqrt(dividir);          
	printf("%.2f\t\t%d\t\t%d\t\t%.4g\n", resultado,min,max,desviacion);
	return 0;
}
