#ifndef H_RESRC_TESTO_COMPOSANT
#define H_RESRC_TESTO_COMPOSANT

#include "Racine.h"

#include <string>

namespace resrc
{
    namespace testo
    {
        class Composant
        {
        public:
            enum class Type
            {
                TEST,
                SUITE
            };

        private:
            const Type _type;
            const std::string _nom;

        protected:
            Composant(const Type type, const std::string nom);
                
        public:
            const Type& type() const;
            const std::string& nom() const;  

            virtual const int executer(const int argc, const char** argv) = 0;
        };
    }
}

#endif