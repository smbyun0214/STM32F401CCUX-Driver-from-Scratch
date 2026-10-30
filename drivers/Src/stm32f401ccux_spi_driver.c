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
	// Peripheral clock enable
	SPI_PeriClockControl(pSPIHandle->pSPIx, ENABLE);

	uint32_t tempreg = 0;

	// 1. Configure the device mode
	tempreg |= pSPIHandle->SPIConfig.SPI_DeviceMode << SPI_CR1_MSTR;

	// 2. Configure the bus config
	if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD) {
		// BIDIMODE should be cleared
		tempreg &= ~(1 << SPI_CR1_BIDIMODE);
	} else if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD) {
		// BIDIMODE should be set
		tempreg |= (1 << SPI_CR1_BIDIMODE);
	} else if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLE_RXONLY) {
		// BIDIMODE should be cleared
		tempreg &= ~(1 << SPI_CR1_BIDIMODE);
		// RXONLY bit must be set
		tempreg |= (1 << SPI_CR1_RXONLY);
	}

	// 3. Configure the SPI serial clock speed (baud rate)
	tempreg |= pSPIHandle->SPIConfig.SPI_SclkSpeed << SPI_CR1_BR;

	// 4. Configure the DFF
	tempreg |= pSPIHandle->SPIConfig.SPI_DFF << SPI_CR1_DFF;

	// 5. Configure the CPOL
	tempreg |= pSPIHandle->SPIConfig.SPI_CPOL << SPI_CR1_CPOL;

	// 6. Configure the CPHA
	tempreg |= pSPIHandle->SPIConfig.SPI_CPHA << SPI_CR1_CPHA;

	pSPIHandle->pSPIx->CR1 = tempreg;
}

void SPI_DeInit(SPI_RegDef_t *pSPIx) {

}


/*
 * Data read and write
 */

uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t FlagName) {
	if (pSPIx->SR & FlagName) {
		return FLAG_SET;
	}
	return FLAG_RESET;
}

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
 * @Note			- This is blocking call
 */
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t* pTxBuffer, uint32_t Len) {
	while (Len > 0) {
		// 1. Wait until TEX is set
		while (SPI_GetFlagStatus(pSPIx, SPI_TXE_FLAG) == FLAG_RESET);

		// 2. Check the DFF bit in CR1
		if (pSPIx->CR1 & (1 << SPI_CR1_DFF)) {
			// 16 bit DFF
			// 1. Load the data in to the DR
			pSPIx->DR = *((uint16_t*)pTxBuffer);
			Len--;
			Len--;
			(uint16_t*)pTxBuffer++;
		} else {
			// 8 bit DFF
			pSPIx->DR = *pTxBuffer;
			Len--;
			pTxBuffer++;
		}

	}
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
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t* pRxBuffer, uint32_t Len) {

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


/*
 * Other peripheral control APIs
 */

/*****************************************************************
 * @fn				- SPI_PeripheralControl
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
void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EnOrDi) {
	if (EnOrDi == ENABLE) {
		pSPIx->CR1 |= (1 << SPI_CR1_SPE);
	} else {
		pSPIx->CR1 &= ~(1 << SPI_CR1_SPE);
	}
}

/*****************************************************************
 * @fn				- SPI_SSICONFIG
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
void SPI_SSICONFIG(SPI_RegDef_t *pSPIx, uint8_t EnOrDi) {
	if (EnOrDi == ENABLE) {
		pSPIx->CR1 |= (1 << SPI_CR1_SSI);
	} else {
		pSPIx->CR1 &= ~(1 << SPI_CR1_SSI);
	}
}
