#include "py/runtime.h"

// Function to print "Hello, World!" in MicroPython
static mp_obj_t helloworld_print() {
    printf("Hello, World!\n");
    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_0(helloworld_print_obj, helloworld_print);

// Define module functions
static const mp_rom_map_elem_t helloworld_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR_print), MP_ROM_PTR(&helloworld_print_obj) },
};
static MP_DEFINE_CONST_DICT(helloworld_module_globals, helloworld_module_globals_table);

// Define module
const mp_obj_module_t helloworld_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&helloworld_module_globals,
};

// Register module
MP_REGISTER_MODULE(MP_QSTR_helloworld, helloworld_user_cmodule);
