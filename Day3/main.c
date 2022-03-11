/**
 * @file main.c
 * @author Josef Mička (jozkamic@seznam.cz)
 * @brief This is the main file of Advent of Code (2021) - Day 3; What is the power consumption of the submarine?
 * @version 0.1
 * @date 2022-03-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Length of the line
 * 
 */
#define LINE_LEN 20

/**
 * @brief Expected bit length
 * 
 */
#define BIT_LEN 12


/**
 * @brief The main function of the program
 * 
 * @return int 
 */
int main(int argc, char *argv[]) {

    // The array must be filled with zeros, so use static.
    static int bitcount[BIT_LEN];  
    static char line[LINE_LEN];
    
    unsigned int gammarate = 0;
    unsigned int epsilonrate = 0;

    // Open a file with the input date
    FILE *pfl = fopen(argv[1], "r");

    if (pfl == NULL)
    {
        exit(1);
    }

    // Go through input data
    while (fgets(line, LINE_LEN, pfl))
    {
        // Read the input line byte by byte and count the appearance of ones and zeros at every position.
        for (int i = 0; i < BIT_LEN; i++)
        {
            switch (line[i])
            {
                case '0': bitcount[i]--; break;
                case '1': bitcount[i]++; break;
                default: i = BIT_LEN; // Finish the for cycle
            }            
        }                                         
    }

    // Compose the gammarate number and epsilonrate number
    for (int i = 0; i < BIT_LEN; i++)
    {
        gammarate <<= 1;
        epsilonrate <<= 1;

        if (bitcount[i] >= 0)
        {
            gammarate += 1;
        }
        else
        {
            epsilonrate += 1;
        }
        
    }

    fclose(pfl);

    // Give a final report
    printf("Gamma rate * epsilon rate = %lu * %lu = %lu \n\r", gammarate, epsilonrate, gammarate * epsilonrate);

    return 0;
}


