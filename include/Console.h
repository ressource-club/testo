#ifndef H_RESRC_TESTO_CONSOLE
#define H_RESRC_TESTO_CONSOLE

#include "Composant.h"

#include <iostream>

namespace resrc
{
    namespace testo
    {
        class Console
        {
        private:
            static size_t _indentation;

        public:
            static void augmenter_indentation();
            static void reduire_indentation();

            // TODO Affichage par crans avec la tabulation.
            static void afficher(const std::string message, const bool retour = true);

            static void afficher(const Composant* const composant, const std::string message, const bool retour = true, const bool nom = true);

            inline static void saut() { afficher(""); }
        };
    }
}

#endif