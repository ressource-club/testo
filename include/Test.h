#ifndef H_RESRC_TESTO_TEST
#define H_RESRC_TESTO_TEST

#include "ITest.h"

namespace resrc
{
    namespace testo
    {
        class Test : public ITest
        {
        private:
            const std::string _nom;

        protected:
            Test(const std::string nom) : _nom{ nom } {}

        public:
            inline const std::string& nom() const override { return this->_nom; }
        };
    }
}

#endif