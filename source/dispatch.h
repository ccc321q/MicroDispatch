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

#ifndef DISPATCH_H
#define DISPATCH_H

#include <inttypes.h>

/**** set for your application ***************************/

// total number of tasks. range is 1 to 255
#define TOTALTASKS 4

// allocate each task a position in the task array
// each name must be defined as a unique number
#define TSK_SAMPLE_TASK_NAME_1 0
#define TSK_SAMPLE_TASK_NAME_2 1
#define TSK_SAMPLE_TASK_NAME_3 2
#define TSK_SAMPLE_TASK_NAME_4 3

/*********************************************************/

void dispatchInit(void);
void dispatchTasks(void);
void dispatchTick(void);
void queueTask(uint8_t taskID);
void queueTaskDelayed(uint8_t taskID, uint16_t delay_);
void unQueueTask(uint8_t taskID);
void setTask(uint8_t taskID, void (*pointer_to_function)(void));

#endif
