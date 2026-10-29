/*
 * stm32f401ccux.h
 *
 *  Created on: Oct 23, 2026
 *      Author: smbyun
 */

#ifndef INC_STM32F401CCUX_H_
#define INC_STM32F401CCUX_H_

#include <stdint.h>

#define __vo volatile

/******************* Processor Specific Details *******************/
/*
 * ARM Cortex Mx Processor NVIC ISERx register Addresses
 */
// Table 6-1 NVIC registers
#define NVIC_ISER0						((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1						((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2						((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3						((__vo uint32_t*)0xE000E10C)
#define NVIC_ISER4						((__vo uint32_t*)0xE000E110)
#define NVIC_ISER5						((__vo uint32_t*)0xE000E114)
#define NVIC_ISER6						((__vo uint32_t*)0xE000E118)
#define NVIC_ISER7						((__vo uint32_t*)0xE000E11C)


/*
 * ARM Cortex Mx Processor NVIC ICERx register Addresses
 */
// Table 6-1 NVIC registers
#define NVIC_ICER0						((__vo uint32_t*)0xE000E180)
#define NVIC_ICER1						((__vo uint32_t*)0xE000E184)
#define NVIC_ICER2						((__vo uint32_t*)0xE000E188)
#define NVIC_ICER3						((__vo uint32_t*)0xE000E18C)
#define NVIC_ICER4						((__vo uint32_t*)0xE000E190)
#define NVIC_ICER5						((__vo uint32_t*)0xE000E194)
#define NVIC_ICER6						((__vo uint32_t*)0xE000E198)
#define NVIC_ICER7						((__vo uint32_t*)0xE000E19C)

/*
 * ARM Cortex Mx Processor Priority Register Address Calculation
 */
#define NVIC_PR_BASE_ADDR	 			((__vo uint32_t*)0xE000E400)


/*
 * ARM Cortex Mx Processor number of priority bits implemented in Priority Register
 */
#define NO_PR_BITS_IMPLEMENTED			4


/*
 * base addresses of Flash and SRAM memories
 */
// [Reference Manual] Table 5. Flash module organization (STM32F401xB/C and STM32F401xD/E)
#define FLASH_BASEADDR 					0x08000000U

// [Reference Manual] Table 3. Memory mapping vs. Boot mode/physical remap in STM32F401xB/C
#define SRAM1_BASEADDR					0x20000000U // 64KB = 64*1024bit = 65536bit = 0x00010000U
#define SRAM2_BASEADDR					0x20010000U // 0x20000000U + 0x00010000U
#define SRAM 							SRAM1_BASEADDR

// [Reference Manual] Table 5. Flash module organization (STM32F401xB/C and STM32F401xD/E)
#define ROM_BASEADDR 					0x1FFF0000U // System memory


/*
 * AHBx and APBx Bus Peripheral base addresses
 */
// [Reference Manual] Table 1. STM32F401xB/C and STM32F401xD/E register boundary addresses
#define PERIPH_BASEADDR 				0x40000000U
#define APB1PERIPH_BASEADDR				PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR				0x40010000U
#define AHB1PERIPH_BASEADDR				0x40020000U
#define AHB2PERIPH_BASEADDR				0x50000000U


/*
 * Base addresses of peripherals which are hanging on AHB1 bus
 */
// [Reference Manual] Table 1. STM32F401xB/C and STM32F401xD/E register boundary addresses
#define GPIOA_BASEADDR					(AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR					(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR					(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR					(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR					(AHB1PERIPH_BASEADDR + 0x1000)
//#define GPIOF_BASEADDR
//#define GPIOG_BASEADDR
#define GPIOH_BASEADDR					(AHB1PERIPH_BASEADDR + 0x1C00)
#define RCC_BASEADDR					(AHB1PERIPH_BASEADDR + 0x3800)

/*
 * Base addresses of peripherals which are hanging on APB1 bus
 */
// [Reference Manual] Table 1. STM32F401xB/C and STM32F401xD/E register boundary addresses
#define I2C1_BASEADDR					(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR					(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR					(APB1PERIPH_BASEADDR + 0x5C00)

#define SPI1_BASEADDR					(APB2PERIPH_BASEADDR + 0x3000)
#define SPI2_BASEADDR					(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR					(APB1PERIPH_BASEADDR + 0x3C00)
#define SPI4_BASEADDR					(APB2PERIPH_BASEADDR + 0x3400)

#define USART2_BASEADDR					(APB1PERIPH_BASEADDR + 0x4400)
//#define USART3_BASEADDR
//#define USART4_BASEADDR
//#define USART5_BASEADDR


