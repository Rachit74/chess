#include <SFML/Graphics.hpp>

int main() {
    // Create a window with a title and resolution
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Window");

    // make textures

    // make a CircleShape object with a radius of 50;
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(200, 100); // Initial position

    // physcis
    sf::Vector2f velocity(0.f, 0.f);
    sf::Vector2f acceleration(0.f, 1.0f);

    float deltaTime = 0.01f;

    // Main loop: runs while the window is open
    while (window.isOpen()) {
        sf::Event event;
        // Poll events
        while (window.pollEvent(event)) {
            // Close window when close button is pressed
            if (event.type == sf::Event::Closed)
                window.close();
        }


                // Apply gravity to velocity (in the Y direction)
        velocity.y += acceleration.y * deltaTime;

        // Update the circle's position based on the velocity
        // provide x,y movement
        circle.move(0.f, velocity.y * deltaTime);

         // Get the current position and size of the circle
        sf::Vector2f position = circle.getPosition();
        float radius = circle.getRadius();

        // Check for collision with the bottom of the window
        if (position.y + radius * 2 >= window.getSize().y) {
            // Adjust position to prevent it from going out of bounds
            circle.setPosition(position.x, window.getSize().y - radius * 2);
            velocity.y = -velocity.y + 5;
        }

        // if (position.x + radius * 2 >= window.getSize().x) {
        //     circle.setPosition(0,0);
        // }


        // Clear window with a blue color
        window.clear(sf::Color::Blue);


        // Draw the sprite
        window.draw(circle);

        // Display content to the screen
        window.display();
    }

    return 0;
}
