/**
 * @file Sonar.c
 * @author Josef Mička (jozkamic@seznam.cz)
 * @brief 
 * @version 0.1
 * @date 2022-03-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Sonar.h"


/**
 * @brief Check change of depth by comparing the previous and current value
 * 
 * @param prev_depth previous value
 * @param new_depth current value
 * @return DEPTH_INCREASED,DEPTH_NOTCHANGED or DEPTH_DECREASED
 */
int DepthCheck(int prev_depth, int new_depth)
{
    if (new_depth > prev_depth)
    {
        return DEPTH_INCREASED;
    }
    else if (new_depth == prev_depth)
    {
        return DEPTH_NOTCHANGED;
    }
    
    return DEPTH_DECREASED;
}