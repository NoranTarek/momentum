/*
 * EXIT_config.h
 *
 *  Created on: Dec 4, 2024
 *      Author: mylap
 */

#ifndef EXIT_CONFIG_H_
#define EXIT_CONFIG_H_

/*
   options :
   1-EXTI_LINE0
   2-EXTI_LINE1
   3-EXTI_LINE2
 */
#define EXTI_LINE EXTI_LINE0

/*
  options :
  1-EXTI_FALLING_EDGE
  2-EXTI_RISING_EDGE
  3-EXTI_LOW_LEVEL
  4-EXTI_ON_CHANGE
 */

#define EXTI_SENSE_MODE  EXTI_FALLING_EDGE

#endif /* EXIT_CONFIG_H_ */
