/*
    * data-stats.c
    * 
    * Author: Junoput
    * Date: 2024-11-04
    *
*/
#include "data-stats.h"

#include <stdio.h>

symboleCount *dataGetSymbolsOccurrence(const char *data, unsigned int len) {
    if (data == NULL || len == 0) {
        return NULL;
    }

    symboleCount *symbols = (symboleCount *)calloc(MAX_SYMBOLS,sizeof(symboleCount));
    if (symbols == NULL) {
        return NULL;
    }

    for (unsigned int i = 0; i < len; i++) {
        symbols[(symbole)data[i]]++;
    }

    return symbols;
}

float dataEntropy(const char *data, int len) {
    if (data == NULL || len == 0) {
        return 0.0;
    }

    symboleCount *symbols = dataGetSymbolsOccurrence(data, len);
    if (symbols == NULL) {
        return 0.0;
    }

    // Calculate entropy
    // H(X) = Σ probability(x) * log2(1/probability(x))
    float entropy = 0.0;
    for (int i = 0; i < MAX_SYMBOLS; i++) {
        if (symbols[i] > 0) {
            float probability = (float)symbols[i] / len * sizeof(symbole);
            entropy = probability * log2(1/probability);
        }
    }

    free(symbols);
    return entropy;
}
