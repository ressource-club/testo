# resrc/__testo__
__testo__ est un outil de test unitaire pour le _C++_ simple, léger et entièrement libre et indépendant. L'application utilise __CMake__ afin de générer _un unique exécutable_ de test intégrant l'ensemble de vos tests unitaires.

## Utilisation
1. Clonez le repo __ressource-club/testo__ dans votre projet, ou bien utilisez le en tant que __module Git__ : 
    ```sh
    git submodule add https://github.com/ressource-club/testo.git bib/testo
    ```

2. Dans le fichier _CMakeLists.txt_ de votre projet, pensez à inclure le dossier contenant __testo__ dans la compilation avec la commande suivante :
    ```cmake
    include(${CMAKE_CURRENT_LIST_DIR}/bib/testo/CMakeLists.txt)
    ```
    Vous pouvez également ajouter les fichiers sources de votre projet à la compilation de __testo__ grâce à la variable _RESRC_TESTO_PROJET_SRC_, et des bibliothèques via la variable _RESRC_TESTO_PROJET_BIB_ :
    ```cmake
    set(
        RESRC_TESTO_PROJET_SRC
        ${PROJET_INCLUDES}      # Fichiers d'entête.
        ${PROJET_SRC}           # Fichiers sources.
    )
    set(
        RESRC_TESTO_PROJET_BIB
        ${PROJET} ${PROJET_DEP} # Bibliothèques à inclure.
    )
    ```

3. Créez un dossier nommé __tests__ dans le répertoire contenant le fichier _CMakeLists.txt_ de votre projet. Vous y placerez l'ensemble de vos fichiers _.h_ et _.cpp_ contenant des tests unitaires.

4. Dans un nouveau fichier __Tests.h__, écrivez votre premier test :
    ```cpp
    #include "../bib/testo/include/testo.h"

    class Test : public resrc::testo::Test
    {
    public:
        Test() : resrc::testo::Test("Test unitaire n°1") {}

        const bool test() override
        {
            return 7 == 8;
        }
    };
    ```

5. Vous pouvez également définir une suite de tests afin de regrouper vos tests :
    ```cpp
    class Suite : public resrc::testo::Tests
    {
    public:
        Suite() : resrc::testo::Tests("Suite de tests") 
        {
            this->ajouter(new Test());
        }
    };    
    ```
    > ___REMARQUE :__ vous pouvez spécifier dans le constructeur si vous souhaitez que la suite de tests s'__arrête au premier échec__ rencontré, ou bien à la __première erreur__ non gérée._

6. Créez enfin un fichier _.cpp_ implémentant la fonction __main__ dans laquelle vous ajouterez votre test et votre suite de tests à l'application de test :
    ```cpp
    #include "Tests.h"

    int main(const int argc, const char** argv)
    {
        // Ajout à la suite de tests générale.
        resrc::testo::app::ajouter(new Test());
        // Ajout de votre suite de tests.
        resrc::testo::app::ajouter(new Suite());
        // Lancement de l'application
        return resrc::testo::app::executer(argc, argv);
    }
    ```
    > ___REMARQUE :__ ajouter un test à l'application (première opération) revient à l'ajouter à la suite de tests par défaut nommée __tests__._

7. Compilez ensuite l'application à l'aide de _CMake_ :
    ```sh
    mkdir cmake
    cd cmake
    cmake ..
    make
    ```

8. Lancez l'application de test ```testo``` qui a été génrée dans le dossiers des binaires (_bin_). Avec l'exemple précédent, vous devriez obtenir un affichage similaire à celui-ci :
    ```sh
    > testo v0.0.2 - resrc.club
        tests > Exécution des tests...
                > [1/1] Test unitaire n°1 -> ECHEC
        tests > Résultat : 0 sur 1
        Suite de tests > Exécution des tests...
                > [1/1] Test unitaire n°1 -> ECHEC
        Suite de tests > Résultat : 0 sur 1
    ```