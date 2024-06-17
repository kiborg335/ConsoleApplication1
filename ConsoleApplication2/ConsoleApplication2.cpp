#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>
#include <chrono>

int main() {
    // Створюємо вікно
    sf::RenderWindow window(sf::VideoMode(576, 564), "Sprite Animation");

    // Завантажуємо текстури спрайтів
    std::vector<sf::Texture> textures(24);
    for (int i = 0; i < 24; ++i) {
        if (!textures[i].loadFromFile("C:\\Users\\Admin\\Desktop\\ConsoleApplication1\\photos\\" + std::to_string(i) + ".png")) {
            return -1; // Помилка при запускі зображення
        }
    }

    // Створюємо спрайт
    sf::Sprite sprite;
    sprite.setPosition(0, 0); // Позиція спрайта (центр вікна)

    // Індекс поточного спрайта
    int currentFrame = 0;

    // Головний цикл
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Обновляєм текстуру спрайта
        sprite.setTexture(textures[currentFrame]);

        // Очищуємо вікно
        window.clear();

        // Малюєм спрайт
        window.draw(sprite);

        // Відображаємо вміст вікна
        window.display();

        // Переходим до наступного кадру
        currentFrame = (currentFrame + 1) % 24;

        // Затримка 50 мілісекунд
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}
