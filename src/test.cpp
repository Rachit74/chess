#include <SFML/Graphics.hpp>

int main() {
    // Create a window for the chessboard
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Board");

    const int tileSize = 100;  // Each tile is 100x100 pixels (assuming an 800x800 window)
    const int boardSize = 8;   // 8x8 board

    // Load textures for chess pieces
    sf::Texture whiteKing, blackKing;
    if (!whiteKing.loadFromFile("assets/white_king.png")) {
        return EXIT_FAILURE;
    }
    if (!blackKing.loadFromFile("assets/black_king.png")) {
        return EXIT_FAILURE;
    }

    // Sprites for pieces
    sf::Sprite whiteKingSprite(whiteKing);
    sf::Sprite blackKingSprite(blackKing);

    // Position the pieces on the board
    whiteKingSprite.setPosition(4 * tileSize, 7 * tileSize); // White king at E1 (0-indexed)
    blackKingSprite.setPosition(4 * tileSize, 0 * tileSize); // Black king at E8 (0-indexed)

    // Main loop for drawing
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window to draw the board from scratch
        window.clear(sf::Color::White);

        // Draw the chessboard tiles
        for (int row = 0; row < boardSize; ++row) {
            for (int col = 0; col < boardSize; ++col) {
                sf::RectangleShape tile(sf::Vector2f(tileSize, tileSize));
                tile.setPosition(col * tileSize, row * tileSize);
                // Alternate colors (light/dark tiles)
                if ((row + col) % 2 == 0) {
                    tile.setFillColor(sf::Color(240, 217, 181)); // Light tile
                } else {
                    tile.setFillColor(sf::Color(181, 136, 99));  // Dark tile
                }
                window.draw(tile);
            }
        }

        // Draw the pieces on top of the chessboard
        window.draw(whiteKingSprite);
        window.draw(blackKingSprite);

        // Display everything
        window.display();
    }

    return 0;
}
