#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>
#include <chrono>

int main() {
    // Создаем окно
    sf::RenderWindow window(sf::VideoMode(576, 564), "Sprite Animation");

    // Загружаем текстуры спрайтов
    std::vector<sf::Texture> textures(24);
    for (int i = 0; i < 24; ++i) {
        if (!textures[i].loadFromFile("C:\\Users\\Admin\\Desktop\\ConsoleApplication1\\photos\\" + std::to_string(i) + ".png")) {
            return -1; // Ошибка при загрузке изображения
        }
    }

    // Создаем спрайт
    sf::Sprite sprite;
    sprite.setPosition(0, 0); // Позиция спрайта (центр окна)

    // Индекс текущего спрайта
    int currentFrame = 0;

    // Главный цикл
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Обновляем текстуру спрайта
        sprite.setTexture(textures[currentFrame]);

        // Очищаем окно
        window.clear();

        // Рисуем спрайт
        window.draw(sprite);

        // Отображаем содержимое окна
        window.display();

        // Переходим к следующему кадру
        currentFrame = (currentFrame + 1) % 24;

        // Задержка 50 миллисекунд
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}
