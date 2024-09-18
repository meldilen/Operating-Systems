#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void){
    int integer = INT_MAX;
    unsigned short int unsigned_short_int = USHRT_MAX;
    long int long_int = LONG_MAX;
    float float_var = FLT_MAX;
    double double_var = DBL_MAX;

    printf ("Integer: size %zu, value %d\n", sizeof(integer), integer);
    printf ("Unsigned short int: size %zu, value %hu\n", sizeof(unsigned_short_int), unsigned_short_int);
    printf ("Long int: size %zu, value %ld\n", sizeof(long_int), long_int);
    printf ("Float: size %zu, value %f\n", sizeof(float_var), float_var);
    printf ("Double: size %zu, value %lf\n", sizeof(double_var), double_var);

    return 0;
}