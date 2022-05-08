#include "../include/Test.h"

namespace resrc
{
    namespace testo
    {
        Test::Test(const std::string nom)
            : Composant(Composant::Type::TEST, nom)
        {}

        const int Test::executer(const int argc, const char** argv)
        {
            try
            {
                if (this->test()) return (int) Retour::SUCCES;
                else return (int) Retour::ECHEC;
            }
            catch (std::exception* erreur)
            {
                return (int) Retour::ERREUR;
            }
        }
    }
}