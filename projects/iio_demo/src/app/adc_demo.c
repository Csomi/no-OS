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

	adesc->reg = (uint8_t*)malloc(16*sizeof(uint8_t));

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
	int32_t ret;

	if(!desc || reg_index > 15) {
		return FAILURE;
	}

	readval = &desc->reg[reg_index];
	ret = (int32_t) *readval;

	return SUCCESS;
}

int32_t adc_demo_reg_write(struct adc_demo_desc *desc, uint8_t reg_index,
			   uint8_t *writeval)
{
	int32_t ret;

	if(!desc || reg_index > 15 || !writeval) {
		return FAILURE;
	}

	desc->reg[reg_index] = *writeval;
	ret = (int32_t) desc->reg[reg_index];

	return SUCCESS;
}
