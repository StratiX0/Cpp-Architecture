#pragma once

#include "Vector.h"

template<typename T>
class Colliders {
public:
    // Constructeur de la classe Colliders
    Colliders() {}

    // Méthode pour détecter une collision entre un carré et un cercle
    bool checkCollision(const SquareObject<T>& square, const CircleObject<T>& circle) {
        Vector2D<T, T> squareCenter = square.getPosition();
        Vector2D<T, T> circleCenter = circle.getPosition();

        // Calcule la distance entre les centres du carré et du cercle
        T distanceX = abs(squareCenter.getX() - circleCenter.getX());
        T distanceY = abs(squareCenter.getY() - circleCenter.getY());

        // Calcule la distance maximale entre les centres où la collision n'est pas possible
        T maxDistanceX = (square.getWidth() / 2) + circle.getRadius();
        T maxDistanceY = (square.getHeight() / 2) + circle.getRadius();

        // Si la distance entre les centres est inférieure à la distance maximale, il y a collision
        if (distanceX <= maxDistanceX && distanceY <= maxDistanceY) {
            return true;
        }

        return false;
    }

    // Méthode pour détecter une collision entre deux carrés
    bool checkCollision(const SquareObject<T>& square1, const SquareObject<T>& square2) {
        Vector2D<T, T> center1 = square1.getPosition();
        Vector2D<T, T> center2 = square2.getPosition();
        T halfWidth1 = square1.getWidth() / 2;
        T halfWidth2 = square2.getWidth() / 2;
        T halfHeight1 = square1.getHeight() / 2;
        T halfHeight2 = square2.getHeight() / 2;

        // Calcule la distance minimale nécessaire entre les centres pour qu'il n'y ait pas de collision
        T minDistanceX = halfWidth1 + halfWidth2;
        T minDistanceY = halfHeight1 + halfHeight2;

        // Calcule la distance entre les centres
        T distanceX = abs(center1.getX() - center2.getX());
        T distanceY = abs(center1.getY() - center2.getY());

        // Si la distance entre les centres est inférieure à la distance minimale, il y a collision
        if (distanceX <= minDistanceX && distanceY <= minDistanceY) {
            return true;
        }

        return false;
    }

    // Méthode pour détecter une collision entre deux cercles
    bool checkCollision(const CircleObject<T>& circle1, const CircleObject<T>& circle2) {
        Vector2D<T, T> center1 = circle1.getPosition();
        Vector2D<T, T> center2 = circle2.getPosition();
        T radius1 = circle1.getRadius();
        T radius2 = circle2.getRadius();

        // Calcule la distance entre les centres des deux cercles
        T distance = Vector2D<T, T>(center1.getX() - center2.getX(), center1.getY() - center2.getY()).magnitude();

        // Si la distance entre les centres est inférieure à la somme des rayons, il y a collision
        if (distance <= radius1 + radius2) {
            return true;
        }

        return false;
    }

};
