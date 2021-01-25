#include "inttypes.h"
#include "app_ad9083.h"
#include "ad9083.h"
#include "parameters.h"
#include "spi.h"
#include "spi_extra.h"
#include "gpio_extra.h"
#include "error.h"

bool app_ad9083_check_sysref_rate(uint32_t lmfc, uint32_t sysref)
{
	uint32_t div, mod;

	div = lmfc / sysref;
	mod = lmfc % sysref;

	/* Ignore minor deviations that can be introduced by rounding. */
	return mod <= div || mod >= sysref - div;
}

int32_t app_ad9083_init(void)
{
	struct ad9083_phy *ad9083_phy;
	int32_t status;

	struct xil_spi_init_param xil_spi_param = {
		.type = SPI_PS,
		.device_id = 0,
	};

	// clock chip spi settings
	struct spi_init_param ad9083_spi_init_param = {
		.max_speed_hz = 10000000,
		.mode = SPI_MODE_0,
		.chip_select = SPI_AD9083_CS,

		.platform_ops = &xil_platform_ops,
		.extra = &xil_spi_param
	};
	struct xil_gpio_init_param  xil_gpio_param = {
		.type = GPIO_PS,
		.device_id = GPIO_DEVICE_ID
	};
	struct gpio_init_param	gpio_phy_resetb = {
		.number = AD9528_RSTB,
		.platform_ops = &xil_gpio_platform_ops,
		.extra = &xil_gpio_param
	};
	struct gpio_init_param	gpio_phy_pd = {
		.number = AD9528_PWDN,
		.platform_ops = &xil_gpio_platform_ops,
		.extra = &xil_gpio_param
	};
	struct gpio_init_param	gpio_phy_ref_sel = {
		.number = AD9528_REFSEL,
		.platform_ops = &xil_gpio_platform_ops,
		.extra = &xil_gpio_param
	};

	struct ad9083_init_param ad9083_init_param = {
		.spi_init = &ad9083_spi_init_param,
		.gpio_reset = &gpio_phy_resetb,
		.gpio_pd = &gpio_phy_pd,
		.gpio_ref_sel = &gpio_phy_ref_sel,
	};

	status = ad9083_init(&ad9083_phy, &ad9083_init_param);
	if (status != SUCCESS)
		printf("ad9083_initialize() error: %" PRId32 "\n", status);

	return SUCCESS;
}
