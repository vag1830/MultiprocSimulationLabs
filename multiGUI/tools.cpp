#include <QString>

bool toBoolean ( QString str ) {
    return ( !str.compare("true") ) ? true : false;
}
