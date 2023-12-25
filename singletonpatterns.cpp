#include <iostream>
#include <string>

class University {
private:
    // Приватний конструктор, щоб заборонити створення об'єктів ззовні класу
    University() {
        // Ініціалізація даних за необхідності
    }

    // Приватний статичний екземпляр класу
    static University* instance;

public:
    // Метод для отримання єдиного екземпляра класу
    static University* getInstance() {
        if (!instance) {
            instance = new University();
        }
        return instance;
    }

    // Інші методи та дані класу
    void displayInfo() {
        std::cout << "Welcome to the University!" << std::endl;
    }

    // Додаткові методи та дані класу
};

// Ініціалізація статичної змінної
University* University::instance = nullptr;

int main() {
    // Використання єдиного екземпляра класу
    University* myUniversity = University::getInstance();
    myUniversity->displayInfo();

    // Ще один спроба отримати екземпляр класу
    University* anotherUniversity = University::getInstance();
    anotherUniversity->displayInfo();

    // Порівняння адрес об'єктів, повинно бути однаковою
    std::cout << "Address of myUniversity: " << myUniversity << std::endl;
    std::cout << "Address of anotherUniversity: " << anotherUniversity << std::endl;

    return 0;
}
