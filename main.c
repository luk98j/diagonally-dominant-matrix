#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int dd_test( const int * ptr, int width, int height );

int main()
{

   int size = 5;
    int tabT[size][size];
    int * ptrTab = &tabT[0][0];

    printf( "Podaj liczby:\n" );
    for(int i = 0; i < size; i++ )
    {
        for(int j = 0;j<size;j++){
     int scan = scanf( "%d", ptrTab+size*i+j);
     if(scan==0){
            printf("Incorrect input");
            return 1;
            break;
        }
        }
    }
    int test = dd_test( ptrTab, size, size);
    if(test==0){
        printf("NO");

    }
    if(test==1){
        printf("YES");

    }
    if(test==-1){
        printf("Error");
    }
    return 0;

}

int dd_test( const int * ptr, int width, int height )
{
    if( width != height || ptr == NULL )
        {
            return -1;
    }
    if (width<1||height<1)return -1;
    int sumDiag = 0;
    int sumRow = 0;
    int i,j;
    int sumDiag_temp = 0;
    int sumRow_temp = 0;
    for(i = 0; i < width; i++ )
    {
        for(j = 0; j < height; j++, ptr++ )
        {
            if(i==j)
            {
                sumDiag += abs(*ptr);
                sumDiag_temp += abs(*ptr);
            }
            else
            {
                sumRow += abs(*ptr);
                sumRow_temp += abs(*ptr);
            }

        }
        if( sumDiag_temp <= sumRow_temp )
            {
                return 0;
            }
        sumDiag_temp = 0;
        sumRow_temp = 0;

    }
    if( sumDiag <= sumRow )
            {
                return 0;
            }else{
            return 1;
            }
}
