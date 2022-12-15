//------------------------------------------------------------------------------
//
//  Description: This is the timers.c file where all the timers needed to run
//  functions go
//  Mohamed Mohamed-Ali
//  October 5 2022
//  Built with IAR Embedded Workbench Version: (7.21.1)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

#include "macros.h"
#include  "functions.h"
#include  "msp430.h"

/*
void Init_TimerB1P5(void){
TB1CTL |= TBCLR;
TB1CTL |= TBSSEL__ACLK; 
TB1CTL |= MC__UP;
TB1CCR0 = CNTR__2;
TB1CCTL0 |= CCIE; 
TB1CCTL0 &= ~CCIFG; 
TB1CCR1 = CNTR__10;
TB1CCTL1 |= CCIE; 
TB1CCTL1 &= ~CCIFG; 
}
*/

// Timer B0 initialization sets up both B0_0, B0_1-B0_2 and overflow
void Init_Timer_B0(void) {
TB0CTL = TBSSEL__SMCLK; // SMCLK source
TB0CTL |= TBCLR; // Resets TB0R, clock divider, count direction
TB0CTL |= MC__CONTINOUS; // Continuous up
TB0CTL |= ID__2; // Divide clock by 2
TB0EX0 = TBIDEX__8; // Divide clock by an additional 8
TB0CCR0 = TB0CCR0_INTERVAL; // CCR0
TB0CCTL0 |= CCIE; // CCR0 enable interrupt
TB0CCTL0 &= ~CCIFG;
TB0CCR1 = TB0CCR1_INTERVAL; // CCR1
TB0CCTL1 |= CCIE; // CCR1 enable interrupt
TB0CCTL1 &= ~CCIFG; 
// TB0CCR2 = TB0CCR2_INTERVAL; // CCR2
//TB0CCTL2 &= ~CCIE; // CCR2 enable interrupt
//TB0CCTL1 &= ~CCIFG;
TB0CTL &= ~TBIE; // Disable Overflow Interrupt
TB0CTL &= ~TBIFG; // Clear Overflow Interrupt flag
}
//------------------------------------------------------------------------------

// Timer B1 initialization sets up both B0_0, B0_1-B0_2 and overflow

void Init_Timer_B1(void) {
TB1CTL = TBSSEL__SMCLK; // SMCLK source
TB1CTL |= TBCLR; // Resets TB0R, clock divider, count direction
TB1CTL |= MC__CONTINOUS; // Continuous up
TB1CTL |= ID__2; // Divide clock by 2
TB1EX0 = TBIDEX__8; // Divide clock by an additional 8
TB1CCR0 = TB1CCR0_INTERVAL; // CCR0
TB1CCTL0 |= CCIE; // CCR0 enable interrupt
TB1CCTL0 &= ~CCIFG;
TB1CCR1 = TB0CCR1_INTERVAL; // CCR1
TB1CCTL1 |= CCIE; // CCR1 enable interrupt
TB1CCTL1 &= ~CCIFG; 
// TB0CCR2 = TB0CCR2_INTERVAL; // CCR2
// TB0CCTL2 |= CCIE; // CCR2 enable interrupt
// TB0CCTL1 &= ~CCIFG;
TB1CTL &= ~TBIE; // Disable Overflow Interrupt
TB1CTL &= ~TBIFG; // Clear Overflow Interrupt flag
}

//------------------------------------------------------------------------------

// Timer B2 initialization sets up both B0_0, B0_1-B0_2 and overflow

void Init_Timer_B2(void) {
TB2CTL = TBSSEL__SMCLK; // SMCLK source
TB2CTL |= TBCLR; // Resets TB0R, clock divider, count direction
TB2CTL |= MC__CONTINOUS; // Continuous up
TB2CTL |= ID__2; // Divide clock by 2
TB2EX0 = TBIDEX__8; // Divide clock by an additional 8
TB2CCR0 = TB2CCR0_INTERVAL; // CCR0
TB2CCTL0 |= CCIE; // CCR0 enable interrupt
TB2CCTL0 &= ~CCIFG;
TB2CCR1 = TB2CCR1_INTERVAL; // CCR1
TB2CCTL1 |= CCIE; // CCR1 enable interrupt
TB2CCTL1 &= ~CCIFG; 
// TB0CCR2 = TB0CCR2_INTERVAL; // CCR2
// TB0CCTL2 |= CCIE; // CCR2 enable interrupt
// TB0CCTL1 &= ~CCIFG;
TB2CTL &= ~TBIE; // Disable Overflow Interrupt
TB2CTL &= ~TBIFG; // Clear Overflow Interrupt flag
}
//------------------------------------------------------------------------------

void Init_Timer_B3(void) {
//------------------------------------------------------------------------------
// SMCLK source, up count mode, PWM Right Side
// TB3.1 P6.0 R_FORWARD
// TB3.2 P6.1 R_REVERSE
// TB3.3 P6.2 L_FORWARD
// TB3.4 P6.3 L_REVERSE
//------------------------------------------------------------------------------
TB3CTL = TBSSEL__SMCLK; // SMCLK
TB3CTL |= MC__UP; // Up Mode
TB3CTL |= TBCLR; // Clear TAR
TB3CCR0 = WHEEL_PERIOD; // PWM Period
TB3CCTL1 = OUTMOD_7; // CCR1 reset/set
RIGHT_FORWARD_SPEED = WHEEL_OFF; // P6.0 Right Forward PWM duty cycle
TB3CCTL2 = OUTMOD_7; // CCR2 reset/set
RIGHT_REVERSE_SPEED = WHEEL_OFF; // P6.1 Right Reverse PWM duty cycle
TB3CCTL3 = OUTMOD_7; // CCR3 reset/set
LEFT_FORWARD_SPEED = WHEEL_OFF; // P6.2 Left Forward PWM duty cycle
TB3CCTL4 = OUTMOD_7; // CCR4 reset/set
LEFT_REVERSE_SPEED = WHEEL_OFF; // P6.3 Left Reverse PWM duty cycle
//------------------------------------------------------------------------------
}
