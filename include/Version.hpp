#pragma once
#include "string"

const std::string &GetTemplateVersion()
{
    static std::string templateVersion("2.0");
    return templateVersion;
}

const std::string &GetSFMLVersion()
{
    static std::string sfmlVersion("2.6.1");
    return sfmlVersion;
}
