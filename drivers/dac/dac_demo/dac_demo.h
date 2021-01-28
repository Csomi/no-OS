#ifndef IIO_DEMO_DAC_
#define IIO_DEMO_DAC_

/******************************************************************************/
/***************************** Include Files **********************************/
/******************************************************************************/

#include <stdio.h>
#include "iio_types.h"

/******************************************************************************/
/*************************** Types Declarations *******************************/
/******************************************************************************/

#define DEMO_NUM_CHANNELS	2
#define MAX_REG_ADDR		10
#define NB_LOCAL_SAMPLES	500

/**
 * @struct iio_demo_desc
 * @brief Desciptor.
 */
struct dac_demo_desc {
	/** Dummy registers of device for testing direct_reg_access attribute
	uint32_t dummy_regs[MAX_REG_ADDR];
	* Active reg
	uint32_t active_reg_addr;
	* Demo global device attribute
	uint32_t dev_global_attr;
	* Demo device channel attribute
	uint32_t dev_ch_attr;
	* Active channels
	uint32_t ch_mask;*/
	uint8_t *reg;
};

/**
 * @struct iio_demo_init_param
 * @brief iio demo configuration.
 */
struct dac_demo_init_param {
	/** Demo global device attribute */
	uint32_t dev_global_attr;
	/** Demo device channel attribute */
	uint32_t dev_ch_attr;
};

/******************************************************************************/
/************************ Functions Declarations ******************************/
/******************************************************************************/

//INit function
int32_t dac_demo_init(struct dac_demo_desc **desc,
		      struct dac_demo_init_param *param);

int32_t dac_demo_remove(struct dac_demo_desc *desc);

int32_t dac_demo_reg_read(struct dac_demo_desc *desc, uint8_t reg_index,
			  uint8_t *readval);

int32_t dac_demo_reg_write(struct dac_demo_desc *desc, uint8_t reg_index,
			   uint8_t *writeval);

#endif /*IIO_DEMO_DAC_*/
