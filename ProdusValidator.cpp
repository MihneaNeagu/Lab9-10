#include "ProdusValidator.h"

void ProdusValidator::validate(Produs p) {
    if (p.getPret() < 1)
        throw ProdusValidationError("Pretul nu poate fi < 1! ");
    if (p.getCod() < 1)
        throw ProdusValidationError("Codul nu poate fi < 1! ");
    if (p.getNume().length() > 10)
        throw ProdusValidationError("Numele nu poate avea o lungime mai mare de 10 caractere! ");
}
