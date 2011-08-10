#include "EtCamera.h"

plugin_params {
	printf("Added Parameters\n");
	EiNodeParamPoint(&node->params,"position",0,0,0);
	EiNodeParamPoint(&node->params,"lookAt",0,1,0);
};

plugin_init {
	printf("camera initialized\n");
};

camera_create_ray {
	printf("rays created bitch!\n");
};

static EtNodeDefaultMtds defmtds = {
	&init,
	&setParams
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

