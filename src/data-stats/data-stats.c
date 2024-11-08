/*
    * data-stats.c
    * 
    * Author: Junoput
    * Date: 2024-11-04
    *
*/
#include "data-stats.h"

#include <stdlib.h>
#include <math.h>

void incrementSymbol(symboleOccurrence *symbols, symbole symbol) {
    symboleOccurrence *current = symbols;
    while (current->next != NULL) {
        if (current->symbol == symbol) {
            current->count++;
            return;
        }
        current = current->next;
    }

    symboleOccurrence *newSymbol = malloc(sizeof(symboleOccurrence));
    newSymbol->symbol = symbol;
    newSymbol->count = 1;
    newSymbol->next = NULL;
    current->next = newSymbol;
}

void freeSymbols(symboleOccurrence *symbols) {
    symboleOccurrence *current = symbols;
    while (current != NULL) {
        symboleOccurrence *next = current->next;
        free(current);
        current = next;
    }
}

symboleOccurrence *dataGetSymbolsOccurrence(const char *data, unsigned int len) {
    const symbole *symboleData = (const symbole *)data; // type-punning data to type symbole

    symboleOccurrence *symbols = malloc(sizeof(symboleOccurrence) * MAX_SYMBOLS);
    symbols->next = NULL;
    symbols->count = 0;
    symbols->symbol = 0;

    if (symboleData == NULL || len == 0) {
        return symbols;
    }

    for (unsigned int i = 0; i < len; i++) {
        incrementSymbol(symbols, symboleData[i]);
    }

    return symbols;
}

float dataEntropy(const char *data, int len) {
    if (data == NULL || len == 0) {
        return 0.0;
    }

    symboleOccurrence *symbols = dataGetSymbolsOccurrence(data, len);

    // Calculate entropy
    // H(X) = Σ probability(x) * log2(1/probability(x))
    float entropy = 0.0;
    while (symbols->next != NULL) {
        if (symbols->count > 0) {
            float probability = (double)symbols->count / (len * sizeof(symbole));
            entropy = probability * log2(1/probability);
        }
    }

    freeSymbols(symbols);
    return entropy;
}
