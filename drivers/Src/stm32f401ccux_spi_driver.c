/*
 * stm32f401ccux_spi_driver.c
 *
 *  Created on: Oct 28, 2026
 *      Author: smbyun
 */

#include "stm32f401ccux_spi_driver.h"

/*
 * Peripheral Clock setup
 */

/*****************************************************************
 * @fn				- SPI_PeriClockControl
 *
 * @brief 			- This function enables or disables peripheral clock for the given SPI port
 *
 * @param[in]		- base address of the SPI peripheral
 * @param[in]		- ENABLE or DISABLE macros
 *
 * @return 			- none
 *
 * @Note			- none
 */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi) {
	if (EnorDi == ENABLE) {
		if (pSPIx == SPI1) {
			SPI1_PCLK_EN();
		} else if (pSPIx == SPI2) {
			SPI2_PCLK_EN();
		} else if (pSPIx == SPI3) {
			SPI3_PCLK_EN();
		} else if (pSPIx == SPI4) {
			SPI4_PCLK_EN();
		}
	} else {
		if (pSPIx == SPI1) {
			SPI1_PCLK_DI();
		} else if (pSPIx == SPI2) {
			SPI2_PCLK_DI();
		} else if (pSPIx == SPI3) {
			SPI3_PCLK_DI();
		} else if (pSPIx == SPI4) {
			SPI4_PCLK_DI();
		}
	}
}


/*
 * Init and De-init
 */
void SPI_Init(SPI_Handle_t *pSPIHandle) {

}

void SPI_DeInit(SPI_RegDef_t *pSPIx) {

}


/*
 * Data read and write
 */


/*****************************************************************
 * @fn				- SPI_SendData
 *
 * @brief 			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 * @return 			- none
 *
 * @Note			- none
 */
void SPI_SendData(SPI_RegDef_t *SPIx, uint8_t* pTxBuffer, uint32_t Len) {

}

/*****************************************************************
 * @fn				- SPI_ReceiveData
 *
 * @brief 			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 * @return 			- none
 *
 * @Note			- none
 */
void SPI_ReceiveData(SPI_RegDef_t *SPIx, uint8_t* pRxBuffer, uint32_t Len) {

}


/*
 * IRQ Configuration and ISR handling
 */

/*****************************************************************
 * @fn				- GPIO_IRQInterruptConfig
 *
 * @brief 			-
 *
 * @param[in]		-
 * @param[in]		-
 *
 * @return 			-
 *
 * @Note			- none
 */
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi) {

}

/*****************************************************************
 * @fn				- SPI_IRQPriorityConfig
 *
 * @brief 			-
 *
 * @param[in]		-
 * @param[in]		-
 *
 * @return 			-
 *
 * @Note			- none
 */
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority) {

}

/*****************************************************************
 * @fn				- SPI_IRQHandling
 *
 * @brief 			-
 *
 * @param[in]		-
 *
 * @return 			-
 *
 * @Note			- none
 */
void SPI_IRQHandling(SPI_Handle_t *pSPIHandle) {

}
