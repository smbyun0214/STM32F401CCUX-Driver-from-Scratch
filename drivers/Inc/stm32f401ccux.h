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

#define SPI2_BASEADDR					(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR					(APB1PERIPH_BASEADDR + 0x3C00)

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
 * Some generic macros
 */

#define ENABLE 							1
#define DISABLE 						0
#define SET 							ENABLE
#define RESET 							DISABLE
#define GPIO_PIN_SET					SET
#define GPIO_PIN_RESET					RESET












#endif /* INC_STM32F401CCUX_H_ */
