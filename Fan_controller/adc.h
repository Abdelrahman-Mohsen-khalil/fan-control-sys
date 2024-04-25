#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56
typedef enum {
	ARF_volt, AVCC_volt, Resreved, internal_2_65VOlt
} ADC_ReferenceVolatge;
typedef enum {
	no_prescal_2,
	prescal_2,
	prescal_4,
	prescal_8,
	prescal_16,
	prescal_32,
	prescal_64,
	prescal_128,
} ADC_Prescaler;

typedef struct {
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
} ADC_ConfigType;

void ADC_init(const ADC_ConfigType *Config_Ptr);

uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
