/**
 * \file adrv9009/src/app/headless.c
 *
 * \brief Contains example code for user integration with their application
 *
 * Copyright 2015-2017 Analog Devices Inc.
 * Released under the AD9378-AD9379 API license, for more information see the "LICENSE.txt" file in this zip file.
 *
 */

/****< Insert User Includes Here >***/

#include <stdio.h>
#include "ad9083.h"
//#include "adi_hal.h"
#include "inttypes.h"
#include "spi.h"
#include "spi_extra.h"
#include "gpio_extra.h"
#include "error.h"
#include "delay.h"
#include "parameters.h"
#include "util.h"
//#include "axi_dac_core.h"
#include "axi_adc_core.h"
#include "axi_dmac.h"
#ifndef ALTERA_PLATFORM
#include "xil_cache.h"
#endif
//#include "talise.h"
//#include "talise_config.h"
#include "app_config.h"
#include "app_clocking.h"
#include "app_jesd.h"
#include "app_transceiver.h"
#include "app_ad9083.h"
#include "ad9528.h"

#ifdef IIO_SUPPORT

#include "iio.h"
#include "iio_axi_adc.h"
#include "iio_axi_dac.h"
#include "irq.h"
#include "irq_extra.h"
#include "uart.h"
#include "uart_extra.h"

static struct uart_desc *uart_desc;

/**
 * iio_uart_write() - Write data to UART device wrapper.
 * @buf - Pointer to buffer containing data.
 * @len - Number of bytes to write.
 * @Return: SUCCESS in case of success, FAILURE otherwise.
 */
static ssize_t iio_uart_write(const char *buf, size_t len)
{
	return uart_write(uart_desc, (const uint8_t *)buf, len);
}

/**
 * iio_uart_read() - Read data from UART device wrapper.
 * @buf - Pointer to buffer containing data.
 * @len - Number of bytes to read.
 * @Return: SUCCESS in case of success, FAILURE otherwise.
 */
static ssize_t iio_uart_read(char *buf, size_t len)
{
	return uart_read(uart_desc, (uint8_t *)buf, len);
}

#endif // IIO_SUPPORT

/**********************************************************/
/**********************************************************/
/********** Talise Data Structure Initializations ********/
/**********************************************************/
/**********************************************************/

int main(void)
{
//	adiHalErr_t err;
	int32_t status;
	struct ad9083_phy *ad9083_phy;
	uint32_t deviceClock_kHz = 40000000;
	uint32_t lmfc_rate = 10000000;

	printf("Hello\n");

	status = app_clocking_init(deviceClock_kHz, lmfc_rate);
	if (status != SUCCESS)
		printf("app_clock_init() error: %" PRId32 "\n", status);

	status = app_ad9083_init();
	if (status != SUCCESS)
		printf("app_clock_init() error: %" PRId32 "\n", status);




//	status = app_jesd_init(jesd_clk,
//			       500000, 250000, 250000, 10000000, 10000000);
//	if (status != SUCCESS)
//		printf("app_jesd_init() error: %" PRId32 "\n", status);

	printf("Bye\n");
	return SUCCESS;
}
