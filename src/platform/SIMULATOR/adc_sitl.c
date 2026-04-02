/*
* SITL ADC Driver
 */

#include <stdbool.h>
#include <stdint.h>

#include "platform.h"
#include "build/build_config.h"
#include "drivers/adc.h"
#include "common/utils.h"

// Only compile this file if we are building the SITL target
#ifdef SITL

// Import the variables defined in sitl.c
extern volatile uint16_t externalCurrentADC;
extern volatile uint16_t externalBatteryADC;

void adcInit(const struct adcConfig_s *config)
{
    UNUSED(config);
    // No hardware initialization needed for simulation
}

// The function name MUST be adcGetValue to match the betaflight API
uint16_t adcGetValue(adcSource_e source)
{
    switch (source) {
    case ADC_CURRENT:
        return externalCurrentADC;
    case ADC_BATTERY:
        return externalBatteryADC;
    default:
        return 0;
    }
}

#endif // SITL