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

void desplegar(){
  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j< n+1; j++) {
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
void cambiarRenglon(int temp, int a){
    
    int arr[100];
    int var=n;
    for (int i =0; i<var+1; i++) {
        
        arr[i] = matriz[a][i];
        
        matriz[a][i] = matriz[temp][i];
        
        matriz[temp][i] = arr[i];
    }
    pivAct= matriz[a][a];
   
    //desplegar();
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
    //cout<<"DEBUG:: Entra opercion Montante Cuarto"<<endl;
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
    int x;
    bool check=false;
    
    
    for (int p = 0; p < n; p++)
    {
        pivAct = matriz[p][p];
        
        x=p+1;
        if (pivAct == 0) {
            while (x<n && check == false) {
                if (matriz[x][p] !=0) {
                    cambiarRenglon(x,p);
                        check = true;
                   
                    
                    
                    
                }
                x++;
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
void validarMultiplo(){
    int temp=0;
    int a,b;
    bool same = false;
      while (temp<n) {
        
        for (int i =0; i<n+1; i++) {
         a=matriz[i][temp];
         b=matriz[i+1][temp];
         // cout<<"DEBUG:: a: "<<a<<" y b: "<<b<<endl;
          if ( (b == 0 && a == 1) || ( b == 1 && a== 0) ) {
         same = false;
         break;
         }
         else if ((matriz[i][temp]) > matriz[i+1][temp] ) {
         if(!(a % b) || !(a != b)){
         same=false;
         break;
         
         }
         else{
         if(!(b % a) || !(a != b)){
         same=false;
         break;
         
         }
         }
         
         }
         
         
         }
        temp++;
    }
    if (same) {
        //desplegar();
        cout<<"NO UNICA 3"<<endl;
        pivAnt=1;
        
        despl=false;
    }
      
    else{
        //desplegar();
        //cout<<"DEBUG:: No contiene ecuaciones que son multiples"<<endl;
    }
      
        montante();
    
    
    
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
