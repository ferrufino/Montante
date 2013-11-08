#include <iostream>
using namespace std;


int matriz[100][100];
int static n=0;
int x;
int arr[100];
int pivAct;
int pivAnt=1;
bool despl = true;
bool ckeck= true;



void cambiarRenglon(int temp, int a){
    
    int arr[100];
    int var=n;
    for (int i =0; i<var+1; i++) {
        
        arr[i] = matriz[a][i];
        
        matriz[a][i] = matriz[temp][i];
        
        matriz[temp][i] = arr[i];
    }
    pivAct= matriz[a][a];
   
   
}



bool checaArriba(int p){
    if (p != 0) {
        return true;
    }
    return false;
}
bool checaAbajo(int p) {
    if (p <= n - 1) {
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
        j = p + 1;
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
    
    //cout<<"DEBUG:: Entra opercion Montante Primer"<<endl;
    for(int i = 0; i < p; i++){
        matriz[i][i] = pivAct;
        
    }
    
    
    for(int i = 0; i < p; i++){
        while(b < n + 1){
            
            matriz[p - f][p + g] = (matriz[p][p] * matriz[p -f][p + g] - matriz[p - f][p] * matriz[p][p + g]) / pivAnt;
            g++;
            b++;
            
        }
        b = p + 1;
        g = 1;
        f++;
        
    }
    
    for(int i = 0; i < p; i++){
        
        matriz[i][p] = 0;
    }
    
}
void respuesta(){
    int cont=0;
    int x1,x2;
    //cout<< "DEBUG:: RESPUESTA:";
    for (int i = 0; i<n; i++) {
        x2=matriz[cont][i];
        x1=matriz[cont][n];
        cout  << x1 << "/" << x2 << " ";
        cont+=1;
    }
    cout<<endl;
}

void montante(){
    
    //cout<<"DEBUG:: Entra opercion Montante"<<endl;
    int renglon;
    bool check=false;
    
    
    for (int p = 0; p < n; p++)
    {
        pivAct = matriz[p][p];
        
        renglon=p+1;
        if (pivAct == 0) {
            while (renglon<n && check == false) {
                if (matriz[renglon][p] !=0) {
                    cambiarRenglon(renglon,p);
                        check = true;
                   
                    
                    
                    
                }
                renglon++;
            }
            
            
        }
        
        if (matriz[p][p] == 0) {
            cout<<"NO UNICA"<<endl;
            pivAnt=1;
            despl=false;
            check = false;
            break;
        }
        else{
            
            if(checaAbajo(p)){
                montanteCuarto(p);
            }
            
            if(checaArriba(p)){
                montantePrimer(p);
            }
            pivAnt = pivAct;
        }
        
    }
    
    if (matriz[n-1][n-1] == 0 && check)  {
        cout<<"NO UNICA"<<endl;
        despl=false;
        
    }
    else if(despl) {
        
        respuesta();
    }
    check = true;
    
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
    //int pos = 0;
    if (pivAct == 0) {
        int renglon = 0;
        bool cambio= false;
        // cout<<"DEBUG::PRIMER Pivote = 0"<<endl;
        while (renglon<n && cambio == false) {
            if (matriz[renglon][0] != 0) {
               
                cout<<"Pivote actual:"<<pivAct<<endl;
                cambiarRenglon(renglon, 0);
                cout<<"Pivote actual:"<<pivAct<<endl;
                
                if (pivAct != 0) {
                    cambio = true;
                    cout<<"Pivote actual:"<<pivAct<<endl;
                    break;
                }
                
                
                
            }
            renglon++;
        }
        if (!cambio){
            //desplegar();
            cout<<"NO UNICA"<<endl;
            pivAnt=1;
            
            despl=false;
        }
        else{
            //desplegar();
            cout<<"DEBUG:: valida- son multiplos? v.1"<<endl;
           // validarMultiplo();
            montante();
        }
        
    }
    else{
        //cout<<"DEBUG:: valida- son multiplos? v.2"<<endl;
        //validarMultiplo();
        montante();
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
        despl=true;
        
        
    }
    
    return 0;
}
