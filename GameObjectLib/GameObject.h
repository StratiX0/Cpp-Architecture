#pragma once

#include "Vector.h"

template<typename T>
class GameObject {
public:

    // Constructeur de la classe de base GameObject
    GameObject(const Vector2D<T, T>& position) : position(position) {}

    // Méthode pour obtenir la position de l'objet
    const Vector2D<T, T>& getPosition() const {
        return position;
    }

    // Méthode pour définir la position de l'objet
    void setPosition(const Vector2D<T, T>& new_position) {
        position = new_position;
    }

private:
    Vector2D<T, T> position;
};

template<typename T>
class SquareObject : public GameObject<T> {
public:

    // Constructeur de la classe SquareObject qui hérite de GameObject
    SquareObject(const Vector2D<T, T>& position, T width, T height)
        : GameObject<T>(position), width(width), height(height) {}

    // Méthode pour obtenir la largeur du carré
    int getWidth() const {
        return width;
    }

    // Méthode pour obtenir la hauteur du carré
    int getHeight() const {
        return height;
    }

private:
    int width;
    int height;
};

template<typename T>
class CircleObject : public GameObject<T> {
public:

    // Constructeur de la classe CircleObject qui hérite de GameObject
    CircleObject(const Vector2D<T, T>& position, T radius)
        : GameObject<T>(position), radius(radius) {}

    // Méthode pour obtenir le rayon du cercle
    int getRadius() const {
        return radius;
    }

private:
    T radius;
};
