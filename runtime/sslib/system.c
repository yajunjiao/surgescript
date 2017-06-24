/*
 * SurgeScript
 * A lightweight programming language for computer games and interactive apps
 * Copyright (C) 2017  Alexandre Martins <alemartf(at)gmail(dot)com>
 *
 * util/system.c
 * SurgeScript standard library: System object
 */

#include <stdio.h>
#include "../vm.h"
#include "../heap.h"
#include "../object.h"
#include "../object_manager.h"
#include "../variable.h"
#include "../../util/util.h"

/* private stuff */
static surgescript_var_t* fun_constructor(surgescript_object_t* object, const surgescript_var_t** param, int num_params);
static surgescript_var_t* fun_exit(surgescript_object_t* object, const surgescript_var_t** param, int num_params);
static surgescript_var_t* fun_destroy(surgescript_object_t* object, const surgescript_var_t** param, int num_params);
static surgescript_var_t* fun_main(surgescript_object_t* object, const surgescript_var_t** param, int num_params);
static surgescript_heapptr_t ISACTIVE_ADDR = 0;

/*
 * surgescript_sslib_register_system()
 * Register methods
 */
void surgescript_sslib_register_system(surgescript_vm_t* vm)
{
    surgescript_vm_bind(vm, "System", "__constructor", fun_constructor, 0);
    surgescript_vm_bind(vm, "System", "exit", fun_exit, 0);
    surgescript_vm_bind(vm, "System", "destroy", fun_destroy, 0); /* overloads Object's destroy() */
    surgescript_vm_bind(vm, "System", "state:main", fun_main, 0);
}



/* my functions */

/* register some built-in objects */
surgescript_var_t* fun_constructor(surgescript_object_t* object, const surgescript_var_t** param, int num_params)
{
    const char** system_objects = surgescript_object_userdata(object);
    surgescript_objectmanager_t* manager = surgescript_object_manager(object);
    surgescript_objecthandle_t me = surgescript_object_handle(object);
    surgescript_heap_t* heap = surgescript_object_heap(object);

    /* is_active flag */
    surgescript_heapptr_t isactive_addr = surgescript_heap_malloc(heap);
    ssassert(isactive_addr == ISACTIVE_ADDR);
    surgescript_var_set_bool(surgescript_heap_at(heap, ISACTIVE_ADDR), true);

    /* spawn system objects */
    for(const char** p = system_objects; *p != NULL; p++) {
        surgescript_var_t* mem = surgescript_heap_at(heap, surgescript_heap_malloc(heap));
        surgescript_var_set_objecthandle(mem, surgescript_objectmanager_spawn(manager, me, *p, NULL));
    }

    return NULL;
}

/* exit() will shut down the VM */
surgescript_var_t* fun_exit(surgescript_object_t* object, const surgescript_var_t** param, int num_params)
{
    surgescript_heap_t* heap = surgescript_object_heap(object);
    surgescript_var_set_bool(surgescript_heap_at(heap, ISACTIVE_ADDR), false);
    return NULL;
}

/* destroy function */
surgescript_var_t* fun_destroy(surgescript_object_t* object, const surgescript_var_t** param, int num_params)
{
    /* this is the same as exit() */
    return fun_exit(object, param, num_params);
}

/* main state */
surgescript_var_t* fun_main(surgescript_object_t* object, const surgescript_var_t** param, int num_params)
{
    surgescript_heap_t* heap = surgescript_object_heap(object);
    bool is_active = surgescript_var_get_bool(surgescript_heap_at(heap, ISACTIVE_ADDR));

    if(!is_active)
        surgescript_object_kill(object);

    return NULL;
}