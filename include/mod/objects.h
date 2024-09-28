/*
 * COPYRIGHT (c) 2024 Massonskyi
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef MOD_OBJECTS_H_
#define MOD_OBJECTS_H_
#include <pthread.h>
// Определяем макрос для слотов
#define public_slot public
#define protected_slot protected
#define private_slot private

#define public_signal public
#define protected_signal protected
#define private_signal private_signal

// Проверочный макрос
#define CHECK_SLOTS_ONLY static_assert(true, "This section should contain only slots!");

#define MI_API

// Проверочный макрос
#define CHECK_SLOTS_ONLY static_assert(true, "This section should contain only slots!");

#define CREATE_SLOT(func, args) ((Slot){.func = func, .args = args})
#define CREATE_SIGNAL(capacity) ((Signal){.slots = malloc(sizeof(Slot) * capacity), .capacity = capacity, .count = 0, .mutex = PTHREAD_MUTEX_INITIALIZER})
#define ADD_SLOT_TO_SIGNAL(signal, slot)                          \
    do {                                                          \
    pthread_mutex_lock(&(signal).mutex);                      \
    if ((signal).count >= (signal).capacity) {                \
    (signal).capacity *= 2;                               \
    (signal).slots = realloc((signal).slots, sizeof(Slot) * (signal).capacity); \
    }                                                         \
    (signal).slots[(signal).count++] = slot;                  \
    pthread_mutex_unlock(&(signal).mutex);                    \
} while(0)

#define EMIT_SIGNAL(signal)                                   \
do {                                                          \
   pthread_mutex_lock(&(signal).mutex);                       \
   for (int i = 0; i < (signal).count; ++i) {                 \
   (signal).slots[i].func((signal).slots[i].args);            \
   }                                                          \
   pthread_mutex_unlock(&(signal).mutex);                     \
} while(0)

/**
 * @brief Function pointer type for slot functions.
 *
 * @param data Pointer to the data passed to the slot function.
 * @param args Pointer to the arguments passed to the slot function.
 */
typedef void (*func_t)(void *data, void *args);

/**
 * @brief Structure representing a slot.
 *
 * A slot contains a function pointer and its associated arguments.
 */
typedef struct {
    func_t func; /**< Function pointer for the slot. */
    void *args;  /**< Arguments for the slot function. */
} Slot;

/**
 * @brief Structure representing a signal.
 *
 * A signal contains a dynamic array of slots, its capacity, and the current count of slots.
 */
typedef struct {
    Slot *slots;   /**< Dynamic array of slots. */
    int capacity;  /**< Capacity of the slots array. */
    int count;     /**< Current count of slots. */

    pthread_mutex_t mutex; // Мьютекс для защиты доступа к слотам
} Signal;

/**
 * @brief Initializes a Signal object.
 *
 * This function initializes a Signal object by setting its count to 0, its capacity to 2,
 * and allocating memory for its slots array.
 *
 * @param signal Pointer to the Signal object to be initialized.
 */
void signal_init(Signal *signal);

/**
 * @brief Frees the memory allocated for a Signal object.
 *
 * This function frees the memory allocated for the slots array of a Signal object.
 *
 * @param signal Pointer to the Signal object to be freed.
 */
void free_signal(Signal *signal);

/**
 * @brief Expands the slots array of a Signal object.
 *
 * This function doubles the capacity of the slots array if the current count of slots
 * reaches the capacity.
 *
 * @param signal Pointer to the Signal object whose slots array should be expanded.
 */
void expand_slots(Signal *signal);

/**
 * @brief Connects a slot to a signal.
 *
 * This function adds a slot to the signal's list of slots. If the slots array is full,
 * it expands the array before adding the new slot.
 *
 * @param signal Pointer to the Signal object to which the slot should be connected.
 * @param func Function pointer for the slot function.
 * @param args Arguments for the slot function.
 */
void connect_slot(Signal *signal, const func_t func, void *args);

/**
 * @brief Disconnects a slot from a signal.
 *
 * This function removes a slot from the signal's list of slots if the slot's
 * function matches the provided function pointer. It shifts the remaining slots
 * in the list to fill the gap and decrements the slot count.
 *
 * @param signal Pointer to the Signal object from which the slot should be disconnected.
 * @param func Function pointer to the slot function that should be disconnected.
 */
void disconnect_slot(Signal *signal, const func_t func);

/**
 * @brief Disconnects all slots from a signal.
 *
 * This function removes all slots from the signal's list of slots by setting the slot count to 0.
 *
 * @param signal Pointer to the Signal object from which all slots should be disconnected.
 */
void disconnect_all_slots(Signal *signal);

/**
 * @brief Emits a signal.
 *
 * This function calls the function of each slot in the signal's list of slots,
 * passing the provided data and the slot's arguments to the function.
 *
 * @param signal Pointer to the Signal object to be emitted.
 * @param data Pointer to the data to be passed to each slot function.
 */
void emit_signal(Signal *signal, void *data);

#endif // MOD_OBJECTS_H_
