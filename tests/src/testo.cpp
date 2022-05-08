#include "../../include/testo.h"
/**
void ajouter_tests(resrc::testo::App& app)
{
}

int main(const int argc, const char** argv)
{
    resrc::testo::App app{ "testo" };
    ajouter_tests(app);
    return app.executer(argc, argv);
}
*/
class Test : public resrc::testo::Test
{
public:
    Test() : resrc::testo::Test("Test unitaire n°1") {}

    const bool test() override
    {
        return 7 == 8;
    }
};

class Suite : public resrc::testo::Suite
{
public:
    Suite() : resrc::testo::Suite("Suite de tests") 
    {
        this->ajouter(new Test());
    }
};

int main(const int argc, const char** argv)
{
    resrc::testo::App app{ "Application de test" };
    // Ajout à la suite de tests générale.
    app.ajouter(new Test());
    // Ajout de votre suite de tests.
    app.ajouter(new Suite());
    // Lancement de l'application
    return app.executer(argc, argv);
}