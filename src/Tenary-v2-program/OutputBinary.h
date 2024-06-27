#ifndef OutputBinary
#define OutputBinary

#include "Arduino.h"

extern void OutputCalculate(double CalResult, double DecimalResult);

extern void build16BitValue(uint8_t intPart, double decPart);

extern void buildBitsForInt(uint8_t CalculateNum);

extern void buildBitsForDecimal();

extern void bits_setBit(uint16_t *bitsPtr, uint8_t bitNumber);

extern void shiftOut();

#endif
