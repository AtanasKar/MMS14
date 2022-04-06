#include <stdio.h>
#include <stdlib.h>

double* movingAverage(double*x,size_t len,size_t window){
    double* avgArr=malloc(sizeof(double)*(len/window));
    size_t avgArrIndex=0;
    for (size_t i = 0; i <= len-window; i++)
    {
        double sum=0;
        for (size_t j = i; j < window+i; j++)
        {
            sum+=x[j];

        }
       
        i+=window-1;
        avgArr[avgArrIndex]=sum/window;
       avgArrIndex++;
    }
    
    return avgArr;
}

int main(){
    double arr[]={1,2,3,1,2,3,1,2};
    double* arrAvg = movingAverage(arr,8,2);

    for (size_t i = 0; i < 4; i++)
    {
        printf("%lf ",arrAvg[i]);
    }
    putchar('\n');

    free(arrAvg);

    return EXIT_SUCCESS;
}