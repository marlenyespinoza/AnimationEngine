#include <cassert>
#include <iostream>
#include <stdexcept>

#include "ActionQueue.h"
#include "UndoStack.h"

// Funcion para deshacer la ultima accion
void undoLast(UndoStack& history) {
    if (history.empty()) {
        std::cout << "Nothing to undo\n";
    } else {
        std::cout << "Undoing: "
                  << history.pop() << "\n";
    }
}

int main() {

    // -------------------------
    // TESTS PARA ACTION QUEUE
    // -------------------------

    ActionQueue q(3);

    assert(q.empty());

    q.enqueue("Fade In");
    q.enqueue("Move Character");
    q.enqueue("Play Sound");

    // FIFO: primero entra, primero sale
    assert(q.dequeue() == "Fade In");

    // Esto reutiliza el espacio libre
    q.enqueue("Rotate Character");

    assert(q.dequeue() == "Move Character");

    assert(q.size() == 2);

    // Llena la queue
    q.enqueue("Fade Out");

    assert(q.full());

    // No debe aceptar otro elemento
    assert(!q.enqueue("Too Many"));

    // Verifica el orden
    assert(q.peek() == "Play Sound");

    assert(q.dequeue() == "Play Sound");
    assert(q.dequeue() == "Rotate Character");
    assert(q.dequeue() == "Fade Out");

    assert(q.empty());

    // Probar excepcion cuando esta vacia
    bool threw = false;

    try {
        q.dequeue();
    } catch (const std::out_of_range&) {
        threw = true;
    }

    assert(threw);

    std::cout << "All queue tests passed!\n";


    // -------------------------
    // TESTS PARA UNDO STACK
    // -------------------------

    UndoStack history;

    history.push("Fade In");
    history.push("Move Character");
    history.push("Play Sound");

    // LIFO: ultimo entra, primero sale
    assert(history.pop() == "Play Sound");

    history.push("Rotate Character");

    assert(history.pop() == "Rotate Character");

    std::cout << "All stack tests passed!\n";


    // Probar undoLast
    history.push("Fade In");
    history.push("Move Character");

    undoLast(history);
    undoLast(history);
    undoLast(history);

    return 0;
}