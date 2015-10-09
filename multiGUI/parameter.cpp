/************************************************************************************************
* From the point of view of the compiler, templates are not normal functions or classes.        *
* They are compiled on demand, meaning that the code of a template function is not compiled     *
* until an instantiation with specific template arguments is required.                          *
* At that moment, when an instantiation is required, the compiler generates a function          *
* specifically for those arguments from the template.                                           *
*                                                                                               *
* When projects grow it is usual to split the code of a program in different source code files. *
* In these cases, the interface and implementation are generally separated. Taking a library of *
* functions as example, the interface generally consists of declarations of the prototypes of   *
* all the functions that can be called. These are generally declared in a "header file" with a  *
* .h extension, and the implementation (the definition of these functions) is in an independent *
* file with c++ code.                                                                           *
*                                                                                               *
* Because templates are compiled when required, this forces a restriction for multi-file        *
* projects: the implementation (definition) of a template class or function must be in the same *
* file as its declaration. That means that we cannot separate the interface in a separate       *
* header file, and that we must include both interface and implementation in any file that uses *
* the templates.                                                                                *
*                                                                                               *
* Since no code is generated until a template is instantiated when required, compilers are      *
* prepared to allow the inclusion more than once of the same template file with both            *
* declarations and definitions in a project without generating linkage errors.                  *
************************************************************************************************/

#include "parameter.h"
/* -------------------------- Parameter methods implementation ------------------------------- */
Parameter::Parameter ( const QString gName, const QString gtype, QString gDesc, QString gGroup, QString gValue, QString gDValue, QString gSmallDesc ) {

    name = gName;
    type = gtype;
    desc = gDesc;
    group = gGroup;
    value = gValue;
    dValue = gDValue;
    smallDesc = gSmallDesc;
}

bool Parameter::isDefault() const {
    return ( value == dValue ) ? true : false;
}

QString Parameter::getName() const {
    return name;
}

QString Parameter::getType() const {
    return type;
}

QString Parameter::getDesc() const {
    return desc;
}

QString Parameter::getGroup() const {
    return group;
}
QString Parameter::getSmallDesc() const {
    return smallDesc;
}

void Parameter::setName( const QString gName ) {
    name = gName;
}

void Parameter::setType( const QString gtype ) {
    type = gtype;
}

void Parameter::setDesc( const QString gDesc ) {
    desc = gDesc;
}

void Parameter::setGroup( const QString gGroup ) {
    group = gGroup;
}
void Parameter::setSmallDesc( const QString gSmallDesc ) {
    smallDesc = gSmallDesc;
}

QString Parameter::getValue() const {
    return value;
}
QString Parameter::getDValue() const {
    return dValue;
}
void Parameter::setValue( const QString gValue ) {
    value = gValue;
}
void Parameter::setDValue( const QString gDValue) {
    dValue = gDValue;
}


Parameter::~Parameter() {}
/* -------------------------- Parameter methods implementation END --------------------------- */
/* -------------------------- Parameter_INT methods implementation --------------------------- */
//Parameter_INT::Parameter_INT ( const QString gName, const QString gType, QString gDesc, QString gGroup, const int gValue, const int gDValue ) :
//    Parameter( gName, gType, gDesc, gGroup ), value( gValue ), dValue( gDValue ) {}

//bool Parameter_INT::isDefault() const {
//    return ( value == dValue ) ? true : false;
//}

//int Parameter_INT::getIntValue() const {
//    return value;
//}
//int Parameter_INT::getIntDValue() const {
//    return dValue;
//}
//void Parameter_INT::setValue( const int gValue) {
//     value = gValue;
//}
//void Parameter_INT::setDValue( const int gDValue ) {
//    dValue = gDValue;
//}

//Parameter_INT::~Parameter_INT() {}
/* -------------------------- Parameter_INT methods implementation END ----------------------- */
/* -------------------------- Parameter_BOOL methods implementation -------------------------- */
//Parameter_BOOL::Parameter_BOOL ( const QString gName, const QString gType, QString gDesc, QString gGroup, const bool gValue, const bool gDValue ) :
//    Parameter( gName, gType, gDesc, gGroup ), value( gValue ), dValue( gDValue ) {}

//bool Parameter_BOOL::isDefault() const {
//    return ( value == dValue ) ? true : false;
//}

//bool Parameter_BOOL::getBoolValue() const {
//    return value;
//}
//bool Parameter_BOOL::getBoolDValue() const {
//    return dValue;
//}
//void Parameter_BOOL::setValue( const bool gValue) {
//     value = gValue;
//}
//void Parameter_BOOL::setDValue( const bool gDValue ) {
//    dValue = gDValue;
//}

//Parameter_BOOL::~Parameter_BOOL() {}
/* -------------------------- Parameter_BOOL methods implementation END ---------------------- */
/* -------------------------- Parameter_STRING methods implementation ------------------------ */
//Parameter_STRING::Parameter_STRING ( const QString gName, const QString gType, QString gDesc, QString gGroup, const QString gValue, const QString gDValue ) :
//    Parameter( gName, gType, gDesc, gGroup ), value( gValue ), dValue( gDValue ) {}

//bool Parameter_STRING::isDefault() const {
//    return ( value == dValue ) ? true : false;
//}

//QString Parameter_STRING::getStringValue() const {
//    return value;
//}
//QString Parameter_STRING::getStringDValue() const {
//    return dValue;
//}
//void Parameter_STRING::setValue( const QString gValue) {
//     value = gValue;
//}
//void Parameter_STRING::setDValue( const QString gDValue ) {
//    dValue = gDValue;
//}

//Parameter_STRING::~Parameter_STRING() {}
/* -------------------------- Parameter_STRING methods implementation END -------------------- */





















