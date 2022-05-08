#include "../include/testo.h"

#include <iostream>

namespace resrc
{
    namespace testo
    {
        App::App(const std::string nom)
            : Suite(nom)
        {}

        const int App::executer(const int argc, const char** argv)
        {
            Console::afficher(this, RESRC_TESTO_INTRO);
            Console::saut();
            const int retour = ((Suite)*this).executer(argc, argv);
            Console::saut();
            return retour;
        }
    }
}