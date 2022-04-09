#ifndef H_RESRC_TESTO_CONSOLE
#define H_RESRC_TESTO_CONSOLE

#include "IElement.h"

#include <iostream>

namespace resrc
{
    namespace testo
    {
        class Console
        {
        public:
            // TODO Affichage par crans avec la tabulation.
            inline void afficher(const std::string message, const bool retour = true)
            { std::cout << message << (retour ? "\n" : "") << std::flush; }

            inline void afficher(const IElement& element, const std::string message, const bool retour = true)
            { afficher("\t" + element.nom() + " > " + message, retour); }
        };
    }
}

#endif