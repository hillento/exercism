#include "rational_numbers.h"

rational_t standardize (rational_t r1){
	if(r1.denominator < 1){
		r1.numerator = -r1.numerator;
		r1.denominator = -r1.denominator;
	}
	return r1;
}
int gcd(int a, int b){

	if(a < 0){
		a = -a;
	}
	if(b < 0){
		b = -b;
	}
	if(a == 0){
		return b;
	}
	if(b==0){
		return a;
	}

	if(a==b){
		return a;
	}

	if(a>b){
		return gcd(a-b,b);
	}
	return gcd(a,b-a);
}
rational_t reduce(rational_t r1){
	int d = gcd(r1.numerator, r1.denominator);
	r1.numerator /= d;
	r1.denominator /= d;
	return standardize(r1);
}

rational_t add(rational_t r1, rational_t r2){
	rational_t r;
	r.denominator = r1.denominator*r2.denominator;
	r.numerator = (r1.numerator*r2.denominator)+(r2.numerator*r1.denominator);
	return reduce(r);
}

rational_t subtract(rational_t r1,rational_t r2){
	rational_t r;
	r.denominator = r1.denominator * r2.denominator;
	r.numerator = (r1.numerator * r2.denominator) - (r2.numerator * r1.denominator);
	return reduce(r);
}

rational_t multiply(rational_t r1, rational_t r2){
	rational_t r;
	r.denominator = r1.denominator * r2.denominator;
	r.numerator = r1.numerator * r2.numerator;
	return reduce(r);

}
rational_t divide(rational_t r1, rational_t r2){
	rational_t r;
	r.numerator = (r1.numerator * r2.denominator);
	r.denominator = (r1.denominator * r2.numerator);
	return reduce(r);
}
rational_t absolute(rational_t r1){
	rational_t r;
	if(r1.numerator < 0){
		r1.numerator *= -1;
	}
	if(r1.denominator < 0){
		r1.denominator *= -1;
	}
	r.numerator = r1.numerator;
	r.denominator = r1.denominator;
	return reduce(r);
}
rational_t exp_rational(rational_t r1, int16_t n){
   //rational_t r = { -3, 5 };
   //int16_t n = -2;
   //rational_t expected = { 25, 9 };
	rational_t r;
	r.numerator = 1;
	r.denominator = 1;
	if(n < 0){
		n *= -1;
		int a = r1.numerator;
		r1.numerator = r1.denominator;
		r1.denominator = a;
	}
	for( int i = 0; i < n; i++){
		r.numerator *= r1.numerator;
		r.denominator *= r1.denominator;
	}
	return reduce(r);
}
float exp_real(uint16_t x, rational_t r1){
	return pow(pow(x,(float)r1.numerator),1/(float)r1.denominator);
}

