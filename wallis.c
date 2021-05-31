#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float wallis_pi(int a);
{
    int numerator = 1,denominator = 1;
    float pi_value;

    for (int i = 1; i<=a ; i++)
        {
        numerator *= 4 *  i *i;
        denominator *= (4 * i * i - 1);
        }
        
    float real_value;
    real_value = numerator/denominator;
    
    for (int j = 1; j < 5 ;j++)
        {
        float remainder, decimal_number, decimal_part;
        remainder = numerator % denominator;
        remainder *= 10;
        decimal_number = remainder/denominator;
        decimal_part = decimal_number * pow(10,-j);
        real_value += decimal_part;
        }
    pi_value = 2 * real_value;
    return (pi_value);
}

int main(void) {
  float pi,M_PI = 3.14159;
  for (int i=0; i<5; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) > 0.15)) {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
}

