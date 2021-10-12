#include <SFML/Graphics.hpp>
#include <filesystem>
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
        window.display();
    }

    return 0;
}

void modifyCurrentWorkingDirectory()
{
    while (!std::filesystem::exists("resources"))
    {
        std::filesystem::current_path(std::filesystem::current_path().parent_path());
    }
    auto cwd = std::filesystem::current_path();
}
