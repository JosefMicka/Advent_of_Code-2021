/**
 * @file main.c
 * @author Josef Mička (jozkamic@seznam.cz)
 * @brief This is the main file of Advent of Code (2021) - Day 1 part B
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

#define WINDOW_LEN 3
#define BUFFER_LEN (WINDOW_LEN+1)

/**
 * @brief The main function of the program
 * 
 * @return int 
 */
int main(int argc, char *argv[]) {

    char line[LINE_LEN];
    int count_inc = 0;
    int winA = 0;
    int winB = 0;
    int buffer[BUFFER_LEN]; 

    FILE *pfl = fopen(argv[1], "r");

    if (pfl == NULL)
    {
        exit(1);
    }

    // Initialize the buffer with the first 3 samples
    for (int i = 0; i < BUFFER_LEN-1; i++)
    {
        if (fgets(line, LINE_LEN, pfl))
        {
            buffer[i] = atoi(line);
        } 
        else
        {
            printf("Not enough samples!\r\n");
            exit(2);
        }       
    }
    
    
    // Go through input data
    while (fgets(line, LINE_LEN, pfl))
    {
        // Insert new value to the buffer
        buffer[BUFFER_LEN-1] = atoi(line);

        winA = buffer[0] + buffer[1] + buffer[2];
        winB = buffer[1] + buffer[2] + buffer[3];

        printf("%d < %d: ", winA, winB);

        // Check the change of value
        switch(DepthCheck(winA, winB))
        {
            case DEPTH_DECREASED: printf("(decreased)\r\n"); break;
            case DEPTH_INCREASED: printf("(increased)\r\n"); count_inc++; break;
            case DEPTH_NOTCHANGED: printf("(not changed)\r\n"); break;
        }

        // Shift the data in the buffer, throw away the 'oldest' value
        for (int i = 1; i < BUFFER_LEN; i++)
        {
            buffer[i-1] = buffer[i];         
        }              
    }
    
    fclose(pfl);

    // Give a final report
    printf("Window value increased: %d times\n\r", count_inc);

    return 0;
}
