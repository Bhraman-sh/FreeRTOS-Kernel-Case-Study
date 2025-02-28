# FreeRTOS Kernel Fork

This is a fork of the FreeRTOS kernel for a case study on scheduling. A new feature has been added to support **variable time slicing**.

## Feature: Variable Time Slice
A new configuration option, `configUSE_VARIABLE_TIME_SLICE`, has been introduced. When enabled (`1`), this allows tasks to have variable-length time slices instead of fixed ones, providing more flexibility in scheduling.

## Purpose
This modification is part of a case study exploring enhancements to FreeRTOS scheduling mechanisms and their impact on real-time task execution.

## Getting Started
Clone this repository and configure FreeRTOS to enable the variable time slice feature:

```
#define configUSE_VARIABLE_TIME_SLICE 1
```

Compile and run your FreeRTOS project to see the effects of the new scheduling mechanism.

## Contributions
This fork is maintained as part of a research project. Contributions and discussions are welcome!

