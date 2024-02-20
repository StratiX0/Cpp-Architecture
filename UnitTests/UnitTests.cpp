#include "CppUnitTest.h"
#include "../Container.h"
#include "../GameObject.h"
#include "../Vector.h"
#include "../Collider.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    // Série de tests sur les container
    TEST_CLASS(ContainerTests)
    {
    public:
        // Test de base : vérifie si la taille du conteneur est correcte après l'ajout d'éléments
        TEST_METHOD(TestContainerSize)
        {
            Container<int> intContainer;
            intContainer.push_back(10);
            intContainer.push_back(20);
            intContainer.push_back(30);

            Assert::AreEqual(intContainer.getSize(), 3);
        }

        // Test de base : vérifie si les éléments sont corrects après avoir été ajoutés au conteneur
        TEST_METHOD(TestContainerElements)
        {
            Container<int> intContainer;
            intContainer.push_back(10);
            intContainer.push_back(20);
            intContainer.push_back(30);

            Assert::AreEqual(intContainer[0], 10);
            Assert::AreEqual(intContainer[1], 20);
            Assert::AreEqual(intContainer[2], 30);
        }

        // Test de base : vérifie si la capacité augmente correctement en ajoutant plus d'éléments
        TEST_METHOD(TestContainerCapacity)
        {
            Container<int> intContainer(2); // Capacité initiale de 2
            intContainer.push_back(10);
            intContainer.push_back(20);
            intContainer.push_back(30); // La capacité doit augmenter automatiquement

            Assert::AreEqual(intContainer.getSize(), 3);
            Assert::AreEqual(intContainer[2], 30);
        }

        // Test de base : vérifie si la suppression d'éléments fonctionne correctement
        TEST_METHOD(TestContainerPopBack)
        {
            Container<int> intContainer;
            intContainer.push_back(10);
            intContainer.push_back(20);
            intContainer.pop_back();

            Assert::AreEqual(intContainer.getSize(), 1);
            Assert::AreEqual(intContainer[0], 10);
        }
    };

    // Série de tests sur les vector
    TEST_CLASS(VectorTests)
    {
    public:

        // Test de base : vérifie que Vector2D fonctionne comme un std::vector
        TEST_METHOD(TestVectorCreate)
        {
            Vector2D<int, int> vector1(10, 2);
            std::vector<int> vector2 = { 10, 2 };
            int element1 = vector1.getX();
            int element2 = vector2[0];
            int element3 = vector1.getY();
            int element4 = vector2[1];

            Assert::AreEqual(element1, element2);
            Assert::AreEqual(element3, element4);
        }

        // Test de base : vérifie la somme de 2 vecteurs
        TEST_METHOD(TestVectorSum)
        {
            Vector2D<int, int> vector1(10, 2);
            Vector2D<int, int> vector2(5, 8);
            Vector2D<int, int> sumInt = vector1 + vector2;
            Vector2D<int, int> vector3(15, 10);

            Vector2D<float, float> vector4(8.0f, 5.0f);
            Vector2D<float, float> vector5(23.5f, 10.0f);
            Vector2D<float, float> sumFloat = vector4 + vector5;
            Vector2D<float, float> vector6(31.5f, 15.0f);

            Vector2D<int, float> vector7(10, 23.5f);
            Vector2D<int, int> vector8(5, 8);
            Vector2D<int, float> sumMix = vector7 + vector8;
            Vector2D<int, float> vector9(15, 31.5f);

            Assert::IsTrue(sumInt == vector3);
            Assert::IsTrue(sumFloat == vector6);
            Assert::IsTrue(sumMix == vector9);
        }

        // Test de base : vérifie la différence (soustraction) entre 2 vecteurs
        TEST_METHOD(TestVectorDif)
        {
            Vector2D<int, int> vector1(10, 2);
            Vector2D<int, int> vector2(5, 8);
            Vector2D<int, int> difference = vector1 - vector2;
            Vector2D<int, int> vector3(5, -6);

            Vector2D<int, float> vector4(10, 2);
            Vector2D<int, int> vector5(5, 8);
            Vector2D<int, float> difference2 = vector4 - vector5;
            Vector2D<int, float> vector6(5, -6);

            Assert::IsTrue(difference == vector3);
            Assert::IsTrue(difference2 == vector6);
        }

        // Test de base : vérifie le produit scalaire de 2 vecteurs
        TEST_METHOD(TestVectorScalaire)
        {
            Vector2D<int, int> vector1(10, 2);
            Vector2D<int, int> vector2(5, 8);
            int dot = dotProduct(vector1, vector2);

            Assert::AreEqual(dot, 66);
        }

        //Test de base : vérifie l'angle entre 2 vecteurs
        TEST_METHOD(TestVectorAngle)
        {
            Vector2D<int, int> vector1(10, 2);
            Vector2D<int, int> vector2(5, 8);

            double angle = angleBetween(vector1, vector2);
            double targetAngle = 0.814801;
            double tolerance = 0.000001; // Tolérance pour la comparaison, car nombre arrondi

            Assert::IsTrue(abs(angle - targetAngle) < tolerance);
        }

        //Test de base : vérifie la magnitude d'un vecteur
        TEST_METHOD(TestVectorMagnitude)
        {
            Vector2D<int, int> vector1(2, 2);
            Vector2D<int, int> vector2(2, 2);

            int mag = sqrt(vector1.getX() * vector2.getX() + vector1.getY() * vector2.getY());

            Assert::AreEqual(mag, 2);
        }
        
    };

    TEST_CLASS(ColliderTests)
    {
    public:

        // Test de base : vérifie si deux cercle sont en collision
        TEST_METHOD(TestColliderSquareCircle) {

            // Deux cercle en collision
            CircleObject<int> circle1(Vector2D<int, int>(0, 0), 10);
            SquareObject<int> square1(Vector2D<int, int>(0, 0), 10, 10);

            Colliders<int> collider;

            bool result = collider.checkCollision(square1, circle1);

            Assert::AreEqual(result, true);

            // Deux cercle qui ne sont pas en collision
            CircleObject<int> circle2(Vector2D<int, int>(0, 0), 10);
            SquareObject<int> square2(Vector2D<int, int>(100, 100), 10, 10);

            Colliders<int> collider2;

            bool result2 = collider2.checkCollision(square2, circle2);

            Assert::AreEqual(result2, false);
        }

        // Test de base : vérifie si deux carres sont en collision
        TEST_METHOD(TestColliderSquareSquare) {

            // Deux carres en collision
            SquareObject<int> square1(Vector2D<int, int>(0, 0), 10, 10);
            SquareObject<int> square2(Vector2D<int, int>(0, 0), 10, 10);

            Colliders<int> collider;

            bool result = collider.checkCollision(square1, square2);

            Assert::AreEqual(result, true);

            // Deux carres qui ne sont pas en collision
            SquareObject<int> square3(Vector2D<int, int>(0, 0), 10, 10);
            SquareObject<int> square4(Vector2D<int, int>(100, 100), 10, 10);

            Colliders<int> collider2;

            bool result2 = collider2.checkCollision(square3, square4);

            Assert::AreEqual(result2, false);
        }

        // Test de base : vérifie si deux cercle sont en collision
        TEST_METHOD(TestColliderCircleCircle) {

            // Deux cercle en collision
            CircleObject<int> circle1(Vector2D<int, int>(0, 0), 10);
            CircleObject<int> circle2(Vector2D<int, int>(0, 0), 10);

            Colliders<int> collider;

            bool result = collider.checkCollision(circle1, circle2);

            Assert::AreEqual(result, true);

            // Deux cercle qui ne sont pas en collision
            CircleObject<int> circle3(Vector2D<int, int>(0, 0), 10);
            CircleObject<int> circle4(Vector2D<int, int>(100, 100), 10);

            Colliders<int> collider2;

            bool result2 = collider2.checkCollision(circle3, circle4);

            Assert::AreEqual(result2, false);
        }
        
    };

}