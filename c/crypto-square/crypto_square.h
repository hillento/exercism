#ifndef CRYPTO_SQUARE_H
#define CRYPTO_SQUARE_H

typedef struct coordinates {
	int row;
	int col;
}coordinates;

typedef struct directions {
	char name[2];
	coordinates direction;
} directions;


char *ciphertext(const char *input);

#endif
