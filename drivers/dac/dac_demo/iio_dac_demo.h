#ifndef IIO_DEMO_DAC
#define IIO_DEMO_DAC

#include <stdlib.h>
#include "dac_demo.h"

struct iio_device dac_demo_iio_descriptor = {
	.debug_reg_read = (int32_t (*)()) dac_demo_reg_read,
	.debug_reg_write = (int32_t (*)()) dac_demo_reg_write
};

#endif /* IIO_DEMO_DAC */
