# Change Log: acw-15 to acw-16

## Version Identifier Updates

All files have been updated from `eminj-pcw00-1500-a-t-M4` to `eminj-pcw00-1600-a-t-M4`.

## Modified Files

### eminj_l_mat.c
- **Line 1**: Version identifier updated
- **Total Lines**: 4,961
- **Key Functions**: All function signatures preserved
  - vdg_eminj_pwon() - Power-on initialization
  - vdg_eminj_8msm() - 8ms main task
  - vdg_eminj_einj_dataget() - Injection data acquisition (structure 1)
  - vdg_eminj_eminj_dataget() - Injection data acquisition (structure 2)

### eminj_c_mat.c
- **Line 1**: Version identifier updated
- **Total Lines**: 659
- **Purpose**: Constant table definitions

### eminj.h
- **Line 1**: Version identifier updated
- **Total Lines**: 1,323
- **Purpose**: Type definitions and interface declarations

### eminj_c.h
- **Line 1**: Version identifier updated
- **Total Lines**: 362
- **Purpose**: Compile-time configuration switches

## Compatibility

The generated files maintain:
- Binary compatibility with automotive ECU framework
- API compatibility with calling modules
- Data structure layouts unchanged
- Conditional compilation logic preserved

## Testing Recommendations

1. Compile with Green Hills compiler v2013.5.x
2. Verify all conditional compilation paths
3. Run static analysis tools
4. Validate against unit test suite
5. Perform integration testing with ECU framework

## Notes

- All Japanese comments preserved in CP932 encoding
- No logic changes beyond version number update
- Ready for integration into build system
