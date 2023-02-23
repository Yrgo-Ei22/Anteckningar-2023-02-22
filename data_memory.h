/********************************************************************************
* data_memory.h: Contains function declarations and macro definitions for
*                implementation of a 2 kB data memory.
********************************************************************************/
#ifndef DATA_MEMORY_H_
#define DATA_MEMORY_H_

/* Include directives: */
#include "cpu.h"

/* Macro definitions: */
#define DATA_MEMORY_DATA_WIDTH    8   /* 8 bits per address. */
#define DATA_MEMORY_ADDRESS_WIDTH 2048 /* 2048 addresses (0 - 2047). */

/********************************************************************************
* data_memory_reset: Clears content of the data memory.
********************************************************************************/
void data_memory_reset(void);

/********************************************************************************
* data_memory_write: Writes value to specified address in data memory and
*                    returns 0 after write is complete. If an invalid address 
*                    is specified (address >= DATA_MEMORY_ADDRESS_WIDTH),
*                    no write is done and error code 1 is returned.
* 
*                    - address: Destination address in data memory.
*                    - value  : Value to write to the destination address.
********************************************************************************/
int data_memory_write(const uint16_t address, 
                      const uint8_t value);

/********************************************************************************
* data_memory_read: Returns value read from specified address. If an invalid
*                   address is specified, no read is done and 0 is returned.
*
*                   - address: Read address in data memory.
********************************************************************************/
uint8_t data_memory_read(const uint16_t address);

/********************************************************************************
* data_memory_set_bit: Sets bit in specified data memory address.
*                  
*                      - address: Destination address in data memory.
*                      - bit    : Specified bit to set.
********************************************************************************/
static inline int data_memory_set_bit(const uint16_t address,
                                      const uint8_t bit)
{
   const uint8_t data = data_memory_read(address);
   return data_memory_write(address, data | (1 << bit));
}

/********************************************************************************
* data_memory_clear_bit: Clears bit in specified data memory address.
*
*                        - address: Destination address in data memory.
*                        - bit    : Specified bit to clear.
********************************************************************************/
static inline int data_memory_clear_bit(const uint16_t address,
                                        const uint8_t bit)
{
   const uint8_t data = data_memory_read(address);
   return data_memory_write(address, data & ~(1 << bit));
}

#endif /* DATA_MEMORY_H_ */