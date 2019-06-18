#include <Arduino.h>
#include "timer.h"

void timer_init() {
}

msec_t timer_get_msec() {
	return millis();
}

void timer_delay_msec(msec_t t) {
  msec_t now = millis();

  while(millis() - now < t);
}
