/*
    * data-stats.h
    * 
    * Author: Junoput
    * Date: 2024-11-04
    *
*/

#ifndef __DATA_STATS_H__
#define __DATA_STATS_H__

#define MAX_SYMBOLS 256

typedef unsigned int symboleCount;
typedef char symbole;

/*
    * dataGetSymbols
    * 
    * Get the number of occurrences of each symbol in the data.
    * 
    * @param data: The data to analyze.
    * @param len: The length of the data.
    * 
    * @return: An array of symboleCount of lenght MAX_SYMBOLS, with the number of each simbole instances.
*/
symboleCount *dataGetSymbolsOccurrence(const char *data, unsigned int len);

/*
    * dataEntropy
    * 
    * Calculate the entropy of the data.
    * 
    * @param data: The data to analyze.
    * @param len: The length of the data.
    * 
    * @return: The entropy of the data.
*/
float dataEntropy(const char *data, int len);

#endif // __DATA_STATS_H__
