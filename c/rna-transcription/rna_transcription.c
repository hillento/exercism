#include "rna_transcription.h"

char *to_rna(const char *dna)
{
    size_t l = strlen(dna);
    char *rna = calloc(1, l+1);

    for(size_t i =0; i < l+1; i++)
    {
        switch (dna[i])
        {
            case 'G':
                rna[i] = 'C';
                break;
            case 'T':
                rna[i] = 'A';
                break;
            case 'C':
                rna[i] = 'G';
                break;
            case 'A':
                rna[i] = 'U';
                break;
            default:
                rna[i] = '\0';
                break;
        }
    }
    return rna;
}
