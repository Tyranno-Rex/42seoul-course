#include <stdio.h>
#include <stdarg.h>

double  average(int count, ...){
    double avg = 0;
    va_list ap;
    va_start(ap, count);
    for (int i = 0; i < count; i++){
        avg += va_arg(ap, double);
        printf("%d ", avg);
    }
    avg = avg / count;
    va_end(ap);
    return avg;
}


int main(){
    double avg, count = 4;
    avg = average(count, 1, 39, 22, 10);
    printf("%f", avg);
}