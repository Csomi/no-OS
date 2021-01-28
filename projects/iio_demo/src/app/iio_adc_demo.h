#ifndef IIO_DEMO_DEV
#define IIO_DEMO_DEV

#include <stdlib.h>
#include "adc_demo.h"

struct iio_device adc_demo_iio_descriptor = {
	.debug_reg_read = (int32_t (*)()) adc_demo_reg_read,
	.debug_reg_write = (int32_t (*)()) adc_demo_reg_write
};

#endif /* IIO_DEMO_DEV */
