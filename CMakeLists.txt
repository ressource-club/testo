cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${EXECUTABLE_OUTPUT_PATH}/bib)

# CONSTANTES
set(RESRC_TESTO resrc.testo) # Nom du projet CMake
set(RESRC_TESTO_VERSION 0.0.3) # Version de testo
set(RESRC_TESTO_RACINE ${CMAKE_CURRENT_LIST_DIR}/include/Racine.h) # En-tête racine (fichier de configuration)
set(RESRC_TESTO_DOSSIER ${CMAKE_SOURCE_DIR}/tests/) # Chemin du dossier contenant les tests utilisateurs
set(RESRC_TESTO_EXE testo) # Nom de l'executable généré

# Paramètres
if(NOT DEFINED RESRC_TESTO_MESSAGE_SUCCES)
    set(RESRC_TESTO_MESSAGE_SUCCES BRAVO) # Message de succès.
endif()
if(NOT DEFINED RESRC_TESTO_MESSAGE_ECHEC)
    set(RESRC_TESTO_MESSAGE_ECHEC ECHEC) # Message d'échec.
endif()
if(NOT DEFINED RESRC_TESTO_MESSAGE_ERREUR)
    set(RESRC_TESTO_MESSAGE_ERREUR ERREUR) # Message d'erreur.
endif()
# if(NOT DEFINED RESRC_TESTO_TESTS_NOM_PAR_DEFAUT)
#     set(RESRC_TESTO_TESTS_NOM_PAR_DEFAUT tests) # Nom par défaut des séries de tests.
# endif()
# if(NOT DEFINED RESRC_TESTO_TESTS_ARRET_ECHEC_PAR_DEFAUT)
#     set(RESRC_TESTO_TESTS_ARRET_ECHEC_PAR_DEFAUT false) # Défini si les séries doivent s'arrêter par défaut au premier échec.
# endif()
# if(NOT DEFINED RESRC_TESTO_TESTS_ARRET_ERREUR_PAR_DEFAUT)
#     set(RESRC_TESTO_TESTS_ARRET_ERREUR_PAR_DEFAUT false) # Défini si les séries doivent s'arrêter par défaut à la première erreur rencontrée.
# endif()

# PROJET
project(${RESRC_TESTO} LANGUAGES CXX VERSION ${RESRC_TESTO_VERSION})

# EXECUTABLE
# Configuration
configure_file(${RESRC_TESTO_RACINE}.in ${RESRC_TESTO_RACINE})
# Sources
file(
    GLOB_RECURSE
    RESRC_TESTO_SRC
    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
)
# En-têtes
file(
    GLOB_RECURSE
    RESRC_TESTO_INCLUDES
    ${CMAKE_CURRENT_LIST_DIR}/include/*.h
)
# Sources utilisateurs
file(
    GLOB_RECURSE
    RESRC_TESTO_SRC_TESTS
    ${RESRC_TESTO_DOSSIER}/*.cpp
)
# En-têtes utilisateurs
file(
    GLOB_RECURSE
    RESRC_TESTO_INCLUDES_TESTS
    ${RESRC_TESTO_DOSSIER}/*.h
)

# Bibliothèque
add_library(
    ${RESRC_TESTO}
    ${RESRC_TESTO_SRC}
    ${RESRC_TESTO_INCLUDES}
)

# Exécutable
add_executable(
    ${RESRC_TESTO_EXE}
    ${RESRC_TESTO_SRC_TESTS}
    ${RESRC_TESTO_INCLUDES_TESTS}
    ${RESRC_TESTO_PROJET_SRC} # Liste des fichiers du projet à tester
)
target_link_libraries(
    ${RESRC_TESTO_EXE}
    ${RESRC_TESTO}
    ${RESRC_TESTO_PROJET_BIB} # Liste des bibliothèques à tester
)