/*
 * Base addresses of peripherals which are hanging on APB2 bus
 */
// [Reference Manual] Table 1. STM32F401xB/C and STM32F401xD/E register boundary addresses
#define EXTI_BASEADDR					(APB2PERIPH_BASEADDR + 0x3C00)
#define SPI1_BASEADDR					(APB2PERIPH_BASEADDR + 0x3000)
#define SPI4_BASEADDR					(APB2PERIPH_BASEADDR + 0x3400)
#define SYSCFG_BASEADDR					(APB2PERIPH_BASEADDR + 0x3800)
#define USART1_BASEADDR					(APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR					(APB2PERIPH_BASEADDR + 0x1400)


/******************* Peripheral Register Definition Structures *******************/

/*
 * Peripheral register definition structure for GPIO
 */
// [Reference Manual] Table 27. GPIO register map and reset values
typedef struct {
    __vo uint32_t MODER;				// GPIO port mode register,					Address offset: 0x00
    __vo uint32_t OTYPER;				// GPIO port output type register, 			Address offset: 0x04
    __vo uint32_t OSPEEDR;				// GPIO port output speed register, 		Address offset: 0x08
    __vo uint32_t PUPDR;				// GPIO port pull-up/pull-down register, 	Address offset: 0x0C
    __vo uint32_t IDR;					// GPIO port input data register, 			Address offset: 0x10
    __vo uint32_t ODR;					// GPIO port output data register, 			Address offset: 0x14
    __vo uint32_t BSRR;					// GPIO port bit set/reset register, 		Address offset: 0x18
    __vo uint32_t LCKR;					// GPIO port configuration lock register, 	Address offset: 0x1C
    __vo uint32_t AFR[2];				// GPIO alternate function register, 		Address offset: 0x20-0x24
} GPIO_RegDef_t;

/*
 * Peripheral register definition structure for RCC
 */
// Table 22. RCC register map and reset values for STM32F401xB/C and STM32F401xD/E
typedef struct {
    __vo uint32_t CR;					// RCC clock control register, 										Address offset: 0x00
    __vo uint32_t PLLCFGR;				// RCC PLL configuration register, 									Address offset: 0x04
    __vo uint32_t CFGR;					// RCC clock configuration register, 								Address offset: 0x08
    __vo uint32_t CIR;					// RCC clock interrupt register, 									Address offset: 0x0C
    __vo uint32_t AHB1RSTR;				// RCC AHB1 peripheral reset register, 								Address offset: 0x10
    __vo uint32_t AHB2RSTR;				// RCC AHB2 peripheral reset register, 								Address offset: 0x14
    uint32_t RESERVED0[2];				// Reserved, 														Address offset: 0x18-0x1C
    __vo uint32_t APB1RSTR;				// RCC APB1 peripheral reset register, 								Address offset: 0x20
    __vo uint32_t APB2RSTR;				// RCC APB2 peripheral reset register, 								Address offset: 0x24
    uint32_t RESERVED1[2];				// Reserved, 														Address offset: 0x28-0x2C
    __vo uint32_t AHB1ENR;				// RCC AHB1 peripheral clock enable register, 						Address offset: 0x30
    __vo uint32_t AHB2ENR;				// RCC AHB2 peripheral clock enable register, 						Address offset: 0x34
    uint32_t RESERVED2[2];				// Reserved,								 						Address offset: 0x38-0x3C
    __vo uint32_t APB1ENR;				// RCC APB1 peripheral clock enable register, 						Address offset: 0x40
    __vo uint32_t APB2ENR;				// RCC APB2 peripheral clock enable register, 						Address offset: 0x44
    uint32_t RESERVED3[2];				// Reserved,													 	Address offset: 0x48-0x4C
    __vo uint32_t AHB1LPENR;			// RCC AHB1 peripheral clock enable in low power mode register,		Address offset: 0x50
    __vo uint32_t AHB2LPENR;			// RCC AHB2 peripheral clock enable in low power mode register,		Address offset: 0x54
    uint32_t RESERVED4[2];				// Reserved,													 	Address offset: 0x58-0x5C
    __vo uint32_t APB1LPENR;			// RCC APB1 peripheral clock enable in low power mode register,		Address offset: 0x60
    __vo uint32_t APB2LPENR;			// RCC APB2 peripheral clock enabled in low power mode register,	Address offset: 0x64
    uint32_t RESERVED5[2];				// Reserved,								 						Address offset: 0x68-0x6C
    __vo uint32_t BDCR;					// RCC Backup domain control register,								Address offset: 0x70
    __vo uint32_t CSR;					// RCC clock control & status register,								Address offset: 0x74
    uint32_t RESERVED6[2];				// Reserved,														Address offset: 0x78-0x7C
    __vo uint32_t SSCGR;				// RCC spread spectrum clock generation register,					Address offset: 0x80
    __vo uint32_t PLLI2SCFGR;			// RCC PLLI2S configuration register,								Address offset: 0x84
    uint32_t RESERVED7;					// Reserved,														Address offset: 0x88
    __vo uint32_t DCKCFGR;				// RCC Dedicated Clocks Configuration Register,						Address offset: 0x8C
} RCC_RegDef_t;


