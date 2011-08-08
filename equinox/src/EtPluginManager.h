#ifndef ET_PLUGIN_MANAGER_H
#define ET_PLUGIN_MANAGER_H
#include <stdio.h>
#include <dirent.h>
#include <dlfcn.h>
#include <strings.h>
#include "buf.h"
#include "EtTypes.h"
#include "EtApi.h"

struct EtNodeDefaultMtds {
	 void (* init)(void);
};
typedef struct EtNodeDefaultMtds EtNodeDefaultMtds;

struct EtNodeMtds {
	EtNodeDefaultMtds 	*dmethods;
	void				*umethods;
};
typedef struct EtNodeMtds EtNodeMtds;

struct EtPlugin {
	char 		*name;
	unsigned int pluginType;
	unsigned int returnType;
	EtNodeMtds	*mtds;
};
typedef struct EtPlugin EtPlugin;

/* The plugin registry keeps the  plugins that have been registered */
struct EtPluginRegistry {
	char 			**names;
	EtPlugin		*plugins;
} EtPluginRegistry;


#define plugin_loader bool load(int i, EtPlugin *plugin)
#define plugin_init void init(void)

ET_API int EiLoadPlugin(const char *lib);
ET_API int EiLoadPlugins(const char *dir);
ET_API void* EiGetPlugin(const char *name);

#endif //ET_PLUGIN_MANAGER_H
