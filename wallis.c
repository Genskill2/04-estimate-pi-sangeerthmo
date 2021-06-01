#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float wallis_pi(int);


int main(void) {
  float pi;
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
float wallis_pi(int a)
{
    
	long double  num = 1 ,  pi_value = 1 ;
	
	for (int j =1 ; j = 1 + a ; j++)
    {
    	long double num = 4 * (j+1) * (j+1);
    	pi_value *= (num/(num - 1));
	}
	return pi_value * 2;
}
