#include "auth.h"
#include "db.h"
#include <string>

std::string handleAuthRequest(const std::string& uniqueId) {
    Database db;

    if (db.verifyUserStatus(uniqueId)) {
        return "<h1>Доступ разрешен</h1>";
    } else {
        return "<h1>Ошибка доступа</h1>";
    }
}
