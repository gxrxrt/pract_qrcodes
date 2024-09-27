#ifndef AUTH_H
#define AUTH_H

#include <string>
#include "db.h"

std::string handleAuthRequest(const std::string& uniqueId);

#endif
