#ifndef H_RESRC_TESTO_IELEMENT
#define H_RESRC_TESTO_IELEMENT

#include "Racine.h"

#include <string>

namespace resrc
{
    namespace testo
    {
        class IElement
        {
        public:
            virtual const std::string& nom() const = 0;
        };
    }
}

#endif