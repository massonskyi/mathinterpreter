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

#include <stdio.h>
#include <stdlib.h>
#include "../../include/mod/objects.h"

/**
 * @brief Initializes a Signal object.
 *
 * This function initializes a Signal object by setting its count to 0, its capacity to 2,
 * and allocating memory for its slots array.
 *
 * @param signal Pointer to the Signal object to be initialized.
 */
void signal_init(Signal *signal) {
    signal->count = 0;
    signal->capacity = 2;
    signal->slots = (Slot *)malloc(sizeof(Slot) * signal->capacity);
    pthread_mutex_init(&signal->mutex, NULL); // Инициализация мьютекса
}

/**
 * @brief Frees the memory allocated for a Signal object.
 *
 * This function frees the memory allocated for the slots array of a Signal object.
 *
 * @param signal Pointer to the Signal object to be freed.
 */
void free_signal(Signal *signal) {
    if (signal->slots != NULL){
        pthread_mutex_destroy(&signal->mutex);
        signal->slots = NULL;
        signal->capacity = 0;
        signal->count = 0;
        free(signal->slots);
    }
}

/**
 * @brief Expands the slots array of a Signal object.
 *
 * This function doubles the capacity of the slots array if the current count of slots
 * reaches the capacity.
 *
 * @param signal Pointer to the Signal object whose slots array should be expanded.
 */
void expand_slots(Signal *signal) {
    if (signal->count >= signal->capacity) {
        signal->capacity *= 2;
        signal->slots = (Slot *)realloc(signal->slots, signal->capacity * sizeof(Slot));
    }
}

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
void connect_slot(Signal *signal, func_t func, void *args) {
    pthread_mutex_lock(&signal->mutex); // Захватываем мьютекс

    expand_slots(signal);
    signal->slots[signal->count].func = func;
    signal->slots[signal->count].args = args;
    signal->count++;

    pthread_mutex_unlock(&signal->mutex); // Освобождаем мьютекс
}

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
void disconnect_slot(Signal *signal, func_t func) {
    pthread_mutex_lock(&signal->mutex); // Захватываем мьютекс

    for (int i = 0; i < signal->count; i++) {
        if (signal->slots[i].func == func) {
            for (int j = i; j < signal->count - 1; j++) {
                signal->slots[j] = signal->slots[j + 1];
            }
            signal->count--;
            break;
        }
    }

    pthread_mutex_unlock(&signal->mutex); // Освобождаем мьютекс
}

/**
 * @brief Disconnects all slots from a signal.
 *
 * This function removes all slots from the signal's list of slots by setting the slot count to 0.
 *
 * @param signal Pointer to the Signal object from which all slots should be disconnected.
 */
void disconnect_all_slots(Signal *signal) {
    pthread_mutex_lock(&signal->mutex); // Захватываем мьютекс
    
    signal->count = 0;
    
    pthread_mutex_unlock(&signal->mutex); // Освобождаем мьютекс
}

/**
 * @brief Emits a signal.
 *
 * This function calls the function of each slot in the signal's list of slots,
 * passing the provided data and the slot's arguments to the function.
 *
 * @param signal Pointer to the Signal object to be emitted.
 * @param data Pointer to the data to be passed to each slot function.
 */

void emit_signal(Signal *signal, void *data) {
    pthread_mutex_lock(&signal->mutex); // Захватываем мьютекс
    for (int i = 0; i < signal->count; i++) {
        Slot *slot = &signal->slots[i];
        slot->func(data, slot->args);
    }
    pthread_mutex_unlock(&signal->mutex); // Освобождаем мьютекс
}

