#ifndef _OBJECT_H
#define _OBJECT_H

#include "rb3/BinStream.h"
#include "rb3/Data.h"
#include "rb3/Symbol.h"

typedef struct _Object Object;

typedef void (*ObjDestructor_t)(Object *thisObject);
typedef void (*ObjOnlyReturns_t)();
typedef int (*ObjReturnsZero_t)();
typedef Symbol (*ObjClassName_t)(Symbol retSym);
typedef void (*ObjSetType_t)(Object *thisObject, Symbol type);
typedef DataNode *(*ObjHandle_t)(DataNode *retNode, Object *thisObject, DataArray *msg, char unk);
typedef void (*ObjSyncProperty_t)(Object *thisObject);
typedef void (*ObjSave_t)(Object *thisObject, BinStream *binStream);
typedef void (*ObjCopy_t)(Object *to, Object *from, int copyType);
typedef void (*ObjLoad_t)(Object *thisObject, BinStream *binStream);
typedef void (*ObjSetTypeDef_t)(Object *thisObject, DataArray *typeDef);
typedef void (*ObjSetName_t)(Object *thisObject, Symbol name, int *parentDir);
typedef int *(*ObjDataDir_t)(Object *thisObject);
typedef void (*ObjPreLoad_t)(Object *thisObject, BinStream *binStream);
typedef char *(*ObjFindPathName_t)(Object *thisObject);

typedef struct _Object_vtable
{
    ObjDestructor_t destructor;
    ObjOnlyReturns_t onlyReturns1;
    ObjOnlyReturns_t onlyReturns2;
    ObjReturnsZero_t returnsZero;
    ObjClassName_t className;
    ObjSetType_t setType;
    ObjHandle_t handle;
    ObjSyncProperty_t syncProperty;
    ObjSave_t save;
    ObjCopy_t copy;
    ObjLoad_t load;
    ObjOnlyReturns_t onlyReturns3;
    ObjOnlyReturns_t onlyReturns4;
    ObjOnlyReturns_t onlyReturns5;
    ObjOnlyReturns_t onlyReturns6;
    ObjSetTypeDef_t setTypeDef;
    ObjSetName_t setName;
    ObjDataDir_t dataDir;
    ObjPreLoad_t preLoad;
    ObjOnlyReturns_t onlyReturns7;
    ObjFindPathName_t findPathName;
} Object_vtable;

struct _Object
{

    Object_vtable *table; // the object's vtable
    char unk[0x14];
    char *name;
};

#endif // _OBJECT_H