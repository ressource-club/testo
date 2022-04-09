#include "../include/Tests.h"
#include "../../include/testo.h"

void ajouter_tests()
{
    resrc::testo::app::ajouter(
        new resrc::testo::tests::Tests::Tests()
    );
}

int main(const int argc, const char** argv)
{
    ajouter_tests();
    return resrc::testo::app::executer(argc, argv);
}