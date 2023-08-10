/* 
 * File:   app.c
 * Author: Mahmoud El Arabi
 *
 * Created on August 3, 2023, 3:17 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "app.h"
uint16 adc_res_1, adc_res_2, adc_res_3, adc_res_4;

adc_conf_t adc_1 = {
    .ADC_InterruptHandler = NULL,
    .acquisition_time = ADC_12_TAD,
    .adc_channel = ADC_CHANNEL_AN0,
    .conversion_clock = ADC_CONVERSION_CLOCK_FOSC_DIV_16,
    .result_format = ADC_RESULT_RIGHT,
    .voltage_reference = ADC_VOLTAGE_REFERENCE_DISABLED
};

int main() { 
    Std_ReturnType ret  = E_NOT_OK;
    while(1){
        ret = ADC_GetConversion_Blocking(&adc_1, ADC_CHANNEL_AN0, &adc_res_1);
        ret = ADC_GetConversion_Blocking(&adc_1, ADC_CHANNEL_AN1, &adc_res_2);
        ret = ADC_GetConversion_Blocking(&adc_1, ADC_CHANNEL_AN2, &adc_res_3);
        ret = ADC_GetConversion_Blocking(&adc_1, ADC_CHANNEL_AN3, &adc_res_4);
    }
    return (EXIT_SUCCESS);
}