/*
 * Peripheral register definition structure for EXTI
 */
// Table 39. External interrupt/event controller register map and reset values
typedef struct {
	__vo uint32_t IMR;					// Interrupt mask register,											Address offset: 0x00
	__vo uint32_t EMR;					// Event mask register,												Address offset: 0x04
	__vo uint32_t RTSR;					// Rising trigger selection register,								Address offset: 0x08
	__vo uint32_t FTSR;					// Falling trigger selection register, 								Address offset: 0x0C
	__vo uint32_t SWIER;				// Software interrupt event register,								Address offset: 0x10
	__vo uint32_t PR;					// Pending register, 												Address offset: 0x14
} EXTI_RegDef_t;


/*
 * Peripheral register definition structure for SPI
 */
// Table 93. SPI register map and reset values
typedef struct {
	__vo uint32_t CR1;					// SPI control register 1,											Address offset: 0x00
	__vo uint32_t CR2;					// SPI control register 2,											Address offset: 0x04
	__vo uint32_t SR;					// SPI status register,												Address offset: 0x08
	__vo uint32_t DR;					// SPI data register,												Address offset: 0x0C
	__vo uint32_t CRCPR;				// SPI CRC polynomial register, 									Address offset: 0x10
	__vo uint32_t RXCRCR;				// SPI RX CRC register,												Address offset: 0x14
	__vo uint32_t TXCRCR;				// SPI TX CRC register, 											Address offset: 0x18
	__vo uint32_t I2SCFGR;				// SPI_I2S configuration register, 									Address offset: 0x1C
	__vo uint32_t I2SPR;				// SPI_I2S prescaler register, 										Address offset: 0x20
} SPI_RegDef_t;


/*
 * Peripheral register definition structure for SYSCFG
 */
// Table 23. SYSCFG register map and reset values
typedef struct {
	__vo uint32_t MEMRMP;				// SYSCFG memory remap register,									Address offset: 0x00
	__vo uint32_t PMC;					// SYSCFG peripheral mode configuration register,					Address offset: 0x04
	__vo uint32_t EXTICR[4];			// SYSCFG external interrupt configuration register,				Address offset: 0x08-0x14
	uint32_t REVERSED1[2];
	__vo uint32_t CMPCR;				// Compensation cell control register,								Address offset: 0x20
} SYSCFG_RegDef_t;

/*
 * Peripheral Definitions (Peripheral base addresses typecasted to xxx_RegDef_t)
 */
#define GPIOA							((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB							((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC							((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD							((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE							((GPIO_RegDef_t*)GPIOE_BASEADDR)
//#define GPIOF
//#define GPIOG
#define GPIOH							((GPIO_RegDef_t*)GPIOH_BASEADDR)

#define RCC								((RCC_RegDef_t*)RCC_BASEADDR)

#define EXTI							((EXTI_RegDef_t*)EXTI_BASEADDR)

#define SPI1							((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2							((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3							((SPI_RegDef_t*)SPI3_BASEADDR)
#define SPI4							((SPI_RegDef_t*)SPI4_BASEADDR)

#define SYSCFG							((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)


/*
 * Clock Enable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_EN() 				(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN() 				(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN() 				(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN() 				(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN() 				(RCC->AHB1ENR |= (1 << 4))
//#define GPIOF_PCLK_EN()
//#define GPIOG_PCLK_EN()
#define GPIOH_PCLK_EN() 				(RCC->AHB1ENR |= (1 << 7))


/*
 * Clock Enable Macros for I2Cx peripherals
 */
#define I2C1_PCLK_EN()					(RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()					(RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()					(RCC->APB1ENR |= (1 << 23))


/*
 * Clock Enable Macros for SPIx peripherals
 */
#define SPI1_PCLK_EN() 					(RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN() 					(RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN() 					(RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN() 					(RCC->APB2ENR |= (1 << 13))


/*
 * Clock Enable Macros for USARTx peripherals
 */
