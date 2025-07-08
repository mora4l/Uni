int Fattoriale(int numero){ 
 int f; 
 
 if (numero==0) 
  f = 1; 
 else  
  f = numero*Fattoriale(numero-1); 
 return f; 
 } 