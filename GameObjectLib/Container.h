#pragma once

// Classe de type Container
template <typename T>
class Container {
public:

    // Constructeur par défaut
    Container() : size(0), capacity(10) {
        elements = new T[capacity];
    }

    // Constructeur avec capacité initiale spécifiée
    Container(int initialCapacity) : size(0), capacity(initialCapacity) {
        elements = new T[capacity];
    }

    // Destructeur pour libérer la mémoire allouée dynamiquement
    ~Container() {
        delete[] elements;
    }

    // Ajouter un élément à la fin du conteneur
    void push_back(const T& value) {

        // Si la capacité est atteinte, doubler la capacité du conteneur
        if (size == capacity) {
            resize();
        }
        elements[size] = value;
        size++;
    }

    // Retirer le dernier élément du conteneur
    void pop_back() {
        if (size > 0) {
            size--;
        }
    }

    // Accéder à un élément par son indice
    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    // Obtenir la taille actuelle du conteneur
    int getSize() const {
        return size;
    }

private:

    // Méthode privée pour redimensionner le conteneur (doubler la capacité)
    void resize() {
        capacity *= 2;
        T* newElements = new T[capacity];
        for (int i = 0; i < size; i++) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }

    T* elements; // Tableau de stockage des éléments
    int size;
    int capacity;
};