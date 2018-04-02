/*
 * SurgeScript
 * A lightweight programming language for computer games and interactive apps
 * Copyright (C) 2018  Alexandre Martins <alemartf(at)gmail(dot)com>
 *
 * runtime/sslib/tags.c
 * SurgeScript standard library: Tag System
 */

#include "../vm.h"
#include "../object.h"
#include "../../util/util.h"

/* API */
static surgescript_var_t* fun_constructor(surgescript_object_t* object, const surgescript_var_t** param, int num_params);
static surgescript_var_t* fun_main(surgescript_object_t* object, const surgescript_var_t** param, int num_params);
static surgescript_var_t* fun_spawn(surgescript_object_t* object, const surgescript_var_t** param, int num_params);
static surgescript_var_t* fun_destroy(surgescript_object_t* object, const surgescript_var_t** param, int num_params);
static surgescript_var_t* fun_list(surgescript_object_t* object, const surgescript_var_t** param, int num_params);
static surgescript_var_t* fun_select(surgescript_object_t* object, const surgescript_var_t** param, int num_params);

/* private stuff */
static void push_to_array(const char* string, void* arr);

/*
 * surgescript_sslib_register_tagsystem()
 * Register methods
 */
void surgescript_sslib_register_tagsystem(surgescript_vm_t* vm)
{
    surgescript_vm_bind(vm, "__TagSystem", "constructor", fun_constructor, 0);
    surgescript_vm_bind(vm, "__TagSystem", "state:main", fun_main, 0);
    surgescript_vm_bind(vm, "__TagSystem", "spawn", fun_spawn, 1);
    surgescript_vm_bind(vm, "__TagSystem", "destroy", fun_destroy, 0);
    surgescript_vm_bind(vm, "__TagSystem", "list", fun_list, 0);
    surgescript_vm_bind(vm, "__TagSystem", "select", fun_select, 1);
}



/* my functions */

/* constructor */
surgescript_var_t* fun_constructor(surgescript_object_t* object, const surgescript_var_t** param, int num_params)
{
    return NULL;
}

/* main state */
surgescript_var_t* fun_main(surgescript_object_t* object, const surgescript_var_t** param, int num_params)
{
    return NULL;
}

/* spawn */
surgescript_var_t* fun_spawn(surgescript_object_t* object, const surgescript_var_t** param, int num_params)
{
    /* can't spawn anything here! */
    return NULL;
}

/* destroy */
surgescript_var_t* fun_destroy(surgescript_object_t* object, const surgescript_var_t** param, int num_params)
{
    /* can't destroy this object! */
    return NULL;
}

/* list(): returns an array with all tags */
surgescript_var_t* fun_list(surgescript_object_t* object, const surgescript_var_t** param, int num_params)
{
    surgescript_objectmanager_t* object_manager = surgescript_object_manager(object);
    surgescript_objecthandle_t array_handle = surgescript_objectmanager_spawn_array(object_manager);
    surgescript_object_t* array = surgescript_objectmanager_get(object_manager, array_handle);
    surgescript_tagsystem_t* tag_system = surgescript_objectmanager_tagsystem(object_manager);

    surgescript_tagsystem_foreach_tag(tag_system, array, push_to_array);

    return surgescript_var_set_objecthandle(surgescript_var_create(), array_handle);
}

/* select(tag): returns an array with all the names of the objects tagged tag */
surgescript_var_t* fun_select(surgescript_object_t* object, const surgescript_var_t** param, int num_params)
{
    surgescript_objectmanager_t* object_manager = surgescript_object_manager(object);
    surgescript_objecthandle_t array_handle = surgescript_objectmanager_spawn_array(object_manager);
    surgescript_object_t* array = surgescript_objectmanager_get(object_manager, array_handle);
    surgescript_tagsystem_t* tag_system = surgescript_objectmanager_tagsystem(object_manager);
    char* tag_name = surgescript_var_get_string(param[0], object_manager);

    surgescript_tagsystem_foreach_tagged_object(tag_system, tag_name, array, push_to_array);

    ssfree(tag_name);
    return surgescript_var_set_objecthandle(surgescript_var_create(), array_handle);
}



/* --- private stuff --- */
void push_to_array(const char* string, void* arr)
{
    surgescript_object_t* array = (surgescript_object_t*)arr;
    surgescript_var_t* tmp = surgescript_var_create();
    const surgescript_var_t* param[] = { tmp };

    surgescript_var_set_string(tmp, string);
    surgescript_object_call_function(array, "push", param, 1, NULL);

    surgescript_var_destroy(tmp);
}