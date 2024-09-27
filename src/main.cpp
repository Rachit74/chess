#include <SFML/Graphics.hpp>

int main() {
    // Create a window with a title and resolution
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    // loading a spirte(object?) to dispay
    sf::Texture texture;
    if (!texture.loadFromFile("./assets/test.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    // Main loop: runs while the window is open
    while (window.isOpen()) {
        sf::Event event;
        // Poll events
        while (window.pollEvent(event)) {
            // Close window when close button is pressed
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear window
        window.clear();

        // Draw sprite
        window.draw(sprite);

        // Display content to the screen
        window.display();
    }
    return 0;
}
