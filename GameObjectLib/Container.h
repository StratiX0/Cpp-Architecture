#pragma once

// Classe de type Container
template <typename T>
class Container {
public:

    // Constructeur par d�faut
    Container() : size(0), capacity(10) {
        elements = new T[capacity];
    }

    // Constructeur avec capacit� initiale sp�cifi�e
    Container(int initialCapacity) : size(0), capacity(initialCapacity) {
        elements = new T[capacity];
    }

    // Destructeur pour lib�rer la m�moire allou�e dynamiquement
    ~Container() {
        delete[] elements;
    }

    // Ajouter un �l�ment � la fin du conteneur
    void push_back(const T& value) {

        // Si la capacit� est atteinte, doubler la capacit� du conteneur
        if (size == capacity) {
            resize();
        }
        elements[size] = value;
        size++;
    }

    // Retirer le dernier �l�ment du conteneur
    void pop_back() {
        if (size > 0) {
            size--;
        }
    }

    // Acc�der � un �l�ment par son indice
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

    // M�thode priv�e pour redimensionner le conteneur (doubler la capacit�)
    void resize() {
        capacity *= 2;
        T* newElements = new T[capacity];
        for (int i = 0; i < size; i++) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }

    T* elements; // Tableau de stockage des �l�ments
    int size;
    int capacity;
};