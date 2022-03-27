#include <stdio.h>
#include <string.h>

#define WIERSZE 8
#define KOLUMNY 8

int palindrom(int a,int b,int c,int d,int e){
  if(a!=0 && b!=0 && c!=0 && a==e && b==d) return 1;
  else return 0;
}

int sprawdz_czy_wygral(int a[WIERSZE][KOLUMNY],int w,int k){
  int minK; int maxK;
  if((k-4)>0) minK = k-4;
  else minK = 0;
  if((k+4)<KOLUMNY) maxK = k+4;
  else maxK = KOLUMNY - 1;
  int minW; int maxW;
  if((w-4)>0) minW = w- 4;
  else minW = 0;
  if((w+4)<WIERSZE) maxW = w+4;
  else maxW = WIERSZE - 1;


  int found = 0; //DLA WSZYSTKICH PETLI; JAK KTORAS GO ZMIENI TO NIE SPRAWDZAMY RESZTY

  // wiersz:
  int i = minK;
  while((i+4)<=maxK && found==0){
    if (palindrom(a[w][i],a[w][i+1],a[w][i+2],a[w][i+3],a[w][i+4])){
      found=1;
    }
    i++;
  }

  //kolumna:
  int j = w;
  if (found == 0 && (j+4)<=7){ // sprawdzamy tylko 4 w dol
    if (palindrom(a[j][k],a[j+1][k],a[j+2][k],a[j+3][k],a[j+4][k])){
      found=1;
    }

  }


  //na ukos (z gory do dolu w prawo):
  //a[wiersz][kolumna]
  int j1 = minW; int i1 = minK;
  if (k-4<0 && w>=k){
    i1=0; //kolumna
    j1=w-k; //wiersz
  }
  else if (w-4<0 && k>=w){
    i1=k-w;
    j1=0;
  }

  while(((j1+4)<=maxW && (i1+4)<=maxK) && found==0){
    if(palindrom(a[j1][i1],a[j1+1][i1+1],a[j1+2][i1+2],a[j1+3][i1+3],a[j1+4][i1+4])){
      found =1;
    }
    i1++; j1++;
  }

  //na ukos (z dolu do gory w prawo):
  // j2- wiersz; i2 - kolumna;

  int j2=maxW; int i2=minK; //j2 sie zmienilo
  if ((w+4>7) && (k>7-w)){ //"przecina sie z osia x"
    i2=k-(7-w);
    j2=7;
  }
  else if ((k-4<0) && (7-w>=k)){ // "przecina sie z osia y"
    i2=0;
    j2=w+k;
  }

  while(((j2-4)>=0 && (i2+4)<=7) && found==0){
    if(palindrom(a[j2][i2],a[j2-1][i2+1],a[j2-2][i2+2],a[j2-3][i2+3],a[j2-4][i2+4])){
      found =1;
    }
    i2++; j2--;
  }

  return found;
}

int pelna_plansza(int licznik_wierszy[KOLUMNY]){
    //zwroci 1 jesli wypelniona, zwroci 0 jesli nie wypelniona
    int i=0; int zw = 1;
    while(i<KOLUMNY && zw==1){ // jedna petla ktora sprawdza czy istnieje niepusta kolumna
      if (licznik_wierszy[i]<=(KOLUMNY-1)) zw =0; // plansza nie jest zapelniona
      i++;
    }
  return zw;
}

void update_board(int arr[WIERSZE][KOLUMNY], int licznik_wierszy[KOLUMNY],int kol,int nr_gracza){
  arr[KOLUMNY-1-licznik_wierszy[kol]][kol] = nr_gracza;
  licznik_wierszy[kol]++;

}

void print_board(int arr[WIERSZE][KOLUMNY]){
  for(int i=0;i<WIERSZE;i++){
    for(int j=0;j<KOLUMNY;j++){
      if(arr[i][j]==0) printf(" -");
      else  printf(" %d", arr[i][j]);
    }
    printf("\n");
  }
  for(int i=0;i<WIERSZE;i++){
    printf(" %c",i+'a');
  }
  printf("\n");
}


int get_input(int a[WIERSZE][KOLUMNY]){ // Zwraca numer kolumny lub -1 jesli user wyszedl z programu
  int ch; int i=0; int ch1; int x;
  while ((ch=getchar()) != '\n'){
    if (ch==EOF) return -1;
    ch1 = ch;
    i++;
  }
     if (i==1){ //uzytkownik wpisal 1 znak i enter
      x = ch1-'a';
      if(x<KOLUMNY && x>=0 && a[0][x]==0){ // spr czy jest miedzy a i h + czy kolumna nie jest pelna
        return x;
      }
      else if ((ch1-'=')==0){
        return -1;
      }
      else return -2;
    }
    else return -2;

}

int main(){

    int arr[WIERSZE][KOLUMNY] = {{0}};
    int licznik_wierszy[KOLUMNY] = {0};

//poczatek programu:
  int pelna =0; int input=0; int wygrana =0;int nr_gracza =1;
  print_board(arr);
  while(input!=-1 && wygrana!=1){
    printf("%d:\n",nr_gracza);
    input = get_input(arr);
    if (input != -1){
      if (input!=-2 && pelna==0){
        update_board(arr,licznik_wierszy,input,nr_gracza); //dodaje input do tablicy i updatuje licznik wierszy
      }
      print_board(arr);
      if (input!=-2){
        wygrana = sprawdz_czy_wygral(arr,(WIERSZE-licznik_wierszy[input]),input);
        if(wygrana) printf("%d.\n",nr_gracza);
        pelna = pelna_plansza(licznik_wierszy);
        nr_gracza = (nr_gracza+1)%2;
        if(nr_gracza==0) nr_gracza =2;
      }
    }
  }
}
