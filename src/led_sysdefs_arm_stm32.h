#ifndef __INC_LED_SYSDEFS_ARM_SAM_H
#define __INC_LED_SYSDEFS_ARM_SAM_H

#include "application.h"

#define FASTLED_NAMESPACE_BEGIN namespace NSFastLED {
#define FASTLED_NAMESPACE_END }
#define FASTLED_USING_NAMESPACE using namespace NSFastLED;

#define FASTLED_ARM

#ifndef INTERRUPT_THRESHOLD
#define INTERRUPT_THRESHOLD 1
#endif

// Default to allowing interrupts
#ifndef FASTLED_ALLOW_INTERRUPTS
#define FASTLED_ALLOW_INTERRUPTS 0
#endif

#if FASTLED_ALLOW_INTERRUPTS == 1
#define FASTLED_ACCURATE_CLOCK
#endif

// reuseing/abusing cli/sei defs for due
#define cli()  __disable_irq(); __disable_fault_irq();
#define sei() __enable_irq(); __enable_fault_irq();

// pgmspace definitions
#define PROGMEM
#define pgm_read_dword(addr) (*(const unsigned long *)(addr))
#define pgm_read_dword_near(addr) pgm_read_dword(addr)

// data type defs
typedef volatile       uint8_t RoReg; /**< Read only 8-bit register (volatile const unsigned int) */
typedef volatile       uint8_t RwReg; /**< Read-Write 8-bit register (volatile unsigned int) */

#define FASTLED_NO_PINMAP

#if defined(STM32F2XX)
#define F_CPU 120000000
#else
#define F_CPU 72000000
#endif

#endif
