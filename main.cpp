//
//  main.cpp
//  Montante
//
//  Created by Gustavo Ferrufino on 10/29/13.
//  Copyright (c) 2013 Gustavo Ferrufino. All rights reserved.
//

#include <iostream>
using namespace std;


int matriz[10][10];
int n=0;
int x;
int arr[10];


void respuesta(){
    int cont=0;
    int x1,x2;
    cout<< "DEBUG:: RESPUESTA:";
    for (int i = 0; i<n; i++) {
        x2=matriz[cont][i];
        x1=matriz[cont][n];
        cout  << x1 << "/" << x2 << " ";
        cont+=1;
    }
    cout<<endl;
}

bool validaRenglon() {
	int cont = 0;
	for(int i = 0; i < n; i++) {
		
		for(int j = 0; j < n; j++) {
			if(matriz[i][j] != 0) {
				cont++;
			}
		}
		if(cont != 1) {
			return false;
		}
		cont = 0;
	}
	return true;
}

bool validarDiagonal(){
    int cont=0;
   
    //cout<<"DEBUG:: DIAGONAL";
        for (int i=0; i<n; i++) {
            if (matriz[cont][i] == 0) {
                return false;
            }
            cout<<matriz[cont][i];
            cont+=1;
        }
    cout<<endl;
    return true;

}
void ajustarMatriz(int r, int c){

      int arr[10];
    for (int i =0; i<n+1; i++) {
        
        arr[i] = matriz[r][i];
        
        matriz[r][i] = matriz[c][i];
       
        matriz[c][i] = arr[i];
    }
    
    cout<<endl;

}

bool cambiarRenglon(){

        for (int r = 0 ; r < n; r++) {
            for( int c = 0; c < n; c++){
            if (matriz[r][c] == 1){
            
                ajustarMatriz(r,c);
              
            }
        }
    }

 
   return validarDiagonal()? true : false;

   
}

void vaciar(){//vacia y despliega datos
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n+1 ; j++)
        {
            cout<<matriz[i][j];//DEBUG
            matriz[i][j]=0;
            
        }
        cout<<endl;//DEBUG
    }
    
    
}
int main()
{
    
    cin >> n;
	while (n != 0)
	{
        
		
		vaciar();
        
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n+1; j++)
			{
				cin>>x;
				matriz[i][j]=x;
                
			}
		}
		//string validaRngln = validaRenglon() ?  "hay un dato" : "hay mas de un dato";
        //cout << validaRngln<<endl;
        if (validaRenglon()) {
            
            if (validarDiagonal()) {
                
                respuesta();
            }
            else{
                
            if (cambiarRenglon()) {
                respuesta();
            }
            else
                cout<<"DEBUG:: No Hay Respuesta"<<endl;
             respuesta();
            }
        }
        validarDiagonal();
        vaciar();
        cin >> n;
		
	}
    

	
	return 0;
}