#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include "adc_demo.h"
#include "error.h"
#include "util.h"

/** Local channel for loopback */
uint16_t local_ch[DEMO_NUM_CHANNELS][NB_LOCAL_SAMPLES];

/******************************************************************************/
/************************ Functions Definitions *******************************/
/******************************************************************************/

int32_t adc_demo_init(struct adc_demo_desc **desc,
		      struct adc_demo_init_param *param)
{
	struct adc_demo_desc *adesc;
	adesc = (struct adc_demo_desc*)calloc(1,sizeof(*adesc));

	if(!adesc) {
		return -ENOMEM;
	}

	*desc = adesc;

	return SUCCESS;
}

int32_t adc_demo_remove(struct adc_demo_desc *desc)
{
	if(!desc) {
		return FAILURE;
	}

	free(desc);

	return SUCCESS;
}

int32_t adc_demo_reg_read(struct adc_demo_desc *desc, uint8_t reg_index,
			  uint8_t *readval)
{

	if(!desc || reg_index > 15) {
		return FAILURE;
	}

	*readval =  desc->reg[reg_index];

	return SUCCESS;
}

int32_t adc_demo_reg_write(struct adc_demo_desc *desc, uint8_t reg_index,
			   uint8_t writeval)
{

	if(!desc || reg_index > 15 || !writeval) {
		return FAILURE;
	}

	desc->reg[reg_index] = writeval;

	return SUCCESS;
}
