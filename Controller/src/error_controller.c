#include "error_controller.h"

/**
 * @brief current error flags bitmask
 * 
 */
static error_flags_e error_flags = ERROR_NONE;

void error_controller_init(void) {
    error_flags = ERROR_NONE; // Clear all errors on init
}

void error_controller_set_error(error_flags_e error) {
    error_flags |= error; // Set the specified error flag(s)
}

void error_controller_clear_error(error_flags_e error) {
    error_flags &= ~error; // Clear the specified error flag(s)
}

error_flags_e error_controller_gete_errors(void) {
    return error_flags; // Return current error flags
}
