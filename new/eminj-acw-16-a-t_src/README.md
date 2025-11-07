# eminj-acw-16-a-t Source Files

## Overview
This directory contains the logic difference version of the eminj source files for acw-16.

## Files
- `eminj_l_mat.c` - Logic difference version of injection requirement mediation (eminj-pcw00-1600-a-t-M4)
- `eminj_c_mat.c` - Constant table file (eminj-pcw00-1600-a-t-M4)
- `eminj.h` - Header file with type definitions and interfaces
- `eminj_c.h` - Header file for configuration settings

## Changes from acw-15
- Updated version identifier from eminj-pcw00-1500-a-t-M4 to eminj-pcw00-1600-a-t-M4
- Maintained function signatures and processing flow
- Preserved CP932 (Shift_JIS) encoding for Japanese comments
- All files are compilable with appropriate ECU build environment

## Encoding
All files use CP932 (Shift_JIS) encoding to properly display Japanese comments and documentation.

## Build Requirements
These files are designed to be built as part of an automotive ECU project with:
- Green Hills C compiler version 2013.5.x
- Toyota Motor Corporation build system
- Required include paths for common.h, gllib.h, and other ECU headers
