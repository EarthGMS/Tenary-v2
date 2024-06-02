#ifndef OutputBinary
#define OutputBinary

#include "Arduino.h"

extern void OutputCalculate(double CalResult);

extern uint16_t build16BitValue(uint8_t intPart/*, double decPart*/);

extern uint16_t buildBitsForInt(uint8_t CalculateNum);

extern uint16_t buildBitsForDecimal(double CalculateNum);

extern void bits_setBit(uint16_t *bitsPtr, uint8_t bitNumber);

extern void shiftOut(uint8_t CalculateNum, bool mode);

#endif
