//
// Created by Marleny Espinoza on 11/1/26.
//
#include "ActionQueue.h"

#include <stdexcept>

ActionQueue::ActionQueue(std::size_t capacity)
    : items_(capacity) {
}

bool ActionQueue::empty() const {
    return count_ == 0;
}

bool ActionQueue::full() const {
    return count_ == items_.size();
}

std::size_t ActionQueue::size() const {
    return count_;
}

bool ActionQueue::enqueue(const std::string& action) {
    // Si esta llena, no agregamos nada
    if (full()) {
        return false;
    }

    // Calcula donde va el nuevo elemento
    std::size_t backIndex =
        (frontIndex_ + count_) % items_.size();

    items_[backIndex] = action;
    count_++;

    return true;
}

std::string ActionQueue::dequeue() {
    // No podemos quitar nada si esta vacia
    if (empty()) {
        throw std::out_of_range("queue is empty");
    }

    // Guardamos el elemento del frente
    std::string action = items_[frontIndex_];

    // Movemos el frente a la siguiente posicion
    frontIndex_ =
        (frontIndex_ + 1) % items_.size();

    count_--;

    return action;
}

std::string ActionQueue::peek() const {
    if (empty()) {
        throw std::out_of_range("queue is empty");
    }

    return items_[frontIndex_];
}
