#include <SFML/Graphics.hpp>

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");

    // Constant integer for tile pixel size
    const int tileSize = 100;

    // Main loop
    while (window.isOpen()) {
        sf::Event event;

        // Process events
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Clear the window
        window.clear();

        // Draw the board
        for (int row = 0; row < 8; ++row) {
            for (int column = 0; column < 8; ++column) {
                // Create a tile
                sf::RectangleShape tile(sf::Vector2f(tileSize, tileSize));
                tile.setPosition(column * tileSize, row * tileSize);

                // Alternate colors
                if ((row + column) % 2 == 0) {
                    tile.setFillColor(sf::Color(255, 255, 255)); // White
                } else {
                    tile.setFillColor(sf::Color(0, 0, 0)); // Black
                }

                // Draw the tile
                window.draw(tile);
            }
        }

        // Display the contents of the window
        window.display();
    }

    return 0;
}
