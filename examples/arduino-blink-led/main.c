/* The MIT License (MIT)
 *
 * Copyright (c) 2016 Christiaan Aspeling
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <avr/interrupt.h>
#include <avr/io.h>
#include "dispatch.h"

/***
 * 1. define total number of tasks in dispatch.h
 * 2. define a name for each task in dispatch.h, each name must be defined as a
 * unique number.
 * 3. call setTask(TASK_NAME, &functionName); to link the task name and
 * function.
 * 4. call queueTask(TASK_NAME) or queueTaskDelayed(TASK_NAME, 32), the delay
 * range is 0 to 65535
 */

void toggleLed(void) {
  // toggle pin 13 on the arduino, which is the led
  PORTB ^= (1 << 5);

  // rerun this task every 200 ticks
  queueTaskDelayed(TSK_TOGGLE_LED, 200);
}

int main(void) {
  dispatchInit();  // must be called first

  // Setup timer0 to interrupt at 10 kHz
  // this is the main tick period for the dispatcher
  TCCR0A = _BV(WGM01);   // CTC mode
  TCCR0B = _BV(CS01);    // prescalar 8
  OCR0A = 199;           // timer counts, 199 = 10kHz
  TIMSK0 = _BV(OCIE0A);  // enable output-compare interrupt TIMER0_COMPA

  setTask(TSK_TOGGLE_LED, &toggleLed);
  queueTask(TSK_TOGGLE_LED);
  for (;;) {
    dispatchTasks();
  }
}

/*** INTERRUPT: Timer0A @ 0.1 ms / 100 microseconds
 * ***************************************/
ISR(TIMER0_COMPA_vect) {
  // Tick the dispatcher
  dispatchTick();
}
