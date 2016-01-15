#ifndef _INSTRUCTIONS_H_
#define _INSTRUCTIONS_H_

// Store value into reg 
#define I_STORE 0x10 //store reg(8) value(8)

// Load the value of reg1 into the memory address stored in reg2
#define I_LOAD  0x11 //load reg1(8) reg2(8)

// Add the values of reg1 with reg2 and place the results into reg3
#define I_ADD   0x20 //add reg1(8) reg2(8) reg3(8)

// Subtract the value of reg1 with reg2 and place the result in reg3
#define I_SUB   0x21 //sub reg1(8) reg2(8) reg3(8)

#endif // _INSTRUCTIONS_H_

