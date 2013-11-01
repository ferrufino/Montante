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
int pivAct;
int pivAnt;
int k = 0;

void desplegar(){

    for (int i = 0; i < n; i++) {
        for (int j = 0; j< n+1; j++) {
            cout<<matriz[i][j];
        }
        cout<<endl;
    }

}


bool checaArriba(int p){
	if (p != 0) {
		return true;
	}
	return false;
}

bool checaAbajo(int p) {
	if (p <= n -1) {
		return true;
	}
	return false;
}



void montanteCuarto(int p){
	int b = 1;
	int a = 1;
	int i = p + 1;
	int j = p + 1;
	while(i < n) {
		while(j < n+1) {
			matriz[p + b][p + a] = (matriz[p][p] * matriz[p + b][p + a] - matriz[p + b][p] * matriz[p][p + a]) / pivAnt;
			a++;
			j++;
		}
		b++;
		a = 1;
		i++;
	}
	
	int h = p + 1;
	while(h < n){
		matriz[h][p] = 0;
		h++;
	}
	
}

void montantePrimer(int p) {
	int f = 1;
	int g = 1;
	int b = p + 1;
	
    
	for(int i = 0; i < p; i++){
		while(b < n + 1){
            
			matriz[p - f][p + g] = (matriz[p][p] * matriz[p -f][p + g] - matriz[p - f][p] * matriz[p][p + g]) / pivAnt * -1;
			g++;
			b++;
		}
		f++;
        
	}
    
	for(int i = 0; i < p; i++){
		matriz[i][i] = pivAct;
		matriz[i][p] = 0;
	}
    
}

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

void validarMultiplo(){
    int temp=0;
    bool same = true;
    while (temp<n) {
     
        for (int i =0; i<n+1; i++) {
            if ((matriz[i][temp]) != matriz[i+1][temp] ) {
                same=false;
            }
        }
        temp++;
    }
    if (same) {
        desplegar();
        cout<<"NO UNICA"<<endl;
    }
    else{
        desplegar();
        cout<<"DEBUG:: No contiene ecuaciones que son multiples"<<endl;
        for (int p = 0; p < n; p++)
        {
            pivAct = matriz[p][p];
            if(checaAbajo(p)){
                cout<<"DEBUG:: montante abajo"<<endl;
                montanteCuarto(p);
            }
            if(checaArriba(p)){
                 cout<<"DEBUG:: montante arriba"<<endl;
                montantePrimer(p);
            }
            pivAnt = pivAct;
        }
    
    }
   


}
void cambiarRenglon(int temp){

    int arr[10];
    
    for (int i =0; i<n+1; i++) {
        
        arr[i] = matriz[0][i];
        
        matriz[0][i] = matriz[temp][i];
        
        matriz[temp][i] = arr[i];
    }
}




void vaciar(){//vacia y despliega datos
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n+1 ; j++)
        {
            //cout<<matriz[i][j];//DEBUG
            matriz[i][j]=0;
            
        }
        //cout<<endl;//DEBUG
    }
    
    
}
void validacionMontante(){

    pivAct = matriz[0][0];
    int pos = 0;
    if (pivAct == 0) {
        int temp = 0;
        bool cambio= false;
        cout<<"DEBUG:: Pivote = 0"<<endl;
        while (temp<n || cambio == false) {
            if (matriz[pos][temp] != 0) {
                cambio = true;
                cambiarRenglon(temp);
               
            }
            temp++;
        }
        if (!cambio){
            desplegar();
            cout<<"NO UNICA"<<endl;
        }
        else{
            desplegar();
            cout<<"DEBUG:: valida- son multiplos? v.1"<<endl;
            validarMultiplo();
        }
        
    }
    else{
        cout<<"DEBUG:: valida- son multiplos? v.2"<<endl;
        validarMultiplo();
    }

}
int main()
{
    //n=numero de ecuaciones
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
        
        validacionMontante();
        cin >> n;
        
    }
	
	return 0;
}