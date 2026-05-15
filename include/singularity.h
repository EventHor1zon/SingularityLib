/**
 *    @file    singularity.h
 *
 *    @brief    header file for singularity
 *
 *
 *
 *    @author    RJAM
 *    @created   Sat 10 Jan 22:34:57 GMT 2026
 */

#pragma once

/** Includes **/
#include <stdint.h>
/** Defines **/

/** Typedefs **/

typedef enum __attribute__((packed)) sngl_ret {
    RET_OK = 0,
    RET_ERR = 1,
} sngl_ret_t;

typedef enum {
    EVENT_PRIO_NORMAL,
    EVENT_PRIO_HIGH,
    EVENT_PRIO_INVALID,
} sngl_event_prio_t;

typedef struct {
    union {
        uint32_t code;
        struct {
            uint8_t id;
            uint8_t base;
            uint8_t emitter;
            uint8_t source;
        };
    } event;

    void *args;
} sngl_event_t;

typedef struct {
    bool in_use;
    sngl_event_t event;
    sngl_event_prio_t priority;
    event_callback_t callback;
    void *callback_args;
} sngl_event_registry_t;

typedef struct {
} event_bus_t;

/** Function Declarations **/

sngl_ret_t singularity_init();

sngl_ret_t singularity_event_handler();

/** END **/
