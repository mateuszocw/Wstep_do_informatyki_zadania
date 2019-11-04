#include <iostream>
using namespace std;
const int MAX=8;
int x=MAX*MAX-2;
int kolumna=MAX/2;
int wiersz=MAX/2;
int t[MAX][MAX];
int main() {
   t[MAX/2][MAX/2]=MAX*MAX-1;


       for (int i = 1; i < MAX; i+=2) {                             //caly cykl gora->lewo->dol->prawo, i+=2 bo o tyle komorek powieksza sie slimak za kazdym cyklem
           for (int j = 1; j <=i;
           j++)
           {
               wiersz--;
               t[wiersz][kolumna] = x;
               x--;
           }
           for (int k = 1; k <= i; k++) {
               kolumna--;
               t[wiersz][kolumna] = x;
               x--;
           }

           for (int l = 1; l <=i+1; l++)
           {
               wiersz++;
               t[wiersz][kolumna] = x;
               x--;
           }
           for (int m = 1; m <= i+1; m++) {
               kolumna++;
               t[wiersz][kolumna] = x;
               x--;
           }

       }
    if(MAX%2==1)
    {
        for(int i=0; i<MAX; i++)
        {    wiersz--;
            t[wiersz][kolumna] = x;
            x--;}
    }

   for(int n=0; n<MAX; n++)
{
for(int p = 0;p<MAX;p++)
{
cout<<t[n][p]<<" ";
}
cout<<endl;
}
   return 0;
}
