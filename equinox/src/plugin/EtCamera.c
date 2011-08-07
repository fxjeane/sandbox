#include "EtCamera.h"

//EtNodeMtds *mtds = (EtNodeMtds *) malloc(sizeof(EtNodeMtds));
plugin_init {
	printf("ran init\n");
};
camera_create_ray {
	printf("rays created bitch!\n");
};

static EtNodeDefaultMtds defmtds = {
	&init
};
static EtCameraMethods cammtds = {
	&createRay
};
static EtNodeMtds amtds = {
	&defmtds,
	&cammtds
};



EtNodeMtds *mtds = &amtds;

plugin_loader {
	plugin->pluginType 	= EI_PLUGIN_CAMERA;
	plugin->returnType 	= EI_TYPE_POINTER;
	plugin->name		= "ortho_camera";
	plugin->mtds		= mtds;
	return 1;
}

