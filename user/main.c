/* --COPYRIGHT--,BSD
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
/******************************************************************************
 * MSP432 Empty Project
 *
 * Description: An empty project that uses DriverLib
 *
 *                MSP432P401
 *             ------------------
 *         /|\|                  |
 *          | |                  |
 *          --|RST               |
 *            |                  |
 *            |                  |
 *            |                  |
 *            |                  |
 *            |                  |
 * Author: 
*******************************************************************************/
/* DriverLib Includes */
#include <driverlib.h>

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>
#include <led.h>
#include <key.h>
#include "sysinit.h"
#include "baudrate_calculate.h"
#include "delay.h"
#include "usart.h"
#include "timA.h"

#define CLKDIV 48     // ?????
#define CCR0 19999    // ???0
#define CCR1_MIN 499  // ( 499 + 1) / (19999 + 1) =  500 / 20000 =  2.5%
#define CCR1_MAX 2499 // (2499 + 1) / (19999 + 1) = 2500 / 20000 = 12.5%


int main(void)
{
    bool dir = 1;
    uint16_t i = CCR1_MIN;

    SysInit();    //?3? ????
    delay_init(); //?4? ????
    TimA1_PWM_Init(CCR0, CLKDIV); //?8? ???A PWM
    while (1)
    {
        if (dir)
            i++;
        else
            i--;

        if (i == CCR1_MAX)
        {
            dir = 0;
            delay_ms(50);
        }
        else if (i == CCR1_MIN)
        {
            dir = 1;
            delay_ms(50);
        }
        MAP_Timer_A_setCompareValue(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_2, i);
        delay_us(600);
    }
}
