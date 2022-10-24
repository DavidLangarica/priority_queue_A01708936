// =================================================================
//
// Archivo: priorityqueue.h
// Autores: David René Langarica Hernández - A01708936
// Descripción: Clase priority queue para la actividad 3.2.
//
// Recursos utilizados: Basado en la solución del libro 
// =================================================================

#include <iostream>
#include <vector>

using std::cout;
using std::swap;
using std::vector;

// =================================================================
// Definition of the Priority_Queue class
// =================================================================
class Priority_Queue {
   private:
    vector<int> heap;

   public:
    Priority_Queue(){};

    void sort_parent(int);
    void sort_child(int);

    void push(int);

    void pop();
    int top();
    bool empty();
    int size();
    void print();
};

// =================================================================
// Ordena el heap de forma ascendente con base en el padre
//
// @param i, posición del elemento recién agregado.
// =================================================================

void Priority_Queue::sort_parent(int i) {
    // Llegar a la posición del padre
    int parent = (i - 1) / 2;

    // Si el hijo es mayor que el padre
    if (heap[i] > heap[parent]) {
        // Hacer swap con el hijo y el padre
        swap(heap[i], heap[parent]);

        // Aplicar recursividad con el padre
        sort_parent(parent);
    }
}

// =================================================================
// Ordena el heap de forma ascendente con base en el hijo
//
// @param i, posición del elemento recién agregado.
// =================================================================

void Priority_Queue::sort_child(int i) {
    // Llegar a la posición de los hijos
    int left = (2 * i);
    int right = (2 * i + 1);

    // Se asume que el padre es el valor más alto
    int largest = i;

    // Comparar si la suposición anterior es correcta con ambos hijos
    if (heap[i] < heap[left]) {
        largest = left;
    }

    if (heap[i] < heap[right]) {
        largest = right;
    }

    // Si el padre no fue el mayor en los casos anteriores, hacer Swap
    // y aplicar recursividad con el hijo
    if (largest != i) {
        swap(heap[i], heap[largest]);
        sort_child(largest);
    }
}

// =================================================================
// Agrega un elemento a la fila priorizada y la ordena con base en
// los cambios necesarios por el elemento agregado.
//
// @param n, número entero para agregar en la lista.
// =================================================================

void Priority_Queue::push(int n) {
    heap.push_back(n);

    int i = size() - 1;
    sort_parent(i);
}

// =================================================================
// Saca de la fila priorizada el dato que tiene mayor prioridad
//
// @param
// =================================================================

void Priority_Queue::pop() {
    if (size() == 0) {
        cout << "La fila no tiene al menos un dato" << '\n';
    } else {
        // Swap entre el primer y último elemento
        swap(heap[0], heap.back());

        // Disminuir el tamaño del vector
        heap.resize(size() - 1);

        // Reacomodar la fila priorizada
        sort_child(0);
    }
};

// =================================================================
// Regresa el valor del dato que esta con mayor prioridad en la fila priorizada.
//
// @param
// =================================================================

int Priority_Queue::top() {
    if (size() == 0) {
        cout << "La fila esta vacia" << '\n';
        return 0;
    } else {
        // Se retorna la raíz, pues será el valor con mayor prioridad
        return heap.front();
    }
}

// =================================================================
// Regresa un valor booleano diciendo si la fila priorizada esta vacía o tiene datos.
//
// @param
// =================================================================

bool Priority_Queue::empty() {
    if (size() > 0) {
        return false;
    } else {
        return true;
    }
}

// =================================================================
// Regresa la cantidad de datos que tiene la fila priorizada
//
// @param
// =================================================================

int Priority_Queue::size() {
    return heap.size();
}

// =================================================================
// Imprime la fila priorizada
//
// @param
// =================================================================

void Priority_Queue::print() {
    if (size() == 0) {
        cout << "La fila esta vacia" << '\n';
    } else {
        for (int i = 0; i <= size() - 1; i++) {
            cout << heap[i] << " ";
        }
    }
}

int main() {
    Priority_Queue pq;

    cout << '\n'
         << "La fila esta vacia? (0 = NO, 1 = SI): " << pq.empty() << '\n';

    pq.push(5);
    pq.push(4);
    pq.push(221);
    pq.push(211);
    pq.push(3);
    pq.push(22);
    pq.push(2);
    pq.push(9);

    cout << '\n'
         << "Fila de prueba: ";
    pq.print();

    cout << '\n'
         << "La fila esta vacia? (0 = NO, 1 = SI): " << pq.empty() << '\n';
    cout << "Tamanio de la fila: " << pq.size() << '\n';

    pq.pop();

    cout << '\n'
         << "Fila despues de pop: ";
    pq.print();
    cout << '\n'
         << "El dato con mayor prioridad es: " << pq.top();

    return 0;
}