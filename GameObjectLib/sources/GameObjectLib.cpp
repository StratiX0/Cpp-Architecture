#include <iostream>
#include <vector>
#include "../Container.h"
#include "../GameObject.h"
#include "../Vector.h"
#include "../Collider.h"

void HelloFromLib() {
    /*std::cout << "Hello from GameObjectLib" << std::endl;*/
}

void projet() {
    // Utilisation de la classe Vector2D
    Vector2D<int, float> intFloatVector(3, 2.5f);
    intFloatVector.print();
    intFloatVector.setX(5);
    intFloatVector.setY(3.0f);
    intFloatVector.print();

    Vector2D<double, int> doubleIntVector(2.5, 4);
    doubleIntVector.print();

    // Créez deux vecteurs
    Vector2D<int, int> vector1(10, 2);
    Vector2D<int, int> vector2(5, 8);

    // Addition de vecteurs
    Vector2D<int, int> sum = vector1 + vector2;
    std::cout << "Somme des vecteurs : ";
    sum.print();

    // Soustraction de vecteurs
    Vector2D<int, int> difference = vector1 - vector2;
    std::cout << "Difference des vecteurs : ";
    difference.print();

    // Produit scalaire
    int dot = dotProduct(vector1, vector2);
    std::cout << "Produit scalaire des vecteurs : " << dot << std::endl;

    // Angle entre deux vecteurs
    double angle = angleBetween(vector1, vector2);
    std::cout << "Angle entre les vecteurs (en radians) : " << angle << std::endl;

    // Utilisation de la classe Container
    Container<int> intContainer;
    intContainer.push_back(10);
    intContainer.push_back(20);
    intContainer.push_back(30);

    Container<std::string> stringContainer;
    stringContainer.push_back("Hello");
    stringContainer.push_back("World");

    std::cout << "Size of stringContainer: " << stringContainer.getSize() << std::endl;
    std::cout << "Elements in stringContainer: ";
    for (int i = 0; i < stringContainer.getSize(); i++) {
        std::cout << stringContainer[i] << " ";
    }
    std::cout << std::endl;


    // Créez un GameObject avec une position initiale
    GameObject<int> gameObj(Vector2D<int, int>(5, 10)); 

    // Accède à la position en utilisant la méthode getPosition()
    Vector2D<int, int> position = gameObj.getPosition();

    // Affiche la position
    std::cout << "Position de l'objet : (" << position.getX() << ", " << position.getY() << ")" << std::endl;

    // ---------------------------------------




    SquareObject<int> squareObj(Vector2D<int, int>(6, 9), 10, 10); // Créez un carre avec une position et une taille initiale

    // Accède à la position en utilisant la méthode getPosition()
    Vector2D<int, int> positionCarre = squareObj.getPosition();

    // Accède à la hauteur en utilisant la méthode getHeight()
    int height = squareObj.getHeight();

    // Accède à la largeur en utilisant la méthode getWidth()
    int width = squareObj.getWidth();

    // Affiche la position
    std::cout << "Position du carre : (" << positionCarre.getX() << ", " << positionCarre.getY() << ")" << std::endl;

    // Affiche la hauteur et la largeur
    std::cout << "La hauteur et la largeur du carre : (" << height << ", " << width << ")" << std::endl;

    // ---------------------------------------

    CircleObject<int> circleObj(Vector2D<int, int>(6, 9), 10); // Créez un cercle avec une position et un rayon initiale

    // Accède à la position en utilisant la méthode getPosition()
    Vector2D<int, int> positionCircle = circleObj.getPosition();

    // Accède au radius en utilisant la méthode getRadius()
    int radius = circleObj.getRadius();

    // Affiche la position
    std::cout << "Position du cercle : (" << positionCircle.getX() << ", " << positionCircle.getY() << ")" << std::endl;

    // Affiche le rayon
    std::cout << "Le rayon du cercle : " << radius << std::endl;

    Colliders<int> collider; // Créez une instance de la classe Colliders pour tester les collisions

    if (collider.checkCollision(squareObj, circleObj)) {
        std::cout << "Collision detectee entre le carre et le cercle." << std::endl;
    }
    else {
        std::cout << "Pas de collision entre le carre et le cercle." << std::endl;
    }










}
