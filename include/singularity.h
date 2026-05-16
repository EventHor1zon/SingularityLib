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

#define SNGL_CONFIG_MAX_SUBSCRIBERS 8
#define SNGL_CONFIG_MAX_EVT_IDS     255

/** Typedefs **/

typedef uint32_t buslock_t;

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
    };

    void *args;
} sngl_event_t;

typedef struct {
    uint8_t in_use;
    event_callback_t callback;
    void *const callback_args;
} sngl_event_reg_t;

typedef struct {
    buslock_t lock;
    sngl_event_reg_t event_registry[SNGL_CONFIG_MAX_EVT_IDS][SNGL_CONFIG_MAX_SUBSCRIBERS];
} event_bus_t;

/** Function Declarations **/

/**
 *  @brief sngl_init_bus creates a new event bus
 *
 *         This function creates the event table registry
 *         and establishes the event "bus"
 */
sngl_ret_t sngl_init_bus();

/**
 *  @brief sngl_register event registers an event for
 *         publication
 *
 */
sngl_ret_t sngl_register_event();

/**
 *  @brief sngl_subscribe registers a listener to a bus
 *         and associates a callback
 *
 *          This callback function __must not be blocking!__
 */
sngl_ret_t sngl_subscribe();

/**
 *  @brief sngl_unsubscribe unregisters a listener from
 *         future events on this bus
 */
sngl_ret_t sngl_unsubscribe();

/**
 *  @brief sngl_publish emits an event onto a bus
 *         calling all handlers for that event in order
 *         of their registration
 */
sngl_ret_t sngl_publish();

/** END **/
