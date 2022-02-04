int buscaBinaria (int x, int n, int v[]) { 
   int e = -1, d = n; 
   int k = 0;// atenção!
   
   while (e < d-1) {  
      int m = (e + d)/2;
      if (v[m] < x){ 
          e = m;
          if(v[e] == x) k++;
      }
      else { 
          d = m;
          if(v[d] == x) k++;
      }
   }
   
   return k;
}
