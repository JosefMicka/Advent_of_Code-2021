/**
 * @file main.c
 * @author Josef Mička (jozkamic@seznam.cz)
 * @brief This is the main file of Advent of Code (2021) - Day 1
 * @version 0.1
 * @date 2022-03-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

#include "Sonar.h"

/**
 * @brief Size of character buffer
 * 
 */
#define LINE_LEN 20


/**
 * @brief The main function of the program
 * 
 * @return int 
 */
int main(int argc, char *argv[]) {

    char line[LINE_LEN];
    int count_inc = 0;

    // Initialize values to the negative number because depth cannot have a negative value.
    int prev_value = -1;
    int new_value = -1;

    FILE *pfl = fopen(argv[1], "r");

    if (pfl == NULL)
    {
        exit(1);
    }
    
    // Go through input data
    while (fgets(line, LINE_LEN, pfl))
    {
        new_value = atoi(line);

        printf("%d ", new_value);

        if (prev_value < 0) // The first sample must be skipped because there is no previous reference value
        {
            printf("(N/A - no previous measurement)\r\n");
        }
        else
        {
            // Check the change of value
            switch(DepthCheck(prev_value, new_value))
            {
                case DEPTH_DECREASED: printf("(decreased)\r\n"); break;
                case DEPTH_INCREASED: printf("(increased)\r\n"); count_inc++; break;
                case DEPTH_NOTCHANGED: printf("(not changed)\r\n"); break;
            }
        }
        prev_value = new_value; 
    }
    
    fclose(pfl);

    // Give a final report
    printf("Measurement value increased: %d times\n\r", count_inc);

    return 0;
}
