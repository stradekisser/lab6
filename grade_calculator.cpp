#include <iostream>
#include <string>

int main() {
    // === ШАГ 2. Объявление переменных ===
    int totalScore;           // Общий балл (0-100)
    int labScore;             // Баллы за лабораторные работы (0-40)
    int examScore;            // Баллы за экзамен (0-60)
    std::string grade;        // Итоговая оценка
    std::string status;       // Статус (зачтено/не зачтено)

    // === ШАГ 3. Организация ввода данных ===
    std::cout << "=== СИСТЕМА ОЦЕНИВАНИЯ СТУДЕНТОВ ===" << std::endl;
    std::cout << std::endl;

    std::cout << "Введите баллы за лабораторные работы (0-40): ";
    std::cin >> labScore;

    std::cout << "Введите баллы за экзамен (0-60): ";
    std::cin >> examScore;

    // === ШАГ 4. Валидация входных данных ===
    // Проверка диапазона баллов за лабораторные работы
    if (labScore < 0 || labScore > 40) {
        std::cout << "Ошибка: баллы за лабораторные должны быть от 0 до 40" << std::endl;
        return 1;
    }

    // Проверка диапазона баллов за экзамен
    if (examScore < 0 || examScore > 60) {
        std::cout << "Ошибка: баллы за экзамен должны быть от 0 до 60" << std::endl;
        return 1;
    }

    // === ШАГ 5. Вычисление общего балла и определение оценки ===
    totalScore = labScore + examScore;

    std::cout << std::endl;
    std::cout << "Ваш общий балл: " << totalScore << " из 100" << std::endl;
    std::cout << std::endl;

    // Определение оценки по шкале
    if (totalScore >= 90) {
        grade = "5 (Отлично)";
        status = "ЗАЧТЕНО";
    } else if (totalScore >= 75) {
        grade = "4 (Хорошо)";
        status = "ЗАЧТЕНО";
    } else if (totalScore >= 60) {
        grade = "3 (Удовлетворительно)";
        status = "ЗАЧТЕНО";
    } else {
        grade = "2 (Неудовлетворительно)";
        status = "НЕ ЗАЧТЕНО";
    }

    std::cout << "Оценка: " << grade << std::endl;
    std::cout << "Статус: " << status << std::endl;

    // === ШАГ 6. Дополнительные проверки и рекомендации ===
    std::cout << std::endl;
    std::cout << "=== АНАЛИЗ РЕЗУЛЬТАТОВ ===" << std::endl;

    // Проверка минимального порога по экзамену
    if (examScore < 20) {
        std::cout << "Внимание: набрано менее 20 баллов за экзамен" << std::endl;
        std::cout << "Рекомендуется пересдача экзамена." << std::endl;
    }

    // Проверка активности на лабораторных работах
    if (labScore < 20) {
        std::cout << "Внимание: низкая активность на лабораторных работах." << std::endl;
    } else if (labScore >= 35) {
        std::cout << "Отличная работа на лабораторных." << std::endl;
    }

    // Рекомендации по улучшению результата
    if (totalScore < 60) {
        std::cout << std::endl;
        std::cout << "Для получения зачёта необходимо набрать минимум 60 баллов." << std::endl;
        std::cout << "Недостающее количество баллов: " << (60 - totalScore) << std::endl;
    } else if (totalScore < 90) {
        std::cout << std::endl;
        std::cout << "Для получения оценки 'Отлично' необходимо набрать 90 и более баллов." << std::endl;
        std::cout << "Недостающее количество баллов: " << (90 - totalScore) << std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "Достигнут максимальный уровень." << std::endl;
    }

    // Проверка условий получения стипендии
    std::cout << std::endl;
    if (totalScore >= 75 && examScore >= 30) {
        std::cout << "Имеются основания для получения академической стипендии." << std::endl;
    } else if (totalScore >= 60) {
        std::cout << "Баллов недостаточно для получения стипендии." << std::endl;
    }

    return 0;
}