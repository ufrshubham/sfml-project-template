#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream> 
#include "Version.hpp"

static void modifyCurrentWorkingDirectory();

int main()
{
    modifyCurrentWorkingDirectory();
    auto title = "Template-" + GetTemplateVersion() + "/SFML-" + GetSFMLVersion();
    sf::RenderWindow window(sf::VideoMode(640, 360), title, sf::Style::Close);

    sf::Texture texture;
    sf::Sprite sprite;
    sf::Text text;
    
    if (texture.loadFromFile("resources/sfml-project-template.png"))
    {
        sprite.setTexture(texture);
        sprite.setOrigin({(float)texture.getSize().x / 2, (float)texture.getSize().y / 2});
        sprite.setPosition((float)window.getSize().x / 2, (float)window.getSize().y / 2);
    }

    sf::Font font;
    if (!font.loadFromFile("resources/OpenSans-Regular.ttf"))
    {
        std::cerr << "Failed to load font. Application will continue without displaying text.\n";
    }
    else {
        text.setFont(font);
        text.setString("Hello SFML");
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(sf::Vector2f(400.0f, 20.0f));
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
        window.draw(text);
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
