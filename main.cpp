#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>

int RANGO=20;
int N=800;
int INTENTOS=2;
using namespace std;
string Convert (float number){
    std::ostringstream buff;
    buff<<number;
    return buff.str();}
/*
void Imprimir(int **Mat){
	for(int x=0;x<N;x++){
		cout << "[";
    	for(int y=0;y<N;y++)
    		cout << Mat[x][y]<<" ";
    	cout << "]"<<endl;
    	}
}*/
void transpose(int **src, int **dst) {
    for(int x=0;x<N;x++)
    	for(int y=0;y<N;y++)
    		dst[y][x]=src[x][y];
    }
    
int main(int argc, char const *argv[])
{
	N=atoi(argv[1]);
	INTENTOS=atoi(argv[2]);
	ofstream file;
	clock_t tiempoInicio, tiempoFinal;
	double segundos;
	srand((unsigned)time(NULL));
	file.open("Resultados.txt",ios::app);
	int **P_Matriz1;
	P_Matriz1=new int*[N];
	int **P_Matriz2;
	P_Matriz2=new int*[N];
	int **P_Matriz2_T;
	P_Matriz2_T=new int*[N];
	int **P_MatrizR;
	P_MatrizR=new int*[N];
	for(int i=0;i<N;i++)
	{
		P_Matriz1[i]=new int[N];
		P_Matriz2[i]=new int[N];
		P_Matriz2_T[i]=new int[N];
		P_MatrizR[i]=new int[N];
	}
	//LLENADO DE MATRICES 1 Y 2
	
		for(int x=0;x<N;x++)
			for(int y=0;y<N;y++)
			{
				P_Matriz1[x][y]=(rand()%(RANGO+1))-(RANGO/2);
				P_Matriz2[x][y]=(rand()%(RANGO+1))-(RANGO/2);
			}
		transpose(P_Matriz2,P_Matriz2_T);
	file << "'Resultados para N=" << N << " y sin transponer:'\n";
	cout <<"\nResultados para N=" << N << " y sin transponer:"<<endl;
	for(int inte=0;inte<INTENTOS;inte++)
	{
		//Multiplicación sin transponer
		tiempoInicio=clock();
		for(int a=0;a<N;a++){
	   	 	for(int i=0;i<N;i++) {
	        	int suma=0;
	        	for (int j=0;j<N;j++) 
	            	suma+=P_Matriz1[i][j]*P_Matriz2[j][a];
	            P_MatrizR[i][a]=suma;
	        }
	    }
		tiempoFinal = clock();
		segundos = (double) (tiempoFinal - tiempoInicio) / CLOCKS_PER_SEC;
		cout << "Tamano Matriz: " << N << "x" << N << " tardo: " << segundos << endl;
		file << Convert(segundos) <<"\n";	
	}
	file << "'Resultados para N=" << N << " y con transponer:'\n";
	cout <<"\nResultados para N=" << N << " y con transponer:"<<endl;
	for(int inte=0;inte<INTENTOS;inte++)
	{
		tiempoInicio=clock();
		for(int a=0;a<N;a++){
	   	 	for(int i=0;i<N;i++) {
	        	int suma=0;
	        	for (int j=0;j<N;j++) 
	            	suma+=P_Matriz1[i][j]*P_Matriz2_T[a][j];
	            P_MatrizR[i][a]=suma;
	        }
	    }
		tiempoFinal = clock();
		segundos = (double) (tiempoFinal - tiempoInicio) / CLOCKS_PER_SEC;
		cout << "Tamano Matriz: " << N << "x" << N << " tardo: " << segundos << endl;
		file << Convert(segundos) <<"\n";	
	}
	file.close();
    return 0;
}


