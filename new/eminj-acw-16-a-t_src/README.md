# eminj-acw-16-a-t Source Files

## Overview
This directory contains the constant difference version of source files for eminj-acw-16-a-t.

## Files Generated
- `eminj_c_mat.c` - Constant definitions file (updated from acw-15 to acw-16)
- `eminj.h` - Main header file (updated from acw-15 to acw-16)
- `eminj_c.h` - Constants header file (updated from acw-15 to acw-16)

## Changes from Base Version (acw-15 to acw-16)
1. Updated model identifier from `eminj-pcw00-1500-a-t-M4` to `eminj-kjcw00-1600-a-t-M4`
2. All files maintain CP932 (Shift-JIS) encoding for Japanese character compatibility
3. File structure and constant definitions preserved from base version

## Encoding
All source files use **CP932 (Shift-JIS)** encoding to support Japanese comments and documentation.

## Verification
- Syntax check: Passed (verified with GCC -fsyntax-only)
- Encoding check: CP932 (unknown-8bit) - Confirmed
- Structure validation: 5 include directives, 52 constant definitions

## Base Version
Based on: `base/eminj-acw-15-c-t_src/`

## Specification References
- New spec: `new/eminj-acw-16-a-t/document/定数管理エクセル_eminj-acw-16-a-t.xlsm`
- Base spec: `base/eminj-acw-15-c-t_spec/`

## Generation Date
2025-11-07
