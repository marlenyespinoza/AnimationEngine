//
// Created by Marleny Espinoza on 11/1/26.
//

#ifndef ANIMATIONENGINE_ACTIONQUEUE_H
#define ANIMATIONENGINE_ACTIONQUEUE_H
#pragma once

#include <cstddef>
#include <string>
#include <vector>

class ActionQueue {
public:
    explicit ActionQueue(std::size_t capacity);

    bool empty() const;
    bool full() const;
    std::size_t size() const;

    // Agrega una accion.
    // Regresa false si la queue esta llena.
    bool enqueue(const std::string& action);

    // Quita y regresa la accion del frente.
    // Lanza una excepcion si la queue esta vacia.
    std::string dequeue();

    // Regresa la accion del frente sin eliminarla.
    std::string peek() const;

private:
    std::vector<std::string> items_;

    // Posicion del primer elemento
    std::size_t frontIndex_ = 0;

    // Cantidad de elementos guardados
    std::size_t count_ = 0;
};

#endif //ANIMATIONENGINE_ACTIONQUEUE_H