#define USART1_PCLK_EN() 				(RCC->APB2ENR |= (1 << 4))
#define USART2_PCLK_EN() 				(RCC->APB1ENR |= (1 << 17))
#define USART6_PCLK_EN() 				(RCC->APB2ENR |= (1 << 5))


/*
 * Clock Enable Macros for SYSCFG peripheral
 */
#define SYSCFG_PCLK_EN() 				(RCC->APB2ENR |= (1 << 14))


/*
 * Clock Disable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_DI() 				(RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI() 				(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI() 				(RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI() 				(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI() 				(RCC->AHB1ENR &= ~(1 << 4))
//#define GPIOF_PCLK_DI()
//#define GPIOG_PCLK_DI()
#define GPIOH_PCLK_DI() 				(RCC->AHB1ENR &= ~(1 << 7))


/*
 * Clock Disable Macros for I2Cx peripherals
 */
#define I2C1_PCLK_DI()					(RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()					(RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI()					(RCC->APB1ENR &= ~(1 << 23))


/*
 * Clock Disable Macros for SPIx peripherals
 */
#define SPI1_PCLK_DI() 					(RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI() 					(RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI() 					(RCC->APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DI() 					(RCC->APB2ENR &= ~(1 << 13))


/*
 * Clock Disable Macros for USARTx peripherals
 */
#define USART1_PCLK_DI() 				(RCC->APB2ENR &= ~(1 << 4))
#define USART2_PCLK_DI() 				(RCC->APB1ENR &= ~(1 << 17))
#define USART6_PCLK_DI() 				(RCC->APB2ENR &= ~(1 << 5))


/*
 * Clock Disable Macros for SYSCFG peripheral
 */
#define SYSCFG_PCLK_DI() 				(RCC->APB2ENR &= ~(1 << 14))


/*
 * Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET()				do { (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); } while (0)
#define GPIOB_REG_RESET()				do { (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); } while (0)
#define GPIOC_REG_RESET()				do { (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); } while (0)
#define GPIOD_REG_RESET()				do { (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); } while (0)
#define GPIOE_REG_RESET()				do { (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); } while (0)
//#define GPIOF_REG_RESET()
//#define GPIOG_REG_RESET()
#define GPIOH_REG_RESET()				do { (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); } while (0)


/*
 * Returns port code for given GPIOx base address
 */
#define GPIO_BASEADDR_TO_CODE(x)		((x == GPIOA) ? 0 : \
										 (x == GPIOB) ? 1 : \
										 (x == GPIOC) ? 2 : \
										 (x == GPIOD) ? 3 : \
										 (x == GPIOE) ? 4 : \
										 (x == GPIOH) ? 7 : 0)


/*
 * IRQ(Interrupt Request) Number of STM32F401CCUx MCU
 */
// Table 38. Vector table for STM32F401xB/CSTM32F401xD/E
#define IRQ_NO_EXTI0					6
#define IRQ_NO_EXTI1					7
#define IRQ_NO_EXTI2					8
#define IRQ_NO_EXTI3					9
#define IRQ_NO_EXTI4					10
#define IRQ_NO_EXTI9_5					23
#define IRQ_NO_EXTI15_10				40
#define IRQ_NO_EXTI16					1
#define IRQ_NO_EXTI17					41
#define IRQ_NO_EXTI18					42
#define IRQ_NO_EXTI21					2
#define IRQ_NO_EXTI22					3


/*
 * Macros for all the possible priority levels
 */
#define NVIC_IRQ_PRI0					0
#define NVIC_IRQ_PRI1					1
#define NVIC_IRQ_PRI2					2
#define NVIC_IRQ_PRI3					3
#define NVIC_IRQ_PRI4					4
#define NVIC_IRQ_PRI5					5
#define NVIC_IRQ_PRI6					6
#define NVIC_IRQ_PRI7					7
#define NVIC_IRQ_PRI8					8
#define NVIC_IRQ_PRI9					9
#define NVIC_IRQ_PRI10					10
#define NVIC_IRQ_PRI11					11
#define NVIC_IRQ_PRI12					12
#define NVIC_IRQ_PRI13					13
#define NVIC_IRQ_PRI14					14
#define NVIC_IRQ_PRI15					15


/*
 * Some generic macros
 */

#define ENABLE 							1
#define DISABLE 						0
#define SET 							ENABLE
#define RESET 							DISABLE
#define GPIO_PIN_SET					SET
#define GPIO_PIN_RESET					RESET


#include "stm32f401ccux_gpio_driver.h"
#include "stm32f401ccux_spi_driver.h"

#endif /* INC_STM32F401CCUX_H_ */
