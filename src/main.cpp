#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>
#include "Version.hpp"

static void modifyCurrentWorkingDirectory();
static void setupVersionTexts(sf::RenderWindow &window, sf::Font &font, sf::Text &templateVersion, sf::Text &sfmlVersion);

int main()
{
    modifyCurrentWorkingDirectory();

    const auto clearColor = sf::Color(234, 240, 206);
    auto title = "Template-" + GetTemplateVersion() + "/SFML-" + GetSFMLVersion();
    sf::RenderWindow window(sf::VideoMode(640, 360), title, sf::Style::Close);

    sf::Font font;
    sf::Text sfmlVersion;
    sf::Text templateVersion;

    if (font.loadFromFile("resources/FiraCode-Regular.ttf"))
    {
        setupVersionTexts(window, font, templateVersion, sfmlVersion);
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

        window.clear(clearColor);
        window.draw(templateVersion);
        window.draw(sfmlVersion);
        window.display();
    }

    return 0;
}

void setupVersionTexts(sf::RenderWindow &window, sf::Font &font, sf::Text &templateVersion, sf::Text &sfmlVersion)
{
    auto windowCenter = sf::Vector2f(window.getSize().x * 0.5f, window.getSize().y * 0.5f);
    const auto characterSize = 65;
    const auto outlineThickness = 4.f;
    const auto fillColor = sf::Color(63, 51, 77);
    const auto outlineColor = sf::Color(192, 197, 193);

    templateVersion.setFont(font);
    templateVersion.setString("Template-v" + GetTemplateVersion());
    templateVersion.setCharacterSize(characterSize);
    templateVersion.setFillColor(fillColor);
    templateVersion.setOutlineColor(outlineColor);
    templateVersion.setOutlineThickness(outlineThickness);

    auto textRect = templateVersion.getLocalBounds();
    templateVersion.setOrigin(textRect.left + textRect.width * 0.5f, textRect.top + textRect.height * 0.5f);
    templateVersion.setPosition(windowCenter - sf::Vector2f(0.f, textRect.height));

    sfmlVersion.setFont(font);
    sfmlVersion.setString("SFML-v" + GetSFMLVersion());
    sfmlVersion.setCharacterSize(characterSize);
    sfmlVersion.setFillColor(fillColor);
    sfmlVersion.setOutlineColor(outlineColor);
    sfmlVersion.setOutlineThickness(outlineThickness);

    textRect = sfmlVersion.getLocalBounds();
    sfmlVersion.setOrigin(textRect.left + textRect.width * 0.5f, textRect.top + textRect.height * 0.5f);
    sfmlVersion.setPosition(windowCenter + sf::Vector2f(0.f, textRect.height));
}

void modifyCurrentWorkingDirectory()
{
    while (!std::filesystem::exists("resources"))
    {
        std::filesystem::current_path(std::filesystem::current_path().parent_path());
    }
    auto cwd = std::filesystem::current_path();
}
