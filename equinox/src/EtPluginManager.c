#include "EtPluginManager.h"


int EiLoadPlugin(const char *lib) {
    void 		*handle;
	int 		*pluginType;
    //char		*name;
	bool 		(*load)(int i, EtPlugin *);
    char 		*error;

	handle = dlopen (lib, RTLD_LAZY);

    if (!handle) {
        fputs (dlerror(), stderr);
        exit(1);
    } else {
		load = dlsym(handle, "load");
		EtPlugin *plugin = (EtPlugin *) malloc(sizeof(EtPlugin));
		int i;
		load(i,plugin);

		printf("Loaded %s\n",plugin->name);	
		buf_push(EtPluginRegistry.names, plugin->name);
		buf_push(EtPluginRegistry.plugins, *plugin);
	}

    if ((error = dlerror()) != NULL)  {
        fputs(error, stderr);
		//printf("\nBar\n");
        exit(1);
    }
    //dlclose(handle);

}

int EiLoadPlugins(const char *directory) {
 	struct dirent **filelist = {0};
 	int fcount = -1;
 	int i = 0;
 	fcount = scandir(directory, &filelist, 0, alphasort);
 	if(fcount < 0) {
  		perror(directory);
  		return 1;
 	}
	for(i = 2; i < fcount; i++)  {
		// prepare  path for loading
		char path[sizeof(directory)+sizeof(filelist[i]->d_name)+2];
		strcat(strcat(path,directory),"/");

  		EiLoadPlugin(strcat(path,filelist[i]->d_name));
		free(filelist[i]);
		strcpy(path,"");
 	}
 	free(filelist);
}

void* EiGetPlugin(const char *name) {
	EtInt i = 0;
	for (i ; i < buf_len(EtPluginRegistry.names); i++) {
		if (strcmp(EtPluginRegistry.names[i],name) == 0) {
			return &EtPluginRegistry.plugins[i];
		}
	}
	return NULL;
	
}
