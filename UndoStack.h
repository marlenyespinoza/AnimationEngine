//
// Created by Marleny Espinoza on 11/1/26.
//

#ifndef ANIMATIONENGINE_UNDOSTACK_H
#define ANIMATIONENGINE_UNDOSTACK_H
#pragma once

#include <cstddef>
#include <stdexcept>
#include <string>
#include <vector>

class UndoStack {
public:
    bool empty() const {
        return items_.empty();
    }

    std::size_t size() const {
        return items_.size();
    }

    void push(const std::string& action) {
        // Agrega la accion al final del vector
        items_.push_back(action);
    }

    std::string pop() {
        if (empty()) {
            throw std::out_of_range("stack is empty");
        }

        // Guarda el ultimo elemento
        std::string action = items_.back();

        // Elimina el ultimo elemento
        items_.pop_back();

        return action;
    }

    std::string peek() const {
        if (empty()) {
            throw std::out_of_range("stack is empty");
        }

        return items_.back();
    }

private:
    std::vector<std::string> items_;
};
#endif //ANIMATIONENGINE_UNDOSTACK_H
