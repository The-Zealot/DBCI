#ifndef DBCI_LIB_GLOBAL_H
#define DBCI_LIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DBCI_LIB_LIBRARY)
#  define DBCI_LIB_EXPORT Q_DECL_EXPORT
#else
#  define DBCI_LIB_EXPORT Q_DECL_IMPORT
#endif

#endif // DBCI_LIB_GLOBAL_H
