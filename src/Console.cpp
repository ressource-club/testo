#include "../include/Console.h"

namespace resrc
{
    namespace testo
    {
        size_t Console::_indentation = 0;

        void Console::augmenter_indentation()
        { if (_indentation < SIZE_MAX) _indentation++; }

        void Console::reduire_indentation()
        { if (_indentation > 0) _indentation--; }

        void Console::afficher(const std::string message, const bool retour)
        { std::cout << message << (retour ? "\n" : "") << std::flush; }

        void Console::afficher(const Composant* const composant, const std::string message, const bool retour, const bool nom)
        {
            std::string pre = " > ";
            if (nom) pre = composant->nom() + pre;
            else
            {
                const size_t n = composant->nom().size();
                std::string espace;
                for (size_t c = 0; c < n; c++)
                    espace += " ";
                pre = espace + pre;
            }
            std::string tab;
            for (size_t i = 0; i < _indentation; i++)
                tab += "\t";
            afficher(tab + pre + message, retour);
        }
    }
}