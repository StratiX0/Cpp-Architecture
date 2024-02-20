#pragma once

// Classe mathématique Vector2D
template <typename T, typename U>
class Vector2D {
public:

    // Constructeur de la classe Vector2D
    Vector2D(T x, U y) : x(x), y(y) {}

    // Méthode pour obtenir l'élément X du vecteur
    T getX() const {
        return x;
    }

    // Méthode pour obtenir l'élément Y du vecteur
    U getY() const {
        return y;
    }

    // Méthode pour définir l'élément X du vecteur
    void setX(T new_x) {
        x = new_x;
    }

    // Méthode pour définir l'élément Y du vecteur
    void setY(U new_y) {
        y = new_y;
    }

    // Méthode pour calculer la magnitude du vecteur
    double magnitude() const {
        return sqrt(x * x + y * y);
    }

    // Méthode pour afficher le vecteur
    void print() const {
        std::cout << "Vector2D(" << x << ", " << y << ")" << std::endl;
    }

    // Surcharge de l'opérateur d'égalité ( == ) pour comparer deux instances de Vector2D
    bool operator==(const Vector2D& other) const {
        return (x == other.x) && (y == other.y);
    }

private:
    T x;
    U y;
};

// Opérateur de somme de vecteurs
template <typename T1, typename U1, typename T2, typename U2>
auto operator+(const Vector2D<T1, U1>& v1, const Vector2D<T2, U2>& v2) {
    return Vector2D<decltype(v1.getX() + v2.getX()), decltype(v1.getY() + v2.getY())>(
        v1.getX() + v2.getX(), v1.getY() + v2.getY());
}

// Opérateur de soustraction de vecteurs
template <typename T1, typename U1, typename T2, typename U2>
auto operator-(const Vector2D<T1, U1>& v1, const Vector2D<T2, U2>& v2) {
    return Vector2D<decltype(v1.getX() - v2.getX()), decltype(v1.getY() - v2.getY())>(
        v1.getX() - v2.getX(), v1.getY() - v2.getY());
}


// Fonction pour calculer le produit scalaire entre deux vecteurs
template <typename T, typename U>
T dotProduct(const Vector2D<T, U>& v1, const Vector2D<T, U>& v2) {
    return v1.getX() * v2.getX() + v1.getY() * v2.getY();
}


// Fonction pour calculer l'angle entre deux vecteurs
template <typename T, typename U>
double angleBetween(const Vector2D<T, U>& v1, const Vector2D<T, U>& v2) {
    double dot = dotProduct(v1, v2);
    double length_v1 = sqrt(v1.getX() * v1.getX() + v1.getY() * v1.getY());
    double length_v2 = sqrt(v2.getX() * v2.getX() + v2.getY() * v2.getY());
    return acos(dot / (length_v1 * length_v2));
}