#ifndef Resources_H
#define Resources_H

#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <memory>
#include <string>

namespace rap {
    class  Resources {
    private:

        std::map<std::string, std::shared_ptr<sf::Texture>> m_textures;


    public:
        Resources();

        bool load(const std::string &file_path, const std::string &resource_name);

        std::shared_ptr<sf::Texture> getTexture(const std::string &name);

        /* ~Resources(); */
    };
}

#endif
