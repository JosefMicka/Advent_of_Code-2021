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

#include "Sonar.h"

/**
 * @brief Input data
 * 
 */
int sonarData[] = {199, 200, 208, 210, 200, 207, 240, 269, 260, 263};


/**
 * @brief The main function of the program
 * 
 * @return int 
 */
int main() {

    // Get number of elements in sonarData array     
    int count = sizeof(sonarData)/sizeof(sonarData[0]);

    // Check the data
    for (int i = 0; i < count; i++)
    {
        printf("%d ", sonarData[i]);
        if (i == 0) // The first sample must be skipped because there is no previous reference value
        {
            printf("(N/A - no previous measurement)\r\n");
        }
        else
        {
            // Check the change of value
            switch(DepthCheck(sonarData[i-1], sonarData[i]))
            {
                case DEPTH_DECREASED: printf("(decreased)\r\n"); break;
                case DEPTH_INCREASED: printf("(increased)\r\n"); break;
                case DEPTH_NOTCHANGED: printf("(not changed)\r\n"); break;
            }
        }
    }
    return 0;
}
