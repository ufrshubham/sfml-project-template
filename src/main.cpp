#include <SFML/Graphics.hpp>
#include <experimental/filesystem>
#include "Version.hpp"

static void modifyCurrentWorkingDirectory();

int main()
{
    modifyCurrentWorkingDirectory();
    auto title = "Template-" + GetTemplateVersion() + "/SFML-" + GetSFMLVersion();
    sf::RenderWindow window(sf::VideoMode(640, 360), title, sf::Style::Close);

    sf::Texture texture;
    sf::Sprite sprite;

    if (texture.loadFromFile("resources/sfml-project-template.png"))
    {
        sprite.setTexture(texture);
        sprite.setOrigin({(float)texture.getSize().x / 2, (float)texture.getSize().y / 2});
        sprite.setPosition((float)window.getSize().x / 2, (float)window.getSize().y / 2);
    }

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        return EXIT_FAILURE;
    }

    sf::Text text("Hello SFML", font, 24);
    text.setFillColor(sf::Color::White);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(sprite);
        window.draw(text);
        window.display();
    }

    return 0;
}
void modifyCurrentWorkingDirectory()
{
    while (!std::experimental::filesystem::exists("resources")) 
    {
        std::experimental::filesystem::current_path(std::experimental::filesystem::current_path().parent_path());
    }
    auto cwd = std::experimental::filesystem::current_path();
}
