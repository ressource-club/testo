#include "../include/Composant.h"

namespace resrc
{
    namespace testo
    {
        Composant::Composant(const Type type, const std::string nom)
            : _type{ type }, _nom{ nom }
        {}

        const Composant::Type& Composant::type() const
        { return this->_type; }

        const std::string& Composant::nom() const
        { return this->_nom; }
    }
}