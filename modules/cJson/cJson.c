#include "py/runtime.h"
#include "py/obj.h"
#include <stdio.h>
#include <string.h>

#define MAX_JSON_SIZE 256

static char json_buffer[MAX_JSON_SIZE];

static mp_obj_t json_init() {
    snprintf(json_buffer, MAX_JSON_SIZE, "{");
    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_0(json_init_obj, json_init);

static mp_obj_t json_add(mp_obj_t key, mp_obj_t value) {
    const char *key_str = mp_obj_str_get_str(key);
    const char *value_str = mp_obj_str_get_str(value);

    if (strlen(json_buffer) + strlen(key_str) + strlen(value_str) + 6 < MAX_JSON_SIZE) {
        if (strlen(json_buffer) > 1) {
            strncat(json_buffer, ",", MAX_JSON_SIZE - strlen(json_buffer) - 1);
        }
        snprintf(json_buffer + strlen(json_buffer), MAX_JSON_SIZE - strlen(json_buffer),
                 "\"%s\":\"%s\"", key_str, value_str);
    }
    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_2(json_add_obj, json_add);

static mp_obj_t json_print() {
    strncat(json_buffer, "}", MAX_JSON_SIZE - strlen(json_buffer) - 1);
    printf("%s\n", json_buffer);
    return mp_obj_new_str(json_buffer, strlen(json_buffer));
}
static MP_DEFINE_CONST_FUN_OBJ_0(json_print_obj, json_print);

static const mp_rom_map_elem_t jsonModule_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR_init), MP_ROM_PTR(&json_init_obj) },
    { MP_ROM_QSTR(MP_QSTR_add), MP_ROM_PTR(&json_add_obj) },
    { MP_ROM_QSTR(MP_QSTR_print), MP_ROM_PTR(&json_print_obj) },
};
static MP_DEFINE_CONST_DICT(jsonModule_globals, jsonModule_globals_table);

const mp_obj_module_t json_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&jsonModule_globals,
};

MP_REGISTER_MODULE(MP_QSTR_jsonModule, json_user_cmodule);
