/**
 * @file main.c
 * @author Josef Mička (jozkamic@seznam.cz)
 * @brief This is the main file of Advent of Code (2021) - Day 2
 * @version 0.1
 * @date 2022-03-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Length of the line
 * 
 */
#define LINE_LEN 50

/**
 * @brief Possible commands
 * 
 */
const char cmd_fwd[] = "forward";
const char cmd_dwn[] = "down";
const char cmd_up[] = "up";


/**
 * @brief The main function of the program
 * 
 * @return int 
 */
int main(int argc, char *argv[]) {

    char line[LINE_LEN];

    int horizontal = 0;
    int depth = 0;

    FILE *pfl = fopen(argv[1], "r");

    if (pfl == NULL)
    {
        exit(1);
    }

    // Go through input data
    while (fgets(line, LINE_LEN, pfl))
    {
        // Check the command and extract the value
        if (strstr(line, cmd_fwd) != NULL)
        {
            horizontal += atoi(line + sizeof(cmd_fwd));
        }
        else if (strstr(line, cmd_dwn) != NULL)
        {
            depth += atoi(line + sizeof(cmd_dwn));
        }     
        else if (strstr(line, cmd_up) != NULL)
        {
            depth -= atoi(line + sizeof(cmd_up));
        }                   
    }
    
    fclose(pfl);

    // Give a final report
    printf("Horizontal position * depth = %d * %d = %d \n\r", horizontal, depth, horizontal * depth);

    return 0;
}


